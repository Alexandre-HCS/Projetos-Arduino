#include<LiquidCrystal.h>
LiquidCrystal lcd(19,18,17,16,15,14);
int money=10;
int pin;
int bet=1;
int Q=0;
char A[3][10]={"WIN","LOSE","Restart"};
int a=7,b=7,c=7;
int n_pin1=1,n_pin2=1;
int o_pin1=1,o_pin2=1;
void setup(){       ///LCD、SWの初期設定
  lcd.begin(16,2);
  lcd.clear();
  for(pin=8;pin<=12;pin++)
    pinMode(pin,INPUT_PULLUP);
}
void loop(){
  while(digitalRead(8)==1){  ///回転SWが押されるまで掛け金の設定のループ
    n_pin1=digitalRead(11);
    n_pin2=digitalRead(12);
    if(n_pin1==0 && o_pin1==1){
      if(bet>1)
      bet=bet-1;
    }
    if(n_pin2==0 && o_pin2==1){
      if(money>bet)
      bet=bet+1;
    }
    o_pin1=n_pin1;
    o_pin2=n_pin2;
    if(money<=0&&digitalRead(10)==0)
      money=10;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(A[Q]);
    lcd.setCursor(10,0);
    lcd.print(bet);
    lcd.setCursor(10,1);
    lcd.print(money);
    lcd.setCursor(0,1);
    lcd.print(a);
    lcd.setCursor(1,1);
    lcd.print(b);
    lcd.setCursor(2,1);
    lcd.print(c); 
    delay(100);
  }
  while(digitalRead(9)==1){    ///StopSWが押されるまで回転させる
    a=rand()%3;
    b=rand()%3;
    c=rand()%3;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PUSH!");
    lcd.setCursor(0,1);
    lcd.print(a);
    lcd.setCursor(1,1);
    lcd.print(b);
    lcd.setCursor(2,1);
    lcd.print(c);
    lcd.setCursor(10,0);
    lcd.print(bet);
    lcd.setCursor(10,1);
    lcd.print(money);
    delay(50);
  }
  money=money-bet;
  if(a==0&&b==0&&c==0){   ///「000」の場合の金額計算
    bet=bet*10; 
    money=money+bet;
    bet=bet/10;
    Q=0;
  }
  else if(a==1&&b==1&&c==1){   ///「111」の場合の金額計算
    bet=bet*50; 
    money=money+bet;
    bet=bet/50;
    Q=0;
  }
  else if(a==2&&b==2&&c==2){   ///「222」の場合の金額計算
    bet=bet*100; 
    money=money+bet;
    bet=bet/100;
    Q=0;
  }
  else if(a==0&&b==1&&c==2){   ///「012」の場合の金額計算
    money=money+bet;
    Q=2;
  }
  else   ///はずれの場合の金額計算
    Q=1;
  lcd.clear();
  lcd.setCursor(0,0);   ///結果の表示
  lcd.print(A[Q]);
  lcd.setCursor(0,1);
  lcd.print(a);
  lcd.setCursor(1,1);
  lcd.print(b);
  lcd.setCursor(2,1);
  lcd.print(c);
  lcd.setCursor(10,0);
  lcd.print(bet);
  lcd.setCursor(10,1);
  lcd.print(money);
  delay(10);
  while(digitalRead(10)==1);   ///ResetSWが押されるまで結果を表示し続ける
  }
