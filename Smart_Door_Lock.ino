/* roll no = BT18ECE035
* Last digit = 5
* binary eqivivalent = 0101
*/
#include "WiFi.h"
String password = "0101";
int startblink;
int touch;
int digits;
int val;
const char* ssid = "ESP_F1F175"; // wifi Name
const char* Password = "Aditya"; // wifi password
WiFiServer server(80);
// defining the html page
String success ="<!DOCTYPE html>\
<html> \
<body> \
<form> \
<h1>Welcome Home Aditya Wadichar</h1> \
</form> \
</body> \
</html>";
String nosuccess ="<!DOCTYPE html>\
<html> \
<body> \
<form> \
</form> \
</body> \
</html>";


void setup()
{
Serial.begin(115200); // baud rate
pinMode (4, INPUT); // setting pin 4 as input
pinMode (2, OUTPUT); // setting pin 2 as output to show output on built
WiFi.softAP(ssid, Password);
IPAddress IP = WiFi.softAPIP();
Serial.print("AP IP Address: ");
Serial.print(IP);
// printing ip address on which web page is created
server.begin();
}
void loop()
{
String passcheck= "";
String html = "";
startblink = 3;
for (startblink=3; startblink>0; startblink--)
{
digitalWrite(2, HIGH);
delay(1000);
digitalWrite(2, LOW);
delay(1000);
}
for (digits=4; digits>0; digits--)
{
digitalWrite(2, HIGH);
delay(500);
digitalWrite(2, LOW);
touch= touchRead(4); // reading the values
if (touch<70) val = 1;
else val = 0;
passcheck = passcheck + String(val);
delay(500);
}
Serial.print("passcheck is: ");
Serial.println(passcheck);
if (passcheck == password)
{
html = success;
nosuccess=success;
Serial.println("correct password");
}
else
{
html = nosuccess;
Serial.println("incorrect password");
}
WiFiClient client = server.available();
if(client)
{
String request = client.readStringUntil('\r'); // reading the request
client.print(html);
request="";
}
}
