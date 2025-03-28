# Systemd Service Setup

This folder contains systemd unit files for automatically starting the C++ robotics control system and camera streaming module at boot on a Unix-based system such as a Raspberry Pi.

## Folder Structure

```
/robotics-project/
├── control_system/       # Control system code and binary
├── camera_stream/        # Camera streaming code and binary
├── systemd/              # This folder
│   ├── robot.service
│   ├── camera.service
│   └── README.md         # (this file)
```

---

## Service Descriptions

### `robot.service`
Launches the robotics control system binary (`robot`) from the `control_system` folder. This is the core logic that handles servo control and component coordination.

### `camera.service`
Launches the camera streaming binary (`cam_stream`) from the `camera_stream` folder. This module handles image capture and streaming.

---

## Prerequisites

- Ensure both subsystems have been built:
  ```bash
  cd ~/robotics-project/control_system
  make

  cd ~/robotics-project/camera_stream
  make
  ```

- Confirm that the compiled binaries exist:
  - `control_system/robot`
  - `camera_stream/cam_stream`

- Make both binaries executable:
  ```bash
  chmod +x ~/robotics-project/control_system/robot
  chmod +x ~/robotics-project/camera_stream/cam_stream
  ```

---

## Installation Instructions

1. Copy the service files into the systemd directory:
   ```bash
   sudo cp robot.service /etc/systemd/system/
   sudo cp camera.service /etc/systemd/system/
   ```

2. Enable both services to start at boot:
   ```bash
   sudo systemctl daemon-reexec
   sudo systemctl enable robot.service
   sudo systemctl enable camera.service
   ```

3. Start the services manually (for testing):
   ```bash
   sudo systemctl start robot.service
   sudo systemctl start camera.service
   ```

---

## Monitoring & Logs

Check the current status of either service:

```bash
sudo systemctl status robot.service
sudo systemctl status camera.service
```

View runtime logs via `journalctl`:

```bash
sudo journalctl -u robot.service --no-pager
sudo journalctl -u camera.service --no-pager
```

---

## Notes

- These services are configured to:
  - Restart automatically on failure
  - Run as the `pi` user
  - Assume that `DISPLAY=:0` (for any GUI tools like OpenCV preview)
- If your project requires additional environment setup or pre-run compilation, consider adding a wrapper `start.sh` script and modifying the `ExecStart` line in each `.service` file.

---

## Optional: Auto-Build Before Run

If you prefer to compile the project each time the service starts (not recommended for production), you can modify `robot.service` like this:

```ini
ExecStartPre=/usr/bin/make -C /home/pi/robotics-project/control_system
ExecStart=/home/pi/robotics-project/control_system/robot
```

---

## Troubleshooting

If a service fails to start:
- Ensure I²C is enabled on your Raspberry Pi
- Check permissions for `/dev/i2c-1`
- Use `journalctl` logs for detailed error output
- Recheck binary paths and file permissions

---

