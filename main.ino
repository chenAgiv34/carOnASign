#include <Wire.h>
// wifi
#include <WiFi.h>
// servo
// #include <ESP32Servo.h>
// #define servo_pin 12
// Servo my_servo;

#include <Adafruit_NeoPixel.h>

// //LDR_and_LDR
#define LDR 32
#define PINLED 2
#define NUMPIXELS 8
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PINLED, NEO_GRB + NEO_KHZ800);
int darkness = 400;
//move_robot
#define pinDirection1 15  //IN1 rigth
#define pinMotor1 5       //IN2 rigth
#define pinDirection2 18  //IN3 left
#define pinMotor2 19      //IN4 left
// 


// ultrasonic
#define TRIG_PIN 25
#define ECHO_PIN 26

#define PWM_Channel1 0
#define PWM_Channel2 1
#define PWM_Resolution 8
#define PWM_Freq 10000
int maxDistance = 10;
//olde
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define i2c_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//wifi
const char* ssid = "ZTE_AC6ABF";
const char* password = "95213782";
// const char* ssid = "YAL";
// const char* password = "22222222";
// const char* ssid = "MICHAL";
// const char* password = "55555555";

const char* my_password = "CHEN";
const char* print_pasword;

byte flag_fun = 0;
WiFiClient client;
byte flag_print = 0;
WiFiServer server(80);
// String request, print_msg, print_name = "you";
String request;

// servo
// byte place_servo = 90;

void setup() {
  Serial.begin(115200);
  // wifi
  connectToWifi();
  server.begin();
  //move_robot
  pinMode(pinDirection1, OUTPUT);
  pinMode(pinDirection2, OUTPUT);

  ledcAttachPin(pinMotor1, PWM_Channel1);
  ledcSetup(PWM_Channel1, PWM_Freq, PWM_Resolution);

  ledcAttachPin(pinMotor2, PWM_Channel2);
  ledcSetup(PWM_Channel2, PWM_Freq, PWM_Resolution);
  //ultrasonic
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Wire.begin();
  // servo
  // Serial.begin(115200);
  // my_servo.attach(servo_pin);
  // my_servo.write(place_servo);
  // ledcSetup(0, 50, 16);
  // ledcAttachPin(servo_pin, 0);
  // setServoPosition(90);
  // //LDR_and_LDR
  pinMode(LDR, INPUT);
  // Serial.begin(115200);
  pixels.begin();
  //olde
  display.begin(i2c_Address, true);
  olde("start");
}

void loop() {
 web();
  if (flag_fun != 0) {
    ldr_sensor();
  }
  if (flag_fun == 2)
    left();
  else if (flag_fun == 3)
    right();
  else if (flag_fun == 4)
    ahead();
  else if (flag_fun == 5)
    back();
  else if (flag_fun == 6)
    stop();

  // right();
  // Serial.println("m");
  // ahead();

  // startMoveRobot();
  // delay(1000);
  //move_robot
  // move();
  // ultrasonic();
  // temp_sensor();
  //LDR_and_LDR
  // if (ldr_sensor()) {
  //   led_on();
  //   Serial.println("on");
  // } else {
  //   led_off();
  //   Serial.println("off");
  // }
}
