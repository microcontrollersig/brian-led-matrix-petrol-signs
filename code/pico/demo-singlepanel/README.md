
# Demo for Single Panel

### Installation

#### Method 1 Using the UF2 binary file (easiest)

1. Download the UF2 binary file from [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/code/pico/demo-singlepanel/demo-singlepanel.uf2)

2. Press and hold the **BOOTSEL** button on the Raspberry Pico while connecting the USB cable to the PC. Once USB is connected to PC, release button.

<img src="https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/images/pico-bootsel.png" width="300" />

3. If successful, the Pico will show up as USB drive in File Explorer as **RPI-RP2**.

<img src="https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/images/rpi-rp2.png" width="500" />

4. Copy the UF2 binary file to the USB drive. After copying, the USB drive will disappear. The program has been
   successfully uploaded!


#### Method 2 Using the Arduino IDE (harder)

TODO

# Interacting with the demo from a Serial Monitor program

It is highly recommended to use MobaXterm for the demo.

The input format is:

{**command**}

Example:

{0}

Commands available

| Command |Description|
|---------|-----------|
|0|Top Left|
|1|Bottom right|
|2|Top right|
|3|Bottom left|
|4|Test Pattern 1|
|5|Snake Game|
|6|Single character|
|7|Multiple characters|
|8|Pong|
|@|IDLE|

