
#include <ESP8266WiFi.h>
#include <espnow.h>

typedef struct struct_message {
  bool CarPass;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  
  if(myData.CarPass){
    digitalWrite(2,LOW);
    Serial.println("STOP");
    delay(5000);
  }
  else{
    digitalWrite(2,HIGH);
    //Serial.println("Clear");
  }
}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);

  
}

void loop() {
  

}
