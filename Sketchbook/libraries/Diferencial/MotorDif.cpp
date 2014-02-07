/**
 @author Felipe Ferreira
 @version 1.2 23/08/2013
 
 Criada por Felipe Ferreira - felipehfj@gmail.com
 Copyright 2013 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
*/
#include "MotorDif.h"

MotorDif::MotorDif(uint8_t pinoA, uint8_t pinoB)
{
    setPinoA(pinoA);
    setPinoB(pinoB);
    setPinoE(0);
    setInverso(false);
    setVelocidade(0);
}

MotorDif::MotorDif(uint8_t pinoA, uint8_t pinoB, bool inverso)
{
    setPinoA(pinoA);
    setPinoB(pinoB);
    setPinoE(0);
    setInverso(inverso);
    setVelocidade(0);
}

MotorDif::MotorDif(uint8_t pinoA, uint8_t pinoB, uint8_t pinoE, uint8_t velocidade)
{
    setPinoA(pinoA);
    setPinoB(pinoB);
    setPinoE(pinoE);
    setInverso(false);
    setVelocidade(velocidade);
}

MotorDif::MotorDif(uint8_t pinoA, uint8_t pinoB, uint8_t pinoE, bool inverso, uint8_t velocidade)
{
    setPinoA(pinoA);
    setPinoB(pinoB);
    setPinoE(pinoE);
    setInverso(inverso);
    setVelocidade(velocidade);
}

void MotorDif::frente()
{
    if(this->_velocidade == 0)
    {
        if(isInverso())
        {
            digitalWrite(this->_pinoA, 0);
            digitalWrite(this->_pinoB, 1);
        }
        else
        {
            digitalWrite(this->_pinoA, 1);
            digitalWrite(this->_pinoB, 0);
        }

    }
    else
    {
        if(isInverso())
        {
            analogWrite(this->_pinoE, this->_velocidade);
            digitalWrite(this->_pinoA, 0);
            digitalWrite(this->_pinoB, 1);
        }
        else
        {
            analogWrite(this->_pinoE, this->_velocidade);
            digitalWrite(this->_pinoA, 1);
            digitalWrite(this->_pinoB, 0);
        }
    }
}

void MotorDif::tras()
{
    if(this->_velocidade == 0)
    {
        if(isInverso())
        {
            digitalWrite(this->_pinoA, 1);
            digitalWrite(this->_pinoB, 0);
        }
        else
        {
            digitalWrite(this->_pinoA, 0);
            digitalWrite(this->_pinoB, 1);
        }

    }
    else
    {
        if(isInverso())
        {
            analogWrite(this->_pinoE, this->_velocidade);
            digitalWrite(this->_pinoA, 1);
            digitalWrite(this->_pinoB, 0);
        }
        else
        {
            analogWrite(this->_pinoE, this->_velocidade);
            digitalWrite(this->_pinoA, 0);
            digitalWrite(this->_pinoB, 1);
        }
    }
}

void MotorDif::parar()
{
    if(this->_velocidade == 0)
    {
        digitalWrite(this->_pinoA, 0);
        digitalWrite(this->_pinoB, 0);
    }
    else
    {
        analogWrite(this->_pinoE, 1);
        digitalWrite(this->_pinoA, 0);
        digitalWrite(this->_pinoB, 0);
    }
}

void MotorDif::setVelocidade(uint8_t velocidade)
{
    this->_velocidade = velocidade;
}

uint8_t MotorDif::getVelocidade()
{
    return this->_velocidade;
}

void MotorDif::setInverso(bool inverso)
{
    this->_inverso = inverso;
}

bool MotorDif::isInverso()
{
    return this->_inverso;
}

void MotorDif::setPinoA(uint8_t pino)
{
    this->_pinoA = pino;
}

uint8_t MotorDif::getPinoA()
{
    return this->_pinoA;
}

void MotorDif::setPinoB(uint8_t pino)
{
    this->_pinoB = pino;
}

uint8_t MotorDif::getPinoB()
{
    return this->_pinoB;
}

void MotorDif::setPinoE(uint8_t pino)
{
    this->_pinoE = pino;
}

uint8_t MotorDif::getPinoE()
{
    return this->_pinoE;
}
