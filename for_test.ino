#include <Servo.h>
#include <dht.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "TM1637.h"
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10
#define SEALEVELPRESSURE_HPA (1013.25)


Adafruit_BME280 bme;  // I2C
unsigned long delayTime = 1000;
Servo myservo;  //ประกาศตัวแปรแทน Servo
dht DHT;
int test;

String Dpin2 = "pD2";
String Dpin3 = "pD3";
String Dpin4 = "pD4";
String Dpin5 = "pD5";
String Dpin6 = "pD6";
String Dpin7 = "pD7";
String Dpin8 = "pD8";
String Dpin9 = "pD9";
String Dpin10 = "pD10";
String Dpin11 = "pD11";
String Dpin12 = "pD12";
String Dpin13 = "pD13";
String Apin0 = "pA0";
String Apin1 = "pA1";
String Apin2 = "pA2";
String Apin3 = "pA3";
String Apin4 = "pA4";
String Apin5 = "pA5";
String space = " ";
int res3, res4, res5, res6, res7, res8;

String result1, result2, result3, result4, result5, result6, result7, result8;
boolean readError;
int analogPin;
int digitalPin, digitalPin2, digitalPin3, analogpinS;
int count;
const int MAX_ARRAY_SIZE = 100;  // Define the maximum size of your byteArray
const int ARRAY = 100;
char PinpositionDigital, PinpositionDigital2;
char PinpositionAnalog;
unsigned long previousMillis = 0;
const long interval = 100;

String decodeUint8ArrayToString(uint8_t* byteArray, int length) {
  String decodedString = "";
  for (int i = 0; i < length; i++) {
    char character = (char)byteArray[i];  // Convert the byte to a char
    decodedString += character;           // Concatenate the character to the string
  }
  return decodedString;
}

void split(String input) {
  // Convert the String to a char array (C-string)
  char char_array[input.length()];
  input.toCharArray(char_array, input.length());

  // Initialize strtok with the delimiter ":"
  char* token = strtok(char_array, ":");

  // Variables to store the results
  result1 = "";
  result2 = "";
  result3 = "";
  result4 = "";
  result5 = "";
  result6 = "";
  result7 = "";
  result8 = "";


  // Loop through the tokens and extract the values
  int count = 0;
  while (token != NULL) {
    if (count == 0) {
      result1 = String(token);
    } else if (count == 1) {
      result2 = String(token);
    } else if (count == 2) {
      result3 = String(token);
    } else if (count == 3) {
      result4 = String(token);
    } else if (count == 4) {
      result5 = String(token);
    } else if (count == 5) {
      result6 = String(token);
    } else if (count == 6) {
      result7 = String(token);
    } else if (count == 7) {
      result8 = String(token);
    } else {
      // If there are more than two tokens, it's an error
      // Serial.println("Error: Too many tokens!");
      // return;
    }
    token = strtok(NULL, ":");
    count++;
  }
  // Check if the split was successful and print the results
  readError = count < 2;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint8_t byteArray[MAX_ARRAY_SIZE];
  static int arrayIndex = 0;

  // while (Serial.available()) {
  //   delay(3);  //delay to allow buffer to fill

  if (Serial.available() > 0) {
    if (arrayIndex < MAX_ARRAY_SIZE) {
      uint8_t incomingByte = Serial.read();  //gets one byte from serial buffer
      byteArray[arrayIndex] = incomingByte;
      arrayIndex++;
    } else {
      // The buffer is full, might want to handle this case or just read and discard the byte
      Serial.read();
    }
  }
  // }

  if (arrayIndex > 0) {
    String decodedString = decodeUint8ArrayToString(byteArray, arrayIndex);
    split(decodedString);
    Serial.println(result1);
    //delay(1000);
  
    //memset(byteArray, 0, MAX_ARRAY_SIZE);  // Clear the buffer
    //arrayIndex = 0;                        // Reset the index
  }
}
