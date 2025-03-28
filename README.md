# C++ Robotics System Template

This repository contains a modular C++ robotics system template designed for Unix-based systems, including Raspberry Pi. It is built for low-latency, headless operation and real-time control of physical components such as servos and sensors.

## Overview

This project is structured to serve as a foundation for embedded robotics applications. It includes hardware interfacing via I²C, component modeling, and a basic camera streaming module. The system is compiled using Makefiles and is designed to run automatically on system boot using systemd.

## Features

- Component-based architecture for hierarchical robotic systems
- Servo control using the Adafruit 16-channel PCA9685 driver
- Gyroscope and accelerometer integration via MPU6050
- OpenCV-based camera streaming module
- Systemd-compatible boot-time services
- Minimal external dependencies and straightforward Makefile builds

## Project Structure



```
/control_system
  ├── main.cpp           # Entry point for robotic control system
  ├── component.cpp/.h   # Logical modeling of robot parts and hierarchy
  ├── servo.cpp/.h       # Servo data model and interface
  ├── hardware.cpp/.h    # Low-level I²C device communication

/camera_stream
  ├── main.cpp           # Entry point for camera streaming
  ├── camera.cpp/.h      # Camera capture using OpenCV

/systemd
  ├── robot.service      # Systemd service to launch control system
  ├── camera.service     # Systemd service to launch camera stream
```

## Requirements

- C++17 or later
- OpenCV 4.x
- Linux with I²C support (`/dev/i2c-1`)
- Raspberry Pi or any Unix-based system with GPIO/I²C access

## Dependencies (Ubuntu / Raspberry Pi OS)

```bash
sudo apt update
sudo apt install build-essential libopencv-dev i2c-tools
```

## Build Instructions

Compile both subsystems using the provided Makefiles:

```bash
cd control_system
make

cd ../camera_stream
make
```

## Running the System

To execute manually:

```bash
sudo ./control_system/robot
sudo ./camera_stream/cam_stream
```

To enable auto-start on boot:

```bash
sudo cp systemd/robot.service /etc/systemd/system/
sudo cp systemd/camera.service /etc/systemd/system/

sudo systemctl enable robot.service
sudo systemctl enable camera.service
```

## Roadmap

- Add PID control and movement patterns
- Integrate WebSocket or MQTT-based telemetry
- Add GPIO event handling (e.g., tactile sensors)
- Include computer vision and object detection
- Optional web interface for monitoring and command

## Author
Vikram Gardella

## License

This project is licensed under the MIT License. See `LICENSE` for details.

## Contributing

Contributions are welcome. Please submit pull requests for features, improvements, or bug fixes. Open issues if you have questions or suggestions.
