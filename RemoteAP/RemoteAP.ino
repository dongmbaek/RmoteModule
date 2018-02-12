#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "JYPNODEMCU";
const char *password = "123456789";
const char indexsource[] =
"<!DOCTYPE HTML>"
"<html>"
"<head>"
"<meta name = \"viewport\" content = \"width = device-width, initial-scale = 1.0, maximum-scale = 1.0, user-scalable=0\">"
"<titleETRI REMOTE SERVER</title>"
"<style>"
"\"body { background-color: #808080; font-family: Arial, Helvetica, Sans-Serif; Color: #000000; }\""
"</style>"
"</head>"
"<body>"
"<h1>ETRI REMOTEcon</h1>"
"<FORM action=\"/\" method=\"post\">"
"<P>"
"<INPUT type=\"button\" onclick=\"location.href='/tvcon'\" value=\"TV\">"
"<INPUT type=\"button\" onclick=\"location.href='/aircon'\" value=\"Aircon\">"
"</P>"
"</FORM>"
"</body>"
"</html>";

const char tvsource[] =
"<!DOCTYPE HTML>"
"<html>"
"<head>"
"<meta name = \"viewport\" content = \"width = device-width, initial-scale = 1.0, maximum-scale = 1.0, user-scalable=0\">"
"<titleETRI REMOTE SERVER</title>"
"<style>"
"\"body { background-color: #808080; font-family: Arial, Helvetica, Sans-Serif; Color: #000000; }\""
"</style>"
"</head>"
"<body>"
"<h1>TV MODE ON</h1>"
"<FORM action=\"/\" method=\"post\">"
"<P>"
"</P>"
"</FORM>"
"</body>"
"</html>";

ESP8266WebServer server(80);

void indexpg() {
  server.send(200,"text/html", indexsource);
}

void tvpg() {
  server.send(200,"text/html", tvsource);
}

void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", indexpg);
  server.on("/tvcon", tvpg);
	server.begin();
	Serial.println("-----------ETRI REMOTE Server Started--------");
}

void loop() {
	server.handleClient();
}
