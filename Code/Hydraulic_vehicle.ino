const int brakePin = 7;              // Pin for brake sensor (HIGH = brake applied, LOW = no brake) 
const int accumulatorPressurePin = A0; // Pin for reading accumulator pressure (0 to 5V -> 0 to 200 bar) 
const int valveControlPin1 = 9;      // Pin for controlling DCV position 1 (hydraulic motor) 
const int valveControlPin2 = 10;     // Pin for controlling DCV position 2 (electric motor) 
const int valveControlPin3 = 11;     // Pin for controlling DCV position 3 (recharging accumulator) 

const int pressureThreshold = 50;    // Pressure threshold for switching between DCV positions (in bar) 
int brakeState = 0;                  // Variable to store brake state 
int accumulatorPressure = 0;         // Variable to store accumulator pressure 
int pressureValue = 0;               // Analog value read from pressure sensor 

void setup() { 
  // Set the pin modes 
  pinMode(brakePin, INPUT);           // Set brake sensor pin as input 
  pinMode(accumulatorPressurePin, INPUT);  // Set accumulator pressure pin as input 
  pinMode(valveControlPin1, OUTPUT);  // Set valve control pins as output 
  pinMode(valveControlPin2, OUTPUT);  // Set valve control pins as output 
  pinMode(valveControlPin3, OUTPUT);  // Set valve control pins as output 

  // Initialize solenoids to OFF (no current position selected) 
  digitalWrite(valveControlPin1, LOW); 
  digitalWrite(valveControlPin2, LOW); 
  digitalWrite(valveControlPin3, LOW); 

  Serial.begin(9600);   // Initialize serial communication for debugging 
} 

void loop() { 
  // Read brake sensor and accumulator pressure 
  brakeState = digitalRead(brakePin);              // Read brake sensor 
  pressureValue = analogRead(accumulatorPressurePin); // Read pressure sensor value 
  accumulatorPressure = map(pressureValue, 0, 1023, 0, 200); // Convert to bar (assuming 0 to 200 bar range) 

  // Print debug information (optional) 
  Serial.print("Brake State: "); 
  Serial.print(brakeState); 
  Serial.print(" | Accumulator Pressure: "); 
  Serial.println(accumulatorPressure); 

  // When brake is applied, move DCV to 3rd position (recharge accumulator) 
  if (brakeState == HIGH) { 
    digitalWrite(valveControlPin1, LOW);   // Turn off position 1 solenoid 
    digitalWrite(valveControlPin2, LOW);   // Turn off position 2 solenoid 
    digitalWrite(valveControlPin3, HIGH);  // Turn on position 3 solenoid (Repressurize accumulator) 
  } 
  else { 
    // No brake applied, switch based on accumulator pressure 
    if (accumulatorPressure > pressureThreshold) { 
      // If accumulator pressure is above threshold (50 bar), switch to position 1 (run with hydraulic motor) 
      digitalWrite(valveControlPin1, HIGH);  // Turn on position 1 solenoid 
      digitalWrite(valveControlPin2, LOW);   // Turn off position 2 solenoid 
      digitalWrite(valveControlPin3, LOW);   // Turn off position 3 solenoid 
    } 
    else { 
      // If accumulator pressure is below threshold, switch to position 2 (run with electric motor) 
      digitalWrite(valveControlPin1, LOW);   // Turn off position 1 solenoid 
      digitalWrite(valveControlPin2, HIGH);  // Turn on position 2 solenoid 
      digitalWrite(valveControlPin3, LOW);   // Turn off position 3 solenoid 
    } 
  } 

  delay(100); // Small delay before the next loop iteration 
}

