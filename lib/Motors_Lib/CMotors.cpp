#include "CMotors.h"

const int CENTER_Y_MINUS = 127 - 30;
const int CENTER_Y_PLUS  = 127 + 30;
const int SECTION = 70;

#pragma region Public methods

void CMotors::ProcessMotors(String sCommand)
{
	//process command and set movements according to command
	if (sCommand == "u")
	{
		SetMovement(EMovements::Up);
	}
	else if (sCommand == "d")
	{
		SetMovement(EMovements::Down);
	}
	else if (sCommand == "ru")
	{
		SetMovement(EMovements::RightUp);
	}
	else if (sCommand == "rd")
	{
		SetMovement(EMovements::RightDown);
	}
	else if (sCommand == "lu")
	{
		SetMovement(EMovements::LeftUp);
	}
	else if (sCommand == "ld")
	{
		SetMovement(EMovements::LeftDown);
	}
	else if (sCommand == "s")
	{
		SetMovement(EMovements::Stop);
	}
	else
	{
		return;
	}

	SetSpeed(192, m_CurrentMovement);	//constant speed for this kind of processing
	delay(50);		//wait some time in order to give time for motor relays setting the new state
}

void CMotors::ProcessMotors(const byte valueX, const byte valueY)
{
	int iSpeed;
	EMovements movement;

	//process command
	iSpeed = map( abs(valueY - 127) * 2 , 0, 255, SPEED_UNIT, m_iMaxSpeed );	//Speed range: [55, (55, 110, 165, 220)]
	if (valueY > (CENTER_Y_MINUS) && valueY < (CENTER_Y_PLUS))	//Stop -> [Y = 98 to Y = 157]
	{
		movement = EMovements::Stop;
	}
	else
	{
		if (valueY <= CENTER_Y_MINUS)		//from Y = 0 to Y = 97
		{
			if (valueX > (255 - SECTION))	//from X = 185 to X = 255
			{
				movement = EMovements::LeftUp;
			}
			else if (valueX < SECTION)		//from X = 0 to X = 70
			{
				movement = EMovements::RightUp;
			}
			else							//from X = 70 to X = 185
			{
				movement = EMovements::Up;
			}
		}
		else								//from Y = 158 to Y = 255
		{
			if (valueX > (255 - SECTION))	//from X = 185 to X = 255
			{
				movement = EMovements::LeftDown;
			}
			else if (valueX < SECTION)		//from X = 0 to X = 70
			{
				movement = EMovements::RightDown;
			}
			else							//from X = 70 to X = 185
			{
				movement = EMovements::Down;
			}
		}
	}

	//set speed accordingly to command
	SetSpeed(iSpeed, movement);

	//set movements according to command
	if (m_CurrentMovement != movement)
	{
		SetMovement(movement);
		delay(30);     //wait some time in order to give time for motor relays setting the new state
	}
}

#pragma endregion

#pragma region Private methods

void CMotors::SetMovement(EMovements movement)
{
	int iLeftValue1, iLeftValue2;
	int iRightValue1, iRightValue2;

	m_CurrentMovement = movement;
	if (m_CurrentTurnMode == ETurnMode::One)
	{
		switch (m_CurrentMovement)
		{
			case EMovements::LeftUp:
				iLeftValue1 = 0;  iLeftValue2 = 0;
				iRightValue1 = 0; iRightValue2 = 1;
				break;

			case EMovements::RightUp:
				iLeftValue1 = 0;  iLeftValue2 = 1;
				iRightValue1 = 0; iRightValue2 = 0;
				break;

			case EMovements::Up:
				iLeftValue1 = 0;  iLeftValue2 = 1;
				iRightValue1 = 0; iRightValue2 = 1;
				break;

			case EMovements::LeftDown:
				iLeftValue1 = 0;  iLeftValue2 = 0;
				iRightValue1 = 1; iRightValue2 = 0;
				break;

			case EMovements::RightDown:
				iLeftValue1 = 1;  iLeftValue2 = 0;
				iRightValue1 = 0; iRightValue2 = 0;
				break;

			case EMovements::Down:
				iLeftValue1 = 1;  iLeftValue2 = 0;
				iRightValue1 = 1; iRightValue2 = 0;
				break;

			case EMovements::Stop:
			default:
				iLeftValue1 = 0;  iLeftValue2 = 0;
				iRightValue1 = 0; iRightValue2 = 0;
				break;
		}
	}
	else if (m_CurrentTurnMode == ETurnMode::Both)
	{
		switch (m_CurrentMovement)
		{
			case EMovements::LeftUp:
			case EMovements::RightUp:
			case EMovements::Up:
				iLeftValue1 = 0;  iLeftValue2 = 1;
				iRightValue1 = 0; iRightValue2 = 1;
				break;

			case EMovements::LeftDown:
			case EMovements::RightDown:
			case EMovements::Down:
				iLeftValue1 = 1;  iLeftValue2 = 0;
				iRightValue1 = 1; iRightValue2 = 0;
				break;

			case EMovements::Stop:
			default:
				iLeftValue1 = 0;  iLeftValue2 = 0;
				iRightValue1 = 0; iRightValue2 = 0;
				break;
		}
	}

	if (!m_bIsVirtualMotor)
	{
		digitalWrite(m_iPinAxisLeft1, iLeftValue1);
		digitalWrite(m_iPinAxisLeft2, iLeftValue2);
		digitalWrite(m_iPinAxisRight1, iRightValue1);
		digitalWrite(m_iPinAxisRight2, iRightValue2);
	}
}

void CMotors::SetSpeed(int iSpeed, EMovements movement)
{
	SetSpeed(iSpeed, iSpeed - 3, movement);			//there is a hardware offset in ENB, so we compesate it by software
}

void CMotors::SetSpeed(int iSpeedLeft, int iSpeedRight, EMovements movement)
{
	m_iCurrentSpeed = max(iSpeedLeft, iSpeedRight);
	if (m_bIsVirtualMotor)
		return;
	
	//slow down speed to avoid sudden stop.
	if (movement == EMovements::Stop)
	{
		analogWrite(m_iPinENA, SPEED_UNIT / 3);	//ENA needs more time to stop so set smaller speed value
		analogWrite(m_iPinENB, SPEED_UNIT / 2);
		delay(30);
	}

	//after slow down, set final speed
	switch (movement)
	{
		case EMovements::LeftUp:
		case EMovements::LeftDown:
			if (m_CurrentTurnMode == ETurnMode::Both)
				iSpeedRight = iSpeedLeft / 3;
			break;

		case EMovements::RightUp:
		case EMovements::RightDown:
			if (m_CurrentTurnMode == ETurnMode::Both)
				iSpeedLeft = iSpeedRight / 3;
			break;

		case EMovements::Up:
		case EMovements::Down:
			break;

		case EMovements::Stop:
		default:
			iSpeedLeft  = 0;
			iSpeedRight = 0;
			break;
	}
	analogWrite(m_iPinENA, iSpeedLeft);
	analogWrite(m_iPinENB, iSpeedRight);
}

#pragma endregion