# Laboratory Activity #3: Fire Sensor Simulation

### Overview

This project explores the "Input" side of Internet of Things (IoT) systems by integrating environmental sensors. Unlike previous activities that focused on controlling outputs (LEDs), this system "senses" the real world. It simulates a fire alarm by monitoring two critical environmental factors—temperature and light brightness—to detect potential hazards.

### What This Project Does

The system acts as an automated safety monitor. It continuously reads data from the environment and makes a decision based on a specific "danger" criteria:

- **Monitoring:** It tracks ambient temperature and light intensity in real-time.
- **Detection Logic:** It triggers an alarm _only_ if a specific condition is met: the environment must be both **hot** (over 50°C) AND **bright** (reading over 220). This "AND" logic helps prevents false alarms (e.g., a hot day without fire, or a bright room without heat).
- **Alarm System:** If fire conditions are detected, the system activates a fast-blinking red LED and a high-pitched buzzer to alert nearby users.
    

### How the System Works

The project uses a "Sensor Fusion" approach, combining data from two different sources to create a more reliable system.

- **Inputs (Sensors):**
    
    - **Thermistor (Pin A0):** A variable resistor that changes its resistance based on temperature. (Note: The diagram uses a TMP36 as a placeholder, but the code is designed for an NTC Thermistor).
        
    - **Photoresistor (Pin A2):** A light-sensitive resistor that decreases resistance as light intensity increases.
        
    - **Processing:** The Arduino reads the analog voltage from these sensors. It converts the raw electrical signals into readable data (Celsius for temperature, raw values for brightness).
        
- **Output (Actuators):** A Red LED (Pin 12) and a Buzzer (Pin 11) serve as the visual and auditory warning system.
### Code Explanation

The software handles complex math to convert raw electrical readings into meaningful units.

- **Sensor Configuration:** The code defines constants like `beta` (3950.0) and `resistance` (10.0), which are specific calibration values needed to interpret the thermistor's data accurately.
    
- **Data Conversion (`readTempC`):** Reading temperature is not as simple as reading a pin. The `readTempC` function uses a complex mathematical formula (likely a simplified Steinhart-Hart equation) to convert the analog voltage from the thermistor into degrees Celsius.
    
- **The Decision Engine (`loop`):** The main loop continuously checks the sensor values. It uses a conditional statement:
    
    `if(currentTemp >= tempThreshold && currentBright >= brightThreshold)`.
    
    - **If True:** It executes a rapid on/off sequence (`delay(100)`), creating a fast blinking light and a stuttering alarm sound.
        
    - **If False:** It ensures the LED and Buzzer remain completely off
### IoT Concepts Applied

- **Analog Sensing:** Reading variable data (0-1023) from the environment rather than just binary (On/Off) signals.
    
- **Sensor Calibration:** Using mathematical formulas to translate raw electrical input (voltage) into human-readable units (Celsius).
    
- **Conditional Logic (AND Gates):** Implementing safety logic where multiple conditions must be true simultaneously to trigger an action.
    
- **Thresholding:** Defining specific "trip wires" (e.g., 50°C) that separate a normal state from an alarm state