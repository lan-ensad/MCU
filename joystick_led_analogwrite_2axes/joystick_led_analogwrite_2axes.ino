#define X A0 // définit l'entrée de l'axe X joystick
#define Y A1  // définit l'entrée de l'axe Y joystick
#define LED1 9
#define LED2 10

//Position des différents objets {x, y}
const int L1 [] = {200, -100};
const int L2 [] = { -200, 300};

//Définition du rayon des différents objets
int r1 = 200;
int r2 = 340;

//Distance des différents objets
int m1, m2, m3, m4;

//Valeure à envoyées aux moteurs
int val1, val2, val3, val4;

int joyX, joyY; //variable du joystick

int defVal = 30;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  //----------------------------------
  //Récupération des infos du joystick
  joyX = map(analogRead(X), 0, 1023, -512, 512);
  joyY = map(analogRead(Y), 0, 1023, -512, 512);

  //------------------
  //calcul de distance
  m1 = int(DistCalc(joyX, joyY, L1[0], L1[1]));
  m2 = int(DistCalc(joyX, joyY, L2[0], L2[1]));

  //--------------------------------
  //Envoie des valeur
  //Conditionnelle de positionnement
  //--------------------------------
  if (m1 <= r1 && m1 >= 0) {
    val1 = map(m1, 0, r1, 255, 0);
    Serial.print("M1 : ");
    Serial.println(val1);
    analogWrite(LED1, val1);
  } else {
    val1 = defVal;
    val2 = defVal;
  }
  //---------------------------
  if (m2 <= r2 && m2 >= 0) {
    val2 = map(m2, 0, r2, 255, 0);
    Serial.print("M2 : ");
    Serial.println(val2);
    analogWrite(LED2, val2);
  } else {
    val2 = defVal;
    val1 = defVal;
  }
}

//---------------------------
//Calcul la distance entre 2 points
/*
            t
           /|
         /  |
       /    | a
     /      |
   p --------
        b
*/
double DistCalc(double tx, double ty, double px, double py) {
  double a = py - ty;
  double b = tx - px;

  double R = sqrt(sq(a) + sq(b));
  return R;
}
