# Laboratory Activity #4: Arduino Serial Connection

### Overview

This activity introduces two-way communication between the microcontroller and a computer. Unlike previous projects that operated autonomously, this system requires human intervention. It demonstrates **Serial Communication**, allowing users to send text commands from their computer to control the hardware behavior in real-time.

### What This Project Does

The system acts as a "latching" alarm that monitors light levels.

- **Monitoring:** It continuously reads the brightness level from a photoresistor.
    
- **Persistent Alarm:** If the brightness exceeds a specific limit (220), the system enters an "Alarm Mode." The LED begins blinking endlessly.
    
- **Latching State:** Crucially, once the alarm is triggered, it _stays_ on, even if the light level drops back down. The system "remembers" the event.
    
- **Manual Reset:** The alarm will only stop blinking when a user types the command "stop" into the Arduino Serial Monitor.

### How the System Works

The project relies on the relationship between the hardware sensors and the software console.

- **Input (Hardware):** A photoresistor on Pin A2 measures ambient light
    
- **Input (Software):** The Arduino listens for text input from the connected computer via the USB cable (Serial port).
    
- **Processing:** The code converts the raw sensor data and constantly checks for the threshold. If triggered, it locks the program into a blinking loop until the correct password ("stop") is received.
    
- **Output:** An LED on digital pin 12 flashes to indicate the alarm state.

### Code Explanation

The code introduces string handling and distinct "states" of operation.

- **Data Conversion (`readBright`):** The function reads the raw analog value (0-1023) and uses the `map()` function to convert it to a smaller range of 0-255. This standardized value is used for comparison.
    
- **Trigger Logic:** The main loop checks if the brightness hits the `brightThreshold` (220). If it does, it sets a boolean flag `choice = true`, effectively locking the system into the alarm state.
    
- **The "Latching" Loop:** Once `choice` is true, the program enters a `while` loop. Inside this loop, the LED blinks continuously with a 100ms delay. The program _cannot_ escape this loop to check the sensor again; it is stuck here until the user intervenes.
    
- **Serial Command Handling:** Inside the blinking loop, the Arduino checks the Serial buffer for text.
    
    - `Serial.readStringUntil('\n')` captures the user's typed command.
        
    - `input.toLowerCase()` ensures the command works whether the user types "STOP", "Stop", or "stop" (case insensitivity).
        
    - If the input equals "stop", the code breaks the loop and turns off the LED.
### IoT Concepts Applied

- **Serial Communication (UART):** Using the USB interface to send data (debug messages) to the PC and receive commands (strings) from the user.
    
- **State Retention (Latching):** Creating a system that "remembers" an event (the alarm trigger) and persists in that state until explicitly reset. This is common in safety systems where an error must be acknowledged by a human.
    
- **String Manipulation:** Processing text data (converting to lowercase) to make user interfaces more robust and user-friendly.
    
- **Blocking vs. Non-Blocking:** This code uses a "blocking" `while` loop for the alarm, meaning the sensor stops reading new data while the alarm is active.
