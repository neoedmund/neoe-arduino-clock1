// A modern geek clock
// first digit: second in binary, 2nd: hour 0-c
#include <Wire.h>
#include "Sodaq_DS3231.h"

// switch this for different LED
#define low HIGH
#define high LOW



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
  B1100001, // c
};

uint8_t segmap[]  = {
  8, 7, 6, 5, 4, 9, 3, 2
};

uint8_t segmap_reversed []  = {
  5, 4, 9, 8, 7, 6, 3, 2
};

DateTime now;

void setup ()
{
  //Serial.begin(57600);
  //Wire.begin();
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  rtc.begin();
  now = rtc.now();
}

uint32_t old_ts;


// hh:mm
void showTime(uint8_t s1, uint8_t h2, uint8_t m1, uint8_t m2) {
  
  boolean dot1 = false;
  if (h2>12) {
  	dot1 = true;
  	h2 = h2 % 12;
  }
  
  showDigit(h2, 2, false, true);
  showDigit(m1, 3, true, true);
  showDigit(m2, 4, false, false);
  
  selectPos(1);
  showDot(dot1);
  showRaw2(s1, false);  
  delay(3);

}

void selectPos(uint8_t pos) {
  //clear
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmap[i], low);
  }
  digitalWrite(segmap[7], low);
  // select position
  int ppos = 14 - pos;
  for ( int i = 10; i <= 13; i++) {
    if (ppos == i) {
      digitalWrite(i, high);
    } else {
      digitalWrite(i, low);
    }
  }
}
void showDot(boolean dot) {
  if (dot) {
    digitalWrite(segmap[7], high);
  } else {
    digitalWrite(segmap[7], low);
  }  
}
/**
  digit 0-9
  pos: 1,2,3,4
*/
void showDigit(uint8_t digit, uint8_t pos, boolean reverse, boolean dot) {
  selectPos(pos);
  // output dot
  showDot(dot);
  // output 7 seg 
  int v = digit;
  if (v < 0) v = 0; if (v > 12) v = v % 12;
  v = segs[v];
  showRaw(v, reverse);
  delay(3);
}

void showRaw(uint8_t v, boolean reverse) {
  for (int i = 0; i < 7; i++) {
    boolean so = (v & B1000000) != 0;
    if (reverse) {
      digitalWrite(segmap_reversed[i], so ? high : low);
    } else {
      digitalWrite(segmap[i], so ? high : low);
    }
    v = v << 1;
  }
}

void showRaw2(uint8_t v, boolean reverse) {
  for (int i = 0; i < 7; i++) {
    boolean so = (v & 1) != 0;
    if (reverse) {
      digitalWrite(segmap_reversed[i], so ? high : low);
    } else {
      digitalWrite(segmap[i], so ? high : low);
    }
    v = v >> 1;
  }
}
int cnt = 0;
uint8_t h1 = 0, h2 = 0, m1 = 0, m2 = 0, s1 = 0;
void loop ()
{

  if (cnt++ % 83 == 0) {
    now = rtc.now();
    uint8_t  hour = now.hour();
    uint8_t  minute = now.minute();
    uint8_t  second = now.second();
    h1 = hour;
    m1 = minute / 10;
    m2 = minute % 10;
    s1 = second;
  }
  
  showTime(s1, h1, m1, m2);

}
