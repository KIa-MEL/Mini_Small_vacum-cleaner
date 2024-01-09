#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Kianoosh-Android";
const char* password = "123456789";

const char* host = "kia-iot.iran.liara.run";
const int port = 443;

WiFiClientSecure client;
String tmprchAndHmdtStr;
void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  Serial.begin(115200);
  Serial.println("A");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: " + WiFi.localIP().toString());

  // Make sure the client is not connected before connecting again
  if (!client.connected()) {
    client.connect(host, port);
  }
  Serial.println("Client connected");
  client.setInsecure();
}

void loop() {
  if(Serial.available() == 1)
  {
    tmprchAndHmdtStr = Serial.readString();
    tmprchAndHmdtStr.trim();
    // Check if the client is connected
    if (!client.connected()) {
      // If not connected, try to reconnect
      client.connect(host, port);
      // Wait for a moment before sending the request
      delay(100);
    }

    // Send request and process response
    Serial.print(tmprchAndHmdtStr);
    sendRequest(tmprchAndHmdtStr);
    // processResponse();
    delay(3000);
  }
}

void sendRequest(String tmprchAndHmdtStr) {
  // Send HTTP GET request to the server
  String temp = "GET /kia_room/" + tmprchAndHmdtStr + "/hc05/ HTTP/1.1";
  Serial.println(temp);
  client.println(temp);
  client.println("Host: kia-iot.iran.liara.run");
  client.println("User-Agent: ESP8266Client");  // Set your custom User-Agent here
  client.println("Connection: close");
  client.println();
}

void processResponse() 
{
  // Wait for the response to be available
  while (client.connected() && !client.available())
    delay(1);

  String response;
  while (client.available()) 
    response = client.readStringUntil('\n');


    Serial.println(response);

    // if (response == "on" != -1) 
    //   digitalWrite(2, HIGH);
    // else 
    //   digitalWrite(2, LOW);
    

}
