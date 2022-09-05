#include "Arduino.h"

const int ledPin = 16;//将pwm引脚赋给16号引脚

const int freq = 5000;//定义频率
const int ledChannel = 0;//定义通道号，取值0 ~ 15
const int resolution = 8;//定义计数位数，取值0 ~ 20
 
void setup(){
  Serial.begin(115200);
  ledcSetup(ledChannel, freq, resolution);//pwm初始化函数
  ledcAttachPin(ledPin, ledChannel);//将 LEDC 通道绑定到指定 IO 口上以实现输出
}
 
void loop(){
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    ledcWrite(ledChannel, dutyCycle);//指定通道输出一定占空比波形
    Serial.println("dutyCycle++ ");
    delay(15);
  }
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledChannel, dutyCycle);   
    Serial.println("dutyCycle-- ");
    delay(15);
  }
}
