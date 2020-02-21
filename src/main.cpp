#include <MD_MAX72XX.h>
#include <TrueRandom.h>

#include <CCommon.h>
#include <CBluetooth.h>
#include <CJoystick.h>
#include <CMelodies.h>
#include <CMotors.h>
#include <CSDFilesManager.h>

// Test project just to test if libraries in this project compiles. Expendable class
void setup()
{
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
    MD_MAX72XX max7219 = MD_MAX72XX(10);

    Common.ReadKeyboard();
    Common.Sleep(500);
    Common.PowerDownInt0();

    int i = TrueRandom.random(1, 13);
    CBluetooth bluetooth = CBluetooth(i, 3, EBluetoothAdapter::HC_05);
    CJoystick joystick = CJoystick(i, 3, 5);
    CMelodies melodies = CMelodies(i);
    CMotors motors = CMotors();
    CSDFilesManager files = CSDFilesManager(4);
}

void loop()
{

}