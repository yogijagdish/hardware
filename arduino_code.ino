#include<SoftwareSerial.h>
SoftwareSerial arduino_communication(5,6);

const int lm35_pin = A1;  /* LM35 O/P pin */
void setup()
{
  Serial.begin(9600);
  arduino_communication.begin(9600);
}
void loop()
{
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);  /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10); /* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
  arduino_communication.write(temp_val);
  delay(5000);
}
