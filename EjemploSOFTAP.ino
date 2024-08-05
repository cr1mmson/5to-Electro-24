#include <WiFi.h>
#include <WebServer.h>

const char * ssid = "x";
const char * password = " ";

IPAdress ip(192,168,4,22);
IPAdress gateway(192,168,4,2);
IPAdress subnet(255,255,255);

WebServer miservidor(80);

void setup() {

Serial.println(115200);

//INICIALIZACIÓN DEL ACCESS POINT
WiFi.softAP(ssid,password);
WiFi.softAPConfig(ip, gateway, subnet);

Serial.println("SSID" + String(ssid));

miservidor.on("/", handleConnectionRoot)


}

void loop() {

  server.handleClient();

}

String respuestea = "<!DOCTYPE html>\
  <html>\
  <body>\
  <h1>EJEMPLO<\h1>\
  <\body>\
  <\html>";

void handleConnectionRoot(){

  miservidor.send(200, "text/html", respuesta)

}
