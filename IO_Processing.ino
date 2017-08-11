void IO_Processing () {

// ---------------------- DGITIAL INPUTS --------------------------------- //
DI01State = digitalRead(38);
if (DI01State == true) {
  bitSet(DIState[1], 0);
}

DI02State = digitalRead(DI02);
if (DI02State == true) {
  bitSet(DIState[1], 1);
}
DI03State = digitalRead(DI03);
if (DI03State == true) {
  bitSet(DIState[1], 2);
}
DI04State = digitalRead(DI04);
if (DI04State == true) {
  bitSet(DIState[1], 3);
}
DI05State = digitalRead(DI05);
if (DI05State == true) {
  bitSet(DIState[1], 4);
}
DI06State = digitalRead(DI06);
if (DI06State == true) {
  bitSet(DIState[1], 5);
}
DI07State = digitalRead(DI07);
if (DI07State == true) {
  bitSet(DIState[1], 6);
}
DI08State = digitalRead(DI08);
if (DI08State == true) {
  bitSet(DIState[1], 7);
}
DI09State = digitalRead(DI09);
if (DI09State == true) {
  bitSet(DIState[2], 0);
}
DI10State = digitalRead(DI10);
if (DI10State == true) {
  bitSet(DIState[2], 1);
}
DI11State = digitalRead(DI11);
if (DI11State == true) {
  bitSet(DIState[2], 2);
}
DI12State = digitalRead(DI12);
if (DI12State == true) {
  bitSet(DIState[2], 3);
}

// ---------------------- DGITIAL OUTPUTS ------------------------------ //
if (bitRead(DOState[1], 0) == true)
{
  DO01State == true;
}
digitalWrite(DO01, DO01State);
if (bitRead(DOState[1], 1) == true)
{
  DO02State == true;
}
digitalWrite(DO02, DO02State);
if (bitRead(DOState[1], 2) == true)
{
  DO03State == true;
}
digitalWrite(DO03, DO03State);
if (bitRead(DOState[1], 3) == true)
{
  DO04State == true;
}
digitalWrite(DO04, DO04State);
if (bitRead(DOState[1], 4) == true)
{
  DO05State == true;
}
digitalWrite(DO05, DO05State);
if (bitRead(DOState[1], 5) == true)
{
  DO06State == true;
}
digitalWrite(DO06, DO06State);
if (bitRead(DOState[1], 6) == true)
{
  DO07State == true;
}
digitalWrite(DO07, DO07State);
if (bitRead(DOState[1], 7) == true)
{
  DO08State == true;
}
digitalWrite(DO08, DO08State);

// ---------------------- ANALOGUE INPUTS ------------------------------ //

AI01Value = analogRead(AI01);
AI02Value = analogRead(AI02);
AI03Value = analogRead(AI03);
AI04Value = analogRead(AI04);
AI05Value = analogRead(AI05);
AI06Value = analogRead(AI06);
AI07Value = analogRead(AI07);
AI08Value = analogRead(AI08);




  //Serial.print(AI08Value);




// ---------------------- ANALOGUE OUTPUTS ------------------------------ //

analogWrite(PWM01, PWM01Value);
analogWrite(PWM02, PWM02Value);
analogWrite(PWM03, PWM03Value);
analogWrite(PWM04, PWM04Value);
analogWrite(PWM05, PWM05Value);
analogWrite(PWM06, PWM06Value);
analogWrite(PWM07, PWM07Value);
analogWrite(PWM08, PWM08Value);

// ---------------------- MAP FROM UDP PACKET ------------------------------ //

// Map setup data from UDP array
for (int i = 0; i<3; i++) {
  setupData[i] = packetBuffer[i];
}

// Map digital outputs from UDP array
for (int i = 0; i<8; i++) {
 bitSet(DOState[1], i) = bitRead(packetBuffer[4], i);
}

// Map Analogue outputs from UDP array
lowByte(PWM01) == packetBuffer[27];
highByte(PWM01) == packetBuffer[28];

lowByte(PWM02) == packetBuffer[29];
highByte(PWM02) == packetBuffer[30];

lowByte(PWM03) == packetBuffer[31];
highByte(PWM03) == packetBuffer[32];

lowByte(PWM04) == packetBuffer[33];
highByte(PWM04) == packetBuffer[34];

lowByte(PWM05) == packetBuffer[35];
highByte(PWM05) == packetBuffer[36];

lowByte(PWM06) == packetBuffer[37];
highByte(PWM06) == packetBuffer[38];

lowByte(PWM07) == packetBuffer[39];
highByte(PWM07) == packetBuffer[40];

lowByte(PWM08) == packetBuffer[41];
highByte(PWM08) == packetBuffer[42];

// ---------------------- MAP TO UDP PACKET ------------------------------ //

// Map status bits to send array



// Map digital inputs/outputs to send array
for (int i = 0; i<13; i++) {
  bitSet(ReplyBuffer[2], i) = bitRead(DIState[1], i);
  bitSet(ReplyBuffer[3], i) = bitRead(DIState[2], i);
  bitSet(ReplyBuffer[4], i) = bitRead(DOState[1], i);
}



// Map analogue inputs to send array
ReplyBuffer[5] = 26;
ReplyBuffer[6] = highByte(AI01Value);

ReplyBuffer[7] = lowByte(AI02);
ReplyBuffer[8] = highByte(AI02);

ReplyBuffer[9] = lowByte(AI03);
ReplyBuffer[10] = highByte(AI03);

ReplyBuffer[11] = lowByte(AI04);
ReplyBuffer[12] = highByte(AI04);

ReplyBuffer[13] = lowByte(AI05);
ReplyBuffer[14] = highByte(AI05);

ReplyBuffer[15] = lowByte(AI06);
ReplyBuffer[16] = highByte(AI06);

ReplyBuffer[17] = lowByte(AI07);
ReplyBuffer[18] = highByte(AI07);

ReplyBuffer[19] = lowByte(AI08Value);
ReplyBuffer[20] = highByte(AI08Value);

// Map PWM outputs to send array
ReplyBuffer[21] = lowByte(PWM01);
ReplyBuffer[22] = highByte(PWM01);

ReplyBuffer[23] = lowByte(PWM02);
ReplyBuffer[24] = highByte(PWM02);

ReplyBuffer[25] = lowByte(PWM03);
ReplyBuffer[26] = highByte(PWM03);

ReplyBuffer[27] = lowByte(PWM04);
ReplyBuffer[28] = highByte(PWM04);

ReplyBuffer[29] = lowByte(PWM05);
ReplyBuffer[30] = highByte(PWM05);

ReplyBuffer[31] = lowByte(PWM06);
ReplyBuffer[32] = highByte(PWM06);

  EthernetClient client = server.available();  // try to get client

    if (client) {  // got client?
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read(); // read 1 byte (character) from client
                // limit the size of the stored received HTTP request
                // buffer first part of HTTP request in HTTP_req array (string)
                // leave last element in array as 0 to null terminate string (REQ_BUF_SZ - 1)
                if (req_index < (REQ_BUF_SZ - 1)) {
                    HTTP_req[req_index] = c;          // save HTTP request character
                    req_index++;
                }
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) {
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    // remainder of header follows below, depending on if
                    // web page or XML page is requested
                    // Ajax request - send XML file
                    if (StrContains(HTTP_req, "ajax_inputs")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/xml");
                        client.println("Connection: keep-alive");
                        client.println();
                        //SetLEDs();
                        // send XML file containing input states
                        XML_response(client);
                    }
                    else {  // web page request
                        // send rest of HTTP header
                        client.println("Content-Type: text/html");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send web page
                        webFile = SD.open("index.htm");        // open web page file
                        if (webFile) {
                            while(webFile.available()) {
                                client.write(webFile.read()); // send web page to client
                            }
                            webFile.close();
                        }
                    }
                    // display received HTTP request on serial port
                    Serial.print(HTTP_req);
                    // reset buffer index and all buffer elements to 0
                    req_index = 0;
                    StrClear(HTTP_req, REQ_BUF_SZ);
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)

// send the XML file with analog values, switch status
//  and LED status
void XML_response(EthernetClient cl)
{
    int analog_val;            // stores value read from analog inputs
    int count;                 // used by 'for' loops
    int sw_arr[] = {2, 3};  // pins interfaced to switches
    
    cl.print("<?xml version = \"1.0\" ?>");
    cl.print("<inputs>");
    // checkbox LED states
    // LED1
    cl.print("<LED>");
    if (DI01State[0]) {
        cl.print("checked");
    }
    else {
        cl.print("unchecked");
    }
    cl.println("</LED>");
    // button LED states
    // LED3
    cl.print("<LED>");
    if (DI01State[0]) {
        cl.print("on");
    }
    else {
        cl.print("off");
    }
    cl.println("</LED>");
    cl.print("</inputs>");
}

// sets every element of str to 0 (clears array)
void StrClear(char *str, char length)
{
    for (int i = 0; i < length; i++) {
        str[i] = 0;
    }
}

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind)
{
    char found = 0;
    char index = 0;
    char len;

    len = strlen(str);
    
    if (strlen(sfind) > len) {
        return 0;
    }
    while (index < len) {
        if (str[index] == sfind[found]) {
            found++;
            if (strlen(sfind) == found) {
                return 1;
            }
        }
        else {
            found = 0;
        }
        index++;
    }

    return 0;
}

}

