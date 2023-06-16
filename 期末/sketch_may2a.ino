const byte p[4]={2,3,4,5};
byte drive[4]={1,1,1,0};
void setup() {
  // put your setup code here, to run once:
  for (byte i=0;i<4;i++){
    pinMode(p[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (byte i=0;i<4;i++){
    digitalWrite(p[i], drive[i]);
    }
  run();
  delay(5);
  
}

void run(void) {
  int a = drive[0];
  for(byte i=0;i<3;i++){
    drive[i] = drive[i+1]; 
  }
  drive[3] = a;

}
