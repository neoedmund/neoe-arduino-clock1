# Neoe Clock 1

## Clock1 Story

A bad designed clock bought from cheap shop.
Instead of returning it, I hacked it.
Replaced STC15F204EA(8051) with arduino.
Replaced DS1302 with  DS3231.

analyzed PINs
![s1a](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s1a.jpg "s1a")
![s1](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s1.jpg "s1")


extend board
![准备好扩展板](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s2.jpg "准备好扩展板")

write program:
clock1.ino
in arduino UNO
![用arduino UNO调试成功](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s3.jpg "用arduino UNO调试成功")


released to arduino mini pro
![转到arduino mini pro](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s4.jpg "转到arduino mini pro")


soldering
![使用最艰苦的焊接](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s5.jpg "使用最艰苦的焊接")


success
![成功](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s6.jpg "成功")


Epilogue:
It seems the orignal clock is bad designed not only in software but also hardware. It blacked out a segment of LED after about a month.


## I made a successor Clock2. DIY from scratch.


![clock2](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/clock2.jpg "clock2")

Schematics is something like this, I lost it!
![Schematics](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/zpBOD.png "Schematics")

high lights:
* only 3 transistors (http://electronics.stackexchange.com/questions/233157/driving-large-common-anode-7-seg-led-with-npn-transistor-and-arduino-worked-but/233245#233245)
* only 3 LED, A=10 and b=11
* no button needed for adjusting time, thanks DS3231.
* worked 24x7 for more than 6 months and stable.



