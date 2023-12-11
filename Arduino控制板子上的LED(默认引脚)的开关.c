int comData;     //定义从串口接收过来的数据

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       //初始化串口，波特率设置为9600
  pinMode(LED_BUILTIN, OUTPUT);     //设置数字引脚为输出模式
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() )   //检测串口缓冲区是否有数据
  {   
    comData = Serial.read();    
    if (comData == '1')        //接收到该命令，则执行关灯
    {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.write('1');
    }
    if (comData == '0')        //接收到该命令，则执行开灯
    {
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}
