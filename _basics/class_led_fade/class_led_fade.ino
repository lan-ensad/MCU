/*
   FADE CLASS DEFINITION
*/
class Fader {
private:
  byte pinLED;
  bool isUp, isOn, isOff, isDown;
  int value;
  unsigned long PrevTime, onTime,offTime;

  unsigned long stepsUp, stepsDown, timeToUp, timeToDown, timeOn, timeOff;

public:
  Fader(byte pinLED, unsigned long stepsUp, unsigned long stepsDown, unsigned long timeToUp, unsigned long timeToDown, unsigned long timeOn, unsigned long timeOff) {
    this->pinLED = pinLED;
    this->stepsUp = stepsUp;
    this->stepsDown = stepsDown;
    this->timeToUp = timeToUp;
    this->timeToDown = timeToDown;
    
    pinMode(pinLED, OUTPUT);
    isUp = true;
    PrevTime = millis();
  }

  void check() {
    unsigned long currentTime = millis();
    if (isUp) {
      isOff = false;
      if (currentTime - PrevTime >= timeToUp) {
        value += stepsUp;
        if (value >= 255) {
          if (!isOn) {
            onTime = currentTime;
            isOn = true;
          }
          if (currentTime - onTime >= timeOn) {
            isUp = false;
            isDown = true;
          }
        }
        PrevTime = currentTime;
      }
    } else if (isDown) {
      isOn = false;
      if (currentTime - PrevTime >= timeToDown) {
        value -= stepsDown;
        if (value <= 0) {
          if (!isOff) {
            offTime = currentTime;
            isOff = true;
          }
          if (currentTime - onTime >= timeOff) {
            isUp = true;
            isDown = false;
          }
        }
        PrevTime = currentTime;
      }
    }
    analogWrite(pinLED, value);
  }
};