/*
    Program IoT - Termometer LM35 Blynk Based On NodeMCU v3 Lolin
*/
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define PIN_UPTIME V6
BLYNK_READ(PIN_UPTIME){
    Blynk.virtualWrite(PIN_UPTIME, millis() / 1000); // Uptime in seconds
}

char auth[] = "XXXX";       // masukkan kode autentikasi Blynk
char ssid[] = "Veendy-Suseno";  // nama wifi
char pass[] = "12345admin";  // password wifi

BlynkTimer timer;

void myTimerEvent() {  // Deklarasi Pembacaan Sensor
    int analogValue = analogRead(A0); // Pembacaan LM35
    float millivolts = (analogValue / 1024.0) * 3300; 
    float celsius = millivolts / 10;
    Blynk.virtualWrite(V5, celsius); // Kirim suhu ke Blynk (V5)
}

void setup() {
    Serial.begin(9600); // Untuk debugging
    Blynk.begin(auth, ssid, pass); // Koneksi ke Blynk dan Wi-Fi
    timer.setInterval(1000L, myTimerEvent); // Jalankan event pembacaan setiap 1 detik
}

void loop() {
    Blynk.run();  // Jalankan Blynk
    timer.run();  // Jalankan timer
}
