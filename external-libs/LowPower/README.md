Sources version 1.60 comes from [LowPower](https://github.com/rocketscream/Low-Power) and all credits goes for them.

### Comparison power save modes:

| MODE  | WDT   | ADC   | BOD   | T2    | T1    | T0    | SPI   | USART0| TWI   | CURRENT
| ---   | ---   | ---   | ---   | ---   | ---   | ---   | ---   | ---   | ---   | ---
|Idle   | On    | On    | On    | On    | On    | On    | On    | On    | On    | 3648.0 µA
|Idle   | Off   | On    | On    | On    | On    | On    | On    | On    | On    | 3643.0 µA
|Idle   | Off   | Off   | On    | On    | On    | On    | On    | On    | On    | *
|Idle   | Off   | Off   | On    | Off   | On    | On    | On    | On    | On    | *
|Idle   | Off   | Off   | On    | Off   | Off   | On    | On    | On    | On    | 3618.0 µA
|Idle   | Off   | Off   | On    | Off   | Off   | Off   | On    | On    | On    | 927.0 µA
|Idle   | Off   | Off   | On    | Off   | Off   | Off   | Off   | On    | On    | 832.0 µA
|Idle   | Off   | Off   | On    | Off   | Off   | Off   | Off   | Off   | On    | 789.0 µA
|Idle   | Off   | Off   | On    | Off   | Off   | Off   | Off   | Off   | Off   | 687.0 µA
|ADC Noise Reduction    | On    | On    | On    | On    | –    | –    | –    | –    | –    | 651.0 µA
|ADC Noise Reduction    | Off    | On    | On    | On    | –    | –    | –    | –    | –    | 646.0 µA
|ADC Noise Reduction    | Off    | Off    | On    | On    | –    | –    | –    | –    | –    | *
|ADC Noise Reduction    | Off    | Off    | On    | Off    | –    | –    | –    | –    | –    | 584.0 µA
|Power Save    | Off    | Off    | Off    | Off    | –    | –    | –    | –    | –    | 1.7 µA
|Power Save    | Off    | Off    | Off    | On    | –    | –    | –    | –    | –    | 416.0 µA
|Power Save    | Off    | Off    | On    | On    | –    | –    | –    | –    | –    | 435.0 µA
|Power Save    | Off    | On    | On    | On    | –    | –    | –    | –    | –    | 527.0 µA
|Power Save    | On    | On    | On    | On    | –    | –    | –    | –    | –    | 531.0 µA
|Extended Standby   | Off    | Off    | Off    | Off    | –    | –    | –    | –    | –    | 202.2 µA
|Extended Standby   | Off    | Off    | Off    | On    | –    | –    | –    | –    | –    | 416.0 µA
|Extended Standby   | Off    | Off    | On    | On    | –    | –    | –    | –    | –    | 436.0 µA
|Extended Standby   | Off    | On    | On    | On    | –    | –    | –    | –    | –    | 527.0 µA
|Extended Standby   | On    | On    | On    | On    | –    | –    | –    | –    | –    | 531.0 µA
|Standby    | Off   | Off    | Off    | –    | –    | –    | –    | –    | –    | 201.7 µA
|Standby    | Off   | Off    | On    | –    | –    | –    | –    | –    | –    | 218.5 µA
|Standby    | Off   | On    | On    | –    | –    | –    | –    | –    | –    | 309.9 µA
|Standby    | On    | On    | On    | –    | –    | –    | –    | –    | –    | 313.9 µA
|Power Down    | Off    | Off    | Off    | –    | –    | –    | –    | –    | –    | 1.7 µA
|Power Down    | Off    | Off    | On    | –    | –    | –    | –    | –    | –    | 18.6 µA
|Power Down    | Off    | On    | On    | –    | –    | –    | –    | –    | –    | 110.0 µA
|Power Down    | On    | On    | On    | –    | –    | –    | –    | –    | –    | 113.9 µA

Legend:
- WDT: Watch Dog Timer
- ADC: Analog-to-Digital converter module
- BOD: Brownout Detector
- T0, T1, T2: Timers 0, 1 and 2
- SPI: Serial Peripheral Interface module
- USART0: Serial port module
- TWI: Two-wire interface (I2C)

### Comparison sleep modes power consumption set on setup() with nothing in loop() and with the bare-bone ATMega328 chip + Voltage regulators (for +5V and +3.3V) + USB interface chip (for the USB port) + "power" LED instead of a full equipped Arduino Uno:
- SLEEP_MODE_IDLE:          15 mA
- SLEEP_MODE_ADC:           6.5 mA
- SLEEP_MODE_PWR_SAVE:      1.62 mA
- SLEEP_MODE_EXT_STANDBY:   1.62 mA
- SLEEP_MODE_STANDBY:       0.84 mA
- SLEEP_MODE_PWR_DOWN:      0.36 mA

### Time to wake-up if components are disabled:
- BOD: 60 µs

### Wake-up Sources:
- INT and PCINT: all power save modes
- TWI address match: all power save modes
- Timer2: IDLE, ADC, PWR_SAVE, EXT_STANDBY
- WDT: all power save modes
- ADC: IDLE, ADC

[Source 1](http://www.rocketscream.com/blog/2011/07/04/lightweight-low-power-arduino-library/)

[Source 2](http://www.gammon.com.au/power)