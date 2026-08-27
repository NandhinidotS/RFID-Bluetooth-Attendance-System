#include <SoftwareSerial.h>

// ===============================
// SERIAL CONNECTIONS
// ===============================

// EM-18
SoftwareSerial RFID(2, 3);   // RX, TX

// Bluetooth
SoftwareSerial BT(4, 5);     // RX, TX


// ===============================
// RFID CARD IDs
// ===============================

String nandhiniID = "4C003B61BFA9";
String narmadaID  = "4C003A04CCBE";


// ===============================
// ATTENDANCE STATUS
// ===============================

bool nandhiniIn = false;
bool narmadaIn  = false;


// ===============================
// SETUP
// ===============================

void setup() {

  Serial.begin(9600);

  RFID.begin(9600);
  BT.begin(9600);

  RFID.listen();

  Serial.println("RFID Attendance System");
  Serial.println("System Ready");
}


// ===============================
// MAIN LOOP
// ===============================

void loop() {

  RFID.listen();

  if (RFID.available()) {

    String cardID = "";

    // Read RFID card
    while (RFID.available()) {

      char c = RFID.read();

      if (c >= 32 && c <= 126) {
        cardID += c;
      }

      delay(2);
    }

    cardID.trim();

    // EM-18 card ID = 12 characters
    if (cardID.length() > 12) {
      cardID = cardID.substring(cardID.length() - 12);
    }

    // Ignore empty data
    if (cardID.length() == 0) {
      return;
    }


    // ===============================
    // NANDHINI S
    // ===============================

    if (cardID == nandhiniID) {

      if (nandhiniIn == false) {

        nandhiniIn = true;

        sendBoth(
          "Card ID: " + cardID,
          "Nandhini S -> IN"
        );

      } else {

        nandhiniIn = false;

        sendBoth(
          "Card ID: " + cardID,
          "Nandhini S -> LEAVE"
        );
      }
    }


    // ===============================
    // NARMADA C
    // ===============================

    else if (cardID == narmadaID) {

      if (narmadaIn == false) {

        narmadaIn = true;

        sendBoth(
          "Card ID: " + cardID,
          "Narmada C -> IN"
        );

      } else {

        narmadaIn = false;

        sendBoth(
          "Card ID: " + cardID,
          "Narmada C -> LEAVE"
        );
      }
    }


    // ===============================
    // UNKNOWN CARD
    // ===============================

    else {

      sendBoth(
        "Card ID: " + cardID,
        "Unknown RFID Card"
      );
    }


    // Prevent immediate repeated scanning
    delay(1500);

    RFID.listen();
  }
}


// =================================
// SEND TO SERIAL MONITOR + PHONE
// =================================

void sendBoth(String line1, String line2) {

  // Serial Monitor
  Serial.println(line1);
  Serial.println(line2);
  Serial.println();

  // Bluetooth
  BT.listen();

  BT.println(line1);
  BT.println(line2);
  BT.println();

  delay(10);

  RFID.listen();
}
