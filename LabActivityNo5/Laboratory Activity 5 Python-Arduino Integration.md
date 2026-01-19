# Laboratory Activity #5: Python-Arduino Integration

### Overview: Computer-Controlled Lights
This project takes a step up from basic Arduino coding. Instead of using the standard Arduino tools to control the board, we build a custom "remote control" program using the Python programming language. This mimics how professional software communicates with hardware in the real world.

### What This Project Does
The system turns your computer keyboard into a switch for your circuit.

The Interface: A Python program runs on your computer screen, showing a simple text menu (e.g., "Press [R] for Red LED").

The Hardware: An Arduino board with Red, Green, and Blue LEDs connected to it.

The Action: When you type a letter (like 'R') on your computer, the Red LED on your desk immediately turns on or off. It also handles commands for "All On," "All Off," and a mixed-color "Violet" mode.

### How It Works
The system works like a conversation between your computer and the Arduino.

You Speak (Python): You type a command into the Python program. The program cleans up your text and converts it into a digital package ready for travel.

The Message Travels: The Python program sends this package down the USB cable connecting your computer to the Arduino.

The Arduino Listens: The Arduino is constantly waiting for messages. When the package arrives, it opens it and reads the letter inside.

The Action: If the letter is 'r', the Arduino flips the electrical switch for the Red light. If it's 'g', it does the same for Green.

### Code Explanation
To keep things organized, the code is split into logical parts using a method called Modular Programming.

The Computer Script (Python):

The Loop: It runs in a continuous circle, always ready for your next command, until you tell it to quit.

The Translator: Since the USB cable transmits raw data, not words, this script converts your typed letters into the correct format before sending them.

### The Hardware Code (Arduino):

The "Cheat Sheet" (Header File): Instead of cluttering the main code, we put the settings here. It remembers which pins connect to which colors and tracks the "State"—meaning it remembers if a light is currently ON or OFF so it knows what to do next.

The Traffic Cop (Main Sketch): This part handles the decision-making. It looks at the letter it received and routes it to the correct action using a sorting method (Switch-Case), ensuring it ignores any gibberish inputs.

### Key Concepts Learned
Language Bridge: Making two different programming languages (Python on a PC and C++ on a microchip) talk to each other.

Memory (State Management): The code is smart enough to remember the current status of the lights (e.g., "Red is currently ON"), allowing you to toggle them with a single button.

Clean Organization: Splitting code into different files so it is easier to read and fix.

Text Interface: Controlling a machine using simple text commands rather than a graphical mouse-click interface.
    
- **Command Line Interface (CLI):** Building a text-based user interface (UI) to interact with hardware.
