class UltrasonicSensor {
    private:
      const int triggerPin;
      const int echoPin;
  
    public:
      UltrasonicSensor(int trigger, int echo) : triggerPin(trigger), echoPin(echo) {
        pinMode(triggerPin, OUTPUT);
        pinMode(echoPin, INPUT);
      }
  
      long readDistance() {
        digitalWrite(triggerPin, LOW);
        delayMicroseconds(2);
        digitalWrite(triggerPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(triggerPin, LOW);
  
        // Usamos pulseIn en lugar de pulseInLong para reducir el tiempo de exposición
        long duration = pulseIn(echoPin, HIGH, 30000); // Timeout de 30ms
        if (duration == 0) return -1; // Si no hay señal, retorna -1
        return duration * 0.01723;
      }
  };
  
  class LedGroup {
    private:
      const int ledPins[3]; 
      unsigned long ledTimers[3]; 
      const unsigned long ledTimeout = 300; 
  
    public:
      LedGroup(const int pins[3]) : ledPins{pins[0], pins[1], pins[2]} {
        for (int i = 0; i < 3; i++) {
          pinMode(ledPins[i], OUTPUT);
          digitalWrite(ledPins[i], LOW);
          ledTimers[i] = 0;
        }
      }
  
      void turnOnLed(int index) {
        if (index >= 0 && index < 3) {
          digitalWrite(ledPins[index], HIGH);
          ledTimers[index] = millis();
        }
      }
  
      void updateLeds() {
        unsigned long currentTime = millis();
        for (int i = 0; i < 3; i++) {
          if (digitalRead(ledPins[i]) == HIGH && (currentTime - ledTimers[i] > ledTimeout)) {
            digitalWrite(ledPins[i], LOW);
          }
        }
      }
  };
  
  const int LED_PINS[3] = {26, 27, 14};
  const int TRIGGER_PIN = 5;
  const int ECHO_PIN = 18;
  
  UltrasonicSensor ultrasonicSensor(TRIGGER_PIN, ECHO_PIN);
  LedGroup leds(LED_PINS);
  
  void setup() {
    Serial.begin(115200);
  }
  
  void loop() {
    static unsigned long lastCheck = 0;
    const unsigned long sensorInterval = 100;
  
    if (millis() - lastCheck >= sensorInterval) {
      lastCheck = millis();
  
      int cm = ultrasonicSensor.readDistance();
      
      if (cm == -1) {
        Serial.println("Error: No se detecta señal del sensor");
      } else {
        Serial.print(cm);
        Serial.println(" cm");
  
        if (cm > 50) {
          // No se encienden LEDs
        } else if (cm <= 50 && cm > 25) {
          leds.turnOnLed(2);
        } else if (cm <= 25 && cm > 15) {
          leds.turnOnLed(1);
        } else if (cm <= 15) {
          leds.turnOnLed(0);
        }
      }
    }
  
    leds.updateLeds();
  }