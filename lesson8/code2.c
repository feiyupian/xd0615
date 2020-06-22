#include <MsTimer2.h>     //定时器库的头文件
 int pinInterrupt=2;
volatile byte tick =0; //计数值
 
//中断服务程序
void onTimer()
{
  Serial.print("timer ");
  Serial.println(tick++);
  
  digitalWrite(3,tick&0x1);
  digitalWrite(4,(tick>>1)&0x1);
  digitalWrite(5,(tick>>2)&0x1);
  digitalWrite(6,(tick>>3)&0x1);
  if(tick>9)
  {
    tick=0;
  }
}
void setZero()
{
  tick=-1;
}
 
void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600); //初始化串口
  pinMode(13,OUTPUT);
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
  attachInterrupt(digitalPinToInterrupt(pinInterrupt),setZero, CHANGE);
  
  
}
 
void loop()
{
  
}