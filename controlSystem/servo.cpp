#include "servo.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

// Define Constructor
Servo::Servo(string servoId){
    angle = 0;
    id = servoId;
}

// Define Accessors
double Servo::getAngle() {
    return(angle);
}

string Servo::getId() {
    return(id);
}

// Define Mutators
void Servo::setAngle(double newAng) {
    angle = newAng;
}

void Servo::setId(string newId) {
    id = newId;
}

