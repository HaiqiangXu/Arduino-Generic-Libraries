#include <MD_MAX72xx.h>
#include <cppQueue.h>
#include <LinkedList.h>

#include <CCommon.h>
#include <CJoystick.h>
#include <CMelodies.h>
#include <CMotors.h>

// Test project just to test if libraries in this project compiles. Expendable class
void setup()
{
    Common.ReadKeyboard();
    MD_MAX72XX max7219 = MD_MAX72XX(MD_MAX72XX::FC16_HW, 11, 13, 10, 2);

    cppQueue q = cppQueue(sizeof(int), 10, FIFO);
    LinkedList<int> lnk = LinkedList<int>();

    CJoystick joystick = CJoystick(LED_BUILTIN, 3, 5);
    CMelodies melodies = CMelodies(1);
    CMotors motors = CMotors();
}

void loop()
{

}