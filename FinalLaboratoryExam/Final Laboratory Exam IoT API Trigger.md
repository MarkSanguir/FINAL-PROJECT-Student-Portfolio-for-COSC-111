# Final Laboratory Exam: IoT API Trigger

### Overview

This final exam project represents the culmination of the IoT course, demonstrating the "Client" side of a networked system. Unlike previous activities where you hosted the server, here your system acts as a physical trigger for a remote service. This architecture mimics commercial products like "Smart Buttons" (e.g., Amazon Dash or Flic), where a simple physical click initiates a complex web-based action, such as ordering a product or toggling a smart home scene.

### What This Project Does

The system creates a physical "voting" or control button for a specific user group (Group 3).

- **The Trigger:** A user presses a physical push button connected to the Arduino.
    
- **The Signal:** The Arduino detects the press and sends the group's ID number ("3") to the computer via USB.
    
- **The Request:** A Python script running on the computer intercepts this number. It immediately contacts a remote server (the Instructor's API) at `http://172.20.10.3:8000`.
    
- **The Result:** The remote server receives the signal and toggles the status (e.g., an LED or dashboard indicator) associated with Group 3.
    

### How the System Works

The project uses a **Gateway Architecture**, where the computer serves as the bridge between the non-networked Arduino and the internet.

1. **Hardware Layer (Edge):**
    
    - A push button is connected to **Pin 4** using the internal pull-up resistor configuration (`INPUT_PULLUP`), ensuring a stable signal without external resistors.
        
2. **Middleware Layer (Gateway):**
    
    - The `main.py` script continuously listens to the Serial port (`COM7`) for incoming data.
        
3. **Network Layer (Cloud/Server):**
    
    - When the Python script receives the group number, it constructs a dynamic URL: `/led/group/3/toggle`.
        
    - It uses the **HTTP GET** method to "hit" this endpoint, effectively pushing the virtual button on the server.
        

### Code Explanation

The code handles signal noise on the hardware side and network communication on the software side.

- **Arduino Sketch (`LabExamFinal.ino`):**
    
    - **Debouncing:** Mechanical buttons are noisy; one press can look like 10 rapid clicks to a fast microcontroller. The code uses a `debounceDelay` (50ms) and time tracking (`lastDebounceTime`) to ensure that only one clean, deliberate signal is sent per physical press.
        
        +1
        
    - **Serial Transmission:** Once a valid press is confirmed, it sends a simple string—the `groupNumber` (3)—over the serial connection.
        
- **Python Client (`main.py`):**
    
    - **Dependencies:** Uses the `serial` library to talk to the Arduino and the `requests` library to talk to the web server.
        
    - **Dynamic Logic:** It reads the serial input (`raw_data`), verifies it is a number, and injects it into the API URL string. This makes the script reusable for any group number.
        
    - **Error Handling:** It includes `try-except` blocks to handle network failures (e.g., if the server is down) or serial disconnects gracefully, preventing the program from crashing.
        

### IoT Concepts Applied

- **Gateway Pattern:** Using a more powerful device (PC) to provide connectivity for a constrained device (Arduino Uno) that lacks built-in WiFi.
    
- **Debouncing:** Implementing software algorithms to filter out mechanical noise from physical sensors.
    
- **HTTP Client:** Programmatically generating web requests to interact with REST APIs.
    
- **Edge-to-Cloud:** The flow of data originating at the "Edge" (the physical button) and propagating to the "Cloud" (the API server).