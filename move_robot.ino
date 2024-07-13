void ahead() {
  if (ultrasonic() == 1) {
    stop();
  } else {
    Serial.println("ahead");
    motors(200, -200);
    olde("ahead");
  }
}

void back() {
  Serial.println("back");
  motors(-200, 200);
  olde("back");

}

void left() {
  Serial.println("left");
  motors(180, -20);
  olde("left");
}

void right() {
  Serial.println("right");
  motors(20, -180);
  olde("right");
}

void stop() {
  Serial.println("stop");
  motors(0, 0);
  olde("stop");
}

void motors(int Speed1) {

  if (Speed1 >= 0) {
    ledcWrite(PWM_Channel1, Speed1);
    digitalWrite(pinDirection1, LOW);
  }

  else {
    ledcWrite(PWM_Channel1, 256 + Speed1);
    digitalWrite(pinDirection1, HIGH);
  }
}

void motors(int Speed1, int Speed2) {

  if (Speed1 >= 0) {
    ledcWrite(PWM_Channel1, Speed1);
    digitalWrite(pinDirection1, LOW);
  }

  else {
    ledcWrite(PWM_Channel1, 256 + Speed1);
    digitalWrite(pinDirection1, HIGH);
  }


  if (Speed2 >= 0) {
    ledcWrite(PWM_Channel2, Speed2);
    digitalWrite(pinDirection2, LOW);
  }

  else {
    ledcWrite(PWM_Channel2, 256 + Speed2);
    digitalWrite(pinDirection2, HIGH);
  }
}

