#include <robo_hardware2.h> 
#include <Servo.h>

#define pino_valorSensorDir A1
#define pino_valorSensorEsq A2
#define pino_valorSensorMaisEsq A3
#define pino_valorSensorMaisDir A4
#define DIVISOR_BRANCO_PRETO 50

//PINOS PARA LIGAR MOTORES
//Motor direito:
//pino1 PWM_RODA_DIREITA  6
//pino2 SENTIDO_RODA_DIREITA  7
//Motor esquerdo:
//pino1 PWM_RODA_ESQUERDA 5
//pino2 SENTIDO_RODA_ESQUERDA 4

//cofigura o nome dos sensores de refletância 
float valorSensorDir;
float valorSensorEsq;
float valorSensorMaisDir;
float valorSensorMaisEsq;
void setup(){
  robo.configurar(false);
}

void loop(){

  valorSensorDir = robo.lerSensorLinhaEsq();
  valorSensorEsq = robo.lerSensorLinhaDir();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();

  //Identifica se os quatro sensores viram branco
  if(valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO&& valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(50,50); //Aciona os dois motores com a mesma velocidade
  }
  //Identifica se os sensores da esquerda viram branco e os da direita viram preto
  else if (valorSensorMaisDir < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(50,-50);  //Aciona o motor esquerdo e mantem o motor direito desligado
  }
  //Identifica se os sensores da direita viram branco e o da esquerda viu preto
  else if ( valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(-50,50);  //Aciona o motor direito e mantem o motor esquerdo desligado
  }
 else{ //Identifica se os dois sensores viram preto
   robo.acionarMotores(0,0);
  }

}
