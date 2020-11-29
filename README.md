
# CO2 sensor integration

## Quick overview
Using S8 Senseair CO2 sensor and ESP32 development board

## prerequisites

1. You will need to have [node](https://nodejs.org) installed.
2. The esp-idf must be set up. you can follow the instructions in my course (free of charge) on the [Setting up Your Environment](https://www.learnesp32.com/2_introduction) module or follow the [official documentation](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/#step-1-set-up-the-toolchain)
3. this template is for [vscode](https://code.visualstudio.com/download) which will need to be installed
4. In VSCODE add the [c++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

5. ensure tour ESP32 is plugged in and that a COM PORT is established (You may need a driver for your ESP32 dev board)

## flashing the esp32

1. in vs code, open a new terminal by pressing ctrl + \` (or pressing F1 and typing `open new terminal`)
2. type the following command

```bash
idf.py -p [your com port] flash monitor
```
