# Riego-Automatico-Arduino


## Pines
Sensor de Humedad
VCC → 5V del Arduino
GND → GND del Arduino
AOUT (Salida Analógica) → A0 del Arduino

Módulo de Reloj (DS3231)
VCC → 5V del Arduino
GND → GND del Arduino
SDA → Pin 20 del Arduino Mega
SCL → Pin 21 del Arduino Mega

Módulo de Relé (Relay)
VCC → 5V del Arduino
GND → GND del Arduino
IN (Señal) → Pin 8 del Arduino




## Bomba de Agua (a través del Relé y la fuente externa)
El cable negativo (negro) de la bomba → GND de la fuente de poder externa (la que viene de la batería de 9V).
El cable positivo (rojo) de la bomba → Uno de los tornillos del borne (terminal block) del relé.
El cable positivo (rojo) de la fuente de poder externa → El otro tornillo del borne del relé.


<img width="1600" height="916" alt="diagrama" src="https://github.com/user-attachments/assets/5e7adbb5-3406-47eb-b237-4aaa0c45da58" />



![WhatsApp Image 2025-07-21 at 20 07 16](https://github.com/user-attachments/assets/5150f336-6464-4271-bd82-49069eb87329)

![WhatsApp Image 2025-07-21 at 20 07 16 (1)](https://github.com/user-attachments/assets/41e3ffaf-4ae3-4a8d-863b-baf5afe7a229)


