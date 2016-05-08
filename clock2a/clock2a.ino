// A geek clock
// total 3 digit 7 seg
// 1st digit: hour 0-11 10:A 11:b
// 2nd, 3rd: min 00-59
#include <Wire.h>
#include "Sodaq_DS3231.h"

// switch this for different LED
#define low LOW
#define high HIGH



uint8_t segs[] = {
  B1111110, // 0
  B0011000, // 1
  B1101101, // 2
  B0111101, // 3
  B0011011, // 4
  B0110111, // 5
  B1110111, // 6
  B0011100, // 7
  B1111111, // 8
  B0111111, // 9
  B1011111, // A
  B1110011, // b
};

uint8_t segmap[]  = {
  13,12,11,7,8,9,10
};


DateTime now;
uint8_t  h2 = 0, m1 = 0, m2 = 0, s1 = 0, hour1=0, minute1=0, second1=0;
unsigned long hour, minute, second;
unsigned long t1=0,t2;


void setup ()
{
  //Serial.begin(57600);
  Wire.begin();
  for (int i = 4; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  rtc.begin();
  now = rtc.now();
}


// hh:mm
void showTime() {
    h2 = hour;
    m1 = minute / 10;
    m2 = minute % 10;
    s1 = second;

  if (h2 >= 12) {
  	h2 = h2 % 12;
  }


  showDigit(h2, 1, false, true);
  showDigit(m1, 2, true, true);
  showDigit(m2, 3, false, false);



}

void selectPos(uint8_t pos) {
  //clear
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmap[i], high);
  }
  // digitalWrite(segmap[7], low);
  // select position
  int ppos = 3+ pos;
  for ( int i = 4; i <= 6; i++) {
    if (ppos == i) {
      digitalWrite(i, low);
    } else {
      digitalWrite(i, high);
    }
  }
}
void showDot(boolean dot) {
  //if (dot) {
  //  digitalWrite(segmap[7], high);
  //} else {
  //  digitalWrite(segmap[7], low);
  //}
}

void showDigit(uint8_t digit, uint8_t pos, boolean reverse, boolean dot) {
  selectPos(pos);
  // output dot
  // showDot(dot);
  // output 7 seg
  int v = digit;
  if (v < 0) v = 0; if (v > 12) v = v % 12;
  v = segs[v];
  showRaw(v, reverse);
  delay(4);
}

void showRaw(uint8_t v, boolean reverse) {
  for (int i = 0; i < 7; i++) {
    boolean so = (v & B1000000) != 0;
    digitalWrite(segmap[i], so ? low: high);
    v = v << 1;
  }
}

void adjustTimeLocal() {
	int secAdd = (t2-t1)/1000;
	hour = hour1;
	minute = minute1;
	second = second1;
	second += secAdd;

	if (second >= 60 ){
		minute += second / 60;
		second %=  60;
	}
	if (minute >= 60){
		hour += minute/ 60;
		minute %= 60;
	}
	if (hour >= 24) {
		hour %= 24;
	}
}
void getRTC() {
    now = rtc.now(); // cost time
    hour1 = now.hour();
    minute1 = now.minute();
    second1 = now.second();
    t1 = millis();
}
void loop ()
{

  t2 = millis();
  if (t1==0||t2-t1>1000000){  //every 1000sec = 1000/60= 16.66666667 minutes
  	getRTC();
  }

  adjustTimeLocal();

  showTime();

}
