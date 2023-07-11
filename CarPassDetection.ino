#define Between_Time 1000
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(D1,INPUT);
  pinMode(D0,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int s1,s2;
  int p_m,c_m;
  
  s1 = digitalRead(D1);
  if(s1==LOW){
    p_m = millis();
    c_m = millis();
    while(c_m-p_m < Between_Time){
       s2 = digitalRead(D0);
       if(s2==LOW){
          digitalWrite(2,LOW);
          Serial.println("Car Passed");
          break;
      }
      c_m = millis();
    }

  }
  else digitalWrite(2,HIGH);

}
