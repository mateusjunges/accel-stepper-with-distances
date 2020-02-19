#ifndef AccelStepperWithDistance_h
#define AccelStepperWithDistance_h

#include <AccelStepper.h>

class AccelStepperWithDistance : public AccelStepper {
    private:
		int microSteps = 1;
		int stepsPerRevolution = 200;
		float distancePerRevolution = 1;
		float anglePerRevolution = 360;

    public:
		AccelStepperWithDistance(
			uint8_t interface = AccelStepper::DRIVER, 
			uint8_t pin1 = 2, 
			uint8_t pin2 = 3, 
			uint8_t pin3 = 4, 
			uint8_t pin4 = 5, 
			bool enable = true);

		void setMicroStep(int value);
		void setStepsPerRevolution(int value);
		void setDistancePerRevolution(float value);
		float getCurrentPositionDistance();
		void moveToDistance(float value);
		void runToNewDistance(float value);
		void setAnglePerRevolution(float value);
		void moveToAngle(float value);
		void runToNewAngle(float value);
};

#endif
