# Move Session Context: Lab 15 (MQTT & IoT)

เอกสารสรุปบริบท ความคืบหน้า และสิ่งที่ต้องทำต่อ สำหรับย้ายไปดำเนินการต่อใน Session หรือ Agent ถัดไป

---

## 1. ข้อมูลภาพรวม (Overview & Context)
* **วิชา / งาน**: Lab 15 - Internet of Things (IoT) & MQTT with Arduino UNO R4 WiFi
* **เอกสารอ้างอิง**: [`Lab15/docs/PC69-15_Micro04-IoT.pdf`](file:///home/lynn/Antix/Uniwork/cjudge/Lab15/docs/PC69-15_Micro04-IoT.pdf)
* **คลังโค้ดอ้างอิงอาจารย์**: https://github.com/ObeOne-KMITL/lab_iot (โคลนไว้อยู่ที่ [`Lab15/lab_iot`](file:///home/lynn/Antix/Uniwork/cjudge/Lab15/lab_iot))

---

## 2. โครงสร้างโฟลเดอร์ปัจจุบัน (Current Directory Structure)
โฟลเดอร์ถูกจัดระเบียบให้เรียบร้อยแล้ว โดยตัดความซ้ำซ้อนและคืนค่าโค้ดเป็น Default ดังนี้:

```text
Lab15/
├── README.md                          # สรุปโครงสร้างและสถานะของแล็บ
├── move.md                            # ไฟล์สรุปสถานะสำหรับย้าย session นี้
├── docs/
│   └── PC69-15_Micro04-IoT.pdf        # สไลด์เนื้อหาแล็บ
├── mqttviawebsocket1/                 # [งานหลักที่ต้องทำ] โฟลเดอร์งานทดลอง
│   ├── mqttviawebsocket1.ino          # Arduino Sketch (สถานะปัจจุบัน: ว่างเปล่า default setup/loop)
│   └── web/                           # ฝั่งเว็บเบราว์เซอร์ Dashboard
│       ├── control_rev1.html          # หน้า Dashboard ควบคุมผ่าน MQTT over Websocket (สถานะ: default)
│       ├── mqttws31.js                # ไลบรารี Paho MQTT JavaScript
│       └── bower_components/         # Bootstrap, NoUiSlider, Snackbar, Titatoggle
└── lab_iot/                           # โค้ดตัวอย่างจากอาจารย์
    ├── arduino_R4/
    │   ├── mqtt/mqtt.ino              # โค้ดแม่แบบเชื่อมต่อ WiFi + MQTT บน UNO R4
    │   ├── coap_client.ino
    │   └── coap_server.ino
    ├── mqtt/                          # ตัวอย่าง Python pub/sub
    └── websocket/                     # ตัวอย่าง WebSocket
```

---

## 3. โจทย์งานที่ต้องทำ: "แบบฝึกหัดที่ 1 MQTT Control via Websocket" (สไลด์หน้า 75)
### โจทย์
* ปรับปรุงไฟล์ `control_rev1.html` และโค้ด Arduino UNO R4 ให้สามารถ**ควบคุมการผสมสี Color LED (RGB LED)** ได้
* **เงื่อนไขตัวอย่าง**:
  1. `Red : ON` , `Green : OFF` , `Blue : ON` $\rightarrow$ หลอด Color LED แสดงผลเป็น **สีม่วง (Purple)**
  2. ผสมสีอื่นๆ เช่น Amber (ส้ม/เหลือง), White (ขาว), Red, Green, Blue

---

## 4. แผนการต่อวงจรฮาร์ดแวร์ (Hardware Wiring)
ใช้หลอด **RGB LED** (แนะนำแบบ Common Cathode):
* **Red (R)** $\rightarrow$ ผ่านตัวต้านทาน $220\,\Omega$ ต่อเข้าขา **Pin 9**
* **Green (G)** $\rightarrow$ ผ่านตัวต้านทาน $220\,\Omega$ ต่อเข้าขา **Pin 10**
* **Blue (B)** $\rightarrow$ ผ่านตัวต้านทาน $220\,\Omega$ ต่อเข้าขา **Pin 11**
* **Cathode (ขาร่วมยาวสุด)** $\rightarrow$ ต่อเข้า **GND** ของบอร์ด

*(หากใช้แบบ Common Anode ขาร่วมต่อ 5V ให้กลับตรรกะสัญญาณ `HIGH`/`LOW` ในโค้ด Arduino)*

---

## 5. แผนการแก้ไขโค้ดเมื่อเริ่ม Session ถัดไป (Implementation Plan)

### ก. ฝั่ง Web Dashboard (`Lab15/mqttviawebsocket1/web/control_rev1.html`)
1. กำหนด Topic ให้ตรงกัน (เช่น `var MQTTsubTopic = 'kmitl/lab15/rgb';` หรือตั้งตามต้องการ)
2. เพิ่ม UI สำหรับควบคุมสี:
   * ปุ่มเปิด-ปิดแยกสี:
     * Red: ส่งคำสั่ง `R_ON` / `R_OFF`
     * Green: ส่งคำสั่ง `G_ON` / `G_OFF`
     * Blue: ส่งคำสั่ง `B_ON` / `B_OFF`
   * ปุ่ม Preset ผสมสี: `PURPLE`, `AMBER`, `WHITE`, `ALL_OFF`
3. เชื่อมต่อ WebSocket Port: ปกติ `mqtt-dashboard.com` ใช้พอร์ต `8884` (WSS) หรือ `8000` (WS)

### ข. ฝั่ง Arduino (`Lab15/mqttviawebsocket1/mqttviawebsocket1.ino`)
1. นำโครงโค้ดจาก `Lab15/lab_iot/arduino_R4/mqtt/mqtt.ino` มาใช้
2. ตั้งค่าการเชื่อมต่อ:
   * `WIFI_SSID` และ `WIFI_PASSWORD` (จาก Hotspot ผู้ใช้)
   * `MQTT_BROKER_ADRRESS = "mqtt-dashboard.com"`
   * `MQTT_PORT = 1883`
   * `SUBSCRIBE_TOPIC` (ตรงกับใน `control_rev1.html`)
3. ในฟังก์ชัน `messageReceived(String &topic, String &payload)`:
   * เช็คเงื่อนไขข้อความที่ส่งมา (`R_ON`, `R_OFF`, `G_ON`, `G_OFF`, `B_ON`, `B_OFF`, หรือ preset)
   * อัปเดตสถานะของ `digitalWrite()` ไปยังขาสี R, G, B เพื่อให้ผสมสีตามโจทย์

### ค. ข้อควรระวังจากสไลด์ (หน้า 69)
* หากบอร์ด UNO R4 เชื่อมต่อ Broker ไม่ติด (ค้างที่ `.....`) ให้ตรวจสอบใน **Arduino IDE -> Boards Manager** แล้ว Downgrade หรือเลือกเวอร์ชันของ **Arduino UNO R4 Boards** ให้เป็น **`1.2.1`**
