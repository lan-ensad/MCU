//Servo(PIN, min_cycle, max_cycle, min_speed, max_speed);
Servo t(3, 510, 2100, 500, 20000);

void setup() {
}

void loop() {
  for(int i=0; i<180;i++){
    t.Move(i, 0);
  }
  delay(1000);
  for(int i=180; i>0;i--){
    t.Move(i, 100);
  }
  delay(1000);
}