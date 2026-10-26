/*
 *
 * This Arduino UNO R4 code is made available for public use without any restriction
 *
 */

#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "imaximumgooning_on_arduino_r4";     // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "nano9753";  // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "mqtt-dashboard.com";  // CHANGE TO MQTT BROKER'S ADDRESS
//const char MQTT_BROKER_ADRRESS[] = "192.168.0.11";  // CHANGE TO MQTT BROKER'S IP ADDRESS
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "uno-r4-bhumithong-client";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";              // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";              // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
const char PUBLISH_TOPIC[] = "arduino-uno-r4/send";       // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "kmitl/bhumithong/rgb";

const int PUBLISH_INTERVAL = 5000;  // 5 seconds

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

const int PIN_RED = 9, PIN_GREEN = 10, PIN_BLUE = 11;
bool stateR = false, stateG = false, stateB = false;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  updateLEDs();

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    Serial.print("Arduino UNO R4 - Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    // wait 10 seconds for connection:
    delay(10000);
  }
  // print your board's IP address:
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  connectToMQTT();
}

void updateLEDs() {
  digitalWrite(PIN_RED, stateR ? HIGH : LOW);
  digitalWrite(PIN_GREEN, stateG ? HIGH : LOW);
  digitalWrite(PIN_BLUE, stateB ? HIGH : LOW);
}

void loop() {
  mqtt.loop();

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT();
    lastPublishTime = millis();
  }
}

void connectToMQTT() {
  // Connect to the MQTT broker
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);

  // Create a handler for incoming messages
  mqtt.onMessage(messageReceived);

  Serial.print("Arduino UNO R4 - Connecting to MQTT broker");

  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  if (!mqtt.connected()) {
    Serial.println("Arduino UNO R4 - MQTT broker Timeout!");
    return;
  }

  // Subscribe to a topic, the incoming messages are processed by messageHandler() function
  if (mqtt.subscribe(SUBSCRIBE_TOPIC))
    Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  else
    Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  Serial.println(SUBSCRIBE_TOPIC);
  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void sendToMQTT() {

  int val = millis()/1000;
  //int val = analogRead(A0);
  String val_str = String(val);
  char messageBuffer[10];
  val_str.toCharArray(messageBuffer, 10);
  mqtt.publish(PUBLISH_TOPIC, messageBuffer);
  
  Serial.println("Arduino UNO R4 - sent to MQTT:");
  Serial.print("- topic: ");
  Serial.println(PUBLISH_TOPIC);
  Serial.print("- payload:");
  Serial.println(messageBuffer);
}

void messageReceived(String &topic, String &payload) {
  payload.trim();
  Serial.print("Received MQTT: ");
  Serial.println(payload);

  if (payload == "R_ON") stateR = true;
  else if (payload == "R_OFF") stateR = false;
  else if (payload == "G_ON") stateG = true;
  else if (payload == "G_OFF") stateG = false;
  else if (payload == "B_ON") stateB = true;
  else if (payload == "B_OFF") stateB = false;
  else if (payload == "PURPLE") { stateR = true;  stateG = false; stateB = true;  }
  else if (payload == "AMBER")  { stateR = true;  stateG = true;  stateB = false; }
  else if (payload == "CYAN")   { stateR = false; stateG = true;  stateB = true;  }
  else if (payload == "WHITE")  { stateR = true;  stateG = true;  stateB = true;  }
  else if (payload == "ALL_OFF"){ stateR = false; stateG = false; stateB = false; }

  updateLEDs(); // อัปเดตสถานะไฟทันที
}



