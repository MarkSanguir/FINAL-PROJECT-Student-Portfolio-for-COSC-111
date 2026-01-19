#define thermistorPin A0
#define photoresistorPin A2
#define ledPin 12
#define buzzerPin 11

const int tempThreshold = 50;
const int brightThreshold = 220;

const float resistance = 10.0;
const float beta = 3950.0; 

// Function to read brightness
int readBright() {
  return analogRead(photoresistorPin);
}

// Function to read temperature in Celsius
float readTempC() {  
  int analogValue = analogRead(thermistorPin);  
  float tempC = beta / (log((1025.0 * resistance / analogValue - resistance) / resistance ) + beta / 298.0) - 273.0;
  return tempC;
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float currentTemp = readTempC();
  int currentBright = readBright();

  // Temperature and Brightness Check
  Serial.print("Temperature: ");
  Serial.print(currentTemp);
  Serial.print(" Celsius | Brightness: ");
  Serial.print(currentBright);

  
  if(currentTemp >= tempThreshold && currentBright >= brightThreshold) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 4000);
    delay(100);
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    delay(100);
  } else {
    digitalWrite(ledPin, LOW);  
    noTone(buzzerPin);
  }
}