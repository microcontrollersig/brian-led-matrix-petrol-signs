# Uploading code to Raspberry Pico

#### Method 1 Using the UF2 binary file (easiest)

1. Download the UF2 binary file from [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/code/pico/demo-multipanel/demo-multipanel.uf2)

2. Press and hold the **BOOTSEL** button on the Raspberry Pico while connecting the USB cable to the PC. Once USB is connected to PC, release button.

<img src="https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/images/pico-bootsel.png" width="300" />

3. If successful, the Pico will show up as USB drive in File Explorer as **RPI-RP2**.

<img src="https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/images/rpi-rp2.png" width="500" />

4. Copy the UF2 binary file to the USB drive. After copying, the USB drive will disappear. The program has been
   successfully uploaded!


#### Method 2 Using the Arduino IDE (harder)
You can pick out the important steps from [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/code/pico/BUILDING.md)

# Extras

#### Fonts

[1001freefonts](https://www.1001freefonts.com/lcd-fonts.php)

# Troubleshooting a Raspberry Pico

### Unbricking a Pico

If you need to hit the panic button, download this factory reset uf2 from [here](https://www.raspberrypi.org/documentation/pico/getting-started/static/6f6f31460c258138bd33cc96ddd76b91/flash_nuke.uf2)
