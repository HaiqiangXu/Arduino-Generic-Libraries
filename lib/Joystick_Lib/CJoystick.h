#include <Arduino.h>

#define MAX_TIMEOUT 1500

enum class EDirection { None, Left, Right, Up, Down };
enum class EAxis { AxisX, AxisY };

class CJoystick
{
	public:
		// Contructors
		CJoystick(uint8_t iPinAxisX, uint8_t iPinAxisY, uint8_t iPinButton)
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
		bool ReadClick();
		bool ReadDoubleClick();

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
		uint8_t m_iPinAxisX, m_iPinAxisY;
		uint8_t m_iPinButton;
		EDirection m_DirectionX, m_DirectionY;

		// Private methods
		int CalculateValueDirection(EAxis axis);
};
