
#include <ESP8266WiFi.h>
#include <espnow.h>

// Integer for identification (make unique for each transmitter)
int ident = 1;

// REPLACE WITH RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xAC, 0x0B, 0xFB, 0xD3, 0x4F, 0x0B};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  bool CarPass;
} struct_message;

// Create a struct_message called myData
struct_message myData;

unsigned long lastTime = 0;  
unsigned long timerDelay = 10;  // send readings timer

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
 // Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0){
    Serial.println("Delivery success");
  }
  else{
    Serial.println("Delivery fail");
  }
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(9600);
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  pinMode(2,OUTPUT);
  pinMode(D1,INPUT);
  pinMode(D0,INPUT);

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}
 
void loop() {
  if ((millis() - lastTime) > timerDelay) {
  int s1,s2;
  int p_m,c_m;
  
  s1 = digitalRead(D1);
  if(s1==LOW){
    p_m = millis();
    c_m = millis();
    while(c_m-p_m < 1000){
       s2 = digitalRead(D0);
       if(s2==LOW){
          digitalWrite(2,LOW);
          myData.CarPass = true;
          Serial.println("Car Passed");
          esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
          break;
      }
      c_m = millis();
    }

  }
  else{
    digitalWrite(2,HIGH);
    myData.CarPass = false;
    esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

  }
    
  
  // Send message via ESP-NOW

  lastTime = millis();
 }
}
