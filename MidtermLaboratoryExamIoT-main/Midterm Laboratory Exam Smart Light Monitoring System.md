# Project Overview
This project is a "Smart Light Monitor" that acts as a midterm exam, bringing together everything learned so far. It measures room brightness and shows the level using a traffic-light system (Green, Yellow, Red). Its main feature is the ability to switch between two modes: an Automatic mode that follows fixed rules, and a Manual mode that lets you adjust the settings yourself using text commands.

### What It Does
The system works in two distinct ways:

Automatic Mode (Default): The system runs on autopilot. It uses factory settings to decide if it is dark or bright and turns on the corresponding LED (Green for low light, Yellow for medium, Red for high).

Manual Mode: You are in control. You can type commands to change the specific light levels that trigger the LEDs. This allows you to adapt the device to different rooms without needing to rewrite the code.

Live Dashboard: The system constantly sends updates to your computer screen, showing the current light percentage, which LED is on, and which mode is active.

### How It Works
The system combines a light sensor with a feature that understands text commands.

Input: A light sensor (photoresistor) detects how bright the room is.

Processing: It converts the sensor's raw data into a simple 0-100% score that is easy to read. It then checks which mode is active to decide how to react.

Output: Three LEDs (Green, Yellow, Red) light up to visually show the light intensity.

Control: You can type simple text commands (like SET LOW 30) to change the settings instantly.

### Code Explanation
The programming is built around the concept of "Modes"—the device behaves completely differently depending on which mode you choose.

Flexible Settings: Unlike previous activities where the numbers were permanent, this project uses changeable settings. In Manual mode, you can overwrite the defaults with your own numbers.

### The Logic:

Automatic Logic: Follows strict, unchangeable rules (e.g., if light is under 40%, turn Green).

Manual Logic: Uses your custom numbers to decide when to switch lights.

Understanding Commands: The code has a "brain" that reads what you type.

It looks for keywords like MODE AUTO or MODE MANUAL to switch behaviors.

It reads commands like SET LOW followed by a number to update the settings.

Safety Checks: It includes safeguards to prevent errors, such as stopping you from setting the "Low" limit higher than the "High" limit.

### Key Concepts Applied
Real-Time Adjustments: The ability to change how the device works while it is running, without needing to restart or reprogram it.

Reading Text: Teaching the device to understand complex instructions (text combined with numbers).

Mode Switching: Creating a single device that can toggle between two completely different behaviors.

Data Translation: Converting confusing raw sensor numbers into a friendly percentage format.
