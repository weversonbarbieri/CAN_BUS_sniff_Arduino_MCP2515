#include <SPI.h>
#include <mcp2515.h>

// Define CAN message structure
struct can_frame canMsg;
// Create an instance of the MCP2515 class
// The constructor takes the CS pin number as an argument
// In this case, we are using pin 10 for the CS pin
MCP2515 mcp2515(10);


void setup() {
  // Initialize the serial communication at 115200 baud rate
  Serial.begin(115200);
  // Initialize the SPI communication
  SPI.begin();

  // Initialize the MCP2515 CAN controller
  // Set the CS pin to HIGH to deselect the MCP2515
  mcp2515.reset();
  // Set the baud rate to 33 kbps as per GMLAN LOW speed
  mcp2515.setBitrate(CAN_33KBPS);
  // Set the MCP2515 to normal mode
  mcp2515.setNormalMode();

  // Set the filter to accept all messages
  Serial.println("--------- CAN READ --------------");
  Serial.println("ID     DLC     DATA");
}

void loop() {
  // Check if there are any messages in the RX buffer
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    // Print the received message ID, DLC, and data
    Serial.print(canMsg.can_id, HEX);
    Serial.print(": ");
    // Print the DLC (Data Length Code) in hexadecimal format`
    Serial.print(canMsg.can_dlc, HEX);
    Serial.print(" ");

    // Print the data bytes in decimal format
    // Loop through the data bytes and print each byte
    for (int i = 0; i<canMsg.can_dlc; i++) {
      Serial.print(canMsg.data[i], DEC);
      Serial.print(" ");
    }

    Serial.println();
  }

}