# Uploading code to Raspberry Pico

#### Method 1 Using the UF2 binary file (easiest)

1. Need to complete steps from [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/README.md#software)

2. Find **pico.uf2** from the unzipped file you downloaded earlier in this previous step.

3. Press and hold the **BOOTSEL** button on the Raspberry Pico while connecting the USB cable to the PC. Once USB is connected to PC, release button.

<img src="https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/images/pico-bootsel.png" width="300" />

4. If successful, the Pico will show up as USB drive in File Explorer as **RPI-RP2**.

<img src="https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/images/rpi-rp2.png" width="500" />

5. Copy **pico.uf2** to the USB drive marked **RPI-RP2**. After copying, the USB drive will disappear, and the File Explorer window will possibly also close. The program has been successfully uploaded! This complete installation of Raspberry Pico.


#### Method 2 Using the Arduino IDE (harder)
You can pick out the important steps from [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/code/pico/BUILDING.md)


# Troubleshooting a Raspberry Pico

### Unbricking a Pico

If you need to hit the panic button, download this factory reset uf2 from [here](https://www.raspberrypi.org/documentation/pico/getting-started/static/6f6f31460c258138bd33cc96ddd76b91/flash_nuke.uf2)
