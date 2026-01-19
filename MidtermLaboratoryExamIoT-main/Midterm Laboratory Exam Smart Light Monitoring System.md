# Project Overview: The "Smart" Light Monitor
Think of this project as your "Midterm Exam" application that combines everything you've learned so far into one smart device. It is a Dual-Mode Light Monitor that acts like a traffic light for brightness: it reads how bright a room is and turns on a Green, Yellow, or Red LED to match the intensity.

The coolest feature? It has a "brain" with two modes: Automatic (it decides for itself) and Manual (you tell it what to do using text commands).

### What This Project Does
This system is an environmental monitor with two distinct personalities:

Automatic Mode (Default): The system runs on "factory settings." It automatically decides if it’s cloudy or clear based on fixed rules.

Green: Low Light

Yellow: Medium Light

Red: High Light

Manual Mode: You take control! You can type commands into the Serial Monitor to change the definition of "Low" and "High" light on the fly. This lets you adapt the system to a dark bedroom or a bright classroom without rewriting the code.

Real-Time Dashboard: The system constantly texts your computer, updating you every second with the current light percentage, which LED is on, and which mode is running.

### How the System Works
The project mixes hardware sensors with smart coding logic.

The "Eye" (Inputs): A Photoresistor (light sensor) connected to pin A0 measures how much light is in the room.

The "Brain" (Processing):

It takes the raw sensor data (0–1023) and converts it into a readable percentage (0–100%).

It checks a simple switch in the code (automaticMode) to decide whether to follow its own rules or listen to yours.

The "Signal" (Outputs): Three LEDs (Green, Yellow, Red) light up to show the light level visually.

The Interface: A command line (like a chat box) lets you type things like SET LOW 30 to instantly change the device's behavior.

Code Explanation: Under the Hood
The code is built like a State Machine, meaning its behavior changes completely depending on which "State" (Auto or Manual) it is in.

Flexible Thresholds: Unlike previous activities where numbers were set in stone, this project uses variables. In Manual mode, you can overwrite these variables just by typing.

### The Logic Loop:

Automatic Logic: Uses fixed if/else rules. (e.g., "If light is less than 40%, turn Green").

Manual Logic: Uses your custom settings to decide which LED to turn on. This allows you to expand or shrink the "Green Zone" dynamically.

Texting the Device (Command Parsing): This part of the code acts as a translator. It reads the text you type:

MODE AUTO / MODE MANUAL: Switches the system's personality.

SET LOW <number>: Picks out the number you typed and updates the settings—but only if you are in Manual mode.

Safety Checks: The code is smart enough to stop you from making logic errors (like setting the "Low" limit higher than the "High" limit).

### Why This Matters (IoT Concepts)
This project demonstrates how real-world smart devices work:

Dynamic Configuration: Just like you can change your phone's brightness settings without buying a new phone, this code lets you change the device settings without re-uploading the sketch.

Command Parsing: It teaches the device how to understand complex instructions (text + numbers) from a human.

Mode Switching: It shows how one device can have multiple behaviors that toggle back and forth.

Data Normalization: It translates confusing machine numbers (0-1023) into human-friendly percentages (0-100%).
