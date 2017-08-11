

// Pin Definitions
byte DIState[2];
bool DI01 = 38; // General Digital Input 01
bool DI01State = false;
bool DI02 = 39; // General Digital Input 02
bool DI02State = false;
bool DI03 = 40; // General Digital Input 03
bool DI03State = false;
bool DI04 = 41; // General Digital Input 04
bool DI04State = false;
bool DI05 = 42; // General Digital Input 05
bool DI05State = false;
bool DI06 = 43; // General Digital Input 06
bool DI06State = false;
bool DI07 = 44; // General Digital Input 07
bool DI07State = false;
bool DI08 = 45; // General Digital Input 08
bool DI08State = false;
bool DI09 = 46; // General Digital Input 09
bool DI09State = false;
bool DI10 = 47; // General Digital Input 10
bool DI10State = false;
bool DI11 = 48; // General Digital Input 11
bool DI11State = false;
bool DI12 = 39; // General Digital Input 12
bool DI12State = false;

byte DOState [1];
bool DO01 = 22; // General Relay Output 01
bool DO01State = false;
bool DO02 = 23; // General Relay Output 02
bool DO02State = false;
bool DO03 = 24; // General Relay Output 03
bool DO03State = false;
bool DO04 = 25; // General Relay Output 04
bool DO04State = false;
bool DO05 = 26; // General Relay Output 05
bool DO05State = false;
bool DO06 = 27; // General Relay Output 06
bool DO06State = false;
bool DO07 = 28; // General Relay Output 07
bool DO07State = false;
bool DO08 = 29; // General Relay Output 08
bool DO08State = false;

const int PWM01 = 2; // General PWM Output 01
int PWM01Value = 0;
const int PWM02 = 3; // General PWM Output 02
int PWM02Value = 0;
const int PWM03 = 5; // General PWM Output 03
int PWM03Value = 0;
const int PWM04 = 6; // General PWM Output 04
int PWM04Value = 0;
const int PWM05 = 7; // General PWM Output 05
int PWM05Value = 0;
const int PWM06 = 8; // General PWM Output 06
int PWM06Value = 0;
const int PWM07 = 9; // General PWM Output 07
int PWM07Value = 0;
const int PWM08 = 11; // General PWM Output 08
int PWM08Value = 0;

bool ST01 = 30; // General Status 01
bool ST01State = false;
bool ST02 = 31; // General Status 02
bool ST02State = false;
bool ST03 = 32; // General Status 03
bool ST03State = false;
bool ST04 = 33; // General Status 04
bool ST04State = false;

bool CSB0 = 34; // Code Switch Bit 0
bool CSB0State = false;
bool CSB1 = 35; // Code Switch Bit 1
bool CSB1State = false;
bool CSB2 = 36; // Code Switch Bit 2
bool CSB2State = false;
bool CSB3 = 37; // Code Switch Bit 3
bool CSB3State = false;

int AI01 = A0; // Analogue Input 01
int AI01Value = 0;
int AI02 = A1; // Analogue Input 02
int AI02Value = 0;
int AI03 = A2; // Analogue Input 03
int AI03Value = 0;
int AI04 = A3; // Analogue Input 04
int AI04Value = 0;
int AI05 = A4; // Analogue Input 05
int AI05Value = 0;
int AI06 = A5; // Analogue Input 06
int AI06Value = 0;
int AI07 = A6; // Analogue Input 07
int AI07Value = 0;
int AI08 = A7; // Analogue Input 08
int AI08Value = 0;

byte setupData[7];

int temp = 0;

