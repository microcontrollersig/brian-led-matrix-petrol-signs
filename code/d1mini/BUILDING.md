# Building

1. Install Arduino IDE
2. Install ESP8266 Arduino core from git , NOT the usual Boards Manager way. [Instructions here](https://arduino-esp8266.readthedocs.io/en/latest/installing.html#using-git-version)
3. Install LittleFS arduino plugin [here](https://github.com/earlephilhower/arduino-esp8266littlefs-plugin) 
4. Upload sketch as normal.
5. Tools->ESP8266 LittleFS Data Upload

### Creating BIN file

esptool --port COM9 --baud 921600 read_flash 0x00000 0x400000 d1mini.bin
