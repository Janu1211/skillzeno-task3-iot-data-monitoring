#include <WiFi.h>
#include <HTTPClient.h>


#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wokwi-GUEST";
const char* password = "";

String apiKey = "RKQQEJAOZR44YX25";

void setup()
{
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");
}

void loop()
{
  float temperature = dht.readTemperature();

  if (isnan(temperature))
  {
    Serial.println("Sensor Error!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    String url = "http://api.thingspeak.com/update?api_key=";
    url += apiKey;
    url += "&field1=";
    url += String(temperature);

    http.begin(url);

    int response = http.GET();

    Serial.print("ThingSpeak Response: ");
    Serial.println(response);

    http.end();
  }
  else
  {
    Serial.println("WiFi Disconnected!");
  }

  delay(15000);
}