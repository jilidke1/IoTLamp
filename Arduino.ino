
#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

const char* ssid = "yo wifi";
const char* pw = "yo passwordo";


const int espled = 2;
const int ledpin1 = 13;
const int ledpin2 = 27;
const int ledpin3 = 14;
const int ledpin4 = 26;

bool dapurledstate = false;
bool tamuledstate = false;
bool makanledstate = false;
bool kamarledstate = false;

void setup() {
  Serial.begin(115200);

  pinMode(espled,OUTPUT);
  pinMode(ledpin1, OUTPUT); 
  pinMode(ledpin2, OUTPUT); 
  pinMode(ledpin3, OUTPUT);
  pinMode(ledpin4, OUTPUT);  // put your setup code here, to run once:

  digitalWrite(ledpin1,LOW);
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin3,LOW);
  digitalWrite(ledpin4,LOW);


  WiFi.begin(ssid,pw);
  Serial.print("Konek ke wifi;");

  while(WiFi.status() != WL_CONNECTED){
    digitalWrite(espled,LOW);
    delay(1000);
    Serial.print(".");
  }
    digitalWrite(espled,HIGH);
  Serial.println("");
  Serial.println("Konek ke wifi cuyyy: ");
  Serial.println(WiFi.localIP());

  server.on("/dapur", HTTP_GET, getdapurled);
  server.on("/tamu", HTTP_GET, gettamuled);
  server.on("/makan", HTTP_GET,getmakanled);
  server.on("/kamar", HTTP_GET,getkamarled);

  server.on("/dapur",HTTP_POST, SetDapurLed);
  server.on("/tamu",HTTP_POST, SetTamuLed);
  server.on("/makan",HTTP_POST, SetMakanLed);
  server.on("/kamar",HTTP_POST, SetKamarLed);

  server.begin();
  Serial.println("Servernya mulai...");

}

void loop() {
  server.handleClient();


}

void SetDapurLed(){
  dapurledstate = !dapurledstate;
  // true = high dan sebaliknya
  digitalWrite(ledpin1,dapurledstate ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200, "text/plain", dapurledstate ? "ON" : "OFF");
}

void SetTamuLed(){
  tamuledstate = !tamuledstate;
  // true = high dan sebaliknya
  digitalWrite(ledpin2,tamuledstate ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200, "text/plain", tamuledstate ? "ON" : "OFF");
}

void SetMakanLed(){
  makanledstate = !makanledstate;
  // true = high dan sebaliknya
  digitalWrite(ledpin3,makanledstate ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200, "text/plain", makanledstate ? "ON" : "OFF");
}

void SetKamarLed(){
  kamarledstate = !kamarledstate;
  // true = high dan sebaliknya
  digitalWrite(ledpin4,kamarledstate ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200, "text/plain", kamarledstate ? "ON" : "OFF");
}

void getdapurled(){
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200, "text/plain", dapurledstate ? "ON" : "OFF");
}

void gettamuled(){
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200, "text/plain", tamuledstate ? "ON" : "OFF");
}

void getmakanled(){
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200, "text/plain", makanledstate ? "ON" : "OFF");
}

void getkamarled(){
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200, "text/plain", kamarledstate ? "ON" : "OFF");
}


