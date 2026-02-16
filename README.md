# Temperature Controlled Fan System (Arduino)

This project implements a temperature-based automatic fan control system using Arduino and a DHT11 temperature sensor.  
The fan speed is adjusted dynamically with PWM according to the measured temperature.

---

##  Components
- Arduino Uno (ATmega328P)
- DHT11 Temperature Sensor
- DC Motor (Fan)
- 2N2222 NPN Transistor
- 1kΩ Resistor
- 1N4007 Diode
- External 5V Power Supply (optional)

---

## ⚙️ How It Works
1. Arduino reads temperature from the DHT11 sensor.
2. Temperature value is mapped to a PWM range (0–255).
3. PWM signal drives the transistor.
4. Transistor controls motor speed.
5. Temperature and PWM value are printed on Serial Monitor.

---

##  Pin Configuration

| Component | Arduino Pin |
|---------|-------------|
| DHT11 DATA | D2 |
| Motor Control (PWM) | D9 |
| DHT11 VCC | 5V |
| DHT11 GND | GND |

---

##  Formula

PWM = map(temperature, 20, 40, 0, 255)

---

##  Example Serial Output

Temp: 27.0 °C PWM: 80


---

## Simulation

Simulation created using Proteus.

---

##  Future Improvements
- Replace DHT11 with DHT22 for better accuracy  
- Add LCD display  
- Add manual/auto mode selection  
- Add hysteresis to prevent frequent switching  

---

##  Author
Özlem Eker

