#include <Arduino.h>

enum class EMovements { Stop, Up, Down, LeftUp, LeftDown, RightUp, RightDown };
enum class ESpeedMode { None, Slow, Normal, Fast, Turbo }; // sets max. speed range, instead of 255, to values {0, 55, 110, 165, 220} by multiplying with SPEED_UNIT
enum class ETurnMode { One, Both };		//how to change direction: One like a tank with only one axis in movement, or Both with one axis faster than the other axis
const int SPEED_UNIT = 55;	//base value for max. speed which is calculated SPEED_UNIT * int(ESpeedMode)

class CMotors
{
public:
	// Contructors
	CMotors()
	{
		m_CurrentMovement = EMovements::Stop;
		m_CurrentTurnMode = ETurnMode::Both;
		SetSpeedMode(ESpeedMode::Normal);
		m_bIsVirtualMotor = true;
	}

	CMotors(uint8_t iPinAxisLeft1, uint8_t iPinAxisLeft2, uint8_t iPinAxisRight1, uint8_t iPinAxisRight2, uint8_t iPinENA, uint8_t iPinENB) : CMotors()
	{
		m_iPinAxisLeft1 = iPinAxisLeft1;
		m_iPinAxisLeft2 = iPinAxisLeft2;
		m_iPinAxisRight1 = iPinAxisRight1;
		m_iPinAxisRight2 = iPinAxisRight2;
		m_iPinENA = iPinENA;
		m_iPinENB = iPinENB;
		m_bIsVirtualMotor = false;

		pinMode(iPinAxisLeft1, OUTPUT);
		pinMode(iPinAxisLeft2, OUTPUT);
		pinMode(iPinAxisRight1, OUTPUT);
		pinMode(iPinAxisRight2, OUTPUT);
		pinMode(iPinENA, OUTPUT);
		pinMode(iPinENB, OUTPUT);
	};

	// Public methods
	String GetCurrMovString()
	{
		switch (m_CurrentMovement)
		{
			case EMovements::Up:
				return "Up";

			case EMovements::LeftUp:
				return "LeftUp";

			case EMovements::LeftDown:
				return "LeftDown";

			case EMovements::Down:
				return "Down";

			case EMovements::RightUp:
				return "RightUp";

			case EMovements::RightDown:
				return "RightDown";

			case EMovements::Stop:
				return "Stop";

			default:
				return "Unknown";
		}
	}

	EMovements GetCurrentMovement()
	{
		return m_CurrentMovement;
	}

	int GetCurrentSpeed()
	{
		return m_iCurrentSpeed;
	}

	ESpeedMode GetSpeedMode()
	{
		return m_CurrentSpeedMode;
	}

	void SetSpeedMode(ESpeedMode speedMode)
	{
		m_CurrentSpeedMode = speedMode;
		m_iMaxSpeed = SPEED_UNIT * int(speedMode);
	}

	/* for testing with mobile device. Sets only direction with pre-defined commands, constant speed not variable */
	void ProcessMotors(String sCommand);
	/* for using with joystick. Calculates direction and speed according to param coordinates (X, Y).
	Maps joysticks within range (0, 255) in both axes -> direction with digital (0, 1) combination of pins
													  -> speed range (0, 255) for PWN pins */
	void ProcessMotors(const byte byteX, const byte byteY);

	private:
		// Fields
		uint8_t m_iPinAxisLeft1, m_iPinAxisLeft2, m_iPinAxisRight1, m_iPinAxisRight2;	//config pins direction
		uint8_t m_iPinENA, m_iPinENB;			//config pins speed
		EMovements m_CurrentMovement;
		ESpeedMode m_CurrentSpeedMode;
		ETurnMode m_CurrentTurnMode;
		int m_iCurrentSpeed;
		int m_iMaxSpeed;
		bool m_bIsVirtualMotor;

		// Private methods
		void SetMovement(EMovements movement);
		void SetSpeed(int iSpeed, EMovements movement);
		void SetSpeed(int iSpeedLeft, int iSpeedRight, EMovements movement);
};
