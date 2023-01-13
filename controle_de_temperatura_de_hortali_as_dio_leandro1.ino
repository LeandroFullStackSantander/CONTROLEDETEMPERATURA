// PROJETO REALIZADO COM BASE NAS INSTRUÇÕES DO 
// PROFESSOR DIEGO BRUNO, INSTRUTOR DA DIO.
// DEV.: LEANDRO CASTRO MACIEL
// GRATO PELO APRENDIZADO!!!! 

#define led         13
#define buzzer      12
#define motor       10
#define SENSOR_TEMP A5

float temperatura = 0;

void setup(){
 
	Serial.begin(9600);
  	Serial.print("LED ON");
	digitalWrite(led, HIGH);
  	digitalWrite(motor, HIGH);
  	Serial.print("MOTOR ON");
  
  	pinMode(SENSOR_TEMP, INPUT);
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
  	pinMode(motor, OUTPUT);
}
void loop(){
  
	int medicao = analogRead(A5);
  	temperatura = map(medicao, -40, 125, 0, 75);
  	Serial.print("temperatura = ");
	Serial.println(temperatura);
 
  if((temperatura < 30.0) && (temperatura > 10.0)){
  		Serial.println("AMBIENTE CONTROLADO");
  		digitalWrite(motor, LOW);
        digitalWrite(led, LOW);
    	digitalWrite(buzzer, LOW);
  }
  
  if((temperatura >= 30.0) && (temperatura <= 50.0)){
    	Serial.println("30° GRAUS");
  		digitalWrite(motor, HIGH);
        digitalWrite(led, LOW);
    	digitalWrite(buzzer, LOW);
  }
  if(temperatura > 50.0){
  		Serial.println("ACIMA DE 50° GRAUS");
        Serial.println("EMERGÊNCIA ATIVADA");
    	digitalWrite(led, HIGH);
    	digitalWrite(buzzer, HIGH);
        digitalWrite(motor, LOW);
  }

}