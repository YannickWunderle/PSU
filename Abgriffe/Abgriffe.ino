int Vsens = A1;

void setup(){
  //Serial.begin(9600);
  delay(50);
  digitalWrite(9,HIGH);
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
}

void loop(){
  
 Vsens = analogRead(A1);
 //Serial.println(Vsens);


  if (Vsens < 41) {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    delay(10);
    digitalWrite(3, HIGH);
    delay(20);
    
    
  }

  if((Vsens > 40) && (Vsens < 125)) {
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    delay(10);
    digitalWrite(4, HIGH);
    delay(20);
      }
  
   if((Vsens > 124) && (Vsens < 205)) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    delay(10);
    digitalWrite(5, HIGH);
    delay(20);

  }
   if(Vsens > 204) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(10);
    digitalWrite(6, HIGH);
    delay(20);

  } 
} 

