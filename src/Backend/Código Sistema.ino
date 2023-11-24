#define BLYNK_TEMPLATE_ID "TMPL254KYQPHm"
#define BLYNK_TEMPLATE_NAME "Hidroponia"
#define BLYNK_AUTH_TOKEN "H91lrUurLrGp-uY0t8g2p0j9uQQSkcxn"

#define BLYNK_PRINT Serial

#define vSensor V0

#include <ESP8266WiFi.h> // Incluindo a Biblioteca do Wifi do ESP8266
#include <BlynkSimpleEsp8266.h> // Incluindo a Biblioteca do Blynk

const char ssid[] = "gui"; // Login da Internet
const char pass[] = "gui21042004"; // Senha da Internet

int portLedVermelho = 4; // Definindo a Porta do LED Vermelho
int portLedVerde = 0; // Definindo a Porta do LED Verde
int valorSensor = 0;
int portSen = A0;
int portMot = 16;

BlynkTimer timer; 

void setup() {
  Serial1.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  pinMode(portLedVermelho, OUTPUT);
  pinMode(portLedVerde, OUTPUT);
  pinMode(portSen, INPUT);
  pinMode(portMot, OUTPUT);
}

void loop(){

Blynk.run();
timer.run();

valorSensor = analogRead(portSen);
Serial.println(valorSensor); 
Blynk.virtualWrite(vSensor, valorSensor);

if (valorSensor >= 300){
  digitalWrite(portLedVerde, HIGH);
  digitalWrite(portLedVermelho, LOW);
}

else {
  digitalWrite(portLedVerde, LOW);   
  digitalWrite(portLedVermelho, HIGH);
}

digitalWrite(portMot, HIGH);
Serial.println("B Ligada");
Blynk.logEvent("bomba_ligada", "A bomba d'água ligou, suas plantas estão sendo regadas!");
delay(30000);

digitalWrite(portMot, LOW);
Serial.println("B Desligada");
delay(30000);
}
