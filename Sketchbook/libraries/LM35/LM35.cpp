/*************************************************************************
**  Device: LM35 Tenperature Sensor					**
**  File:   LM35.h	   				          	**
**									**
**  Created/Modified by Ferreira, F 2014-05-01                          **
**  Download from "http://www.github.com/felipehfj/Arduino"  		**
**									**
**									**
**  The code is provided under the MIT license please use, 		**
**  edit, change, and share.  		                    		**
**                                                                  	**
**************************************************************************/

#include <Arduino.h>   //Arduino IDE >= V1.0
#include <LM35.h>

//************************************************************************
// Constructor

LM35::LM35(int sensor_pin){
	this->_sensor_pin = sensor_pin;
}

//************************************************************************
// private method

void LM35::_bufferredRead(){
   float buff = 0;
   for (int i = 0; i < BUFFER_SIZE; i++){
      buff += analogRead(this->_sensor_pin); 
   }
   this->_buffer = ((buff / BUFFER_SIZE) * CELSIUS_BASE);
}

//************************************************************************
// public methods

float LM35::getCelsius(){
  this->_bufferredRead();
  return this->_buffer;
}

//************************************************************************

int LM35::getCelsiusInt(){
  this->_bufferredRead();
  return int(this->_buffer * 100.0);
}

//************************************************************************

float LM35::getFahrenheit(){
  this->_bufferredRead();
  return ((this->_buffer * 1.8) + 32);
}

//************************************************************************

int LM35::getFahrenheitInt(){
  this->_bufferredRead();
  return int(((this->_buffer * 1.8) + 32) * 100.0);
}

//************************************************************************

float LM35::getKelvin(){
  this->_bufferredRead();
  return (this->_buffer + 273.0);
}

//************************************************************************

int LM35::getKelvinInt(){
  this->_bufferredRead();
  return int((this->_buffer + 273.0) * 100.0);
}

//************************************************************************
