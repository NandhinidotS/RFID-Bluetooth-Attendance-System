# RFID Bluetooth Attendance System

## 📌 Description

An Arduino-based RFID attendance system using an **EM-18 RFID Reader** and **HC-05 Bluetooth Module** to identify registered users and track their **IN/LEAVE** status.

The attendance details are displayed on the **Serial Monitor** and transmitted to a **mobile phone via Bluetooth**.

## 🔧 Components

- Arduino NANO
- EM-18 RFID Reader
- HC-05 Bluetooth Module
- RFID Cards/Tags
- Breadboard
- Jumper Wires

## ⚡ Features

- RFID-based user identification
- IN / LEAVE attendance tracking
- Registered and unknown card detection
- Bluetooth data transmission
- Serial Monitor output
- Repeated-scan protection

## 🔌 Pin Connections

| Component | Arduino NANO |
|---|---|
| EM-18 TX | D2 |
| EM-18 RX | D3 |
| HC-05 TX | D4 |
| HC-05 RX | D5 |
| EM-18 VCC | 5V |
| EM-18 GND | GND |
| HC-05 VCC | 5V |
| HC-05 GND | GND |

## 🆔 Registered RFID Cards

| User | RFID Card ID |
|---|---|
| Nandhini S | `4C003B61BFA9` |
| Narmada C | `4C003A04CCBE` |

## 🔄 Working

1. EM-18 scans the RFID card.
2. Arduino reads the RFID card ID.
3. The ID is compared with the registered IDs.
4. First valid scan marks the user as **IN**.
5. The next scan marks the user as **LEAVE**.
6. Unknown cards are identified as **Unknown RFID Card**.
7. The result is sent to the Serial Monitor and mobile phone through Bluetooth.

## 📱 Example Output

```text
Card ID: 4C003B61BFA9
Nandhini S -> IN

Card ID: 4C003B61BFA9
Nandhini S -> LEAVE

Card ID: 4C003A04CCBE
Narmada C -> IN

Card ID: XXXXXXXXXXXX
Unknown RFID Card
```

## 💻 Software

- Arduino IDE
- Arduino C/C++
- SoftwareSerial Library

## 📸 Project Photos

### Hardware Setup

![RFID Bluetooth Attendance System](RFID%20Bluetooth%20Attendance%20System.jpeg)

### Project Working

![Project Working](Project%20Working.jpeg)

### Bluetooth Attendance Output

![Bluetooth Output](Bluetooth%20Output.jpeg)