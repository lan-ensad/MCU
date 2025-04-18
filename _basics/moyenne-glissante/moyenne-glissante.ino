const int N = 10; //number of value un buffer

int buff[N];
int index = 0;
long sum = 0;
int average = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < N; i++) {
    buff[i] = 0;
  }
}

void loop() {
  int newVal = analogRead(A0);

  sum -= buff[index];
  buff[index] = newVal;
  sum += newVal;
  index = (index + 1) % N;
  average = sum / N;
  
  Serial.println(average);

  delay(100);
}