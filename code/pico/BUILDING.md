# Building the UF2 file

Use the latest Arduino IDE (1.8.15 at the time of writing).

1. Install the Arduino Mbed board for RP2040 
   ![Mbed Arduino](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/images/mbedarduino.png)
2. In Arduino preferences, enable **Show verbose output during** for both compilation and upload.
3. Build. The last line will indicate the location of the **elf** binary file. You will need access to this file.
4. Install elf2uf2 tool from the Pico SDK.

   On Windows, install msys2, then:
   ```shell
   pacman -Syuu
   pacman -S base-devel gcc make cmake git
   git clone  https://github.com/raspberrypi/pico-sdk
   cd pico-sdk/tools/elf2uf2
   mkdir build
   cd build
   cmake ..
   make
   ./elf2uf2 -v <name_of_binary.elf> <name_of_binary.uf2>
   ```
5. You can upload to Pico as normal in Arduino IDE if you don't need the UF2 file.
