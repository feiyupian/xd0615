void setup() {
  // 以每秒9600位的速度初始化串行通信
  Serial.begin(9600);
}
void loop() {
  // 读取模拟引脚0上的输入
  int sensorValue = analogRead(A0);
  // 将模拟读数（从0-1023）转换为电压（0-5V）
  float voltage = sensorValue * (5.0 / 1023.0);
  // 打印出你读到的值
  Serial.println(voltage);
}