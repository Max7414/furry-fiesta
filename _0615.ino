byte Red8[8];
byte scan8[8];
byte Data[8];
int ii, jj;
int delaytime = 1;
void initMartix(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte p) {
  Red8[7] = a; Red8[6] = b; Red8[5] = c; Red8[4] = d; Red8[3] = e; Red8[2] = f; Red8[1] = g; Red8[0] = p;
  for  (int ii = 0; ii < 8; ii++) {
    pinMode(Red8[ii], OUTPUT);
    digitalWrite(Red8[ii], HIGH);
  }
}
void initScan(byte d7, byte d6, byte d5, byte d4, byte d3, byte d2, byte d1, byte d0) {
  scan8[0] = d7; scan8[1] = d6; scan8[2] = d5; scan8[3] = d4; scan8[4] = d3; scan8[5] = d2; scan8[6] = d1; scan8[7] = d0;
  for (int ii = 0; ii < 8; ii++) {
    pinMode(scan8[ii], OUTPUT);
    digitalWrite(scan8[ii], HIGH);
  }
}
void display(byte n0, byte n1, byte n2, byte n3, byte n4, byte n5, byte n6, byte n7) {
  Data[0] = n0; Data[1] = n1; Data[2] = n2; Data[3] = n3; Data[4] = n4; Data[5] = n5; Data[6] = n6; Data[7] = n7;
}
void ShowRed8(byte data) {
  for (int jj = 0; jj < 8; jj++) {
    digitalWrite(Red8[jj], data % 2 == 0);
    data = data >> 1;
  }
}

void Stay(int ms) {
  unsigned long last_T = millis();
  static byte ScanCnt = 0;
  while (millis() - last_T < ms) {
    ShowRed8(Data[ScanCnt]);
    digitalWrite(scan8[ScanCnt], 0);
    delay(delaytime);
    digitalWrite(scan8[ScanCnt], 1);
    ScanCnt++;
    if (ScanCnt == 8)ScanCnt = 0;
  }
}
void setup() {
  //initMartix(12, 13, A0, A1, A2, A3, 2, 3);
  
  initScan(4, 5, 6, 7, 8, 9, 10, 11);
}
void loop() {
  initMartix(22,24,26,28,30,32,34,36);
  display(48, 48, 30, 57, 72, 20, 34, 97);
  Stay(500);
  display(48, 48, 30, 59, 104, 20, 36, 34);
  Stay(500);
  display(48, 48, 28, 26, 40, 20, 36, 34);
  Stay(500);
  display(48, 48, 24, 28, 24, 12, 20, 36);
  Stay(500);
  display(48, 48, 24, 24, 24, 12, 12, 4);
  Stay(500);
  display(48, 48, 28, 24, 56, 12, 20, 18);
  Stay(500);
  display(48, 48, 28, 58, 88, 8, 20, 34);
  Stay(100);
  for (int i = 1; i <= 10; i++) {
    int x = 500;
    int y = x / i;
    display(96, 96, 48, 120, 24, 52, 34, 102);
    Stay(y);
    display(96, 96, 48, 124, 90, 52, 98, 66);
    Stay(y);
    display(96, 96, 48, 124, 178, 24, 102, 2);
    Stay(y);
    display(192, 192, 120, 98, 172, 40, 198, 2);
    Stay(y);
    display(192, 192, 96, 120, 180, 58, 38, 226);
    Stay(y);
    display(192, 192, 96, 120, 180, 58, 76, 196);
    Stay(y);
    display(192, 192, 96, 120, 116, 48, 88, 40);
    Stay(y);
    display(96, 96, 48, 56, 24, 20, 28, 4);
    Stay(y);
  }
  for(auto i=0;i<=36;i+=2)
  {
  digitalWrite(i,1);
  }
  initMartix(12, 13, A0, A1, A2, A3, 2, 3);
  display(24, 24, 60, 90, 90, 24, 52, 66);
  Stay(5000);
  closered();
}
void closered()
{
  for(auto j=0;j<=36;j+=2)
    digitalWrite(j,0);
  digitalWrite(12,1);
  digitalWrite(13,1);
  digitalWrite(A0,1);
  digitalWrite(A1,1);
  digitalWrite(A2,1);
  digitalWrite(A3,1);
  digitalWrite(2,1);
  digitalWrite(3,1);
}


