#ifndef AccelStepperWithDistance_h
#define AccelStepperWithDistance_h

#include <AccelStepper.h>

class AccelStepperWithDistance : public AccelStepper {
    private:
		int microSteps = 1;
		int stepsPerRotation = 200;
		float distancePerRotation = 1;
		float anglePerRotation = 360;

    public:
		AccelStepperWithDistance(
			uint8_t interface = AccelStepper::DRIVER, 
			uint8_t pin1 = 2, 
			uint8_t pin2 = 3, 
			uint8_t pin3 = 4, 
			uint8_t pin4 = 5, 
			bool enable = true);

		void setMicroStep(int value);

		void setStepsPerRotation(int value);

		void setDistancePerRotation(float value);

		float getCurrentPositionDistance();

		void moveToDistance(float value);

    void moveRelative(float value);
    
    void runRelative(float value);

		void runToNewDistance(float value);

		void setAnglePerRotation(float value);

		void moveToAngle(float value);

		void runToNewAngle(float value);
};

#endif
