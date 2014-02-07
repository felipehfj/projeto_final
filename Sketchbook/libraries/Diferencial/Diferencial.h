#ifndef DIFERENCIAL_H
#define DIFERENCIAL_H

#include "MotorDif.h"

class Diferencial
{
    public:
	Diferencial(){ };
        Diferencial(MotorDif motorA, MotorDif motorB);

        void frente();
        void tras();
        void direita();
        void direitaDupla();
        void esquerda();
        void esquerdaDupla();
        void parar();

        void setMotorA(MotorDif motor);
        MotorDif getMotorA();
        void setMotorB(MotorDif motor);
        MotorDif getMotorB();

    private:
        MotorDif _motorA;
        MotorDif _motorB;
};

#endif // DIFERENCIAL_H
