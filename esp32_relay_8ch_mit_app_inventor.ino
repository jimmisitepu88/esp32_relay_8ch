/*********
 name: Jimmi Kardo Sitepu
 date: 04 Feb 2020
 Complete project details at https://mikroavr.com   
*********/

// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid     = "RELAY_WIFI";
const char* password = "Relay@123";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

const byte REL1 = 5;
const byte REL2 = 18;
const byte REL3 = 19;
const byte REL4 = 21;

const byte REL5 = 22;
const byte REL6 = 23;
const byte REL7 = 17;
const byte REL8 = 16;

void setup() {
  Serial.begin(115200);
  delay(1000);
  // Initialize the output variables as outputs
  pinMode(REL1, OUTPUT);
  pinMode(REL2, OUTPUT);
  pinMode(REL3, OUTPUT);
  pinMode(REL4, OUTPUT);

  pinMode(REL5, OUTPUT);
  pinMode(REL6, OUTPUT);
  pinMode(REL7, OUTPUT);
  pinMode(REL8, OUTPUT);
  
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");    
  Serial.println(IP);
  
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /rel1/on") >= 0) {
              Serial.println("REL1 ON");
              digitalWrite(REL1, HIGH);
            } 
            else if (header.indexOf("GET /rel1/off") >= 0) {
              Serial.println("REL1 OFF");  
              digitalWrite(REL1, LOW);
            } 

            else if (header.indexOf("GET /rel2/on") >= 0) {
              Serial.println("REL2 ON");
              digitalWrite(REL2, HIGH);
            } 
            else if (header.indexOf("GET /rel2/off") >= 0) {
              Serial.println("REL2 OFF");  
              digitalWrite(REL2, LOW);
            }

            else if (header.indexOf("GET /rel3/on") >= 0) {
              Serial.println("REL3 ON");
              digitalWrite(REL3, HIGH);
            } 
            else if (header.indexOf("GET /rel3/off") >= 0) {
              Serial.println("REL3 OFF");  
              digitalWrite(REL3, LOW);
            }

            else if (header.indexOf("GET /rel4/on") >= 0) {
              Serial.println("REL4 ON");
              digitalWrite(REL4, HIGH);
            } 
            else if (header.indexOf("GET /rel4/off") >= 0) {
              Serial.println("REL4 OFF");
              digitalWrite(REL4, LOW);  
            }

            else if (header.indexOf("GET /rel5/on") >= 0) {
              Serial.println("REL5 ON");
              digitalWrite(REL5, HIGH);
            } 
            else if (header.indexOf("GET /rel5/off") >= 0) {
              Serial.println("REL5 OFF");  
              digitalWrite(REL5, LOW);
            }

            else if (header.indexOf("GET /rel6/on") >= 0) {
              Serial.println("REL6 ON");
              digitalWrite(REL6, HIGH);
            } 
            else if (header.indexOf("GET /rel6/off") >= 0) {
              Serial.println("REL6 OFF");  
              digitalWrite(REL6, LOW);
            }

            else if (header.indexOf("GET /rel7/on") >= 0) {
              Serial.println("REL7 ON");
              digitalWrite(REL7, HIGH);
            } 
            else if (header.indexOf("GET /rel7/off") >= 0) {
              Serial.println("REL7 OFF");
              digitalWrite(REL7, LOW);  
            }

            else if (header.indexOf("GET /rel8/on") >= 0) {
              Serial.println("REL8 ON");
              digitalWrite(REL8, HIGH);
            } 
            else if (header.indexOf("GET /rel8/off") >= 0) {
              Serial.println("REL8 OFF");  
              digitalWrite(REL8, LOW);
            }

            else if (header.indexOf("GET /rel2a/on") >= 0) {
              Serial.println("REL 2A ON");
              digitalWrite(REL1, HIGH);
              digitalWrite(REL2, HIGH);
            } 
            else if (header.indexOf("GET /rel2a/off") >= 0) {
              Serial.println("REL 2A OFF");  
              digitalWrite(REL1, LOW);
              digitalWrite(REL2, LOW);
            }

            else if (header.indexOf("GET /rel2b/on") >= 0) {
              Serial.println("REL 2B ON");
              digitalWrite(REL3, HIGH);
              digitalWrite(REL4, HIGH);
            } 
            else if (header.indexOf("GET /rel2b/off") >= 0) {
              Serial.println("REL 2B OFF");  
              digitalWrite(REL3, LOW);
              digitalWrite(REL4, LOW);
            }

            else if (header.indexOf("GET /rel2c/on") >= 0) {
              Serial.println("REL 2C ON");
              digitalWrite(REL5, HIGH);
              digitalWrite(REL6, HIGH);
            } 
            else if (header.indexOf("GET /rel2c/off") >= 0) {
              Serial.println("REL 2C OFF");
              digitalWrite(REL5, LOW);
              digitalWrite(REL6, LOW);  
            }

            else if (header.indexOf("GET /rel2d/on") >= 0) {
              Serial.println("REL 2D ON");
              digitalWrite(REL7, HIGH);
              digitalWrite(REL8, HIGH);
            } 
            else if (header.indexOf("GET /rel2d/off") >= 0) {
              Serial.println("REL 2D OFF");  
              digitalWrite(REL7, LOW);
              digitalWrite(REL8, LOW);
            }

            else if (header.indexOf("GET /rel4a/on") >= 0) {
              Serial.println("REL 4A ON");
              digitalWrite(REL1, HIGH);
              digitalWrite(REL2, HIGH);
              digitalWrite(REL3, HIGH);
              digitalWrite(REL4, HIGH);
            } 
            else if (header.indexOf("GET /rel4a/off") >= 0) {
              Serial.println("REL 4A OFF");  
              digitalWrite(REL1, LOW);
              digitalWrite(REL2, LOW);
              digitalWrite(REL3, LOW);
              digitalWrite(REL4, LOW);
            }

            else if (header.indexOf("GET /rel4b/on") >= 0) {
              Serial.println("REL 4B ON");
              digitalWrite(REL5, HIGH);
              digitalWrite(REL6, HIGH);
              digitalWrite(REL7, HIGH);
              digitalWrite(REL8, HIGH);
            } 
            else if (header.indexOf("GET /rel4b/off") >= 0) {
              Serial.println("REL 4B OFF");  
              digitalWrite(REL5, LOW);
              digitalWrite(REL6, LOW);
              digitalWrite(REL7, LOW);
              digitalWrite(REL8, LOW);
            }                      
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
