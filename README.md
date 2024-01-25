# [AmbientIQ: Smart Home Controller with Pinecorn](https://ambientiq.dorik.io/) 
<a href=""><img src="Project_preview/Pinecone-1.jpg?raw=true" height="75"></a> 

AmbientIQ : A Sophisticated Smart Room Ecosystem for Ultimate Comfort and Efficiency. Our prototype addresses the critical role of indoor climate control in maintaining the well-being of individuals, particularly those vulnerable to health issues stemming from insufficient humidity and tempera- ture levels. At its core, our system features a DHT22 sensor, a micro-controller [Pinecone](https://wiki.pine64.org/wiki/PineCone#PineCone_BL602_EVB_information_and_schematics), relay switches, and wireless control options. The humidity sensor accurately monitors and controls humidity levels, while the temperature sensor finds the current temperature. In order to capture various signals from different sensors, the microcontroller[Pinecone](https://wiki.pine64.org/wiki/PineCone#PineCone_BL602_EVB_information_and_schematics), processes data and adjusts the heating device and humidifier accord- ing to user preferences. Android application will be used as a user interaction point with the system, where users can set convenient temperature and humidity levels and monitor the temperature and humidity range. An Android app that is connected to a microcontroller via WiFi provides realtime information about current temperature and humidity levels. The app also enables users to make decisions about balancing settings for their comfort and health

Key Features:
=====

+ ✏️ [Manual Control:]() Connected devices like Light, Heater, Humidifigher and so one can be controlled manually.

+ 🌟 [Automation:]() User can set temperature and humidity parameter through the app. If the Temperature is below, the heater will autometically turned on and if the heat in the room reach target temparature the the heater will auto matically turned off. And the same goes for humidity and humidifigher.
  
+ 🌟 [User-Friendly:]() The app's clean and user-friendly design ensures a seamless experience, making it suitable for users of all ages.
    
Pinecone
=======
[PineCone](https://pine64.com/product/pinecone-bl602-evaluation-board/) BL602 Evaluation Board(EVB). It is based on the BL602 SoC and has a 32-bit RISC-V microprocessor, 276kB RAM and 128kB ROM.It is an open- source IoT development board with builtin USB to Serial, PCB antenna, and USB-C connection. It supports Bluetooth Low Energy 5.0 and 2.4 GHz Wi-Fi. Also it offers 2MB Flash for pro- totyping IoT projects and features onboard LEDs, en- abling communication with the web application for real- time data visualization and notification delivery.



Multitasking
=======
In the super loop architecture, tasks are sequentially ex- ecuted within a loop. However, if a single task consumes excessive time, there is a risk of overlooking other tasks, such as sensor readings. To address this issue, simulta- neous execution of multiple tasks is necessary.
PineCone leverages the FreeRTOS operating system to run multiple tasks concurrently. This open-source, real-time, and lightweight OS is designed for resource- constrained devices and can seamlessly integrate into applications as a library.
Since PineCone has a single-core processor, the available CPU time must be distributed among tasks, necessitating the establishment of task priorities. Tasks that occur sooner or require more CPU time should be assigned higher priority. For instance, prioritizing user input tasks reduces lag and enhances the overall user ex- perience. The multitasking via FreeRTOS is illustrated in Figure 2.

The proposed system consists of three concurrent tasks: HTTPd task, Wi-Fi task and Sensor task. FreeR- TOS supports 32 priority levels, with 32 being the high- est. The priority settings of HTTPd task, Wi-Fi task and Sensor task are set to 20, 26, and 32 respectively.
The HTTPd task, or Hypertext Transfer Proto- col daemon, serves as an HTTP server implemented

through lightweight IP(lwIP). lwIP is an implementa- tion of TCP/IP protocol suite for embedded systems. The HTTPd task hosts HTTP services that can be ac- cessed by the client. It then waits for the incoming client requests and for each request, it responds with the re- quested information. In the proposed system, the server exposes an HTTP endpoint through which the client can get the water level in JSON format.
PineCone supports three Wi-Fi modes: the station mode, the access point mode and the combined station- access point mode. In the proposed system, the Wi-Fi task configures PineCone to function as a Wi-Fi access point. A Service Set Identifier(SSID) is configured for the created hotpot, to uniquely identify the Wi-Fi net- work. To enhance security, a password is also configured for the access point otherwise, the hotspot operates as an open access point.
The sensor task is responsible for obtaining the wa- ter level readings from the ultrasonic sensor, which is mounted on the top of the water tank. The water level in the tank changes continuously based on the user’s wa- ter consumption. So, the sensor operates concurrently to collect data at predefined intervals.

Hardware Specifications and Technical Implementations
=======
In terms of meeting industrial, social, and economic demands, the system must be sustainable. The following design specifications are specified in table for this project in order to meet the criteria of the proposed solution and to increase system efficiency:

| Element Name | Model Number | Rating |
|----------|----------|----------|
| Pinecone | BL602 | 5v |
| CPU Architecture | RICS-V |  |
|Sensor|DHT22|In 5v, Out 0-3.5v|
|Relay|SRD-05VDC-SL-C|In 3.5-5v, Out 10A 125v AC, 10A 28v DC|
|Heater||220v AC|
|Light||220v AC|
|Humidifier||220v AC|
|Microcontroller \\ Development colspan="3"|Language|C Programming|
||SDK|Bouffalolab/BL602 SDK|
||Wireless Communication | WiFi/LwIP|
|App Development|Android|Android Studio/JAVA|

Circuit Diagram:
=======
The heart of our project is PineCone[1](MCU) which is a BL602 evolution board. This board has multiple multipurpose digital or analog input/output GPIO pins. DHT22, which is an analog sensor, is directly connected to the MCU with an analog input GPIO pin. The pin is configured to have Direct Memory Access (DMA) there- fore, the sensor continuously writes its value directly to the memory. A task is running in parallel that is collecting the sensor data from the memory and con- verting it to human-readable format. The output pe- ripherals (light, heater, and humidifier) are controlled through digital signals and are therefore connected to digital pins.

Pins Configuration
||||
||||
||||
||||


Android Application
=======
The “[AmbientIQ](https://github.com/nazmos-sakib/AmbientIQ/tree/main)” Android application has developed to provide users with a visual representation of the water level in the tank. A red color signals a wa- ter shortage, while a green color indicates that the tank is nearing full capacity. The in-between water level is represented by a blue color.

Flashing Mode
=======
The blflash13 tool, a BL602 serial flasher written in Rust14 is used for flashing. Before initiating the flash, the PineCone is connected to the laptop via a Type-C USB cable and set to flashing mode. This involves po- sitioning the jumper on IO8 to cover IO8 and H(3.3V) and resetting the device using the reset button without repowering it. The firmware flashing process is executed through the “blflash flash” command in the terminal.

Operating Mode
=======
To run the program, the jumper on IO8 is set to cover IO8 and L(0V) and the reset button is pressed. The Web Serial Terminal, a tool from Google Chrome Labs, is then utilized to read the serial output from the PineCone. It is opened in the Chrome browser with a
13 https://github.com/spacemeowx2/blflash/releases 14 https://www.rust- lang.org/
    
baud rate of 2000000 and connected to the same serial port used for flashing.



## Project Preview

| <img src="Project_preview/PXL_20240123_140612173.jpg"> | <img src="Project_preview/PXL_20240123_140616207.jpg">  |<img src="Project_preview/PXL_20240123_140709664.jpg"> |
| ---------------------------------------------- | -------------------------------------------- | ------------------------------------------- | 

| <img src="Project_preview/PXL_20240123_140957827.jpg"> | <img src="Project_preview/PXL_20240123_141002799.jpg"> | <img src="Project_preview/PXL_20240123_141008928.MP.jpg"> |
| ------------------------------------------- | ------------------------------------------- | ------------------------------------------- |

<img src="Project_preview/Screenshot_20240123-132001.png" height="600">

[![Watch how it works Video](https://img.youtube.com/vi/YOUTUBE_VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=YOUTUBE_VIDEO_ID)

SDK Setup
=======
The proposed system utilizes a FreeRTOS-based IoT SDK provided by Bouffalo Labs11. The project is cre- ated inside the customer_app subdirectory in the SDK.

User Data Collection
=======
The app does not collect any user data.

[Download]()
========
Download AmbientIQ now and take controll of your room's ecosystem. Make your life easy and comfortable.

Results and Limitations
========
An Android app has been developed to control and mon- itor connected peripherals manually or to set automa- tion parameters. Fig 2 provides a close look of how the app looks like. In our testing, it has been concluded that the sensor data that are being collected are not too precise and accurate. There is always a 1 or 2 °C temperature difference between the sensor reading and actual temperature.


License
=======



# [Privacy Policy](https://sites.google.com/view/trinkbrunnen-privacy-policy/home)

If you choose to use my Service, then you agree to the collection and use of information in relation to this policy. The Personal Information that I collect is used for providing and improving the Service. I will not use or share your information with anyone except as described in this Privacy Policy. Further Details can be found [here]()


## Development version :hammer:
*   [APK (direct download)]()


## Support :rescue\_worker\_helmet:

If you need assistance or want to ask a question about the Android app, you are welcome to [ask for support](mailto:to.nazmos.sakib@gmail.com) in our Forums. If you have found a bug, feel free to [open a new Issue on GitHub](). Keep in mind, that this repository only manages the Android app. 

## Remarks :scroll:

Google Play and the Google Play logo are trademarks of Google Inc.
    
