const int AS = 20;   //Taille du tableau de valeurs pour la moyenne
const int LDR = A0;  //pin ldr
const int LASER = 2; //pin Laser
const int T = 200; //l'écart entre 2 remplissages (en milliseconde)
const int THRESHOLD = 50; //seuil pour lequel on trigger 'state' (en degré)

float valArray [AS];
float ldrValue;
float average = 0;

float av1, av2;
bool odd = true;
bool firstLoop = true;

int state = 0;

void setup() {
  pinMode(LDR, INPUT);
  pinMode(LASER, OUTPUT);
  digitalWrite(LASER, HIGH);

  FillBuffer();
  Serial.begin(9600);
  state = 0;
}

void loop() {
  if (millis() % T == 0) {
    FillBuffer();

    //1 fois sur 2 on rempli av1 puis av2
    if (odd)av1 = average;
    else av2 = average;
    odd = !odd;
    //Serial.print(odd); Serial.print(" 1 : "); Serial.print(av1); Serial.print(" 2 : "); Serial.println(av2);
    //Serial.print(" cos : ");
    //Serial.println(CosCalulation());


    if (!firstLoop) {
      if (degrees(CosCalculation()) > THRESHOLD)state = !state;
      Serial.println(state);
    }else firstLoop = false;
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
