

#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008


byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

unsigned int localPort = 0;

// buffers for receiving and sending data
byte packetBuffer[UDP_TX_PACKET_MAX_SIZE];  //buffer to hold incoming packet,
byte  ReplyBuffer[64];      // Reply buffer 64 bytes in length

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;



void setup() {

PinDef ();
Setup ();

}

void loop() {


UDP_Recieve ();
IO_Processing ();
UDP_Send ();

}





