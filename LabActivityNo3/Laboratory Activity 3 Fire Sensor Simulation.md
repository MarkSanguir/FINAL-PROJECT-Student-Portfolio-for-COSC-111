# Laboratory Activity #3: Fire Sensor Simulation

Here is a simplified explanation of the project, focusing on how the system "feels" the world around it.

### Overview: The Fire Detector
This project flips the script from previous activities. Instead of telling the Arduino to do something (like turning on a light), we are teaching it to sense something. It simulates a fire alarm by reading the environment to detect danger.

### What This Project Does
The system acts as a smart safety guard that watches the room for you.

The Watch: It constantly measures how hot the room is and how bright the light is.

The Decision: It uses a "Double-Check" rule to avoid false alarms. It only triggers the alarm if the room is Hot (over 50°C) AND Bright (Light level over 220) at the same time. This prevents the alarm from going off on a hot (but safe) day, or in a bright (but cool) room.

The Alarm: If both conditions are met, it panics: blinking a red light and sounding a buzzer to alert you.

### How It Works
The system uses two different senses to get a clear picture of what is happening, similar to how humans use both sight and touch.

The Sensors (The Inputs):

Heat Sensor (Thermistor):

Shutterstock
A component that changes its electrical flow based on temperature. * Light Sensor (Photoresistor): A component that becomes more conductive when light hits it. * The Brain: The Arduino takes the raw electricity coming from these sensors and translates it into numbers it can understand (like "Degrees Celsius").

The Alarm (The Outputs):

A Red LED and a Buzzer act as the warning signals.

### Code Explanation
The code does the heavy lifting to turn electrical signals into human-readable data.

The Translator: The sensors don't actually send "50°C" to the Arduino; they send raw voltage. The code uses a specific math formula to calculate the actual temperature from that voltage.

The Logic Check: The main part of the code is a simple "If" question:

"Is the temperature high AND is the light bright?"

The Reaction:

Yes: Flash the light and beep the buzzer rapidly.

No: Keep everything quiet and dark.

### Key Concepts Learned
Analog Sensing: Reading data that exists on a scale (like a dimmer switch or a thermometer) rather than just a simple On/Off switch.

Calibration: Using math to tune your code so that the sensor readings match the real world (e.g., making sure the sensor says 25°C when the room is actually 25°C).

Smart Logic (AND Condition): Creating rules where multiple things must happen at once for an action to take place.

Thresholds: Setting a specific "Limit Line" (like 50 degrees) that tells the code when to switch from "Safe" to "Danger."
