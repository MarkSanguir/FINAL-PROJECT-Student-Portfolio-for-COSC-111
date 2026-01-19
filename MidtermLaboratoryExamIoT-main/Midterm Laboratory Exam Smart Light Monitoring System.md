# Midterm Laboratory Exam: Smart Light Monitoring System

### Overview

This project serves as a comprehensive "Midterm Exam" application, synthesizing concepts from previous activities into a cohesive "Smart" system. It implements a **Dual-Mode Light Monitor** that reads ambient light levels and visually indicates intensity using a traffic-light system (Green, Yellow, Red). Unique to this project is the ability to switch between an "Automatic" mode with fixed rules and a "Manual" mode where the user can dynamically tune sensitivity thresholds via text commands.

### What This Project Does

The system acts as an intelligent environmental monitor with two distinct personalities:

1. **Automatic Mode (Default):** The system behaves autonomously, categorizing light levels into "Cloudy" or "Clear" based on pre-set factory standards. It automatically lights up Green (Low Light), Yellow (Medium Light), or Red (High Light)1.
    
2. **Manual Mode:** The user takes control. Through the Serial Monitor, the user can type commands to change the "Low" and "High" trigger points on the fly, allowing the system to adapt to different environments without rewriting the code2222.
    
    +1
    
3. **Real-Time Dashboard:** The system constantly reports data back to the computer, displaying the current light percentage, the active LED, and the current operating mode every second3.
    

### How the System Works

The project integrates analog sensing with complex string parsing logic.

- **Inputs:** A **Photoresistor** connected to analog pin A0 measures the light intensity4.
    
- **Processing:**
    
    - The raw sensor data (0-1023) is mapped to a percentage (0-100%) for easier human readability5.
        
    - The code checks if `automaticMode` is true or false to decide which logic path to follow666.
        
        +1
        
- **Outputs:** Three LEDs—Green (Pin 11), Yellow (Pin 12), and Red (Pin 13)—serve as visual indicators7.
    
- **Interface:** A Command Line Interface (CLI) allows the user to type commands like `SET LOW 30` to adjust behavior in real-time.
    

### Code Explanation

The code is structured around a "State Machine" concept, where the behavior changes entirely based on the `automaticMode` variable.

- Variable Thresholding:
    
    Unlike previous activities with fixed numbers, this project uses variables lowThreshold (default 40) and highThreshold (default 70)8. In Manual mode, these variables can be overwritten by user input.
    
- **The Logic Core (`loop`):**
    
    - **Automatic Logic:** Uses hard-coded `if/else` blocks. If light is $\le$ 40%, it sets the environment to "Cloudy" and turns on Green9.
        
    - **Manual Logic:** Uses the mutable variables `lowThreshold` and `highThreshold` to decide which LED to light up. This allows the "Green" zone to be expanded or contracted dynamically10.
        
- Command Parsing (processCommand):
    
    This function acts as the "brain" of the user interface. It analyzes incoming strings:
    
    - `MODE AUTO` / `MODE MANUAL`: Toggles the boolean flag `automaticMode`11.
        
    - `SET LOW <value>`: Parses the number after the text (using `substring(8)`) and updates the `lowThreshold` variable—but _only_ if the system is in Manual mode12.
        
    - **Validation:** It includes safety checks (e.g., you can't set the Low threshold higher than the High threshold) to prevent logic errors13131313.
        
        +1
        

### IoT Concepts Applied

- **Dynamic Configuration:** The ability to change device parameters (thresholds) at runtime without re-uploading the code. This is critical for IoT devices deployed in changing environments.
    
- **Command Parsing:** processing complex string inputs (text + numbers) to extract meaningful commands.
    
- **Mode Switching:** Implementing distinct behaviors (states) within a single device and allowing users to toggle between them.
    
- **Data Normalization:** Using `map()` to convert raw sensor integers into human-friendly percentages14.