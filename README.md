# Raspberry-Pi-Digital-Piano

![raspberry-pi-digital-piano](https://cloud.githubusercontent.com/assets/6564365/12217948/9e06edae-b6d5-11e5-9574-69f8da9255a3.jpg)


## Description
This project uses the Raspberry Pi with electronic components on a breadboard to create a digital piano. The software receives input from 15 buttons, allowing for full chromatic scale with additional auxiliary functions such as instrument switching (Piano, Guitar, and Trumpet) and octave switching. A LCD display is also used for presenting to the user the currently selected instrument and octave.

## Required Hardware & Electronics
- Raspberry Pi 2 Model B, Micro SD card, power source & cable, and speakers
- Breadboard(s)
- Buttons - 15x
- Female-male jumper wires
- Male-male jumper wires
- [LCD Display](https://www.adafruit.com/products/1115)

## Hardware & Electronics Building

The schematic below shows one possible wiring configuration for interfacing the Raspberry Pi with the electronic components. The LED’s and Resistors are optional components used for decoration to light up when a button is pressed. The specific GPIO pin mappings can be found in ‘main.h’ and can be changed if needed (e.g. compatibility for Raspberry Pi 1 models).

![project schematic_schem](https://cloud.githubusercontent.com/assets/6564365/12158870/78764c30-b4a3-11e5-8aed-be6b7dfc3e4f.png)

When interfacing the LCD plate with the Raspberry Pi, you cannot use its female header directly on the Pi's GPIO pins. The reason is that only 4 of the 26 pins—5.0V, GND, SDA, and SCL—are required for the LCD plate to operate and the remaining 22 pins, which are needed for the piano note buttons, are unusable. The diagram below shows the specific pins to connect the wires to on the female header (center figure).

![raspberry_pi_pilcdplate](https://cloud.githubusercontent.com/assets/6564365/12158925/e10926d2-b4a3-11e5-8c05-9ae632453d8c.png)

## Building
This software uses [Wiring Pi](http://wiringpi.com/) and [SMFL](http://www.sfml-dev.org/) libraries. Follow the installation instructions for Wiring Pi [here](http://wiringpi.com/download-and-install/) and SMFL [here](http://www.sfml-dev.org/tutorials/2.3/start-linux.php/). After the libraries are installed on the Raspberry Pi, the binary can be built with the `make` command.

## License
Please read the LICENSE file.
