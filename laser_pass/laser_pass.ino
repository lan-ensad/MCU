const int AS = 20;   //Taille du tableau de valeurs pour la moyenne
const int LDR = A0;  //pin ldr
const int LASER = 2; //pin Laser
const int T = 200; //l'écart entre 2 remplissages (en milliseconde)
const int THRESHOLD = 50; //seuil pour lequel on trigger 'state' (en degré)
const int TIMING = T * 2 - 1; //relax entre un trigger et un autre (en millis)

float valArray [AS];
float ldrValue;
float average = 0;
float av1, av2;

bool odd = true;
bool firstLoop = true;
bool state, prevState, switchin;

unsigned long tDiff;

void setup() {
  pinMode(LDR, INPUT);
  pinMode(LASER, OUTPUT);
  digitalWrite(LASER, HIGH);

  Serial.begin(9600);
  InitCalibration();
}

void loop() {
  if (millis() % T == 0) {
    FillBuffer();

    //1 fois sur 2 on rempli av1 puis av2
    if (odd)av1 = average;
    else av2 = average;
    odd = !odd;

    //changement de 'state' en fonction de 'CosClculation'l.53
    if (!firstLoop) {
      prevState = state;
      if (degrees(CosCalculation()) > THRESHOLD) {
        state = !state;
        switchin = true;
        tDiff = millis();
        if (millis() - tDiff < TIMING && switchin == true) {
          switchin = false;
          Serial.println("TRIGGERED");
        }
      }
    } else {
      firstLoop = false;
    }
    Serial.print(prevState); Serial.print("pS - S"); Serial.println(state);
  }
}

void FillBuffer() {
  ldrValue = analogRead(LDR);
  int sum = 0;
  for (int i = 0; i < AS; i++) {
    valArray[i] = ldrValue;
    sum += ldrValue;
  }
  average = abs(sum / AS);
}

double CosCalculation() {
  int d = 0;
  int cosA;
  if (av1 > av2)d = abs(av1 - av2);
  else d = abs(av2 - av1);
  cosA = 200 / d;

  return cos(cosA);
}

void InitCalibration() {
  Serial.println("...CALIBRATION...");
  state = 0;

  digitalWrite(LASER, LOW);
  delay(1000);
  Serial.println("__Laser Off__");
  for (int i = 1; i < 4; i++) {
    FillBuffer();
    Serial.print("wave : "); Serial.println(i);
    delay(500);
  }

  digitalWrite(LASER, HIGH);
  delay(1000);
  Serial.println("__Laser On__");
  for (int i = 1; i < 4; i++) {
    FillBuffer();
    Serial.print("wave : "); Serial.println(i);
    delay(500);
  }
}
