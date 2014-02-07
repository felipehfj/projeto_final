/*************************************************************************
**  Device: LM35 Tenperature Sensor					**
**  File:   LM35.h	   				          	**
**									**
**  Created/Modified by F. Ferreira 2014-05-01                          **
**  Download from "http://www.github.com/felipehfj/Arduino"  		**
**									**
**									**
**  The code is provided under the MIT license please use, 		**
**  edit, change, and share.  		                    		**
**                                                                  	**
**************************************************************************/


#ifndef LM35_h
#define LM35_h

#define BUFFER_SIZE 1000
const float CELSIUS_BASE = 0.4887585;

#include <Arduino.h>   //Arduino IDE >= V1.0

class LM35
{
  public:
    // Constructor
    LM35(int sensor_pin);		
    float getCelsius();
    int getCelsiusInt();
    float getFahrenheit();
    int getFahrenheitInt();
    float getKelvin();
    int getKelvinInt();

  private:
    int _sensor_pin;
    float _buffer;
    void _bufferredRead();
};

#endif 
