// // void servoMov() {
// //   //להוסיף קוד שכל 20 מעות יעזור לכמה שניות
// //   Serial.println("l");

// //   if (flag_servo) {
// //     byte deg = 180;
// //     my_servo.write(deg);
// //     flag_servo = 0;

// //   }
// //   else {
// //     byte deg = 0;
// //     my_servo.write(deg);
// //     flag_servo = 1;
// //   }
// //   delay(1000);
// // }

// void servoMovLeft(byte value) {
//   if (place_servo + value >= 180) {
//     my_servo.write(180);
//     place_servo = 180;
//   } else {
//     my_servo.write(place_servo + value);
//     place_servo = place_servo + value;
//   }
//   Serial.println(place_servo);
// }
// void servoMovRight(byte value) {
//   if (place_servo - value <= 0) {
//     my_servo.write(0);
//     place_servo = 0;
//   } else {
//     my_servo.write(place_servo - value);
//     place_servo = place_servo - value;
//   }
//   Serial.println(place_servo);
// }
// void setServoPosition(int angle) {
// // Convert the desired angle (in degrees) to PWM duty cycle (in microseconds)
// int dutyCycle = map(angle, 0, 180, 500, 2500);
// // Set the LEDC channel to the desired duty cycle
// ledcWrite(0, dutyCycle);
// }