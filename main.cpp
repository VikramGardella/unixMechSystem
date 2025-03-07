#include <cstdlib>
#include <iostream>
#include "component.h"
#include "servo.h"

using namespace std;

Component torso = Component("Torso");
Component hips = Component("Hips");

Component leftThigh = Component("Left Thigh");
Component rightThigh = Component("Right Thigh");

Component leftCalf = Component("Left Calf");
Component rightCalf = Component("Right Calf");

Component leftFoot = Component("Left Foot");
Component rightFoot = Component("Right Foot");

Component leftShoulder = Component("Left Shoulder");
Component rightShoulder = Component("Right Shoulder");


void initialize(){
    // Initialize System Below
    cout << "\n\nInitializing Central System...\n\n\n";

    // Add Servos to Components
    leftThigh.addServo(Servo("Left Hip Joint"));
    leftThigh.addServo(Servo("Left Knee"));

    rightThigh.addServo(Servo("Right Hip Joint"));
    rightThigh.addServo(Servo("Right Knee"));

    leftCalf.addServo(Servo("Left Ankle"));
    rightCalf.addServo(Servo("Right Ankle"));

    hips.addServo(Servo("Waist"));

    // Link Subcomponents in safest order (lowest level->up)
    leftCalf.addSubComponent(leftFoot); // leftCalf's sub[0] = leftFoot
    leftThigh.addSubComponent(leftCalf); // leftThigh's sub[0] = leftCalf

    rightCalf.addSubComponent(rightFoot); // rightCalf's sub[0] = rightFoot
    rightThigh.addSubComponent(rightCalf); // rightThigh's sub[0] = rightCalf

    hips.addSubComponent(leftThigh); // hips' sub[0] = leftThigh
    hips.addSubComponent(rightThigh); // hips' sub[1] = rightThigh

    // Link hips and shoulders to torso
    torso.addSubComponent(hips); // torso's sub[0] = hips

    torso.addSubComponent(leftShoulder); // torso's sub[1] = leftShoulder Cannon
    torso.addSubComponent(rightShoulder); //torso's sub[2] = rightShoulder Cannon

}

void recursiveStatusPrint() {
    torso.printStatus();
}

int main(int argc, char** argv) {
    initialize();
    recursiveStatusPrint();
    
    return(0);
}

