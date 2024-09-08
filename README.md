# RFID 

[실시간 시계](https://ko.wikipedia.org/wiki/%EC%8B%A4%EC%8B%9C%EA%B0%84_%EC%8B%9C%EA%B3%84)의 개념을 활용해서 아두이노로 시계를 만들어볼 것이다.


![img](https://nerdytechy.com/wp-content/uploads/2021/02/arduino-rtc-5-1024x677.png)

[![YouTube Channel Views](https://img.shields.io/youtube/channel/views/UCz5BOU9J9pB_O0B8-rDjCWQ?label=YouTube&style=social)](https://youtu.be/E6wkvTG2Ofs?si=k_IFc8MM8aGpZE7J)

## 하드웨어 

- 아두이노 우노  
- M-M 점퍼선 8개 
- USB 2.0 케이블 Type A/B


**주의: 점퍼선 연결시 케이블을 제거하고 진행합니다.**

### 선 작업 
#### 회로도
![img](/ppt/img/RTC_Arduino_fritzing.png)
#### 핀 정보
| [Arduino UNO GPIO](https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf) | DS3231 |
|-----------|------|
|   D19     | SCL  |
|   D18     | SDA  |
|   5V      | VCC  |
|   GND     | GND  |

| [Arduino UNO GPIO](https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf) | SSD1306 |
|-----------|------|
|   D19     | SCL  |
|   D18     | SDA  |
|   5V      | VCC  |
|   GND     | GND  |

### 구입처 

The stl files for an enclosure are on thingiverse [here](https://www.thingiverse.com/thing:6125748) (Thanks Ryan!).

## 순서도


## 라이브러리  
- [RFID](https://github.com/miguelbalboa/rfid)


## 응용하기  




