void md(int sl, int sr) {
  if (sl < 0) {
    sl = -sl;
    ml.run(BACKWARD);
  } else {
    ml.run(FORWARD);
  }
  if (sr < 0) {
    sr = -sr;
    mr.run(BACKWARD);
  } else {
    mr.run(FORWARD);
  }
  ml.setSpeed(sl);
  mr.setSpeed(sr);
}



void rss() {
  fl = digitalRead(flpin);
  fr = digitalRead(frpin);  
  }
void showss() {
  Serial.print(sonar[0].ping_cm());
  Serial.print("//");
  Serial.print(sonar[1].ping_cm());
  Serial.print("//");
  Serial.print(fl);
  Serial.print("//");
  Serial.println(fr);
  delay(300);
}
