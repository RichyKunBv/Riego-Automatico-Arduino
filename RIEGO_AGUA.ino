#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

// --- ⏰ PARÁMETROS DE RIEGO AJUSTABLES ---
const int horaRiego = 19;   // <-- Hora 7 PM
const int minutoRiego = 54; // <-- Minuto 40

// --- PINES Y OTROS PARÁMETROS ---
int bomba = 8;
int sensorHumedadPin = A0;
int humedad = 0;
int umbralTierraSeca = 721;
const int duracionRiego = 2000;

// Variable "bandera" para evitar el problema
bool riegoRealizadoHoy = false;

void setup() {
  Serial.begin(9600);
  pinMode(bomba, OUTPUT);
  digitalWrite(bomba, HIGH);

  if (!rtc.begin()) {
    Serial.println("No se encontró el módulo RTC.");
    while (1);
  }
  
   //rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Para ajustar la hora la primera vez
  
  Serial.println("Sistema de riego iniciado.");
}

void loop() {
  DateTime ahora = rtc.now();

  // Revisa si es la hora Y si NO se ha regado ya hoy
  if (ahora.hour() == horaRiego && ahora.minute() == minutoRiego && !riegoRealizadoHoy) {
    Serial.println("Es hora de revisar la humedad.");
    humedad = analogRead(sensorHumedadPin);
    
    if (humedad >= umbralTierraSeca) {
      Serial.println("Regando por 2 segundos...");
      digitalWrite(bomba, LOW);
      delay(duracionRiego);
      digitalWrite(bomba, HIGH);
    } else {
      Serial.println("La tierra ya está húmeda.");
    }

    // Marca que la tarea de hoy ya se hizo para no repetirla
    riegoRealizadoHoy = true;
    Serial.println("Revisión finalizada.");
  }

  // Cuando ya no es la hora de riego, reinicia la bandera para el día siguiente
  if (ahora.hour() != horaRiego || ahora.minute() != minutoRiego) {
    riegoRealizadoHoy = false;
  }

  delay(1000);
}




/*pines
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
*/


/*
Bomba de Agua (a través del Relé y la fuente externa)
El cable negativo (negro) de la bomba → GND de la fuente de poder externa (la que viene de la batería de 9V).
El cable positivo (rojo) de la bomba → Uno de los tornillos del borne (terminal block) del relé.
El cable positivo (rojo) de la fuente de poder externa → El otro tornillo del borne del relé.
*/


