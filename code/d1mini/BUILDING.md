# Building

### Creating BIN file

esptool --port COM9 --baud 921600 read_flash 0x00000 0x400000 d1mini.bin
