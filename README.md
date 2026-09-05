# Arduino Number System Emulator

A hardware converter built on Arduino that translates manual binary inputs into decimal, hexadecimal, and octal outputs on a seven-segment display in real time.

## Features

* Real-time conversion across decimal, hexadecimal, and octal bases
* Direct visual feedback for each bit using individual indicator LEDs
* Software-based switch debouncing for stable inputs
* Custom decoding logic to drive single-digit seven-segment displays

## Components

* Arduino Uno or Nano
* Seven-segment display
* 4x Push buttons or DIP switch (4-bit binary input)
* 4x LEDs (bit indicators)
* 220Ω and 10kΩ resistors
* Breadboard and jumper wires

## Pin Connections

| Function | Arduino Pins |
| :--- | :--- |
| Binary Inputs (Bit 0 to Bit 3) | Pins 2, 3, 4, 5 |
| Mode Selector Switch | Pin 6 |
| 7-Segment Display (Segments a to g) | Pins 7 to 13 |

## Setup

1. Wire the hardware according to the pin connection table.
2. Open the project sketch in the Arduino IDE.
3. Select your board model and port under Tools.
4. Click Upload.

## Video Documentation

* [Project Demonstration and Testing Videos](https://drive.google.com/drive/folders/1rS56CuNCL6RDnIjXLNyAOGdweFR4JFa0?usp=sharing)
