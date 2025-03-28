#ifndef SERVO_H
#define SERVO_H

#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Servo {

public:
    // Declare Constructor
    Servo(string servoId);

    // Declare Accessors
    double getAngle();
    string getId();

    // Declare Mutators
    void setAngle(double newAng);

    void setId(string newId);

    // Declare Functionalities


private:
    // Private Member Variables
    double angle;
    string id;
    
};



#endif
