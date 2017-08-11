void Setup () {

int CSValue = 0;

// The block below takes the 4 bit binary input and converts
// it into a number 0-15
if (digitalRead(CSB0) == HIGH) {
CSValue += 1; }
if (digitalRead(CSB1) == HIGH) {
CSValue += 2; }
if (digitalRead(CSB2) == HIGH) {
CSValue += 4; }
if (digitalRead(CSB3) == HIGH) {
CSValue += 8; }

// The block below sets the UDP port depending on the CSValue

localPort = 4002 ;
//+ CSValue;

// The block below sets the IP address depending on the CSValue

IPAddress ip(192,168,0,56);
//(101 + CSValue));

// Set Up UDP Communications
Ethernet.begin(mac, ip);
Udp.begin(localPort);

// Set Up Serial For Debugging

Serial.begin(115200);

// Set all array values to 0
for (int i = 0; i<15; i++) {
  DIState[i] = 0;
}

for (int i = 0; i<7; i++) {
  DOState[i] = 0;
}



  
}

