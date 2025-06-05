Smart Home Monitoring System (GIT Project MIT)
Overview
This is an IoT-based Smart Home Monitoring System built using an ESP8266 (e.g., NodeMCU) with Arduino. The system monitors temperature, humidity, and motion, sending data to a web server accessible via a browser. It also allows remote control of an LED. The project is modular, with separate files for sensor handling, WiFi configuration, and web server functionality.

Author: Jay Ian Camelotes
Features

Monitors temperature and humidity using a DHT11 sensor.
Detects motion using a PIR sensor.
Controls an LED remotely via a web interface.
Displays real-time sensor data on a web page.
Modular codebase for easy maintenance and scalability.

Hardware Requirements

ESP8266 (e.g., NodeMCU)
DHT11 temperature and humidity sensor
PIR motion sensor
LED (with appropriate resistor)
Breadboard and jumper wires

Software Requirements

Arduino IDE with ESP8266 board support
Libraries:
ESP8266WiFi
ESP8266WebServer
DHT sensor library by Adafruit



Project Structure

main.ino: Main sketch that initializes sensors, WiFi, and web server, and runs the main loop.
sensor.h / sensor.ino: Handles DHT11 and PIR sensor initialization and data reading.
wifi_config.h / wifi_config.ino: Manages WiFi connection setup.
web_server.h / web_server.ino: Implements the web server to display sensor data and control the LED.

Setup Instructions

Hardware Setup:

Connect DHT11 to pin D4.
Connect PIR sensor to pin D5.
Connect LED (with resistor) to pin D6.
Ensure proper wiring on a breadboard or custom PCB.


Software Setup:

Install the Arduino IDE and add ESP8266 board support via Boards Manager.
Install required libraries (ESP8266WiFi, ESP8266WebServer, DHT).
Open the project folder in Arduino IDE (all files must be in the same directory).


Configuration:

Edit wifi_config.h to include your WiFi credentials:const char* SSID = "YOUR_WIFI_SSID";
const char* PASSWORD = "YOUR_WIFI_PASSWORD";




Upload and Run:

Upload the sketch to your ESP8266 board.
Open the Serial Monitor (115200 baud) to view the IP address assigned to the ESP8266.
Access the IP address in a web browser to view sensor data and control the LED.



Usage

The web interface displays real-time temperature, humidity, and motion data.
Use the "Turn LED On" and "Turn LED Off" links to control the LED remotely.
Sensor data updates every 2 seconds (configurable in main.ino).

Future Enhancements

Add more sensors (e.g., light, gas).
Implement data logging to an SD card or cloud service.
Enhance the web interface with CSS and JavaScript for better visuals.
Add authentication to the web server for security.

Troubleshooting

WiFi not connecting: Verify SSID and password in wifi_config.h.
Sensor issues: Check wiring and ensure libraries are installed correctly.
Web server inaccessible: Confirm the IP address in the Serial Monitor and ensure your device is on the same network.

License
This project is open-source and available under the MIT License.
Contact
For questions or contributions, contact Jay Ian Camelotes via [insert preferred contact method, e.g., email or GitHub profile].
