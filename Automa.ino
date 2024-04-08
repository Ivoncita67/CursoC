// Inclui a biblioteca para comunicação Arduino
#include <Arduino.h>

// Define os pinos para os relés e o sensor de movimento
const int rele1Pin = 2; // Pino para controlar o primeiro dispositivo (por exemplo, luz)
const int sensorPresencaPin = 3; // Pino para o sensor de presença

// Variável para armazenar o estado do sensor de presença
int estadoSensorPresenca = 0;

void setup() {
  // Define os pinos como saídas ou entradas
  pinMode(rele1Pin, OUTPUT);
  pinMode(sensorPresencaPin, INPUT);
  
  // Inicialmente, desliga o dispositivo (luz)
  digitalWrite(rele1Pin, LOW);
  
  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Lê o estado do sensor de presença
  estadoSensorPresenca = digitalRead(sensorPresencaPin);
  
  // Se movimento for detectado (sensor de presença ativado)
  if (estadoSensorPresenca == HIGH) {
    // Liga o dispositivo (luz)
    digitalWrite(rele1Pin, HIGH);
    
    // Imprime mensagem indicando que o movimento foi detectado e a luz está ligada
   // Serial.println("Movimento detectado! Luz ligada.");
    
    // Aguarda um curto período para evitar múltiplos acionamentos
    delay(5000);
  } else {
    // Desliga o dispositivo (luz)
    digitalWrite(rele1Pin, LOW);
  }
}
