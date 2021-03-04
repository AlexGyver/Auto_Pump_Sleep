/*
	Данный код превратит вашу Digispark в спящий таймер. Через каждые PERIOD
	секунд система подаёт 5 вольт на протяжении WORK секунд. Всё время,
	кроме переключения пина, система спит и потребляет 28 микроампер
	на плате Digispark с отрезанным светодиодом, стабилизатором
	и двумя диодами на шину USB. На голом камне будет работать ещё лучше!
*/

#define PERIOD 259200   // период работы в секундах (пример: 60*60*24*3 = 259200 - три дня!)
#define WORK 30         // время работы в секундах
#define USE_SENSOR true // false если без датчика наличия воды
#define SENSOR 0        // пин датчика наличия воды
#define MOS 1           // пин мосфета

uint32_t mainTimer, myTimer;
boolean state = false;

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

  if (!state) {                           // если помпа не включена
    if (((long)mainTimer - myTimer > PERIOD) && isWaterPresent()) {   // таймер периода
      myTimer = mainTimer;                // сброс таймера
      state = true;                       // флаг на запуск
      pinMode(MOS, OUTPUT);               // пин как выход
      digitalWrite(MOS, HIGH);            // врубить
    }
  } else {                                // если помпа включена
    if (((long)mainTimer - myTimer > WORK) || !isWaterPresent()) {     // таймер времени работы
      myTimer = mainTimer;                // сброс
      state = false;                      // флаг на выкл
      digitalWrite(MOS, LOW);             // вырубить
      pinMode(MOS, INPUT);                // пин как вход (экономия энергии)
    }
  }

  sleep_enable();   // разрешаем сон
  sleep_cpu();      // спать!
}

ISR (WDT_vect) {
  WDTCR |= _BV(WDIE); // разрешаем прерывания по ватчдогу. Иначе будет реcет.
}

/**
 * Проверка наличия воды для помпы.
 *
 * Бросить в воду два провода: GND и вывод пина SENSOR.
 * Вода должна замыкать эти провода,
 * в таком случае помпу можно включать.
 * 
 * Если воды нет - пин SENSOR не подключен к GND,
 * на нем высокий уровень сигнала,
 * значит помпу выключить и не включать.
 */
void isWaterPresent() {
  if (!USE_SENSOR) return true; // без датчика ничего не проверяем, просто качаем
  pinMode(SENSOR, INPUT_PULLUP); // чтобы когда не будет воды, вывод не ловил наводки из эфира
  boolean retval = LOW == digitalRead(SENSOR); // если низкий уровень сигнала - значит есть контакт с землей, а значит есть вода
  pinMode(SENSOR, INPUT); // снимаем подтяжку к VCC для экономии энергии
  return retval;
}