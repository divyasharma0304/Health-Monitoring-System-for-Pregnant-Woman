#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#define IP "184.106.153.149"  


const char *ssid = "divya";
const char *password = "hello123";
const char *thingSpeakApiKey = "G22R3YTE42TEIWV5";

const int sensorPin = A0;  // Analog pin to which the pulse sensor is connected
int bpm;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  ThingSpeak.begin(client);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  bpm = map(sensorValue, 0, 1023, 60, 120);


  ThingSpeak.setField(3, sensorValue);
  int response = ThingSpeak.writeFields(2335643, thingSpeakApiKey);

  if (response == 200) {
    Serial.println("Data sent to ThingSpeak successfully");
  } else {
    Serial.println("Error sending data to ThingSpeak. HTTP error code " + String(response));
  }

  delay(15000);  // Delay for 15 seconds before sending the next data point
}


int error;
int panic;
float Voltage;

const char *ssid = "divya";
const char *password = "hello123";
const char *thingSpeakApiKey = "G22R3YTE42TEIWV5";
String msg = "GET /update?key=G22R3YTE42TEIWV5"; 

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  ThingSpeak.begin(client);
}

void loop() {
   panic_button();
  start: //label
    error=0;
    //Resend if transmission is not completed
    if (error==1)
    {
      goto start; //go to label "start"
    } 

 delay(4000);
 
  ThingSpeak.setField(4, panic);
  int response = ThingSpeak.writeFields(2335643, thingSpeakApiKey);
  if (response == 200) {
    Serial.println("Data sent to ThingSpeak successfully");
  } else {
    Serial.println("Error sending data to ThingSpeak. HTTP error code " + String(response));
  }

  delay(15000);  // Delay for 15 seconds before sending the next data point
}

void panic_button()
{
  panic = digitalRead(D6);
    if(panic == HIGH)
    {
    Serial.println(panic);
      String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  Serial.println(cmd);
  delay(2000);

  cmd = msg ;
  cmd += "&field4=";    
  cmd += panic;
  cmd += "\r\n";

  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
   }
  else
  {
    Serial.println("AT+CIPCLOSE");
    //Resend...
    error=1;
  }

}
