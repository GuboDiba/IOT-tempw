int distanceThreshold = 0;
int cm = 0;
int inches = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);

  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  
  distanceThreshold = 350;
  
  cm = 0.01723 * readUltrasonicDistance(6, 5);
  
  
  inches = (cm / 2.54);
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  
  if (cm > distanceThreshold) {
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  if (cm <= distanceThreshold && cm > distanceThreshold - 100) {
    digitalWrite(8, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  if (cm <= distanceThreshold - 100 && cm > distanceThreshold - 250) {
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if (cm <= distanceThreshold - 250 && cm > distanceThreshold - 350) {
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  }
  if (cm <= distanceThreshold - 350) {
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  }
  delay(100); 
}