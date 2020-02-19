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

void AccelStepperWithDistance::setStepsPerRevolution(int value) {
	stepsPerRevolution = value;
}

void AccelStepperWithDistance::setDistancePerRevolution(float value) {
	distancePerRevolution = value;
}

float AccelStepperWithDistance::getCurrentPositionDistance() {
	return currentPosition() / (microSteps * stepsPerRevolution / distancePerRevolution);
}

void AccelStepperWithDistance::moveToDistance(float value) {
	moveTo(value * microSteps * stepsPerRevolution / distancePerRevolution);
}

void AccelStepperWithDistance::runToNewDistance(float value) {
    moveToDistance(value);
    runToPosition();
}

void AccelStepperWithDistance::setAnglePerRevolution(float value) {
	anglePerRevolution = value;
}

void AccelStepperWithDistance::moveToAngle(float value) {
	moveTo(value * microSteps * stepsPerRevolution / anglePerRevolution);
}

void AccelStepperWithDistance::runToNewAngle(float value) {
    moveToAngle(value);
    runToPosition();
}
