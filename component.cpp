#include "component.h"
#include "servo.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

// Define Constructor
Component::Component(string partId){
    gyroX = 0;
    gyroY = 0;
    gyroZ = 0;

    accelX = 0;
    accelY = 0;
    accelZ = 0;

    id = partId;
    assemblyId = "xxxxxx";
    sub = vector<Component>();
    servos = vector<Servo>();
}

// Define Accessors
double Component::getGyroX() {
    return(gyroX);
}

double Component::getGyroY() {
    return(gyroY);
}

double Component::getGyroZ() {
    return(gyroZ);
}


double Component::getAccelX() {
    return(accelX);
}

double Component::getAccelY() {
    return(accelY);
}

double Component::getAccelZ() {
    return(accelZ);
}

string Component::getId() {
    return(id);
}

string Component::getAssemblyId() {
    return(assemblyId);
}


// Define Mutators
void Component::setGyroX(double newVal) {
    gyroX = newVal;
}

void Component::setGyroY(double newVal) {
    gyroY = newVal;
}

void Component::setGyroZ(double newVal) {
    gyroZ = newVal;
}

void Component::setAccelX(double newVal) {
    accelX = newVal;
}

void Component::setAccelY(double newVal) {
    accelY = newVal;
}

void Component::setAccelZ(double newVal) {
    accelZ = newVal;
}

void Component::setId(string newId) {
    id = newId;
}

void Component::setAssemblyId(string newId) {
    assemblyId = newId;
}


// Define Functionalities
void Component::addSubComponent(Component subComp) {
    sub.push_back(subComp);
}

void Component::addServo(Servo newServo) {
    servos.push_back(newServo);
}

void Component::printStatus() {
    cout << "\n--------" << endl;
    cout << "ID: " << id << endl;
    cout << "Assembly ID: " << assemblyId << endl;

    cout << "\nGryoscope Values:" << endl;
    cout << "X = " << gyroX << " deg" << endl;
    cout << "Y = " << gyroY << " deg" << endl;
    cout << "Z = " << gyroZ << " deg" << endl;

    cout << "\nAccelerometer Values:" << endl;
    cout << "X = " << accelX << " m/s^2" << endl;
    cout << "Y = " << accelY << " m/s^2" << endl;
    cout << "Z = " << accelZ << " m/s^2" << endl;

    if(servos.size() > 0) {
        cout << "\nServo Motor Angular Displacements:" << endl;
        for(int i = 0; i < servos.size(); i++) {
            cout << servos[i].getId() << " = " << servos[i].getAngle() << " deg" << endl;
        }
    }

    cout << "--------\n\n\n";

    // Recursively call print statements for sub-components
    for(int i = 0; i < sub.size(); i++) {
        sub[i].printStatus();
    }

}