byte Red8[8];
byte scan[8];
byte Data[8];
int ii, jj;
char rorg = 'g';
char prorg;
int times = 60;
int delaytime = 1;

void Stay(int ms)
{
  unsigned long last_T = millis();
  static byte ScanCnt = 0;
  while (millis() - last_T < ms) {
    ShowRed8(Data[ScanCnt]);
    digitalWrite(scan[ScanCnt], 0);
    delay (delaytime);
    digitalWrite (scan [ScanCnt], 1) ;
    ScanCnt++;
    if (ScanCnt == 8) ScanCnt = 0;
  }
}
void initMatrix(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte p)
{
  Red8[7] = a; Red8[6] = b; Red8[5] = c; Red8[4] = d;
  Red8[3] = e; Red8[2] = f; Red8[1] = g; Red8[0] = p;
  for (ii = 0; ii < 8; ii++)
  {
    pinMode(Red8[ii], OUTPUT);
    digitalWrite(Red8[ii], HIGH);
  }
}

void initScan(byte d7, byte d6, byte d5, byte d4, byte d3, byte d2, byte d1, byte d0)
{
 
  scan[0] = d7; scan[1] = d6; scan[2] = d5; scan[3] = d4;
  scan[4] = d3; scan[5] = d2; scan[6] = d1; scan[7] = d0;
  for (ii = 0; ii < 8; ii++)
  {
    pinMode(scan[ii], OUTPUT);
    digitalWrite(scan[ii], HIGH);
  }
}

void display (byte n0, byte n1, byte n2, byte n3, byte n4, byte n5, byte n6, byte n7)
{
  Data[0] = n0; Data[1] = n1; Data[2] = n2; Data[3] = n3;
  Data[4] = n4; Data[5] = n5; Data[6] = n6; Data[7] = n7;
}
void ShowRed8 (byte data) {
  for (jj = 0; jj < 8; jj++) {
    digitalWrite (Red8[jj], data % 2 == 0);
    data = data >> 1;
  }
}


void setup() {
  Serial.begin (9600);
//  if (rorg == 'r')
//    initMatrix(22, 24, 26, 28, 30, 32, 34, 36);
//  else
//    initMatrix(13, 12, A0, A1, A2, A3, 3, 2);
  initScan(4, 5, 6, 7, 8, 9, 10, 11);

  
}

void loop() {
  if (Serial.available() > 0) {
     rorg = Serial.readStringUntil('\n').toInt ();
     Serial.print (rorg);
    }
  
  
  
  
   if (rorg == 'r') {
    initMatrix(22, 24, 26, 28, 30, 32, 34, 36);
    display (24, 24, 60, 90, 24, 60, 36, 36);
    Stay(100);
  }
  else
  {
    initMatrix(13, 12, A0, A1, A2, A3, 3, 2);
    display (48, 48, 24, 24, 56, 24, 28, 16);
    Stay(100);
    display (48, 48, 24, 28, 60, 56, 36, 4);
    Stay(100);
    display (48, 48, 28, 122, 24, 40, 36, 34);
    Stay(100);
    }

}

//void cc()
//{
//  if(rorg=='r')
//    initMatrix(22, 24, 26, 28, 30, 32, 34, 36);
//   else
//    initMatrix(13, 12, A0, A1, A2, A3, 3, 2);
//}




