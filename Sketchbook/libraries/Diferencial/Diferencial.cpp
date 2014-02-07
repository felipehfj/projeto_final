#include "Diferencial.h"
#include "MotorDif.h"


Diferencial::Diferencial(MotorDif motorA, MotorDif motorB)
{
    //ctor
    this->_motorA = motorA;
    this->_motorB = motorB;
}

void Diferencial::frente()
{
    this->_motorA.frente();
    this->_motorB.frente();

}

void Diferencial::tras()
{
    this->_motorA.tras();
    this->_motorB.tras();
}


void Diferencial::direita()
{
    this->_motorA.frente();
    this->_motorB.parar();
}

void Diferencial::direitaDupla()
{
    this->_motorA.frente();
    this->_motorB.tras();
}

void Diferencial::esquerda()
{
    this->_motorA.parar();
    this->_motorB.frente();
}

void Diferencial::esquerdaDupla()
{
    this->_motorA.tras();
    this->_motorB.frente();
}

void Diferencial::parar()
{
    this->_motorA.parar();
    this->_motorB.parar();
}

void Diferencial::setMotorA(MotorDif motor)
{
    this->_motorA = motor;
}

MotorDif Diferencial::getMotorA()
{
    return this->_motorA;
}

void Diferencial::setMotorB(MotorDif motor)
{
    this->_motorB = motor;
}

MotorDif Diferencial::getMotorB()
{
    return this->_motorB;
}
