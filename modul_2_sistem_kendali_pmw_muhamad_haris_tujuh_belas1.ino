int sensor1 = A0; //Input Photodioda 1
int sensor2 = A1; //Input Photodioda 2
int sensor3 = A2; //Input Photodioda 3
int sensor4 = A3; //Input Photodioda 4
int sensor5 = A4; //Input Photodioda 5
int sensor6 = A5; //Input Photodioda 6
int baca_sensor[6]; 

int pinEnable = 4; //Aktifkan motor kiri
int pinEnable2 = 2; //Aktifkan motor kanan

int motor_L1 = 5; //Input motor kiri
int motor_L2 = 6; //Input motor kiri

int motor_R1 = 3; //Input motor kanan
int motor_R2 = 11; //Input motor kanan

int x;

int LastError = 0;

void setup()
{
  //Set photodioda sebagai input
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  
  //Set motor kanan & kiri sebagai output
  pinMode(pinEnable, OUTPUT);
  pinMode(pinEnable2, OUTPUT);

  pinMode(motor_L1, OUTPUT);
  pinMode(motor_L2, OUTPUT);
  
  pinMode(motor_R1, OUTPUT);
  pinMode(motor_R2, OUTPUT);

  Serial.begin(9600);
}

void readsensor(){
  baca_sensor[0] = analogRead(sensor1);
  baca_sensor[1] = analogRead(sensor2);
  baca_sensor[2] = analogRead(sensor3);
  baca_sensor[3] = analogRead(sensor4);
  baca_sensor[4] = analogRead(sensor5);
  baca_sensor[5] = analogRead(sensor6);
  
  delay(100);
  for(x=0; x<=5; x++){
    Serial.print("Sensor ");
    Serial.print(x+1);
    Serial.print(": ");
    Serial.print(baca_sensor[x]);
    Serial.print("\n");
  }
 
}

void loop()
{
  readsensor();
  Serial.print("Nilai LastError : ");
  Serial.println(LastError);
  //Sensor 1 & 2 mendeteksi gelap
  if (baca_sensor[0] < 34 && baca_sensor[1] < 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {    
    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0);
    analogWrite(motor_L2, 0);
   
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0.5*225);
    analogWrite(motor_R2, 0);
  }
  //Sensor 2 & 3 mendeteksi gelap
  if (baca_sensor[0] > 34 && baca_sensor[1] < 34 && 
      baca_sensor[2] < 34 && baca_sensor[3] > 34 && 
      baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0.2*255);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0.5*255);
    analogWrite(motor_R2, 0);
  }
  //Sensor 3 & 4 mendeteksi gelap
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] < 34 && baca_sensor[3] < 34 &&
      baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0.6*255);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0.6*255);
    analogWrite(motor_R2, 0);
  }
  //Sensor 4 & 5 mendeteksi gelap
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] < 34 &&
      baca_sensor[4] < 34 && baca_sensor[5] > 34)
  {
    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0.5*255);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0.2*255);
    analogWrite(motor_R2, 0);
  }
  //Sensor 5 & 6 mendeteksi gelap
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
      baca_sensor[4] < 34 && baca_sensor[5] < 34)
  {
    digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0.5*255);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0);
    analogWrite(motor_R2, 0);
  }
  //Semua sensor mendeteksi terang
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
      baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
  	digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0);
    analogWrite(motor_R2, 0);
  }
  
  //Jika Sensor 1 mendeteksi gelap
  if (baca_sensor[0] < 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
      baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
  	digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 255);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0.75*255);
    analogWrite(motor_R2, 0);
    LastError = 1;
  }
  
  //Jika Sensor 2 mendeteksi gelap
  if (baca_sensor[0] > 34 && baca_sensor[1] < 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
      baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
  	digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0.75*255);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0.5*255);
    analogWrite(motor_R2, 0);
    LastError = 1;
  }
  
  //Jika Sensor 3 mendeteksi gelap
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] < 34 && baca_sensor[3] > 34 &&
      baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
  	digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0.5*255);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0.25*255);
    analogWrite(motor_R2, 0);
    LastError = 1;
  }
  
  //Jika Sensor 4 mendeteksi gelap
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] < 34 &&
      baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
  	digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0.25*255);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0.5*255);
    analogWrite(motor_R2, 0);
    LastError = 1;
  }
  
  //Jika Sensor 5 mendeteksi gelap
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
      baca_sensor[4] < 34 && baca_sensor[5] > 34)
  {
  	digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0.5*255);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 0.75*255);
    analogWrite(motor_R2, 0);
    LastError = 1;
  }
  
  //Jika Sensor 6 mendeteksi gelap
  if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
      baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
      baca_sensor[4] > 34 && baca_sensor[5] < 34)
  {
  	digitalWrite(pinEnable, HIGH);
    analogWrite(motor_L1, 0.75*255);
    analogWrite(motor_L2, 0);
    
    digitalWrite(pinEnable2, HIGH);
    analogWrite(motor_R1, 255);
    analogWrite(motor_R2, 0);
    LastError = 1;
  }
}
