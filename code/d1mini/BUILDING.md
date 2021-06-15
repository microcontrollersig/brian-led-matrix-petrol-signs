# Building

1. Install Arduino IDE
2. Install ESP8266 Arduino core from git , NOT the usual Boards Manager way. [Instructions here](https://arduino-esp8266.readthedocs.io/en/latest/installing.html#using-git-version)
3. Install LittleFS arduino plugin [here](https://github.com/earlephilhower/arduino-esp8266littlefs-plugin) 
4. Upload sketch as normal.
5. Tools->ESP8266 LittleFS Data Upload

# ESP8266 Flash Layout

![ESP8266 Flash Layout](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/images/esp8266flashlayout.svg)

### Creating BIN file

```shell
esptool --port COM9 --baud 921600 read_flash 0x00000 0x400000 d1mini.bin
```
