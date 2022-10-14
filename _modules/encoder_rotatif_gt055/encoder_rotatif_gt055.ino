int SW = 2;  //Switch
int A = 3;   //CLK
int B = 4;   //DT
int encoderPosCount = 0;
int aLast, aVal, btn, prevbtn;
bool bCW;

void setup() {
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(SW, INPUT_PULLUP);
  aLast = digitalRead(A);
  Serial.begin(9600);
  prevbtn = !btn;
}
void ReadBtn() {
  btn = digitalRead(SW);
  if (!btn && prevbtn != btn) {
    prevbtn = btn;
    Serial.println("Click !");
  }
  prevbtn = btn;
}
void ReadCode() {
  aVal = digitalRead(A);
  if (aVal != aLast) {
    if (digitalRead(B) != aVal) {
      encoderPosCount++;
      bCW = true;
    } else {
      bCW = false;
      encoderPosCount--;
    }
    Serial.print("Rotation: ");
    if (bCW) {
      Serial.print("Sens horaire");
    } else {
      Serial.print("Sens anti-horaire");
    }
    Serial.print("\t Position de l'encodeur: ");
    Serial.println(encoderPosCount);
  }
  aLast = aVal;
}
void loop() {
  ReadBtn();
  ReadCode();
}