#ifndef HARDWARE_H
#define HARDWARE_H

#include <string>
#include <vector>

// I²C includes
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

// Addresses (adjust if changed via solder jumper)
#define PCA9685_ADDR 0x40
#define MPU6050_ADDR 0x68

// Initialize all hardware (I²C + devices)
bool initializeHardware();

// Servo functions
void setServoAngle(int channel, double angle);

// IMU functions
double getAccelX();
double getAccelY();
double getAccelZ();

double getGyroX();
double getGyroY();
double getGyroZ();

#endif
