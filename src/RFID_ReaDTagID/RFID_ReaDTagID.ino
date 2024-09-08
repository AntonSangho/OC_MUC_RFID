//RFID 태그 ID 읽어오기
#include <SPI.h>
#include <MFRC522.h>

//SS(Slave Selector)핀 및 reset 핀 번호 정의
#define SS_PIN 10
#define RST_PIN 9

//MFRC522 클래스로 rfid 객체 선언
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  //시리얼 통신 및 SPI 초기화
  Serial.begin(9600);
  SPI.begin();

  //MFRC522 초기화
  rfid.PCD_Init();
}

void loop() {
  //태그가 접촉 되지 않았거나 ID가 읽혀지지 않았을 때
  if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()){
    delay(300);
    return;
  }

  //태그의 ID 출력하기(rfid.uid.uidByte[0] ~ rfid.uid.uidByte[3] 출력)
  Serial.print("Card Tag ID: ");
  for(byte i=0; i<4; i++){
    Serial.print(rfid.uid.uidByte[i]);
    Serial.print(" ");
  }
  Serial.println();
}
