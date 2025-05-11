#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimerOne.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define HEATER_PIN 3
#define BUZZER_PIN 4

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Temperature thresholds
const float TEMP_LOW = 25.0;
const float TEMP_TARGET = 35.0;
const float TEMP_HIGH = 45.0;

volatile bool readSensor = false;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  lcd.backlight();

  pinMode(HEATER_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize LCD
  lcd.setCursor(0, 0);
  lcd.print("Heater System");

  // Setup Timer1 to trigger every 1 second
  Timer1.initialize(1000000); // 1,000,000 microseconds = 1 sec
  Timer1.attachInterrupt(setReadFlag);
}

void loop() {
  if (readSensor) {
    readSensor = false;

    float temp = dht.readTemperature();
    if (isnan(temp)) {
      Serial.println("Failed to read from DHT!");
      return;
    }

    String state = "";

    // Determine system state
    if (temp < TEMP_LOW) {
      digitalWrite(HEATER_PIN, HIGH);  // Turn heater ON
      digitalWrite(BUZZER_PIN, LOW);   // No alarm
      state = "Heating";
    } else if (temp >= TEMP_LOW && temp < TEMP_TARGET) {
      digitalWrite(HEATER_PIN, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
      state = "Stabilizing";
    } else if (temp >= TEMP_TARGET && temp < TEMP_HIGH) {
      digitalWrite(HEATER_PIN, LOW);   // Turn heater OFF
      digitalWrite(BUZZER_PIN, LOW);
      state = "Target Reached";
    } else {
      digitalWrite(HEATER_PIN, LOW);
      digitalWrite(BUZZER_PIN, HIGH);  // Sound alarm
      state = "Overheat!";
    }

    // Display on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: " + String(temp, 1) + "C");
    lcd.setCursor(0, 1);
    lcd.print("State: " + state);

    // Log to Serial
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(" C | State: ");
    Serial.println(state);
  }
}

void setReadFlag() {
  readSensor = true;
}
