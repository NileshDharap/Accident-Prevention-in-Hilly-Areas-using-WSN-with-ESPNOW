void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(D1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int s1;
  
  s1 = digitalRead(D1);
  if(s1==LOW){
          digitalWrite(2,LOW);
          Serial.println("DETECTED");
      }
  else digitalWrite(2,HIGH);

}
