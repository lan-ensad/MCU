/*
   BLINKER CLASS DEFINITION
   Blinker(PIN, DuringHIGH, DuringLOW)
*/
class Blinker {
//—————————————————————————————————————
//             __Init__
  private:
    byte pinLED;
    boolean ledState = LOW;
    unsigned long timeLedOn;
    unsigned long timeLedOff;
    unsigned long nextChangeTime = 0;

  public:
    Blinker(byte pinLED, unsigned long timeLedOn, unsigned long timeLedOff) {
      this->pinLED = pinLED;
      this->timeLedOn = timeLedOn;
      this->timeLedOff = timeLedOff;
      pinMode(pinLED, OUTPUT);
    }

//—————————————————————————————————————
//              Refresh
    void check() {
      unsigned long currentTime = millis();
      if (currentTime >= nextChangeTime) {
        if (ledState) {
          // LED is currently turned On. Turn Off LED.
          ledState = LOW;
          nextChangeTime = currentTime + timeLedOff;
        }
        else {
          // LED is currently turned Off. Turn On LED.
          ledState = HIGH;
          nextChangeTime = currentTime + timeLedOn;
        }
        digitalWrite(pinLED, ledState);
      }
    }
//—————————————————————————————————————
//            Set Functions
    void setDuringTime(){
    }
//—————————————————————————————————————
//            Get Functions
    void getDuringTime(){
    }
};

//=========================================================================
//=========================================================================
/*
   FADE CLASS DEFINITION
   Fader(PIN, StepsUp, StepsDown, TimeToUp, TimeToDown, DuringHIGH, DuringLOW)
*/
class Fader {
//—————————————————————————————————————
//             __Init__
  private:
    byte pinLED;
    bool isUp, isOn, isOff, isDown;
    int value;
    unsigned long PrevTime, onTime, offTime;
    unsigned long stepsUp, stepsDown, timeToUp, timeToDown, timeOn, timeOff;

  public:
    Fader(byte pinLED, unsigned long stepsUp, unsigned long stepsDown, unsigned long timeToUp, unsigned long timeToDown, unsigned long timeOn, unsigned long timeOff) {
      this->pinLED = pinLED;
      this->stepsUp = stepsUp;
      this->stepsDown = stepsDown;
      this->timeToUp = timeToUp;
      this->timeToDown = timeToDown;
      this->timeOn = timeOn;
      this->timeOff = timeOff;

      pinMode(pinLED, OUTPUT);
      isUp = true;
      PrevTime = millis();
    }
//—————————————————————————————————————
//              Refresh
    void check() {
      unsigned long currentTime = millis();
      if (isUp) {
        if (currentTime-PrevTime >= timeToUp) {
          value += stepsUp;
          if (value >= 255) {
            value=255;
            if (!isOn) {
              onTime = currentTime;
              isOn = true;
            }else if (currentTime-onTime>=timeOn && isOn) {
              isOn = false;
              isDown = true;
              isUp = false;
            }
          }
          PrevTime = currentTime;
        }
      } else if (isDown) {
        if (currentTime - PrevTime >= timeToDown) {
          value -= stepsDown;
          if (value <= 0) {
            value=0;
            if (!isOff) {
              offTime = currentTime;
              isOff = true;
            }else if (currentTime - offTime >= timeOff && isOff) {
              isOff = false;
              isUp = true;
              isDown = false;
            }
          }
          PrevTime = currentTime;
        }
      }
      analogWrite(pinLED, value);
    }

//—————————————————————————————————————
//            Set Functions
    void setSteps(){
    }
    void setTimeTo(){
    }
    void setDuringTime(){
    }
//—————————————————————————————————————
//            Get Functions
    void getSteps(){
    }
    void getTimeTo(){
    }
    void getDuringTime(){
    }
};
