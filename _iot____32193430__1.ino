int force = 0;
int buzzer = 13;
int ledPin = 7;
long cnt, mil;
int hour = 0, min = 0;
int check = 0; // 시간, 분, 초를 한 번만 출력하기 위한 변수
boolean state=false;
void setup(){ 
  Serial.begin(9600);
}

void loop(){
  force = analogRead(A0);
  if(force == 0){ // 스마트폰을 집어들었을 경우
    tone(13,160,500);
    digitalWrite(ledPin, HIGH);
    if(cnt > 0){ // 시간, 분, 초 출력
      if(check == 0){
        printTime(cnt, min, hour);
        check = 1;
      }
      delay(3600);
    }
      
  }
  
  else if(force >= 50){ // 스마트폰을 압력센서 위에 올려두었을 경우
    digitalWrite(ledPin, LOW);
    if((millis() - mil) >= 1000){
      mil = millis();
      check = 0;
      cnt++;
      
    }
    }
 else{}
  
  CalcuateTime(cnt);
}

void CalcuateTime(int c){ // 시간을 계산하는 함수
  min = (c/60)%60; // 분 계산
  hour = (c/(60*60))%24;  // 시간 계산 
}

void printTime(int c,int m,int h){ // 시간을 출력하는 함수
  
  Serial.print(h);
  Serial.print("h : ");
  Serial.print(m);
  Serial.print("m : ");
  Serial.print(c);
  Serial.println("s");
}