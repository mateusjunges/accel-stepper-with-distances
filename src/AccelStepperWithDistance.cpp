#include "AccelStepperWithDistance.h"

AccelStepperWithDistance::AccelStepperWithDistance(
	uint8_t interface, 
	uint8_t pin1, 
	uint8_t pin2, 
	uint8_t pin3, 
	uint8_t pin4, 
	bool enable) : 
	AccelStepper(interface, pin1, pin2, pin3, pin4, enable) {} 

/**
 * Set the microSteps value.
 * @param value
 */
void AccelStepperWithDistance::setMicroStep(int value) {
	microSteps = value;
}

/**
 * Set the number of steps a step motor should do to complete one full rotation.
 * @param value
 */
void AccelStepperWithDistance::setStepsPerRotation(int value) {
	stepsPerRotation = value;
}

/**
 * Set the distance which the step motor cover with one full rotation.
 * @param value
 */
void AccelStepperWithDistance::setDistancePerRotation(float value) {
	distancePerRotation = value;
}

/**
 * Return the current distance from the origin.
 * @return
 */
float AccelStepperWithDistance::getCurrentPositionDistance() {
	return currentPosition() / (microSteps * stepsPerRotation / distancePerRotation);
}

/**
 * The motor travel a certain distance.
 * @param value
 */
void AccelStepperWithDistance::moveToDistance(float value) {
	moveTo(value * microSteps * stepsPerRotation / distancePerRotation);
}

/**
 * Move the motor to a new relative distance.
 * @param value
 */
void AccelStepperWithDistance::moveRelative(float value)
{
  move(value * microSteps * stepsPerRotation / distancePerRotation);
}

/**
 * Move and run the motor to a new relative distance.
 * @param value
 */
void AccelStepperWithDistance::runRelative(float value)
{
  move(value * microSteps * stepsPerRotation / distancePerRotation);
  runToPosition();
}

/**
 * The motor goes to the new specified distance.
 * @param value
 */
void AccelStepperWithDistance::runToNewDistance(float value) {
    moveToDistance(value);
    runToPosition();
}

/**
 * Set the angle per rotation property.
 * @param value
 */
void AccelStepperWithDistance::setAnglePerRotation(float value) {
	anglePerRotation = value;
}

/**
 * The motor goes to the new specified angle.
 * @param value
 */
void AccelStepperWithDistance::moveToAngle(float value) {
	moveTo(value * microSteps * stepsPerRotation / anglePerRotation);
}

/**
 * The motor goes to the new specified angle.
 * @param value
 */
void AccelStepperWithDistance::runToNewAngle(float value) {
    moveToAngle(value);
    runToPosition();
}
