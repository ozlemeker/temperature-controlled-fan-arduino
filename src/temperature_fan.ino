#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define FAN 9

DHT dht(DHTPIN, DHTTYPE);

float buffer[5];
int indexx = 0;

float movingAverage(float val){
  buffer[indexx++] = val;
  if(indexx == 5) indexx = 0;

  float sum = 0;
  for(int i=0;i<5;i++)
    sum += buffer[i];

  return sum/5;
}

int mapTemp(float t){
  if(t < 20) return 0;
  else if(t < 30) return 80;
  else if(t < 40) return 160;
  else return 255;
}

void setup(){
  pinMode(FAN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop(){
  float temp = dht.readTemperature();
  float filtered = movingAverage(temp);
  int pwm = mapTemp(filtered);

  analogWrite(FAN, pwm);

  Serial.print("Temp: ");
  Serial.print(filtered);
  Serial.print(" PWM: ");
  Serial.println(pwm);

  delay(1000);
}
