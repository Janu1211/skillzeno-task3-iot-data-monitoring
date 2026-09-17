# Task 3 – IoT Data Monitoring

## Objective
To connect an ESP32 to Wi-Fi and send sensor data to an IoT cloud dashboard.

## Components Used
- ESP32
- DHT22 Temperature Sensor
- Wi-Fi
- ThingSpeak Cloud Dashboard

## Sensor Connection
- DHT22 VCC → ESP32 3.3V
- DHT22 DATA → GPIO 15
- DHT22 GND → ESP32 GND
- NC → Not Connected

## Working
The ESP32 connects to the Wokwi Wi-Fi network and reads temperature data from the DHT22 sensor.

The temperature reading is processed by the ESP32 and periodically sent to the ThingSpeak cloud dashboard using the Write API Key.

## Error Handling
- Displays "Sensor Error!" when an invalid DHT22 reading is detected.
- Displays "WiFi Disconnected!" when the Wi-Fi connection is unavailable.

## Cloud Monitoring
Temperature data is sent to ThingSpeak and displayed in Field 1.

## Simulation
The system is designed using Wokwi and ThingSpeak.