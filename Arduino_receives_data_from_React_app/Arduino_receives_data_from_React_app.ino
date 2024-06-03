bool start = false;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);

  // put your setup code here, to run once:
  Serial.begin(9600);

  // Wait for the serial port to connect (useful for some boards)
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Arduino is ready to receive data");
  
}
    

void loop() {
  Serial.print("BUILT-IN LED: ");
 
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming string
    String receivedData = Serial.readStringUntil('\n');
    
    // Print the received data to the serial monitor
    Serial.println(receivedData);

    // Process the received data (customize this part as needed)
    // For example, you can control an LED based on the received data
    if (receivedData == "ON") {
      // Turn on the Built-In LED on board 
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (receivedData == "OFF") {
      // Turn off the Built-In LED on board 
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  else{
    if (digitalRead(LED_BUILTIN) == HIGH) {
      Serial.println("ON");
    } 
    else if (digitalRead(LED_BUILTIN) == LOW) {
      Serial.println("OFF");
    }
  }

  delay(1000);
}
