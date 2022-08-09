#include <Arduino.h>
int num=0;
int sen=58;
int hou=23;

hw_timer_t *timer = NULL;

void IRAM_ATTR  time() {
  num++;
  if(num ==60)
  {
    sen++;
    num = 0;
  }
  if(sen ==60)
  {
    hou++;
    sen = 0;
  }
  if (hou == 24)
  {
    hou = 0;
  }
  Serial.print(hou);
  Serial.print(":");
  Serial.print(sen);
  Serial.print(":");
  Serial.println(num);  
}

void setup() {
  Serial.begin(9600);
  Serial.println("你好，打工人"); 
  timer = timerBegin(3, 80, true);
  timerAttachInterrupt(timer, &time,true);
  timerAlarmWrite(timer,1000000,true);
  timerAlarmEnable(timer);


  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
