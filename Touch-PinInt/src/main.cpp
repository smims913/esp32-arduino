#include <Arduino.h>//Arduino库头文件

#define LED 0//设定LED的引脚为0
#define Pin 4//设定外部中断引脚为4
#define Touch 2//设定Touch引脚为2

bool num=0;//定义一个位变量用于点亮LED

void Touch_Int() //touch中断处理函数
{
  num =! num;//取反num，用于变换LED状态
  digitalWrite(LED,num);//将num的值赋给LED，来变换LED状态
  Serial.printf("LED is %d\n",num);//打印LED的状态
}

void Pin_Int() //外部中断处理函数
{
  num = ! num;//取反num，用于变换LED状态
  digitalWrite(LED,num);//将num的值赋给LED，来变换LED状态
  Serial.printf("LED is %d\n",num);//打印LED的状态
}

void setup() {//程序初始化函数
  Serial.begin(9600); //初始化串口：设置串口波特率（常用波特率有：9600、115200等等）
  pinMode(LED, OUTPUT);//配置LED引脚为输出模式
  pinMode(Touch, INPUT);//配置Touch引脚为输入模式
  pinMode(Pin, INPUT_PULLUP);//配置Pin引脚为上拉输入模式
  /*
  pinMode();函数模式共有：OUTPUT（输出）PULLUP（上拉）
  INPUT_PULLUP（上拉输入）PULLDOWN（下拉）
  INPUT_PULLDOWN（下拉输入）OPEN_DRAIN（漏极开路）
  OUTPUT_OPEN_DRAIN（漏极开路输出）ANALOG（模拟状态）
  */
  attachInterrupt(Pin,Pin_Int,FALLING);//外部中断初始化函数，配置的三个参数为（输入引脚，外部中断处理函数，触发模式）
  /*
  外部中断触发摸索包括：RISING（上升沿触发）
  FALLING（下降沿触发）CHANGE（边缘触发）
  ONLOW（低电平触发）ONHIGH（高电平触发）
  */
  touchAttachInterrupt(Touch,Touch_Int,20); //touch中断初始化函数，配置的三个参数为（输入引脚，touch中断处理函数，触发阈值“当touch值小于阈值触发中断”）
  digitalWrite(LED,num); //将LED的初始状态赋值为低电平，熄灭LED
  Serial.println("hello poor man!");//初始化结束，打印一句话，用于检测初始化完成
}

void loop() {//程序循环函数
  //Serial.printf("Touch is :%d\n", touchRead(Touch));//打印touch引脚touch值
  /*touchRead（）函数用于读取touch引脚函数*/
  delay(500);//延时函数
}