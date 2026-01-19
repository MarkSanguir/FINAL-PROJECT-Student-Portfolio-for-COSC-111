# Laboratory Activity #7: Web-Controlled IoT System with FastAPI

### Project Summary: Web-Controlled LED System
This project builds a working prototype of a "Smart Home" device. Instead of typing code commands into a console to turn on a light, this system lets you control physical hardware (LED lights) using a modern, clickable website.

It connects a standard web browser to an Arduino board using Python as a bridge.

### What It Does
Think of this system as a remote control that lives in your web browser.

The Remote (Interface): A styled web page with buttons for Red, Green, and Blue LEDs, plus "All On" and "All Off" switches.

The Translator (Bridge): A Python program running on your computer that listens for button clicks and converts them into simple signals.

The Action (Hardware): The Arduino receives those signals instantly and physically turns the LED lights on or off.

### How It Works (The Chain of Command)
The system works in three simple steps, similar to how commercial smart devices work:

The User Clicks: You press a button (like "Red LED") on the webpage. The website sends a message to the computer saying, "The user wants red."

The Computer Translates: The Python program catches that message. It translates the request into a specific number (e.g., sending the number 1 for red) and sends it down the USB cable to the Arduino.

The Hardware Reacts: The Arduino is constantly listening to the USB cable. When it hears the number 1, it knows that means "Turn on the Red Light" and does so immediately.

### The Code Breakdown
The code is split into three distinct parts to keep things organized:

The Look (web.html): This handles the visuals. It creates the "Dark Mode" dashboard and uses background scripts to send messages to the computer without needing to refresh the page every time you click.

The Brains (main.py): This is the "middleman." It uses a tool called FastAPI to create a connection point for the website. It also manages the USB connection to the Arduino so the browser doesn't have to.

The Instructions (LabAct7.ino): This is the code living on the Arduino board. It is very simple: it listens for single characters (like 1, 2, or 9) and flips the electrical switches for the correct pins (Red, Green, or Blue) based on what it hears.

### Key Concepts Learned
Web Control: Using a website URL to trigger physical actions in the real world.

Translation (Middleware): Using a script to help two things talk that usually can't (a web browser and a circuit board).

Smooth Experience: Writing code that lets the user click buttons rapidly without the page freezing or reloading.
