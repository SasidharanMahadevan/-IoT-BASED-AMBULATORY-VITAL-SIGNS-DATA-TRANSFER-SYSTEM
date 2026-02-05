#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

#define REPORTING_PERIOD_MS 16000  // ThingSpeak free account: 1 update/15 sec

PulseOximeter pox;

const int outputPin = A0;
const int ledPin = LED_BUILTIN;

unsigned long lastReportTime = 0;

// ThingSpeak credentials
char thingSpeakAddress[] = "api.thingspeak.com";
unsigned long channelID = 2532839;
const char* writeAPIKey = "H7SRQRNE1Q07QJNE";

const char* ssid = "Sasi";
const char* password = "SASI1234";

WiFiClient client;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  if (!pox.begin()) {
    Serial.println("MAX30100 not found!");
    while (1);
  }

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  pox.setOnBeatDetectedCallback(onBeatDetected);

  ThingSpeak.begin(client);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  pox.update();

  if (millis() - lastReportTime > REPORTING_PERIOD_MS) {
    lastReportTime = millis();

    int ecgValue = analogRead(outputPin);
    float spo2 = pox.getSpO2();
    float heartRate = pox.getHeartRate();

    Serial.print("ECG: "); Serial.print(ecgValue);
    Serial.print("  SpO2: "); Serial.print(spo2);
    Serial.print("  Heart Rate: "); Serial.println(heartRate);

    // Upload all 3 fields in one request
    ThingSpeak.setField(1, ecgValue);
    ThingSpeak.setField(2, spo2);
    ThingSpeak.setField(3, heartRate);
    int response = ThingSpeak.writeFields(channelID, writeAPIKey);

    if (response == 200) {
      Serial.println("Data sent to ThingSpeak");
    } else {
      Serial.print("Error sending data: ");
      Serial.println(response);
    }
  }
}

void onBeatDetected() {
  digitalWrite(ledPin, HIGH);
  delay(20);
  digitalWrite(ledPin, LOW);
}
