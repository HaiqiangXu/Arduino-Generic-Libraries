# Generic-Libraries
General purpose libraries for final Arduino projects which can include them easily as needed through the [platformio.ini](http://docs.platformio.org/en/latest/projectconf.html) config file.

## External libraries
These are the external libraries that are included in Generic-Libraries as [submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) which links to the original source repositories, and following these [instructions](https://stackoverflow.com/questions/10856138/make-change-to-a-git-submodule-and-keep-the-changes?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa) to separate Generic-Libraries superproject local changes from the original source repository:
- [FreeRTOS](https://github.com/feilipu/Arduino_FreeRTOS_Library)   -> v11.1.0-2
- [MD_MAX72XX](https://github.com/MajicDesigns/MD_MAX72XX)          -> v3.5.1
- [Queue](https://github.com/SMFSW/Queue)                           -> v2.0
- [SD](https://github.com/arduino-libraries/SD)                     -> v1.2.4
- [LinkedList](https://github.com/ivanseidel/LinkedList.git)        -> v1.3.3
- [LowPower](https://github.com/rocketscream/Low-Power)             -> v1.81
- [TrueRandom](https://github.com/sirleech/TrueRandom)              -> v1.0

*NOTE:* all credits goes to, of course, the respective owners of these repositories.

## Own libraries
| Library | Description | Hardware associated |
| ------- | ----------- | ------------------- |
| Common_Lib | Quick static classes for frequently used functionalities like Sleep() / PowerDown() or ReadKeyboard() for debugging | - |
| Melodies_Lib | Controls active/passive buzzers to reproduce melodies | <img src="https://i.ebayimg.com/images/g/wLwAAOSwnnpdWqD~/s-l300.jpg" width="25%" alt="Buzzer"> |
| Bluetooth_Lib | Controls bluetooth modules HC-05 and HC-06 via SoftwareSerial library | <img src="https://i2.wp.com/www.martyncurrey.com/wp-content/uploads/2015/08/HC-05-FC-114-HC-06-FC-114_1200-584x400.jpg" width="20%" alt="Bluetooth"> |
| Joystick_Lib | Controls analog joysticks with 2 axes and a switch button | <img src="https://images-na.ssl-images-amazon.com/images/I/41CScnrMzFL._SX425_.jpg" width="25%" alt="Joystick"> |
| Motors_Lib | Controls 4 motors splitted into 2 axes through the driver L298N | <img src="https://http2.mlstatic.com/doble-puente-h-driver-l298n-motor-dc-arduino-arm-avr-l298-D_NQ_NP_838479-MLA31448888181_072019-F.jpg" width="25%" alt="Motors"> |
| SDFilesManager_Lib | Controls SD card with FAT16 limitations (8.3 filename format). Path is Unix based ('/' is root and normal slash means folder instead of backslash) | <img src="https://ae01.alicdn.com/kf/HTB1whIjXs_vK1RkSmRyq6xwupXaD/Micro-SD-Storage-Board-TF-Card-Module-Slot-Socket-Memory-Shield-Module-SPI-for-Arduino-Micro.jpg" width="25%" alt="SD Card"> |