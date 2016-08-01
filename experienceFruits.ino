int i;
int ledpins[7]={3,4,5,6,7,8,9};
const int analogInPin = A0;
int sensorValue = 0;  
int valeurSortie = 0;

void setup() {
  // put your setup code here, to run once:
  for (i=0; i<8; i++){
      pinMode(ledpins[i], OUTPUT);
  }
  analogReference(INTERNAL);
  Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(analogInPin);
  Serial.println(sensorValue);

  valeurSortie = map(sensorValue, 0, 300, 0, 7);
  
  // Pour allumer toutes les lumières
  for (i=0; i<8; i++){
    if (valeurSortie >= i)
      digitalWrite(ledpins[i], HIGH);
  }  

  delay(2000);
  
  for (i=0; i<8; i++){
      digitalWrite(ledpins[i], LOW);
  }

}
