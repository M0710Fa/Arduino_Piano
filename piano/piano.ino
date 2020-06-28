/*
 * 宮田　悠冶
 * Arduinoピアノ
 * ボリューム抵抗で開始の「ド」の音の高さを変えられる白鍵のみのピアノ．(鍵盤数は8)．
 * ボリュームは２つあり片方は音の大きさを変えられる．
 * 黒鍵を含んだバージョンのコードも一応書いてある．
 */

int ad;//ボリューム保存
int pinNum = 13;//ボリュームのピン番号
int sound = 0;

//白鍵のみ
const int doremi[] = {0, 131 , 147 , 165 , 175 , 196 , 220 , 247 , 262 , 294 , 330 , 349 , 392 , 440 , 493 , 523 , 587 , 659 , 698 , 784 , 880 , 988 , 1047 , 1175 , 1319 , 1397 , 1568 , 1760 , 1976 , 2093};
const String dore[] = {"0", "C3", "D3", "E3", "F3", "G3", "A3", "B3", "C4", "D4", "E4", "F4", "G4", "A4", "B4", "C5", "D5", "E5", "F5", "G5", "A5", "B5", "C6", "D6", "E6", "F6", "G6", "A6", "B6", "C7"};
//黒鍵含む(末尾x)
const int doremix[] = {0, 220, 233, 247, 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880};
const String dorex[] = {"0", "A3", "A#3", "B3", "C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4", "C5", "C#5", "D5", "D#5", "E5", "F5", "F#5", "G5", "G#5", "A5"};

void setup() {
  //ボタンのピンをプルアップモードにする
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  
  /*
    pinMode(10, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);
  */
  
  Serial.begin(9600);
}

void loop() {
  ad = analogRead(A0);

  //抵抗から音階判定
  if(0<=ad&&ad<256)sound=1;
  else if(256<=ad&&ad<512)sound=8;
  else if(512<=ad&&ad<768)sound=15;
  else if(768<=ad&&ad<1024)sound=22;
  
  /*
    //黒鍵ありバージョン
    if (0 <= ad && ad < 73)sound = 1;
    else if (73 <= ad && ad < 146)sound = 2;
    else if (146 <= ad && ad < 219)sound = 3;
    else if (219 <= ad && ad < 292)sound = 4;
    else if (292 <= ad && ad < 365)sound = 5;
    else if (365 <= ad && ad < 438)sound = 6;
    else if (438 <= ad && ad < 511)sound = 7;
    else if (511 <= ad && ad < 584)sound = 8;
    else if (584 <= ad && ad < 657)sound = 9;
    else if (657 <= ad && ad < 730)sound = 10;
    else if (730 <= ad && ad < 803)sound = 11;
    else if (803 <= ad && ad < 876)sound = 12;
    else if (876 <= ad && ad < 949)sound = 13;
    else if (949 <= ad && ad < 1024)sound = 14;
  */
  
  Serial.println(dore[sound]);

  //鳴らす
  while (digitalRead(2) == LOW)tone(pinNum, doremi[sound]);
  while (digitalRead(3) == LOW)tone(pinNum, doremi[sound + 1]);
  while (digitalRead(4) == LOW)tone(pinNum, doremi[sound + 2]);
  while (digitalRead(5) == LOW)tone(pinNum, doremi[sound + 3]);
  while (digitalRead(6) == LOW)tone(pinNum, doremi[sound + 4]);
  while (digitalRead(7) == LOW)tone(pinNum, doremi[sound + 5]);
  while (digitalRead(8) == LOW)tone(pinNum, doremi[sound + 6]);
  while (digitalRead(9) == LOW)tone(pinNum, doremi[sound + 7]);
  
  /*
    while (digitalRead(10) == LOW)tone(13, doremi[sound + 8]);
    while (digitalRead(11) == LOW)tone(13, doremi[sound + 9]);
  */
  //音消す
  noTone(pinNum);
}
