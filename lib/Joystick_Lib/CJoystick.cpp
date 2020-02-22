#include "CJoystick.h"

// Public methods
int CJoystick::ReadAxisX()
{
	return CalculateValueDirection(EAxis::AxisX);
}

int CJoystick::ReadAxisY()
{
	return CalculateValueDirection(EAxis::AxisY);
}

int CJoystick::ReadButton()
{
	return digitalRead(m_iPinButton);
}

bool CJoystick::ReadClick()
{
	long timeout = 0;
	while (timeout < MAX_TIMEOUT &&
		   ReadButton() == LOW)			//read button pressed
	{
		delay(50);
		timeout += 50;
	}
	if (timeout > MAX_TIMEOUT)
		return false;

	while (timeout < MAX_TIMEOUT &&
		   ReadButton() == HIGH)		//read button released
	{
		delay(50);
		timeout += 50;
	}
	return (timeout < MAX_TIMEOUT);
}

bool CJoystick::ReadDoubleClick()
{
	if (!ReadClick())
		return false;
	if (!ReadClick())
		return false;
	else
		return true;
}

// Private methods
int CJoystick::CalculateValueDirection(EAxis axis)
{
	int iPinNumber, iValue;

	// Analog inputs	   range: 0 - 1023 (0V - 5V)
	// Analog outpus (PWM) range: 0 - 255  (0V - 5V)
	// calculate axis value
	iPinNumber = (axis == EAxis::AxisX) ? m_iPinAxisX : m_iPinAxisY;
	iValue = map(analogRead(iPinNumber), 0, 1023, 0, 255);

	// calculate Direction
	if (iValue >= 0 && iValue < 30)
	{
		if (axis == EAxis::AxisX)
			m_DirectionX = EDirection::Left;
		else
			m_DirectionY = EDirection::Up;
	}
	else if (iValue > 225 && iValue <= 255)
	{
		if (axis == EAxis::AxisX)
			m_DirectionX = EDirection::Right;
		else
			m_DirectionY = EDirection::Down;
	}
	else
	{
		if (axis == EAxis::AxisX)
			m_DirectionX = EDirection::None;
		else
			m_DirectionY = EDirection::None;
	}

	return iValue;
}
