# Neoe Clock 1

## 故事 （Story）

从淘宝买了一个1英寸的4位8段数码管时钟DIY套件，可是不能用，，，卖家也不给程序。
于是我自己改装。

用arduino代替STC15F204EA(8051)，因为arduino开发方便我也熟悉。
用DS3231代替DS1302,因为DS3231精度1年最多2分钟，DS1302精度估计一周会有1分钟。

另外，我只要显示时间，一次设置好了，永远（好几年吧）不需要调整。


首先，先破解出接口PIN
![s1a](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s1a.jpg "s1a")
![s1](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s1.jpg "s1")


准备好扩展板

![准备好扩展板](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s2.jpg "准备好扩展板")

写程序
clock1.ino
用arduino UNO调试成功

![用arduino UNO调试成功](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s3.jpg "用arduino UNO调试成功")


然后转到arduino mini pro上，这个调试不方便，但是体积小。相当于debug到release版本。
![转到arduino mini pro](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s4.jpg "转到arduino mini pro")


使用最艰苦的焊接
![使用最艰苦的焊接](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s5.jpg "使用最艰苦的焊接")


成功！
![成功](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s6.jpg "成功")

成功了！
![成功2](https://github.com/neoedmund/neoe-arduino-clock1/raw/master/pic/s6a.jpg "成功2")

