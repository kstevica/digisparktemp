#define pinLED 1

void setup() {                
  pinMode(pinLED, OUTPUT);
  
  for (int i=40; i>0; i--) {
    blink(i*20); 
  }
  for (int i=0; i<50; i++) {
     blink(20); 
  }
}

void loop() {
  digitalWrite(pinLED, LOW);
  delay(5000);
  int temp = get_temp();
  for (int i=0; i<temp; i++) {
    blink(333);    
  }  
}

void blink(int useDelay)
{
  digitalWrite(pinLED, HIGH);
  delay(useDelay);           
  digitalWrite(pinLED, LOW); 
  delay(useDelay);           
}

int get_temp() {
  analogReference(INTERNAL1V1);
  int raw = analogRead(A0+15); 
  raw -= 10; // kalibracija
  int in_c = raw - 273; // stupnjevi Celzijusa
  analogReference(DEFAULT);
  return in_c;
}
