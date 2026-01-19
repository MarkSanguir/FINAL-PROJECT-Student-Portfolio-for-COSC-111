# Laboratory Activity #6: Bi-Directional Serial Communication

### Overview: Two-Way Communication
This project marks a major upgrade in how we build systems. In previous activities, communication was a one-way street (either the computer ordered the Arduino around, or the Arduino just sent data to the screen).

This project creates a Two-Way Conversation. The Arduino and the Python program constantly talk to each other, listening and responding simultaneously, creating a complete feedback loop.

### What This Project Does
The system creates a "Round Trip" for data, moving from the physical world to the digital world and back again.

The Trigger: You press a physical button on your circuit board.

The Uplink: The Arduino feels the press and tells the computer, "Button 1 was pressed."

The Brain (Python): The computer hears this, processes it, and decides what to do (e.g., "Okay, that means toggle the Red Light").

The Downlink: The computer sends a command back to the Arduino.

The Action: The Arduino receives the command and actually turns on the light.

Note: Even though the button and the light are right next to each other on the board, the signal travels all the way to the computer and back to make the change happen.

### How It Works
The work is split between the hardware and the software:

Hardware Setup: You have three buttons (Inputs) and three LEDs (Outputs) connected to the Arduino.

The Flow:

Press Button 1 → Arduino sends letter 'R' to PC.

PC sees 'R' → Sends number '1' back to Arduino.

Arduino sees '1' → Turns on Red LED.

### Code Explanation
The code is organized into three specific roles:

The Automated Brain (Python): Unlike the last project where you typed commands, this script runs automatically. It sits in a loop, waiting for the Arduino to speak. If it hears "Button Pressed," it instantly replies with the correct command. It acts like an automated server.

The Multi-Tasker (Arduino): The Arduino has to do two things at once:

The Listener: It waits for orders from the computer to turn lights on/off.

The Reporter: It watches the buttons. It uses a smart logic trick (Edge Detection) to ensure it only sends one message when you click a button, rather than spamming messages while you hold it down.

The Settings File (Header .h): This file handles the wiring setup. It uses a feature called "Input Pull-Up," which turns on internal resistors inside the Arduino chip. This simplifies your circuit because you don't need to add messy extra resistors on your breadboard.

### Key Concepts Learned
Bi-Directional Talk: The ability for devices to send and receive messages at the same time.

Click Precision (Edge Detection): Writing code that reacts to the moment a change happens (the click), rather than the state of the button (being held down).

Speed (Latency): Observing how fast the signal can travel to the computer and back (it happens in milliseconds).

Simpler Wiring: Using the chip's internal features to reduce the number of physical components needed on the board.
