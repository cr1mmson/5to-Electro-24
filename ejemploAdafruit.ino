#include "AdafruitIO_WiFi.h"

#define IO_USERNAME ""
#define IO_KEY ""

#define WIFI_SSID ""
#define WIFI_PASS ""

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

AdafruitIO_Feed *gas  = io.feed("ac");

void setup(){

  Serial.begin(115200);
  Serial.print("Conectando a AdafruitIO");
  io.connect();
  
  while(io.status() < AIO_CONNECTED){
      Serial.print(".");
      delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());
}

void loop(){
  io.run();
  envio_datos();
}

void envio_datos(){
  float pot=analogRead(30);
  Serial.println(pot);
  gas->(pot); 
}
