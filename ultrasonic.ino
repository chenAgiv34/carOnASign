int ultrasonic() {
  // my_servo.write(direction);
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration / 58.2;
  // my_servo.write(90);
  // place_servo = 90;
  String disp = String(distance);
  Serial.print("Distance: ");
  Serial.print(disp);
  Serial.println(" cm");
  if (distance < maxDistance) {
    olde("an obstacle in front of you");
    return 1;
  }
  return 0;
  
}