#include <DHT.h>

#define LED1 8

#define LED2 9

#define LED3 10

#define BUZZER 7

#define DHTPIN A0

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);

  dht.begin();

  tone(BUZZER, 3000);

  pinMode(LED1, OUTPUT);

  pinMode(LED2, OUTPUT);

  pinMode(LED3, OUTPUT);

  pinMode(BUZZER, OUTPUT);

}

void loop() {

  delay(1000);

  float temperatura = dht.readTemperature();

  if (isnan(temperatura)) {

    Serial.println("Erro ao ler o sensor!");

    return;

  }

  if (temperatura >= 28 && temperatura < 30) {

    digitalWrite(LED1, LOW);

    digitalWrite(LED2, HIGH);

    digitalWrite(LED3, LOW);

    tone(BUZZER, 3000);

  }

  else if (temperatura <= 27) {

    digitalWrite(LED1, HIGH);

    digitalWrite(LED2, LOW);

    digitalWrite(LED3, LOW);

    noTone(BUZZER);

  }

  else if (temperatura >= 30) {

    digitalWrite(LED1, LOW);

    digitalWrite(LED2, LOW);

    digitalWrite(LED3, HIGH);

    tone(BUZZER, 500);

  }

  Serial.print("Temperatura: ");

  Serial.print(temperatura);

  Serial.println(" °C");

}git add README.md