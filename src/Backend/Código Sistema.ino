// Definição dos identificadores do Blynk
#define BLYNK_TEMPLATE_ID "TMPL254KYQPHm"
#define BLYNK_TEMPLATE_NAME "Hidroponia"
#define BLYNK_AUTH_TOKEN "H91lrUurLrGp-uY0t8g2p0j9uQQSkcxn"

// Configuração para imprimir mensagens do Blynk no console Serial
#define BLYNK_PRINT Serial

// Identificador virtual do sensor no Blynk
#define vSensor V0

// Inclusão das bibliotecas necessárias para WiFi e Blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Configuração do nome e senha da rede WiFi
const char ssid[] = "gui";
const char pass[] = "gui21042004";

// Definição das portas para LED vermelho, LED verde, sensor, e motor
int portLedVermelho = 4;
int portLedVerde = 0;
int valorSensor = 0;
int portSen = A0; // Porta analógica para o sensor
int portMot = 16; // Porta para o motor

BlynkTimer timer; // Criação do timer do Blynk para eventos

void setup() {
  Serial1.begin(9600); // Inicialização da comunicação serial
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80); // Inicialização do Blynk
  pinMode(portLedVermelho, OUTPUT);
  pinMode(portLedVerde, OUTPUT);
  pinMode(portSen, INPUT); // Configuração da porta do sensor como entrada
  pinMode(portMot, OUTPUT); // Configuração da porta do motor como saída
}

void loop(){
  Blynk.run(); // Execução do loop do Blynk
  timer.run(); // Execução do timer do Blynk

  valorSensor = analogRead(portSen); // Leitura do valor do sensor analógico
  Serial.println(valorSensor);
  Blynk.virtualWrite(vSensor, valorSensor); // Atualização do valor do sensor no Blynk

  // Lógica para controle dos LEDs com base no valor do sensor
  if (valorSensor >= 300){
    digitalWrite(portLedVerde, HIGH);
    digitalWrite(portLedVermelho, LOW);
  } else {
    digitalWrite(portLedVerde, LOW);
    digitalWrite(portLedVermelho, HIGH);
  }

  // Aciona o motor, registra um evento no Blynk e aguarda por 30 segundos
  digitalWrite(portMot, HIGH);
  Serial.println("B Ligada");
  Blynk.logEvent("bomba_ligada", "A bomba d'água ligou, suas plantas estão sendo regadas!");
  delay(30000);

  // Desliga o motor, registra um evento no Blynk e aguarda por mais 30 segundos
  digitalWrite(portMot, LOW);
  Serial.println("B Desligada");
  delay(30000);
}

