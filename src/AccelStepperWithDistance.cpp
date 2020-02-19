#include "AccelStepperWithDistance.h"

AccelStepperWithDistance::AccelStepperWithDistance(
	uint8_t interface, 
	uint8_t pin1, 
	uint8_t pin2, 
	uint8_t pin3, 
	uint8_t pin4, 
	bool enable) : 
	AccelStepper(interface, pin1, pin2, pin3, pin4, enable) {} 

void AccelStepperWithDistance::setMicroStep(int value) {
	microSteps = value;
}

void AccelStepperWithDistance::setStepsPerRotation(int value) {
	stepsPerRotation = value;
}

void AccelStepperWithDistance::setDistancePerRotation(float value) {
	distancePerRotation = value;
}

float AccelStepperWithDistance::getCurrentPositionDistance() {
	return currentPosition() / (microSteps * stepsPerRotation / distancePerRotation);
}

void AccelStepperWithDistance::moveToDistance(float value) {
	moveTo(value * microSteps * stepsPerRotation / distancePerRotation);
}

void AccelStepperWithDistance::runToNewDistance(float value) {
    moveToDistance(value);
    runToPosition();
}

void AccelStepperWithDistance::setAnglePerRotation(float value) {
	anglePerRotation = value;
}

void AccelStepperWithDistance::moveToAngle(float value) {
	moveTo(value * microSteps * stepsPerRotation / anglePerRotation);
}

void AccelStepperWithDistance::runToNewAngle(float value) {
    moveToAngle(value);
    runToPosition();
}
