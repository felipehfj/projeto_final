/**
 @author Felipe Ferreira
 @version 1.2 23/08/2013

 ----------------------------------------------------------------------
 Biblioteca Motor - v1.2 - 23/08/2013

 Autor / Licença:
 Criada por Felipe Ferreira - felipehfj@gmail.com
 Copyright 2013 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
  Esta biblioteca pode ser utilizada com pontes H e CI do tipo L293D ou similares.
  Quando utilizada com ponte H, sem o pino de ativação Enable, não é possível fazer
  o controle da velocidade  da rotação dos motores. Para o controle de velocidade é 
  necessário um pino adicional,  Enable, presente em CI do tipo L293D, que ativam e 
  desativam o funcionamento da ponte.
  
  pinoA e pinoB : Ligação dos motores.
  pinoE : Ativação do controle de ativação (pino Enable em CI) e controle de velocidade de rotação do motor atraves de PWM.
  inverso : Controla o sentido de rotação do motor (direto ou inverso).
  velocidade : Velocidade de rotação do motor. Varia de 1 à 255.
  
  Com ponte H ou CI com o pino Enable ligado ao VCC
  Contrutores
   Motor();
   Motor(uint8_t pinoA, uint8_t pinoB) : Associa os polos dos motores ao uControlador
   Motor(uint8_t pinoA, uint8_t pinoB, bool inverso) : Associa os polos dos motores ao uControlador e define se a rotação sera direta ou reversa
   
  Com ponte H ou CI
  Contrutores
   Motor(uint8_t pinoA, uint8_t pinoB, uint8_t pinoE, uint8_t velocidade) : Associa os polos dos motores ao uControlador, define um pino para o controle de velocidade e uma velocidade
   Motor(uint8_t pinoA, uint8_t pinoB, uint8_t pinoE, bool inverso, uint8_t velocidade) : Associa polos, pino Enable, sentido de rotação e velocidade
   
   Funções
    void fente() : Rotaciona o motor no sentido direto
    void tras() : Rotaciona o motor no sentido inverso
    void parar() : Para a rotação do motor
    void setVelocidade(uint8_t velocidade) : Altera a velocidade de rotação
    uint8_t getVelocidade() : Retorna a velocidade de rotação
    void setInverso(bool inverso) : Altera o sentido de rotação do motor
    bool isInverso() : Retorna um booleano informando se o sentido de rotação está direto ou reverso
*/

#ifndef MOTORDIF_H
#define MOTORDIF_H

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class MotorDif
{
public:
    MotorDif(){ };
    MotorDif(uint8_t pinoA, uint8_t pinoB);
    MotorDif(uint8_t pinoA, uint8_t pinoB, bool inverso);
    MotorDif(uint8_t pinoA, uint8_t pinoB, uint8_t pinoE, uint8_t velocidade);
    MotorDif(uint8_t pinoA, uint8_t pinoB, uint8_t pinoE, bool inverso, uint8_t velocidade);

    void frente();
    void tras();
    void parar();
    void setVelocidade(uint8_t velocidade);
    uint8_t getVelocidade();
    void setInverso(bool inverso);
    bool isInverso();

private:
    uint8_t _pinoA;
    uint8_t _pinoB;
    uint8_t _pinoE;
    uint8_t _velocidade;
    bool _inverso;

    void setPinoA(uint8_t pino);
    uint8_t getPinoA();
    void setPinoB(uint8_t pino);
    uint8_t getPinoB();
    void setPinoE(uint8_t pino);
    uint8_t getPinoE();
};

#endif // MOTORDIF_H
