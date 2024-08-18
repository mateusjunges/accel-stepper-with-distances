# Accel Stepper with Distances

AccelStepperWithDistance is an extension of the AccelStepper library that adds convenient methods for working with distances and angles. It allows you to control stepper motors using steps, distances, or angles interchangeably.

# Installation

To install this library, search for `AccelStepperWithDistances` in the arduino library manager or just place this entire folder as a subfolder in your
`Arduino/lib/targets/libraries` folder.


## Usage

Here's a basic example of how to use the AccelStepperWithDistance library:

```cpp
#include <AccelStepperWithDistance.h>

#define STEP_PIN 2
#define DIR_PIN 3

AccelStepperWithDistance stepper(AccelStepperWithDistance::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  stepper.setStepsPerRotation(200);  // For a 1.8° stepper motor
  stepper.setMicroStep(16);          // If using 1/16 microstepping
  stepper.setDistancePerRotation(8); // If one rotation moves 8mm
}

void loop() {
  stepper.runToNewDistance(100);  // Move 100mm
  delay(1000);
  stepper.runToNewDistance(0);    // Return to starting position
  delay(1000);
}
```

## Methods

### Constructor

```cpp
AccelStepperWithDistance(uint8_t interface = AccelStepper::DRIVER, 
                         uint8_t pin1 = 2, uint8_t pin2 = 3, 
                         uint8_t pin3 = 4, uint8_t pin4 = 5, 
                         bool enable = true)
```

Creates a new instance of AccelStepperWithDistance. The parameters are the same as for AccelStepper.

### Configuration Methods

```cpp
void setMicroStep(int value)
```
Sets the microstep value. For example, if you're using 1/16 microstepping, call `setMicroStep(16)`.

```cpp
void setStepsPerRotation(int value)
```
Sets the number of full steps per rotation. For a 1.8° stepper motor, this would typically be 200.

```cpp
void setDistancePerRotation(float value)
```
Sets the distance traveled in one full rotation. For example, if one rotation moves 8mm, call `setDistancePerRotation(8)`.

```cpp
void setAnglePerRotation(float value)
```
Sets the angle for one full rotation. This is typically 360 degrees but can be changed if needed.

### Movement Methods

```cpp
void moveToDistance(float value)
```
Sets the target position in distance units. The motor will move to this position when you call `run()` or `runToPosition()`.

```cpp
void moveRelative(float value)
```
Sets a relative target position in distance units. The motor will move this distance from its current position when you call `run()` or `runToPosition()`.

```cpp
void runRelative(float value)
```
Moves the motor by a relative distance immediately, blocking until the movement is complete.

```cpp
void runToNewDistance(float value)
```
Moves the motor to an absolute distance position immediately, blocking until the movement is complete.

```cpp
void moveToAngle(float value)
```
Sets the target position in angle units. The motor will move to this angle when you call `run()` or `runToPosition()`.

```cpp
void runToNewAngle(float value)
```
Moves the motor to an absolute angle position immediately, blocking until the movement is complete.

### Position Reporting

```cpp
float getCurrentPositionDistance()
```
Returns the current position in distance units.

## Complete Example

Here's a more comprehensive example showcasing various methods:

```cpp
#include <AccelStepperWithDistance.h>

#define STEP_PIN 2
#define DIR_PIN 3

AccelStepperWithDistance stepper(AccelStepperWithDistance::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  Serial.begin(9600);
  
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  stepper.setStepsPerRotation(200);   // 1.8° stepper motor
  stepper.setMicroStep(16);           // 1/16 microstepping
  stepper.setDistancePerRotation(8);  // 8mm per rotation
  stepper.setAnglePerRotation(360);   // Standard 360° per rotation
  
  // Move to 50mm
  stepper.runToNewDistance(50);
  Serial.print("Current position: ");
  Serial.println(stepper.getCurrentPositionDistance());
  
  // Move relatively by -20mm
  stepper.runRelative(-20);
  Serial.print("New position after relative move: ");
  Serial.println(stepper.getCurrentPositionDistance());
  
  // Move to 90° angle
  stepper.runToNewAngle(90);
  Serial.print("Position after moving to 90°: ");
  Serial.println(stepper.getCurrentPositionDistance());
  
  // Set up a move to 100mm (but don't execute it yet)
  stepper.moveToDistance(100);
}

void loop() {
  // Execute the move set up in setup()
  if (stepper.distanceToGo() != 0) {
    stepper.run();
  }
}
```

This example demonstrates how to use various methods of the AccelStepperWithDistance library, including movement by distance and angle, relative movements, and position reporting.


# Credits
- [Mateus Junges][me]
- [Ariangelo H. Dias][ariangelo]
- miro-ux

[me]: https://twitter.com/mateusjungess
[ariangelo]: https://github.com/ariangelo
