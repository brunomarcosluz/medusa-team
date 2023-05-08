#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <ArduinoOTA.h>

const char* ssid         = "DV6G70XRPLJQ";
const char* password     = "Fbi2@19Cia";
const char* mqttServer   = "demo.thingsboard.io";
const int   mqttPort     = 1883;
const char* mqttUser     = "T3003";        //User name
const char* mqttPassword = "2023";         //Password
const char* mqttClient   = "Turma3003";    //ID

WiFiClient espClient;
PubSubClient client(espClient);
const int capacity = JSON_OBJECT_SIZE(21);
StaticJsonDocument<capacity> doc;

int contador = 1;
char mensagem[30];

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Iniciando conexao com a rede WiFi..");
  }
  Serial.println("Conectado na rede WiFi!");
}

void loop() {
  reconectabroker();

  doc["Dado0"] = random(100);
  doc["Dado1"] = random(100);
  doc["Dado2"] = random(100);
  doc["Dado3"] = random(100);
  doc["Dado4"] = random(100);
  doc["Dado5"] = random(100);
  doc["Dado6"] = random(100);
  doc["Dado7"] = random(100);
  doc["Dado8"] = random(100);
  doc["Dado9"] = random(100);

  String string1 = "v1/devices/me/telemetry";
  char Buf1[256];  string1.toCharArray(Buf1, 256);
  Serial.println(Buf1);

  char docBuffer1[256];
  size_t n = serializeJson(doc, docBuffer1);
  Serial.println(docBuffer1);
  client.publish(Buf1, docBuffer1, n);
  sprintf(mensagem, "MQTT ESP32 - Mensagem no. %d", contador);
  Serial.print("Mensagem enviada: ");
  Serial.println(mensagem);
  
  client.publish(Buf1, mensagem);
  Serial.println("Mensagem enviada com sucesso...");
  delay(1000);
  contador++; 
}

void reconectabroker() {
  client.publish("v1/devices/me/telemetry", mensagem);
  Serial.println(mensagem);
  String string1 = "v1/devices/me/telemetry";
  char Buf1[256];  
  string1.toCharArray(Buf1, 256);
  Serial.println(Buf1);
  client.setServer(mqttServer, mqttPort);
  
  while (!client.connected()) {
    Serial.println("Conectando ao broker MQTT...");  
    if (client.connect(mqttClient, mqttUser, mqttPassword )) {
      Serial.println("Conectado ao broker!");
    }else {
      Serial.print("Falha na conexao ao broker - Estado: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}