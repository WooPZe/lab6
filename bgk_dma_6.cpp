#include "mbed.h"
#include "BME280.h"


BME280 sensor(I2C_SDA, I2C_SCL);

DigitalOut oled1(LED1);
DigitalOut oled2(PA_8);

Ticker toggle_led_ticker;
static auto sleep_time = 1000ms;

char buf[2];

int main()
{
while (true) 
{

printf("%d degC, %d hPa, %d %%\n", (int)sensor.getTemperature());

if ((int)sensor.getTemperature()<27)
{
oled2 = !oled2;
ThisThread::sleep_for(200ms);
}
else if(((int)sensor.getTemperature()>=27)&&((int)sensor.getTemperature()<=30))
{
   oled1 = !oled1;
ThisThread::sleep_for(1500ms);
}
else if((int)sensor.getTemperature()>30)
{
   oled1=!oled1;
   oled2=(oled2+1)%2;
   ThisThread::sleep_for(2500ms);
}
}
}