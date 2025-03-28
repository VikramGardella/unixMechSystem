#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdlib>
#include <vector>
#include <string>
#include "servo.h"

using namespace std;

class Component {

public:
    // Declare Constructor
    Component(string partId);

    // Declare Accessors
    double getGyroX();
    double getGyroY();
    double getGyroZ();

    double getAccelX();
    double getAccelY();
    double getAccelZ();

    string getId();
    string getAssemblyId();

    // Declare Mutators
    void setGyroX(double newVal);
    void setGyroY(double newVal);
    void setGyroZ(double newVal);

    void setAccelX(double newVal);
    void setAccelY(double newVal);
    void setAccelZ(double newVal);

    void setId(string newId);
    void setAssemblyId(string newId);

    // Declare Functionalities
    void addSubComponent(Component subComp);
    void addServo(Servo newServo);

    void printStatus();


private:
    // Private Member Variables
    double gyroX, gyroY, gyroZ; // gyroscope values
    double accelX, accelY, accelZ; // accelerometer values

    string id;
    string assemblyId;

    // Add vector<Servo> here once declared and defined
    vector<Servo> servos;
    // Add vector<LinAct> here once declared and defined

    // Sub-component vector<Component> (ie. hand would have fingers)
    vector<Component> sub;
};



#endif
