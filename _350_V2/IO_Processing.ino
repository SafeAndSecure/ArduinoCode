void IO_Processing () {

// ---------------------- DGITIAL INPUTS --------------------------------- //
DI01State = digitalRead(DI01);
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
for (int i = 0; i<7; i++) {
  setupData[i] = packetBuffer[i];
}

// Map digital outputs from UDP array
for (int i = 0; i<7; i++) {
 bitSet(DOState[10], i) = bitRead(packetBuffer[4], i);
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



// Map digital inputs to send array
for (int i = 0; i<7; i++) {
  bitSet(ReplyBuffer[8], i) = bitRead(DIState[1], i);
  bitSet(ReplyBuffer[9], i) = bitRead(DIState[2], i);
}



// Map analogue inputs to send array
ReplyBuffer[11] = lowByte(AI01);
ReplyBuffer[12] = highByte(AI01);

ReplyBuffer[13] = lowByte(AI02);
ReplyBuffer[14] = highByte(AI02);

ReplyBuffer[15] = lowByte(AI03);
ReplyBuffer[16] = highByte(AI03);

ReplyBuffer[17] = lowByte(AI04);
ReplyBuffer[18] = highByte(AI04);

ReplyBuffer[19] = lowByte(AI05);
ReplyBuffer[20] = highByte(AI05);

ReplyBuffer[21] = lowByte(AI06);
ReplyBuffer[22] = highByte(AI06);

ReplyBuffer[23] = lowByte(AI07);
ReplyBuffer[24] = highByte(AI07);

ReplyBuffer[25] = lowByte(AI08);
ReplyBuffer[26] = highByte(AI08);

}

