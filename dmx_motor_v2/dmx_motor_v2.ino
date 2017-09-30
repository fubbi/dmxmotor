// MOTOR GLOBALS ______________________________________

#include <AccelStepper.h>
int motorDirPin = 9; //digital pin 6
int motorStepPin = 8; //digital pin 3
AccelStepper stepper(1, motorStepPin, motorDirPin);

int energy = 1000;    // The current speed in steps/second
int topSpeed = 750; // The max speed in the energy mapping
int go = 1;      // Either 1, 0 or -1

// DMX GLOBALS ______________________________________

#include <Conceptinetics.h>
#define DMX_SLAVE_CHANNELS   2
DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS );
const int ledPin = 13;

void setup()
{
  // MOTOR SETUP
  stepper.setMaxSpeed(1000);
  stepper.setSpeed(1000);

  // DMX SETUP
  dmx_slave.enable ();
  dmx_slave.setStartAddress (1);
  pinMode ( ledPin, OUTPUT );
}

void loop()
{

  energy = dmx_slave.getChannelValue (2);
  energy = map(energy, 0, 255, 0, topSpeed);

  if ( dmx_slave.getChannelValue (1) > 127 ) {
    digitalWrite ( ledPin, HIGH );
    go = 1;
  }

  if ( dmx_slave.getChannelValue (1) < 127 ) {
    digitalWrite ( ledPin, LOW );
    go = -1;
  }


  stepper.setSpeed(go * energy);
  stepper.runSpeed();

}

