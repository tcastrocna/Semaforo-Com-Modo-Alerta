//Incluir Bibliotecas
#include <Arduino.h>
#include <Bounce2.h>
//Definir pinagem
//semaforo 1
#define verde  18 //Pino 18 para verde do semaforo 1
#define amarelo 19 //Pino 19 para amarelo do semaforo 1
#define  vermelho  23 //Pino 23 para vermelho do semaforo 1
//semaforo 2
#define verde2  14 
#define amarelo2  27
#define vermelho2 16
//Definir botão para alerta de +22hs
const int buttonPin = 17; //Botão 17 para quando acionado os semaforos entra em modo alerta.
int buttonState = 0;

Bounce debouncer = Bounce () ;


void setup() {
  //definir como saída
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(amarelo2, OUTPUT);
  pinMode(vermelho2, OUTPUT);
  pinMode(buttonPin, INPUT);

  buttonState = digitalRead(buttonPin);
  debouncer. attach ( 17 ) ;  // Informa que o tratamento de debouce será feito no pino 17;
  debouncer. interval ( 2 ) ;  // Seta o intervalo de trepidação;

}
void loop() {
  debouncer. update () ;  // Executa o algorítimo de tratamento;
  int  value = debouncer. read () ;  // Lê o valor tratado do botão;
  if  ( value == HIGH )  {

    //Rodada 1
    digitalWrite(verde2, LOW);
    digitalWrite(amarelo2, LOW);
    digitalWrite(vermelho2, HIGH);
    delay(2000);
    digitalWrite(verde, HIGH);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);

    delay(5000);

    //Rodada 2
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);
    digitalWrite(vermelho, LOW);
    digitalWrite(verde2, LOW);
    digitalWrite(amarelo2, LOW);
    digitalWrite(vermelho2, HIGH);
    delay(3000);

    //Rodada 3
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW );
    digitalWrite(vermelho, HIGH);
    delay(2000);
    digitalWrite(verde2, HIGH);
    digitalWrite(amarelo2, LOW);
    digitalWrite(vermelho2, LOW);
    delay(5000);

    //Rodada 4
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW );
    digitalWrite(vermelho, HIGH);
    digitalWrite(verde2, LOW);
    digitalWrite(amarelo2, HIGH);
    digitalWrite(vermelho2, LOW);

    //Reiniciar
    delay(3000);

  }else{
    digitalWrite(amarelo, HIGH);
    digitalWrite(amarelo2, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(vermelho, LOW);

    delay(1000);
    digitalWrite(amarelo, LOW);
    digitalWrite(amarelo2, LOW);
    digitalWrite(verde2, LOW);
    digitalWrite(vermelho2, LOW);
    delay(1000);

  }


}
