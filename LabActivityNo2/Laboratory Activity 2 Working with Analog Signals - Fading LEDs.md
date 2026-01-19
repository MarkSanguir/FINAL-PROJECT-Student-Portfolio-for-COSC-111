# Laboratory Activity #2: Working with Analog Signals - Fading LEDs

### Overview: Beyond Simple Switches
This project takes a step up from just turning lights "On" and "Off." While digital computers usually only think in black and white (0 or 1), this project teaches the Arduino to work in "Grayscale." It demonstrates how to control the brightness of an LED, allowing for smooth dimming and fading effects.

### What This Project Does
The system creates a smooth "breathing" or fading animation across five LEDs.

The Fade In: The LEDs turn on one by one in a line. Instead of snapping on instantly, each light gently fades up from darkness to full brightness.

The Fade Out: Once they are all on, they turn off one by one, slowly fading back down to zero.

The Result: A fluid, wave-like animation that looks much more professional than a blinking light.

### How It Works: The "PWM" Trick
The hardware setup is the same as the previous running light project, but the software uses a clever trick called PWM (Pulse Width Modulation).

The Illusion: The Arduino cannot actually output "half voltage." It can only do 0V (Off) or 5V (On). To create 50% brightness, it flicks the light switch on and off so incredibly fast that your eyes can't see the flickering. They just see a dimmer light.

The Control: We use a command called analogWrite(). We give it a number between 0 (Always Off) and 255 (Always On). A number like 127 tells the Arduino to keep the switch "On" half the time and "Off" half the time.

### Code Explanation
The code uses "Loops inside Loops" to manage the animation.

The Setup: A loop tells the Arduino which five pins are connected to LEDs.

The Outer Loop (The Selector): This loop picks which LED we are currently working on (e.g., "Now focusing on LED #1").

The Inner Loop (The Dimmer): Inside that selection, a second loop counts from 0 to 255 rapidly. This gradually increases the brightness of that specific LED.

The Reverse: To fade out, the loops run backward, counting down from 255 to 0.

### Key Concepts Learned
Simulated Analog: Learning that digital devices can fake analog signals by switching really fast.

PWM (Pulse Width Modulation): The specific technique of controlling power by changing how long a switch stays "on" versus "off."

Nested Loops: Using one loop to control the timing of the fade, inside another loop that controls the sequence of the lights.

Dynamic Control: Using variables to change the state of the hardware smoothly over time, rather than just hard-coding a single value.
