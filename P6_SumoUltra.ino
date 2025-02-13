#include <AFMotor.h>
#define flpin A0           //ขา เซนเซอร์ พื้น ซ้าย
#define frpin A1           //ขา เซนเซอร์ พื้น ขวา
#define distanceL 20       //ระยะ จับศัตรู ซ้าย
#define distanceR 20       //ระยะ จับศัตรู ขวา
#define turnLdelay 50      // เลี้ยวจับศัตรู ซ้าย
#define turnRdelay 50      // เลี้ยวจับศัตรู ขวา
#define bootdelay 5000     // เวลาพุ่งเมื่อไม่เจอศัตรู
#define turnLline 250      // เวลาเลี้ยวเจอเส้นขาว ซ้าย
#define turnRline 250      // เวลาเลี้ยวเจอเส้นขาว ขวา
#define backdelayline 250  // เวลาถอยหลังเจอเส้นขาว ขวา
#define slowwalk 250       // เดินช้า
#include <NewPing.h>
#define SONAR_NUM 2              // Number of sensors.
#define MAX_DISTANCE 200         // Maximum distance (in cm) to ping.
NewPing sonar[SONAR_NUM] = {     // Sensor object array.
  NewPing(1, 6, MAX_DISTANCE),  // Each sensor's trigger pin, echo pin, and max distance to ping.
  NewPing(2, 5, MAX_DISTANCE)
};
AF_DCMotor ml(1);
AF_DCMotor mr(4);




//// อย่าไปแก้
bool testmode = 0;  //true false
int fl, fr;
unsigned long pre = 0;
void setup() {
  Serial.begin(9600);
  delay(5000);
  pre = millis();
}
void loop() {
  if (testmode) {
    rss();
    showss();
  } else {
    rss();
    if (fl == 0) {
      pre = millis();
      md(-200, -200);
      delay(backdelayline);
      md(200, -200);
      delay(turnLline);
    } else if (fr == 0) {
      pre = millis();
      md(-200, -200);
      delay(backdelayline);
      md(-200, 200);
      delay(turnRline);
    } else {
      delay(10);
      int sl = sonar[0].ping_cm();
      int sr = sonar[1].ping_cm();
      if (sl < distanceL && sl != 0) {
        md(-200, 200);
        delay(turnLdelay);
      } else if (sr < distanceR && sr != 0) {
        md(200, -200);
        delay(turnRdelay);
      } else if (millis() - pre > bootdelay) {
        md(255, 255);
      } else
        md(slowwalk, slowwalk);
    }
  }
}
