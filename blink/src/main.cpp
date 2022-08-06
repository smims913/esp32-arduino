#include <Arduino.h>

#define LED 33//将LED引脚设置为33号引脚

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //初始化串口，设置通讯波特率
  pinMode(LED, OUTPUT);//配置LED引脚为输出模式
  Serial.println("你好，打工人！");//利用串口打印一句话，便于观察初始化函数是否正常运行
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);//配置LED引脚高电平
  delay(500);//延时500ms
  digitalWrite(LED,LOW);//配置LED引脚高电平
  delay(500);//延时500ms
}