/**

Testna aplikacija za Digispark by @kstevica
Sluzi kao mjerac temperature
Svakih 5 sekundi pocinje ciklus, kolika je temperetura u stupnjevima Celzija,
toliko puta se LEDica na Digisparku upali i ugasi

Na pocetku se 30 sekundi zagrijava cip, a to je prikazano paljenjem i 
gasenjem LEDice u sve brzem ritmu.

Napajanje Digisparka moze ici preko USB-a (5V), preko 5V i GND pina
ili koristeci izvora 6V - 12V preko VIN i GND pina

Aplikacija je napravljena kako bi Daniel Mondekar @daniel_mondekar i 
MoorZak Blusher shvatili sto je Digispark :P

*/

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
  if (temp<0) {
    for (int i=temp; i<0; i++) {
      blink(999);    
    }          
  } else {
    for (int i=0; i<temp; i++) {
      blink(333);    
    }      
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
  raw -= 10; // kalibracija, treba podesiti rucno, za tiny je 0, inace 10
  int in_c = raw - 273; // stupnjevi Celzijusa
  analogReference(DEFAULT);
  return in_c;
}
