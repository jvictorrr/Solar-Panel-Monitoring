
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
////////////////////////////////////////////////////////////
int val_0 = 0;       
int val_1 = 0;
float Vlight = 0.0;
int Temp = 0;

void setup() {
  Serial.begin(9600);          

}
void loop(){

  // Leitura da tensão 
  Voltage_divide_input= analogRead(voltagePin);
   Voltage_divide_value = Voltage_divide_input * (5.0 / 1023.0);
  finalVoltage = (Voltage_divide_value*referenceVoltage)/Rf;
  Serial.print("Voltage = ");
  Serial.println(finalVoltage,1);

  // Leitura da Corrente 
  adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1024.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);
  Serial.print("Current = ");
  Serial.println(currentValue,3);

  
  Vlight = analogRead(A3);  
  Serial.print("Light = ");         
  Serial.println(Vlight*100/1023);
  Temp = analogRead(A5);  
  float TempCel = (Temp/1024.0)*500;
  Serial.print("Temp = ");  
  Serial.println(TempCel);

    delay(1000);
}
