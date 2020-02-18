# Generic-Libraries
General purpose libraries for final Arduino projects which can include them easily as needed through the [platformio.ini](http://docs.platformio.org/en/latest/projectconf.html) config file.

## External libraries
These are the external libraries that are included in Generic-Libraries as [submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) which links to the original source repositories, and following these [instructions](https://stackoverflow.com/questions/10856138/make-change-to-a-git-submodule-and-keep-the-changes?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa) to separate Generic-Libraries superproject local changes from the original source repository:
- [LowPower](https://github.com/rocketscream/Low-Power)
- [TrueRandom](https://github.com/sirleech/TrueRandom)
- [MD_MAX72XX](https://github.com/MajicDesigns/MD_MAX72XX) v2.11.0. **NOT** in submodule. 

## Own libraries
- Bluetooth_Lib: controls bluetooth modules HC-05 and HC-06 via SoftwareSerial library.
- Common_Lib: quick static classes for frequently used functionalities like Sleep() / PowerDown() or ReadKeyboard() for debugging.
- Joystick_Lib: controls analog joysticks with 2 axes and a switch button.
- Melodies_Lib: controls active/passive buzzers to reproduce melodies.
- Motors_Lib: controls 4 motors splitted into 2 axes through the driver L298N.
