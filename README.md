# **Line-Follower-Robot**

## **Description**
The Line-Follower-Robot is an advanced robotics project combining the capabilities of:
- **Line Following**: Using sensors to follow a path on the ground.
- **Color Recognition**: Detecting and identifying colors on its path.
- **Custom Circuitry**: Includes a designed PCB for the entire system, ensuring compactness and efficiency.

This project is ideal for understanding embedded systems, robotics algorithms, and PCB design.

---

## **Features**
1. **Line Following**:
   - Tracks lines using multiple sensors for precise movement.
   - Implements various motor control strategies for sharp turns and corrections.
2. **Color Recognition**:
   - Identifies red, green, and blue colors using a TCS3200 color sensor.
   - Displays detected color and sensor readings on an LCD.
3. **Custom PCB**:
   - Compact and efficient design integrating all components.
   - Reduces wiring complexity for better performance and reliability.

---

## **Program Flow**
1. **Initialization**:
   - Setup pins for sensors, motors, and ultrasonic modules.
   - Initialize SD card for logging movement data.
2. **Line Following**:
   - Sensors detect the line and determine the robot's position relative to it.
   - Motors adjust speed and direction to keep the robot on track.
3. **Color Recognition**:
   - The TCS3200 color sensor detects the current surface color.
   - Data is displayed on an LCD and sent to the serial monitor.
4. **Obstacle Detection**:
   - Ultrasonic sensors detect obstacles ahead.
   - Robot stops if an obstacle is within a critical distance.

---

## **Example Output**
### **Serial Monitor Output (Line Following)**
```
Distance: 12 cm
Moving Forward...
Distance: 6 cm
Obstacle Detected! Stopping...
```

### **LCD Output (Color Recognition)**
```
V= 12.5V C= 0.8A
Color detected : RED
```

---

## **Hardware Components**
- **Microcontroller**: Arduino (e.g., Uno or Mega).
- **Sensors**:
  - TCS3200 for color recognition.
  - Line sensors for path tracking.
  - Ultrasonic sensor for obstacle detection.
- **Motors**:
  - DC motors with motor drivers for movement.
- **PCB**:
  - Custom-designed PCB integrating sensors, microcontroller, and motor drivers.
- **LCD**: I2C LCD for displaying voltage, current, and detected color.

---

## **Software Requirements**
- **Arduino IDE**: For compiling and uploading code to the microcontroller.
- **Libraries**:
  - `LiquidCrystal_I2C`: For I2C LCD control.
  - `SD`: For SD card operations.

---

## **How to Run**
1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/Line-Follower-Robot.git
   ```
2. Open the provided Arduino sketch files in the Arduino IDE.
3. Connect your hardware components as per the schematics.
4. Compile and upload the respective sketches:
   - `line_follower.ino` for line-following functionality.
   - `color_recognition.ino` for color detection.

---

## **License**
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## **Contributing**
Contributions are welcome! Here’s how you can contribute:
1. Fork the repository.
2. Create a branch for your feature (`git checkout -b feature/your-feature`).
3. Commit your changes (`git commit -m "Add your feature"`).
4. Push your changes (`git push origin feature/your-feature`).
5. Open a pull request.

---

## **Contact**
For any questions or suggestions, feel free to contact me:
- **GitHub**: [Ali Torab](https://github.com/atorab025)
---
