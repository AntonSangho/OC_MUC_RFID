//RFID 등록된 태그 ID로 서보모터 제어하기
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

//SS(Slave Selector)핀 및 reset 핀 번호 정의
#define SS_PIN 10
#define RST_PIN 9
//MFRC522 클래스로 rfid 객체 및 서보모터 객체 선언
MFRC522 rfid(SS_PIN, RST_PIN);
Servo servo;
//등록할 태그 ID 배열
//int tagId[4] = {121, 183, 127, 72};
int tagId[4] = {170, 67, 117, 189};
//핀번호 및 각도 변수 선언
int servoPin = 7, agl = 0;

void setup() {
  //시리얼 통신 및 SPI 초기화
  Serial.begin(9600);
  SPI.begin();
  //MFRC522 초기화
  rfid.PCD_Init();
  //서보모터 연결 핀 설정 및 각도 초기화
  servo.attach(servoPin);
  servo.write(agl);
}

void loop() {
  //태그가 접촉 되지 않았거나 ID가 읽혀지지 않았을 때
  if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()){
    agl = 0;
    servo.write(agl);
    delay(300);
    return;
  }
  int same = 0;
  //태그의 ID 출력하기(rfid.uid.uidByte[0] ~ rfid.uid.uidByte[3] 출력)
  Serial.print("Card Tag ID: ");
  for(byte i=0; i<4; i++){
    Serial.print(rfid.uid.uidByte[i]);
    Serial.print(" ");
    //인식된 태그와 등록된 태그 번호 일치 여부
    if(rfid.uid.uidByte[i] == tagId[i]){
      same++; //모두 맞다면 same 변수는 4가 됨.
    }
  }
  Serial.println();
  if(same == 4){
    Serial.println("태그 ID가 일치합니다.");
    agl = 90;
    servo.write(agl);
    delay(1000);
  }else{
    Serial.println("등록된 태그 ID가 아닙니다.");
  }
}
