int portLedVermelho = 4;
int portLedVerde = 0;
int valSen = 0;
int portSen = A0;
int portBot = 14;
int estadoBot = 0;
int portMot = 16;

void setup()
{
 

  Serial.begin(9600);
  pinMode(portLedVermelho, OUTPUT);
  pinMode(portLedVerde, OUTPUT);
  pinMode(portSen, INPUT);
  pinMode(portBot, INPUT);
  pinMode(portMot, OUTPUT);
}


void loop()
{

   if (valSen > 300){
    digitalWrite(portLedVerde, HIGH);
    digitalWrite(portLedVermelho, LOW);

  }
  
  else {
    digitalWrite(portLedVerde, LOW);   
    digitalWrite(portLedVermelho, HIGH);

  }
  
  valSen = analogRead(portSen);
   Serial.println(valSen);
 
  estadoBot = digitalRead(portBot);   

  digitalWrite(portMot, HIGH);
  Serial.println("Bomba Ligada");
  Serial.println(valSen);
  delay(10000);
  digitalWrite(portMot, LOW);
  Serial.println("Bomba Desligada");
  Serial.println(valSen);
  delay(8000);
  
 

}