#include <arduino.h>

enum class EDirection { None, Left, Right, Up, Down };
enum class EAxis { AxisX, AxisY };

class CJoystick
{
	public:
		// Contructors
		CJoystick(int iPinAxisX, int iPinAxisY, int iPinButton)
		{
			m_iPinAxisX = iPinAxisX;
			m_iPinAxisY = iPinAxisY;
			m_iPinButton = iPinButton;

			pinMode(iPinButton, INPUT_PULLUP);
		};

		// Public methods
		int ReadAxisX();
		int ReadAxisY();
		int ReadButton();

		// Data accessors
		EDirection GetDirectionX()
		{
			return m_DirectionX;
		};

		EDirection GetDirectionY()
		{
			return m_DirectionY;
		};
	private:
		// Fields
		int m_iPinAxisX, m_iPinAxisY;
		int m_iPinButton;
		EDirection m_DirectionX, m_DirectionY;

		// Private methods
		int CalculateValueDirection(EAxis axis);
};
