#define PIR 8
#define led 9
unsigned long counttime;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(PIR, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val=digitalRead(PIR);
  if(val==HIGH){
    Serial.println("high");
    digitalWrite(led, HIGH);
    counttime=millis();
  }
  if(val==LOW && millis()-counttime>=3000){
    Serial.println("LOW");
    digitalWrite(led,LOW);
  }
}
