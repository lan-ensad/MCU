#define NB 3

const int BTN [3] = {2, 3, 4};

boolean state [NB];
boolean prevState [NB];

int s = 3;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < NB; i++) {
    pinMode(BTN[i], INPUT_PULLUP);
    Serial.print(i);
  }
}

void Trig(int b, boolean s, boolean ps, int r) {
  s = digitalRead(b);
  if (!s) {
    if (ps != s) {
      s = r;
    }
  }
  ps = s;
}

void loop() {
  //---- Array OK ----
  for (int i = 0; i < NB ; i++) {
    state[i] = digitalRead(BTN[i]);
    if (!state[i]) {
      if (prevState[i] != state[i]) {
        s = i;
      }
    }
    prevState[i] = state[i];
  }

  switch (s) {
    case 0 :
      Serial.println("STOP 2 et 3");
      delay(2000);
      s = 3;
      break;
    case 1 :
      Serial.println("STOP 1 et 3");
      delay(2000);
      s = 3;
      break;
    case 2 :
      Serial.println("STOP 1 et 2");
      delay(2000);
      s = 3;
      break;
    default :
      break;
  }

  delay(200);
}
