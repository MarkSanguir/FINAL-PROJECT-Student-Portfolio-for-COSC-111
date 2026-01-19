
# Laboratory Activity #1: Working with Digital Signals - Running Light Circuit

### Overview: The "Running Light"
This project is a beginner's guide to the Internet of Things (IoT). It teaches you how to control physical objects (lights) using computer code. instead of just flipping a manual switch, you are writing a program to flip the switches for you.

### What This Project Does
The system creates a simple light animation using five LEDs.

The Wave On: The lights turn on one by one in a line (from pin 12 down to 8), like a slow wave.

The Wave Off: Once they are all lit, they turn off one by one in the same order.

The Speed: The system waits exactly one second between each change, making the movement look deliberate and rhythmic.

### How It Works
The system works by connecting your computer code to physical electricity.

The Hardware: You connect five LEDs to the Arduino board. Resistors are added to the circuit to act as safety valves, ensuring the lights don't burn out from too much power.

The Signal: The Arduino acts as the brain. It sends a "High" signal (Power On) or a "Low" signal (Power Off) to the specific pins connected to the LEDs.

The Result: When the software sends the signal, the hardware lights up.

### Code Explanation
The code is written to be "smart" so you don't have to write the same instructions five times.

The List (Arrays): Instead of giving each light a unique name, the code groups them into a single list called ledPins. This makes it easy for the computer to find them.

The Setup: When the device turns on, it quickly reads through that list and tells the Arduino, "Get ready to send power out of these five pins."

The Loop: The main program runs in a continuous circle:

It counts through the list to turn the lights ON, waiting 1 second between each.

It counts through the list again to turn the lights OFF, waiting 1 second between each.

### Key Concepts Learned
Digital Switching: Learning how to turn voltage on and off using code.

Automation: Using loops (repeating code) so you don't have to manually write every single step.

Timing: Using a "delay" command to control how fast or slow the machine reacts.

Efficiency: Using lists (Arrays) to organize your hardware connections neatly.
