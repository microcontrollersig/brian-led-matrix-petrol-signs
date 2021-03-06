# Big LED Matrix from Petrol Pump Signage

#### Info

![LED Panel Demo](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/images/20210626_175707.jpg)

Not the usual HUB08/HUB12/HUB40/HUB75 style setup. Inner workings [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/REVERSEENGINEER.md)

They usually come in 6 panels wide, 2 panels height (effectively becomes a 96x32 single-color LED matrix)

# PCB Controller for LED matrix

![LED matrix controller](https://cdn.jsdelivr.net/gh/microcontrollersig/brian-led-matrix-petrol-signs@main/screenshots/20211204_105131.jpg)

![PCB controller](https://cdn.jsdelivr.net/gh/microcontrollersig/brian-led-matrix-petrol-signs@main/screenshots/20211204_105143.jpg)

#### Bill of Materials

| Qty |                                                                                                                                                                                             | Code                                                                                                          | Where to Buy                                                                                                                                                                                                                                                                                                                                                                                            | Required |
| --- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------- |
| 1   | ![Pico](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/pico.jpg)                                                                                   | [Raspberry Pico](https://www.raspberrypi.org/documentation/rp2040/getting-started/)                           | [Pi Australia](https://raspberry.piaustralia.com.au/products/raspberry-pi-pico?variant=32587824070705)<br/>[Altronics](https://www.altronics.com.au/p/z6421-raspberry-pi-pico-microcontroller-board/)<br/>[Element 14](https://au.element14.com/raspberry-pi/raspberry-pi-pico/raspberry-pi-32bit-arm-cortex/dp/3643332)<br/>[Core Electronics](https://core-electronics.com.au/raspberry-pi-pico.html) | Y        |
| 1   | ![D1 mini](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/d1_mini_v3.1.0_1_16x16.jpg)                                                                         | [ESP8266 Wemos D1 mini](https://www.wemos.cc/en/latest/d1/d1_mini.html)                                       | [Aliexpress - color: d1 mini](https://www.aliexpress.com/item/32651747570.html)                                                                                                                                                                                                                                                                                                                         | Y        |
| 1   | ![16 Pin IDC](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/PP1138-16-pin-idc-locking-vertical-headerImageMain-515.jpg)                                      | [16 Pin IDC Locking Vertical Header](https://www.jaycar.com.au/16-pin-idc-locking-vertical-header/p/PP1138)   | 16-pin ribbon header                                                                                                                                                                                                                                                                                                                                                                                    | Y        |
| 1   | ![buck converter](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/images/buckconverternew.png)                                                                 | [3.5A buck converter - color: 5V](https://www.aliexpress.com/item/33036075561.html)                           | Buck converter                                                                                                                                                                                                                                                                                                                                                                                          | Y        |
| 1   | ![Terminal block](https://images.altronics.com.au/prod_new/p/P2041.jpg)                                                                                                                     | [Terminal block](https://www.altronics.com.au/p/p2041a-dinkle-3-way-5.08mm-pcb-mount-terminal-block/)         | External power source                                                                                                                                                                                                                                                                                                                                                                                   | Y        |
| 1   | ![Disk Drive Power Connector Socket](https://www.jaycar.com.au/medias/sys_master/images/images/9526620946462/PS0742-disk-drive-power-connector-socketImageMain-515.jpg)                     | [Disk Drive Power Connector Socket](https://www.jaycar.com.au/disk-drive-power-connector-socket/p/PS0742)     | Power connector from LEDs to terminal block                                                                                                                                                                                                                                                                                                                                                             | N        |
| 1   | ![Female header](https://www.jaycar.com.au/medias/sys_master/images/images/9589136949278/HM3230-40-pin-female-header-stripImageMain-515.jpg)                                                | [Female header](https://www.jaycar.com.au/40-pin-female-header-strip/p/HM3230)                                | Female header for Pico                                                                                                                                                                                                                                                                                                                                                                                  | Y        |
| 1   | ![Right-angle connector](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/images/rightangleconnector.jpg)                                            | [Right-angle connector ](https://www.rockby.com.au/CatresultsSql_12.cfm?select=33&subcode=142&stock_no=27464) | Need for connecting buck converter                                                                                                                                                                                                                                                                                                                                                                      | Y        |
| 1   | ![Female Header](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/10pcs-lot-40P-female-header-1x40-Pin-2-54-Round-Female-Pin-Header-connector-1-40.jpg_Q90.jpg) | [Round Female Pin Header connector - snapable](https://www.aliexpress.com/item/32848204130.html)              | Aliexpress                                                                                                                                                                                                                                                                                                                                                                                              | N        |
| 1   | ![2N2222A](https://www.jaycar.com.au/medias/sys_master/images/images/9592372789278/ZT2298-2n2222a-npn-transistorImageMain-515.jpg)                                                          | [2N2222A NPN transistor](https://www.jaycar.com.au/2n2222a-npn-transistor/p/ZT2298)                           | Pico software-controlled reset switch                                                                                                                                                                                                                                                                                                                                                                   | N        |

#### EAGLE Schematic for PCB Board

![schematic](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/eagle/Brians%20test%20board%2018-schematic.png)

#### EAGLE Board file for PCB Board

![board](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/eagle/Brians%20test%20board%2018-board.png)

### PCB Top Layer

![PCB Top Layer](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/eagle/Brians%20test%20board%2018-top.png)

#### PCB Bottom Layer

![PCB Bottom Layer](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/eagle/Brians%20test%20board%2018-bottom.png)

#### Raspberry Pi Pico

![pinout](https://www.raspberrypi-spy.co.uk/wp-content/uploads/2021/01/raspberry_pi_pico_pinout.png)

#### ESP8266 wemos d1 mini

![pinout](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/05/ESP8266-WeMos-D1-Mini-pinout-gpio-pin.png?w=715&quality=100&strip=all&ssl=1)

# Software

Steps needed to complete software setup:

- Firmware needs to be uploaded to Pico, firmware also need to be uploaded to esp8266 D1 mini.
- wifi configuration of D1 mini.

In order to complete these steps, must first do the following steps on your computer:

- Download zip file containing firmware files and CH340 Windows driver for D1 mini from [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/releases/latest/download/brian-petrol-signs-easy-firmware-upload.zip) . Unzip the file to a known location on your computer.
- Download a ESP8266 flash utility. There are a number available, my preferred one is ESPHome-Flasher, which can be
  downloaded from [here](https://github.com/esphome/esphome-flasher/releases) .

## Uploading firmware to Raspberry Pico

[Click here for details](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/tree/main/code/pico).

## Uploading firmware to D1 mini and configuring wifi

[Click here for details](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/tree/main/code/d1mini)

# Roles of Microprocessors

## Pico

- update LED matrix
- receive commands from the D1 mini via serial(RX).

## ESP8266 D1mini

- Present user with web interface for controlling LED matrix.
- Send commands for the Pico to execute on the LED matrix via Serial(TX).

# References

- [How LED matrix was reverse engineered](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/REVERSEENGINEER.md)

- [Eagle files](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/tree/main/eagle)
