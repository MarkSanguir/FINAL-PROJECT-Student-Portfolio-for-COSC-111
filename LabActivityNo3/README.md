# Fire-Sensor-Simulation
Leader: Padilla, Rovick B. <br>
Members: Pagarigan, Mark John Paul A. & Sanguir, Mark I.

**Laboratory Activity #3: Working with Sensors** <br>

Objectives
- Familiarize students with the basic sensor components that can be used in IoT
- Integrate these sensor components in an Arduino circuit
- Create a simple implementation of a fire sensor


Instructions:
1. We are assigned to create a simple implementation of a fire sensor using thermistor and photoresistor
2. Specifics
- We use A0 for thermistor and A2 for photoresistor along with 10k ohm resistor.
- Use Celsius for the temperature, "analog" signal for the photoresistor.
- Threshold Limit: 50 Celsius for the temperature AND 220 for the brightness.
- If the threshold limit is reached, fast blinking Red LED to notify about the fire. LED mapped in digital pin 12.
- Together with the LED, we add a buzzer/speaker that uses the digital pin 11.

This github link contains the following: <br>
- The sketched file named "fire_sensor_simulation.ino"
- Image / Screenshot of Breadboard diagram using Tinkercad. We use Temperature Sensor [TMP36] as a substiture for NTC Thermistor as a placeholder (No Thermistor in Tinkercad) 
- Breadboard Diragram Link: https://www.tinkercad.com/things/hjOXWO2g0xD-laboratory-activity-3-working-with-sensors?sharecode=MmutdbMNaYXJhuH0NkZEU3QpHZ7GzDYaf5hNVpsrJxk
- Individual grades of the members
