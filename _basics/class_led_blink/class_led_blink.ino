/*
   BLINKER CLASS DEFINITION
*/
class Blinker {
  private:
    byte pinLED;

    bool ledState = LOW;

    unsigned long timeLedOn, timeLedOff, nextChangeTime;

  public:
    Blinker(byte pinLED, unsigned long timeLedOn, unsigned long timeLedOff) {
      this->pinLED = pinLED;
      this->timeLedOn = timeLedOn;
      this->timeLedOff = timeLedOff;

      pinMode(pinLED, OUTPUT);
      nextChangeTime = 0;
    }

    void check() {
      unsigned long currentTime = millis();
      if (currentTime >= nextChangeTime) {
        if (ledState) {
          ledState = LOW;
          nextChangeTime = currentTime + timeLedOff;
        }
        else {
          ledState = HIGH;
          nextChangeTime = currentTime + timeLedOn;
        }
        digitalWrite(pinLED, ledState);
      }
    }
};
