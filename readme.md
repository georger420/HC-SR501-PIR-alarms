# HC-SR501 PIR Sensor  

The **HC-SR501** is a simple PIR sensor that detects movement, making it suitable for experiments and tinkering. It is produced by many manufacturers in Asia, but it seems that nobody knows who the original inventor and producer was.  

### PIR Alarms  

This repository contains three versions of PIR alarms, all of which meet the following requirements:  

- **Two stages controlled by a single button and indicated by LED diodes and different colors:**  
    - 🔴 **Alarm off**  
    - 🟢 **Alarm on**  

- **Detected movement is signaled by:**  
    - 💡 LED  
    - 🔊 Buzzer with an intermittent tone  

All three versions were first **designed and tested** on [WOKWI](https://wokwi.com/) before being physically built.  

### [PIR alarm using Raspberry Pi Pico](./PIR_alarm_RPi_Pico_CircuitPython/)

The fist version is built using Raspberry Pi Pico and modules **KY-004** (button), **KY-11** (two color LED), **KY-012** (active buzzer), and ofcourse **HC-SR501**. The code is written in **CircuitPython**. Regarding costs it is most expensive.

It can be tested on **WOKWI**:  [PIR simple intruder alarm](https://wokwi.com/projects/390164423145373697)


### [PIR alarm using no microcontroler but TTL circuits only](./PIR_alarm_no_microcontroller/)

Due to HC-SR501 features there is not necessary to use microcontroller for PIR alarm building. Several TTL or CMOS circuits and passive components can do the same. In this circuits is used TTL **74LS74** for switching alarm on and off by button, **NE555** circuit for periodaical switching of active buzzer and TTL **74LS00** for target logic. And ofcourse several resistors and capacitors. This version is probably most cheaper.

Also this version can be tested on **WOKWI**:  [PIR alarm without microcontroller](https://wokwi.com/projects/390273462188251137)

### [PIR alarm using ATTINY 85](./PIR_alarm_ATtiny85/)

This version has the simplest circuit. Due to the limited number of I/O pins — **ATTINY85** has only 5 I/O pins — two separate LEDs are used instead of a single two-color LED, both controlled by one I/O pin. **ATTINY85** was programmed using an **ARDUINO NANO** as a programmer. There are many articles on the internet explaining how to do this, for example [Programming ATtiny with Arduino code](https://wolles-elektronikkiste.de/en/programming-attiny-with-arduino-code). 

Testing circuit on **WOKWI**:[PIR alarm with ATtiny85](https://wokwi.com/projects/390709442157505537)

### Comments

A good idea is to combine a PIR sensor with a camera. This can be done using a Raspberry Pi and a Raspberry Pi camera — there are plenty of tutorials on the internet for this. However, a Raspberry Pi computer is unnecessarily powerful, and both the computer and the camera are too expensive for this purpose. Probably, an **ESP32-CAM** module would achieve the same result at a much lower cost.

PIR sensors are not only suitable for alarms. Nowadays, their most common use is to automatically switch lights on and off, for example, in public toilets, corridors, and staircases. To test this functionality, it should be enough to replace the buzzer with a suitable relay in the circuits described above and modify the code to replace the intermittent tone with a timer that has a sufficiently long delay — it is very annoying when the lights on a staircase (or in a toilet) switch off too soon. 

### Links

[Raspberry PI Pico](https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html#pico-1-family)

[CircuitPython](https://docs.circuitpython.org/en/latest/docs/index.html)

[ATTINY 85](https://www.laskakit.cz/user/related_files/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf)

[HC-SR501 datasheet](https://www.laskakit.cz/user/related_files/hc-sr501_datasheet.pdf)

[KY-004 module](https://arduinomodules.info/ky-004-key-switch-module/)

[KY-011 module](https://arduinomodules.info/ky-011-two-color-led-module-3mm/)

[KY-012 module](https://arduinomodules.info/ky-012-active-buzzer-module/)

[555 circuit](https://www.ti.com/lit/ds/symlink/ne555.pdf?ts=1746260938577)

[74LS74 circuit](https://www.ti.com/lit/ds/symlink/sn74ls74a.pdf)

[74LS00 circuit](https://www.ti.com/lit/ds/symlink/sn74ls00.pdf)

