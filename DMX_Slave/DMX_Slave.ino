

#include <Conceptinetics.h>
#define DMX_SLAVE_CHANNELS   10 

DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS );

const int ledPin = 13;

void setup() {             
  dmx_slave.enable ();  
  dmx_slave.setStartAddress (1);
  pinMode ( ledPin, OUTPUT );
}

void loop() 
{
  if ( dmx_slave.getChannelValue (1) > 127 )
    digitalWrite ( ledPin, HIGH );
  else
    digitalWrite ( ledPin, LOW );
}
