# Lab 15: Internet of Things (IoT) & MQTT with Arduino UNO R4 WiFi

โครงสร้างโฟลเดอร์สำหรับ **Lab 15** (จัดระเบียบเรียบร้อย โค้ดกลับเป็น Default เริ่มต้น):

```text
Lab15/
├── README.md                          <- คำอธิบายโครงสร้างและวิธีทำแล็บ
├── docs/                              <- เอกสารการสอน
│   └── PC69-15_Micro04-IoT.pdf
├── mqttviawebsocket1/                 <- โฟลเดอร์งานทดลองที่ 6 / แบบฝึกหัดที่ 1
│   ├── mqttviawebsocket1.ino          <- โค้ด Arduino เริ่มต้น (Default)
│   └── web/                           <- โค้ด Dashboard เริ่มต้นจาก web.rar (Default)
│       ├── control_rev1.html          <- หน้าเว็บ Dashboard ควบคุมผ่าน MQTT Websocket
│       ├── mqttws31.js                <- Paho MQTT JavaScript Library
│       └── bower_components/         <- CSS/JS Libraries (Bootstrap, NoUiSlider)
└── lab_iot/                           <- โค้ดตัวอย่างอ้างอิงจาก Repository ของอาจารย์
    ├── arduino_R4/                    <- ตัวอย่างโค้ดบน UNO R4 (MQTT, CoAP)
    ├── mqtt/                          <- ตัวอย่างสคริปต์ MQTT Python
    └── websocket/                     <- ตัวอย่าง WebSocket
```

---

## สรุปสถานะไฟล์ปัจจุบัน (Default State)
1. **[`mqttviawebsocket1.ino`](file:///home/lynn/Antix/Uniwork/cjudge/Lab15/mqttviawebsocket1/mqttviawebsocket1.ino)**:
   * กลับสู่สถานะว่างเปล่าเริ่มต้น (`setup()` / `loop()`)
   * สามารถนำโค้ดต้นแบบจาก `Lab15/lab_iot/arduino_R4/mqtt/mqtt.ino` มาเริ่มต้นพัฒนาได้
2. **[`control_rev1.html`](file:///home/lynn/Antix/Uniwork/cjudge/Lab15/mqttviawebsocket1/web/control_rev1.html)**:
   * กลับสู่ไฟล์ต้นฉบับดั้งเดิม (ปุ่ม ON, OFF และ Slider 0-100)
   * ชี้ไปที่ Topic ค่าเริ่มต้น `panwit/temp` บน Broker `mqtt-dashboard.com:8884`
