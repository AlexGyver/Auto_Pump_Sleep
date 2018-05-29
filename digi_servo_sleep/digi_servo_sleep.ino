/*
	Данный код превратит вашу Digispark в спящий таймер. Через каждые PERIOD
	секунд система поворачивает серво с MIN_ANGLE до MAX_ANGLE, затем
	поворачивает обратно. Всё время, кроме движения серво, система спит 
	и потребляет 28 микроампер на плате Digispark с отрезанным светодиодом, 
	стабилизатором и двумя диодами на шину USB. На голом камне будет работать ещё лучше!
*/


#define PERIOD 10       // период работы в секундах
#define SERVO_PIN 1     // пин серво
#define MIN_ANGLE 20
#define MAX_ANGLE 150

uint32_t mainTimer, myTimer;

#include "SimpleServo.h"
SimpleServo myServo;

#include <avr/wdt.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#define adc_disable() (ADCSRA &= ~(1<<ADEN)) // disable ADC (before power-off)
#define adc_enable()  (ADCSRA |=  (1<<ADEN)) // re-enable ADC
// http://alexgyver.ru/arduino/DigiDrivers.rar

void setup() {
  // все пины как входы, экономия энергии
  for (byte i = 0; i < 6; i++) {
    pinMode(i, INPUT);
  }
  adc_disable();          // отключить АЦП (экономия энергии)

  wdt_reset();            // инициализация ватчдога
  wdt_enable(WDTO_1S);    // разрешаем ватчдог
  // 15MS, 30MS, 60MS, 120MS, 250MS, 500MS, 1S, 2S, 4S, 8S

  WDTCR |= _BV(WDIE);     // разрешаем прерывания по ватчдогу. Иначе будет резет.
  sei();                  // разрешаем прерывания
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // максимальный сон
}

void loop() {
  mainTimer++;

  if ((long)mainTimer - myTimer > PERIOD) {   // таймер периода
    myTimer = mainTimer;                      // сброс таймера
    myServo.attach(SERVO_PIN);
    myServo.write(MIN_ANGLE);
    delay(2000);
    myServo.write(MAX_ANGLE);
    delay(2000);
    myServo.detach();
  }
  sleep_enable();   // разрешаем сон
  sleep_cpu();      // спать!
}

ISR (WDT_vect) {
  WDTCR |= _BV(WDIE); // разрешаем прерывания по ватчдогу. Иначе будет реcет.
}
