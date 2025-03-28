#include "hardware.h"
#include <iostream>
#include <cmath>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "PCA9685.h"       // Controls the 16-channel servo driver
#include "MPU6050.h"       // Reads from the gyroscope/accelerometer


using namespace std;

static int i2c_fd = -1;

// PCA9685 Constants
const double SERVO_MIN_PULSE = 100.0; // 0 deg
const double SERVO_MAX_PULSE = 500.0; // 180 deg
const double SERVO_FREQ = 50.0;       // 50 Hz PWM

// Convert angle to PCA9685 pulse range (assuming 12-bit: 0–4095)
int angleToPulse(double angle) {
    angle = clamp(angle, 0.0, 180.0);
    double pulse = SERVO_MIN_PULSE + (angle / 180.0) * (SERVO_MAX_PULSE - SERVO_MIN_PULSE);
    int value = static_cast<int>((pulse / 20000.0) * 4096.0); // 20ms cycle
    return(clamp(value, 0, 4095));
}

bool initializeHardware() {
    // Open I²C device
    i2c_fd = open("/dev/i2c-1", O_RDWR);
    if(i2c_fd < 0) {
        cerr << "Failed to open I2C device.\n";
        return(false);
    }

    // Reset PCA9685 (optional: more logic to init PWM driver)
    ioctl(i2c_fd, I2C_SLAVE, PCA9685_ADDR);
    char reset[2] = { 0x00, 0x00 }; // MODE1 register reset
    write(i2c_fd, reset, 2);

    cout << "PCA9685 servo driver initialized.\n";

    // Init MPU6050
    ioctl(i2c_fd, I2C_SLAVE, MPU6050_ADDR);
    char powerMgmt[2] = { 0x6B, 0x00 }; // Wake up MPU6050
    write(i2c_fd, powerMgmt, 2);

    cout << "MPU6050 initialized.\n";
    return(true);
}

void setServoAngle(int channel, double angle) {
    if(i2c_fd < 0) {
        return
    };

    int pulse = angleToPulse(angle);

    // Set device to PCA9685
    ioctl(i2c_fd, I2C_SLAVE, PCA9685_ADDR);

    // Set PWM for the channel
    char buffer[5];
    int reg = 0x06 + 4 * channel; // LEDn_ON_L base + 4*channel
    buffer[0] = reg;
    buffer[1] = 0;                  // ON low byte
    buffer[2] = 0;                  // ON high byte
    buffer[3] = pulse & 0xFF;       // OFF low byte
    buffer[4] = (pulse >> 8) & 0xFF; // OFF high byte

    write(i2c_fd, buffer, 5);
}

int16_t readWord(uint8_t reg) {
    char buf[2];
    ioctl(i2c_fd, I2C_SLAVE, MPU6050_ADDR);
    write(i2c_fd, (char*)&reg, 1);
    read(i2c_fd, buf, 2);
    return((buf[0] << 8) | buf[1]);
}

// Simplified for demo: scale factor depends on range settings
double getAccelX() { return readWord(0x3B) / 16384.0; }
double getAccelY() { return readWord(0x3D) / 16384.0; }
double getAccelZ() { return readWord(0x3F) / 16384.0; }

double getGyroX() { return readWord(0x43) / 131.0; }
double getGyroY() { return readWord(0x45) / 131.0; }
double getGyroZ() { return readWord(0x47) / 131.0; }
