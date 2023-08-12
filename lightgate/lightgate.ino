#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int threshold = 150;                      	  
const int count = 500; 
int readings[count];   
int readIndex, total, photoresistor; 
int length = 0; // Length of object passing thru tube in meters

void setup() { 
  Serial.begin(9600);          	  
  lcd.begin(16,2); 
  lcd.clear(); 
  for (int i = 0; i < count; i++) { 
    readings[i] = 0; 
  } 
} 

void loop() { 
  total = total - readings[readIndex]; 
  readings[readIndex] = analogRead(A0); 
  total = total + readings[readIndex]; 
  readIndex = readIndex + 1;
  if (readIndex >= count) { 
    readIndex = 0;
  } 

  photoresistor = analogRead(A0);    
  Serial.println(photoresistor);     
  
  if (photoresistor < threshold) { 
    lcd.clear(); 
    lcd.setCursor(0,0); 
    lcd.print("Lightgate Closed"); 
    lcd.setCursor(0,1); 
    lcd.print(length / readIndex);
    lcd.setCursor(5,1); 
    lcd.print("m/s"); 
  } 

  else { 
    lcd.setCursor(0,0); 
    lcd.print("Lightgate Clear "); 
    readIndex = 0; 
  } 
  delay(100);               	  
} 
