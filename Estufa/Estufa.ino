// Definindo os pinos para os componentes
const int sensorTempPin = A0; // Pino analógico para o sensor de temperatura
const int motorPin = 9;       // Pino digital para o motor de ventilador
const int ledPin = 7;         // Pino digital para o LED
const int buzzerPin = 8;      // Pino digital para a buzina

void setup() {
  // Inicialização dos pinos
  pinMode(sensorTempPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Leitura da temperatura em Celsius
  float temperaturaC = analogRead(sensorTempPin) * 0.48828125;

  // Verificar se a temperatura é maior ou igual a 30°C
  if (temperaturaC >= 30) {
    // Ativar o motor do ventilador
    digitalWrite(motorPin, HIGH);
  } else {
    // Desligar o motor do ventilador
    digitalWrite(motorPin, LOW);
  }

  // Verificar se a temperatura ultrapassou os 50°C
  if (temperaturaC > 50) {
    // Ativar o LED vermelho
    digitalWrite(ledPin, HIGH);
    // Ativar a buzina
    digitalWrite(buzzerPin, HIGH);
    delay(500); // Aguardar meio segundo
    // Desativar o LED e a buzina
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(500); // Aguardar meio segundo
  }

  // Aguardar um segundo antes de realizar a próxima leitura
  delay(1000);
}

