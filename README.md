# Instrument Cluster CAN Bus Reader

![C++](https://img.shields.io/badge/language-C++-blue.svg)
![Arduino](https://img.shields.io/badge/platform-Arduino-blue.svg)

## Description

This project uses an Arduino and the MCP2515 module to read the IDs and hexadecimal messages from the low-speed CAN network (GMLAN Low Speed) of a 2012 Chevrolet Cruze instrument cluster. The CAN network is a single-wire communication system operating at a speed of 33 Kbps.

## Components Used

- Arduino (UNO or similar)
- MCP2515 CAN Bus Module
- Power supply
- Breadboard and jumper wires
- 2012 Chevrolet Cruze instrument cluster
- Termination resistor (120 ohms, if required)

## Instrument Cluster Electrical Diagram

![image](https://github.com/user-attachments/assets/e2f15cab-0b67-4962-a6a8-ff0f4bd27791)


## How It Works

1. The MCP2515 module is configured to operate at 33 Kbps, matching the GMLAN Low Speed network.
2. The Arduino reads CAN messages received by the MCP2515.
3. The IDs and data of the messages are displayed in hexadecimal format on the serial monitor.

## Circuit Setup

1. Connect the MCP2515 module to the Arduino:
   - **INT**: Pin 2 on the Arduino
   - **CS**: Pin 10 on the Arduino
   - **SCK**: Pin 13 on the Arduino
   - **MOSI**: Pin 11 on the Arduino
   - **MISO**: Pin 12 on the Arduino
   - **VCC**: 5V from the Arduino
   - **GND**: GND from the Arduino

2. Connect the instrument cluster's low-speed CAN communication wire to the MCP2515's CANH pin.

3. Connect the instrument cluster's power supply and ground as follows:
   - The **CANH** pin of the MCP2515 connects to the instrument cluster's low-speed CAN wire.
   - The **ground** of the instrument cluster must be connected to the Arduino's GND.
   - The **ground** of the external power supply must also be connected to the Arduino's GND.

## Code

The code is located in the file [`src/main.cpp`](src/main.cpp). It configures the MCP2515 to operate at 33 Kbps and reads CAN messages, displaying the IDs and data on the serial monitor.

### Key Code Features

- **Baud Rate**: Configured to 33 Kbps using `CAN_33KBPS`.
- **Message Reading**: Reads CAN messages and prints the ID, DLC, and data bytes in the serial monitor.
- **Filter**: Configured to accept all messages.

Example output on the serial monitor:

 
40000615: 2 255 255
 
0: 8 0 126 2 0 0 0 0 0 
 
DFFCFF7F: 0 
0: 8 0 0 0 0 127 122 96 96 

800F7F7E: 8 0 0 0 0 0 0 0 0 

800E0FFF: 8 0 0 0 0 0 0 0 0 

DFFF0FFF: 8 255 255 255 255 255 248 255 127


## Demonstration Videos

Here are two videos showcasing the project in action:

1. **Serial Monitor Output**: This video demonstrates the serial monitor printing the CAN messages (IDs and data) in real-time.  
   (https://www.youtube.com/watch?v=zv51l-R-WCM)

2. **Circuit and Serial Monitor**: This video shows the physical circuit setup alongside the serial monitor displaying the CAN messages.  
   (https://www.youtube.com/shorts/67ETuiw3_Fw)



## Installation

1. Clone this repository:
   ```sh
   git clone [https://github.com/weversonbarbieri/instrument-cluster-can-reader](https://github.com/weversonbarbieri/CAN_BUS_sniff_Arduino_MCP2515.git)
   cd instrument-cluster-can-reader
