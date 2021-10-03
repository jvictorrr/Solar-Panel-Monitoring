#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Medição de Corrente 
const int currentPin = A1;
int sensitivity = 66;
int adcValue= 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;

//Medição de Tensão Gerada

int voltagePin= A0;
float referenceVoltage = 6393.75;

float Rf= 1023/((30)/(30+7.5));
float Voltage_divide_value=0;
int Voltage_divide_input=0;
float finalVoltage=0;


// Temperatura e Luminosidade 

float Vlight = 0.0;
int Temp = 0;

void setup() {
  Serial.begin(9600);      
  lcd.begin(16, 2);    

}
void loop(){

   lcd.clear();
   lcd.setCursor(0, 0);

   
  // Leitura da tensão 
  Voltage_divide_input= analogRead(voltagePin);
   Voltage_divide_value = Voltage_divide_input * (5.0 / 1023.0);
  finalVoltage = (Voltage_divide_value*referenceVoltage)/Rf;
  Serial.print("Voltage = ");
  Serial.println(finalVoltage,1);
  lcd.print("V= ");
  lcd.setCursor(2, 0);
  lcd.print(finalVoltage,1);
  lcd.setCursor(6, 0);
  lcd.print("V");  
  

  // Leitura da Corrente 
  adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1024.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);
  Serial.print("Current = ");
  Serial.println(currentValue,3);

  lcd.setCursor(8, 0);
  lcd.print("i= ");
lcd.setCursor(10, 0);
lcd.print(currentValue,2);
lcd.setCursor(14, 0);
lcd.print("A");

  // Leitura da Luminosidade
  Vlight = analogRead(A3);  
  Serial.print("Light = ");         
  Serial.println(Vlight*100/1023);
  
lcd.setCursor(0, 1);
lcd.print("Sun= ");
lcd.setCursor(4, 1);
lcd.print(Vlight*100/1023,1);
lcd.setCursor(8, 1);
lcd.print("%");


  

  //Leitura da Temperatura
  Temp = analogRead(A5);  
  float TempCel = (Temp/1024.0)*500;
  Serial.print("Temp = ");  
  Serial.println(TempCel);

lcd.setCursor(10, 1);
lcd.print("T=");
lcd.setCursor(12, 1);
lcd.print(TempCel,0);
lcd.setCursor(14, 1);
lcd.write(B11011111);
lcd.setCursor(15, 1);
lcd.print("C");


    delay(100);
}
