# Laboratory Activity #5: Python-Arduino Integration

### Overview

This project bridges the gap between high-level software and embedded hardware. While previous activities used the Arduino IDE's built-in monitor for control, this activity introduces **Python** as an external control interface. By creating a custom Python script that communicates with the Arduino via the Serial port, this project demonstrates the foundational architecture used in commercial IoT dashboards and control software.

### What This Project Does

The system creates a "Remote Control" for a circuit using a computer's terminal.

- **The Interface:** A Python script runs on the computer, presenting a menu of options to the user (e.g., "[R] Red ON/OFF", "[A] All ON").
    
- **The Hardware:** Three LEDs (Red, Green, Blue) are connected to the Arduino.
    
- **The Action:** When the user selects an option in Python (like pressing 'R'), the physical Red LED on the breadboard immediately toggles its state (turns on if off, and vice versa). The system also supports "All On," "All Off," and a special "Violet" mode.
### How the System Works

The project relies on a client-server style architecture where Python acts as the client and Arduino as the server.

1. **User Input (Python):** The user types a command into the Python console. The script processes this input, converting it to lowercase and encoding it into a byte format suitable for transmission.
    
2. **Transmission (Serial/UART):** The Python script uses the `serial` library to send this data over the specific USB port (e.g., "COM7") to the Arduino.
    
3. **Processing (Arduino):** The Arduino constantly listens to the serial port. When data arrives, it reads the string, trims whitespace, and parses the command.
    
4. **Execution:** Based on the received character, the Arduino triggers a specific function (e.g., `toggleRed()`) defined in a separate header file, physically changing the voltage on the LED pins.
### Code Explanation

This project introduces **Modular Programming** by splitting the Arduino code into two files for better organization.

- **Python Script (`ArduinoFromPython.py`):**
    
    - **Library:** Uses `import serial` to manage the USB connection.
        
    - **Menu Loop:** Runs a `while True` loop to keep the program open, constantly asking for user input until "x" is pressed to exit.
        
    - **Encoding:** Before sending, commands are encoded (`.encode()`) because Serial communication transmits raw bytes, not Python strings.
        
- **Arduino Header File (`ArduinoFromPythonHeader.h`):**
    
    - **Pin Management:** Defines the hardware connections: Red (Pin 8), Green (Pin 9), and Blue (Pin 10).
        
    - **State Management:** Uses boolean variables (e.g., `bool redState`) to track whether an LED is currently on or off. This allows for the "toggle" logic: `redState = !redState` (set the state to the opposite of what it currently is).
        
- **Arduino Main Sketch (`.ino`):**
    
    - **Switch-Case Logic:** Instead of multiple `if` statements, it uses a `switch` structure to efficiently route commands ('r', 'g', 'b') to their respective functions.
        
    - **Input Validation:** Includes error handling to reject empty strings or multi-character inputs, ensuring the system doesn't crash from bad data.
### IoT Concepts Applied

- **Cross-Platform Communication:** integrating two different programming languages (Python and C++) via a standardized protocol (Serial/UART).
    
- **State Management:** Implementing logic that "remembers" the current status of the hardware (On or Off) to enable toggling.
    
- **Modular Design:** separating hardware definitions and logic functions into a header file (`.h`) to keep the main code clean and readable.
    
- **Command Line Interface (CLI):** Building a text-based user interface (UI) to interact with hardware.