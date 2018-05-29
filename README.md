![PROJECT_PHOTO](https://github.com/AlexGyver/Auto_Pump_Sleep/blob/master/proj_img.jpg)
# Простейшая система авто полива
* [Описание проекта](#chapter-0)
* [Папки проекта](#chapter-1)
* [Схемы подключения](#chapter-2)
* [Материалы и компоненты](#chapter-3)
* [Как скачать и прошить](#chapter-4)
* [FAQ](#chapter-5)
* [Полезная информация](#chapter-6)
[![AlexGyver YouTube](http://alexgyver.ru/git_banner.jpg)](https://www.youtube.com/channel/UCgtAOyEQdAyjvm9ATCi_Aig?sub_confirmation=1)

<a id="chapter-0"></a>
## Описание проекта
Автополив на Digispark
Особенности:
- Простейшая схема: мосфет модуль и помпа
- Режим глубокого энрегосбережения: 30 мкА в режиме сна
- Недорогая платформа Digispark
- Подробности в видео: https://youtu.be/zV0Yx5-yNdw

<a id="chapter-1"></a>
## Папки
**ВНИМАНИЕ! Если это твой первый опыт работы с Arduino, читай [инструкцию](#chapter-4)**
- **libraries** - библиотеки проекта
- **digi_pump** - прошивка из видео
- **digi_servo_sleep** - прошивка для серво (не забудьте установить библиотеку)
- **schemes** - схемы подключения

<a id="chapter-2"></a>
## Схемы
![SCHEME](https://github.com/AlexGyver/Auto_Pump_Sleep/blob/master/schemes/scheme1.jpg)
![SCHEME](https://github.com/AlexGyver/Auto_Pump_Sleep/blob/master/schemes/scheme2.jpg)
![SCHEME](https://github.com/AlexGyver/Auto_Pump_Sleep/blob/master/schemes/modif.jpg)

<a id="chapter-3"></a>
## Материалы и компоненты
### Ссылки оставлены на магазины, с которых я закупаюсь уже не один год
### Почти все компоненты можно взять в магазине WAVGAT по первым ссылкам
* Digispark http://ali.pub/2jm331
* Мосфет модуль http://ali.pub/2jm33m
* Батарейный отсек 4xAA http://ali.pub/2jm365
* Отсек 3-4 АА (другой магаз) http://ali.pub/2jm3bs
* Отсек как на видео (другой магаз) http://ali.pub/2jm3cr
* Транзисторы, конденсаторы и резисторы - в ЛЮБОМ магазине радиодеталей
* Шланг http://ali.pub/2jm3e4
* Тройнички http://ali.pub/2jm3ep
* Разветвитель http://ali.pub/2jm3f3

## Вам скорее всего пригодится
* [Всё для пайки (паяльники и примочки)](http://alexgyver.ru/all-for-soldering/)
* [Недорогие инструменты](http://alexgyver.ru/my_instruments/)
* [Все существующие модули и сенсоры Arduino](http://alexgyver.ru/arduino_shop/)
* [Электронные компоненты](http://alexgyver.ru/electronics/)
* [Аккумуляторы и зарядные модули](http://alexgyver.ru/18650/)

<a id="chapter-4"></a>
## Как скачать и прошить
* [Первые шаги с Arduino](http://alexgyver.ru/arduino-first/) - ультра подробная статья по началу работы с Ардуино, ознакомиться первым делом!
* Скачать архив с проектом
> На главной странице проекта (где ты читаешь этот текст) вверху справа зелёная кнопка **Clone or download**, вот её жми, там будет **Download ZIP**
* Установить библиотеки в  
`C:\Program Files (x86)\Arduino\libraries\` (Windows x64)  
`C:\Program Files\Arduino\libraries\` (Windows x86)
* Подключить Ардуино к компьютеру
* Запустить файл прошивки (который имеет расширение .ino)
* Настроить IDE (COM порт, модель Arduino, как в статье выше)
* Настроить что нужно по проекту
* Нажать загрузить
* Пользоваться  

## Настройки в коде
    #define PERIOD 5       // период работы в секундах
    #define WORK 5         // время работы в секундах
    #define MOS 1          // пин мосфета
<a id="chapter-5"></a>
## FAQ
### Основные вопросы
В: Как скачать с этого грёбаного сайта?  
О: На главной странице проекта (где ты читаешь этот текст) вверху справа зелёная кнопка **Clone or download**, вот её жми, там будет **Download ZIP**

В: Скачался какой то файл .zip, куда его теперь?  
О: Это архив. Можно открыть стандартными средствами Windows, но думаю у всех на компьютере установлен WinRAR, архив нужно правой кнопкой и извлечь.

В: Я совсем новичок! Что мне делать с Ардуиной, где взять все программы?  
О: Читай и смотри видос http://alexgyver.ru/arduino-first/

В: Вылетает ошибка загрузки / компиляции!
О: Читай тут: https://alexgyver.ru/arduino-first/#step-5

В: Сколько стоит?  
О: Ничего не продаю.

### Вопросы по этому проекту

<a id="chapter-6"></a>
## Полезная информация
* [Мой сайт](http://alexgyver.ru/)
* [Основной YouTube канал](https://www.youtube.com/channel/UCgtAOyEQdAyjvm9ATCi_Aig?sub_confirmation=1)
* [YouTube канал про Arduino](https://www.youtube.com/channel/UC4axiS76D784-ofoTdo5zOA?sub_confirmation=1)
* [Мои видеоуроки по пайке](https://www.youtube.com/playlist?list=PLOT_HeyBraBuMIwfSYu7kCKXxQGsUKcqR)
* [Мои видеоуроки по Arduino](http://alexgyver.ru/arduino_lessons/)