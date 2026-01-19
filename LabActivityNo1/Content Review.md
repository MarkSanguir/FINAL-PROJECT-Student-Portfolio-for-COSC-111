
# Laboratory Activity #1: Working with Digital Signals - Running Light Circuit

### Overview

This project is an introductory exploration into the Internet of Things (IoT) using an Arduino microcontroller. The primary goal is to understand how to implement digital signals within a circuit. By constructing a "running light" circuit, this activity demonstrates fundamental control over hardware outputs using software logic.
### What This Project Does

The system creates a sequential lighting pattern using five Light Emitting Diodes (LEDs). Instead of flashing all lights simultaneously, the program creates a specific animation sequence:

1. **Sequential Activation:** The LEDs turn on one by one, starting from the LED connected to pin 12 down to pin 8.
2. **Sequential Deactivation:** Once all LEDs are lit, they turn off one by one in the same order
3. **Timing:** There is a 1-second delay between each state change, creating a deliberate, visible "running" effect.
### How the System Works

The project utilizes a standard IoT prototyping setup involving an Arduino Uno, a breadboard, LEDs, and resistors.

- **Hardware Setup:** Five LEDs are connected to digital pins 12, 11, 10, 9, and 8 on the Arduino board. Each LED is wired in series with a resistor to limit current and prevent burnout, as shown in the breadboard diagram.
- **Signal Processing:** The Arduino executes a compiled C++ sketch (`.ino` file). It sends 5V (HIGH) or 0V (LOW) signals to specific pins based on the program's loop structure.
- **Output:** The physical LEDs respond to these digital voltage changes by illuminating or turning off.
### Code Explanation

The software logic is efficient, utilizing arrays and loops rather than repetitive code blocks.
- **Pin Configuration (Arrays):** Instead of managing five separate variables, the code uses an integer array `int ledPins[]={12,11,10,9,8}`. This allows the program to iterate through the pins programmatically, making the code cleaner and easier to scale if more LEDs were added.
- **System Initialization (`setup`):** The `setup()` function runs once when the device starts. It uses a `for` loop to step through the array and configure every pin (12 through 8) as an `OUTPUT` device.
- **The Main Logic (`loop`):** The `loop()` function runs continuously and consists of two main parts:
    1. **The "On" Cycle:** A loop iterates through the array, setting each pin to `HIGH` (on) with a `delay(1000)` (1 second) pause after each activation.   
    2. **The "Off" Cycle:** Immediately following the first loop, a second loop sets each pin to `LOW` (off), maintaining the same 1-second delay.
### IoT Concepts Applied

- **Digital I/O Control:** Practical application of `digitalWrite()` to switch voltage states.
- **Automation:** Using software loops (`for` loops) to automate repetitive hardware tasks.
- **Timing Control:** Understanding the `delay()` function to manage the pacing of real-world physical outputs.
- **Array Implementation:** Using data structures to manage hardware pins efficiently.