# Generic-Libraries
General purpose libraries for final Arduino projects which can include them easily as needed through the [platformio.ini](http://docs.platformio.org/en/latest/projectconf.html) config file.

## External libraries
These are the external libraries that are included in Generic-Libraries as [submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) which links to the original source repositories, and following these [instructions](https://stackoverflow.com/questions/10856138/make-change-to-a-git-submodule-and-keep-the-changes?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa) to separate Generic-Libraries superproject local changes from the original source repository:
- [LowPower](https://github.com/rocketscream/Low-Power)
- [TrueRandom](https://github.com/sirleech/TrueRandom)
- [MD_MAX72XX](https://github.com/MajicDesigns/MD_MAX72XX)

## Own libraries
- Bluetooth_Lib: controls bluetooth modules HC-05 and HC-06 via SoftwareSerial class.
- Common_Lib: Quick static classes for frequently used functionalities like Sleep() or PowerDown().
- Joystick_Lib: controls analog joysticks with 2 axes and a switch button.
- Melodies_Lib: controls active/passive buzzers to reproduce melodies.
- Motors_Lib: controls 4 motors splitted into 2 axes through the driver L298N.

## Libraries functionalities -> TODO: move to Wiki section
### Bluetooth library
Communicates with the bluetooth (BT) module [HC-05 or HC-06] via [SoftwareSerial](https://www.arduino.cc/en/Reference/SoftwareSerial). List of functions:
- Begin(long lBauds): starts the communication with the BT module
- SendATCommandHC05(EATCommand command, String sValue): sends AT commands to the HC-05 module. Set KEY pin to HIGH or press the physical button in the module to enter AT mode. Use together with HardwareSerial to debug the responses sent by the module.
- SendATCommandHC06(EATCommand command, String sValue): sends AT commands to the HC-06 module. Use together with HardwareSerial to debug the responses sent by the module.
- DirectReceive(): Reads from BT module without any processing.
- Receive(): Reads from BT module when message starts INI_STR_CMD or INI_BYT_CMD character and reads until it founds the END_CMD
- Send(String sMessage): Sends to the BT module without processing, onlyt adding LF or CR + LF when needed.
- SendCommand(String sMessage): Sends to the BT module with INI_STR_CMD at the start and END_CMD at the end of the message.
- SendCommand(byte byteX, byte byteY): Sends to the BT module with INI_BYT_CMD at the start and END_CMD at the end of the message.
- CommandType(String sCommand): distinguishes if the received message is with INI_STR_CMD or with INI_BYT_CMD.
- ProcessArrayBytesCommand(String sCommand): Converts the message with INI_BYT_CMD into array of bytes.
- ProcessStringCommand(String sCommand): Converts the message with INI_STR_CMD into a String.

### Joystick library
Reads the axis values from the Joystick. List of functions:
- ReadAxisX(): returns X coordinate of the joystick
- ReadAxisY(): returns Y coordinate of the joystick
- ReadButton(): returns button value of the joystick. LOW if pressed and HIGH otherwise.

### Melodies library
Reproduces melodies into the attached active/passive buzzer. List of functions:
- 

### Motors library
Controls up to 4 motors splitted into 2 axes through the driver L298N. List of functions:
- 