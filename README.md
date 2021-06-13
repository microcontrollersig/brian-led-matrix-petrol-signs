# Big LED Matrix from Petrol Pump Signage

## Info

Here is the backside of one 16x16 panel up close and personal (Thanks to Brian D. for awesome shot).

![LED Panel](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/IMG_1820-redacted.jpg)

Important note: The 74HC245 operates at **3.3V**, and therefore any inputs connected to the 16-pin input connector has to operate at 3.3V.

Not the usual HUB08/HUB12/HUB40/HUB75 style setup. Inner workings [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/REVERSEENGINEER.md)

They usually come in 6 panels wide, 2 panels height (effectively becomes a 96x32 single-color LED matrix)

# Create PCB Controller for LED matrix

## Bill of Materials

| Qty | Code                                             | Where to Buy            | Optional |
| --- | -------------------------------------------------| ---------------------- |----------|
| 1   | [Raspberry Pico](https://www.raspberrypi.org/documentation/rp2040/getting-started/) | [Pi Australia](https://raspberry.piaustralia.com.au/products/raspberry-pi-pico?variant=32587824070705)  

[Altronics](https://www.altronics.com.au/p/z6421-raspberry-pi-pico-microcontroller-board/)

|    N     |
| 1   | [ESP8266 Wemos D1 mini](https://www.wemos.cc/en/latest/d1/d1_mini.html)         | 240 x 320 Touch screen |    N     |

## Raspberry Pi Pico

![pinout](https://www.raspberrypi-spy.co.uk/wp-content/uploads/2021/01/raspberry_pi_pico_pinout.png)

![pwm](https://i0.wp.com/www.etechnophiles.com/wp-content/uploads/2021/02/Screenshot-671.png)

![powertrain](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/pico-powertrain.png)

![schottky modification](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/pico-powertrain-schottky.png)

## ESP8266 wemos d1 mini

![pinout](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/05/ESP8266-WeMos-D1-Mini-pinout-gpio-pin.png?w=715&quality=100&strip=all&ssl=1)

![footprint](https://i0.wp.com/i.ibb.co/dQFPJr2/Board-de-desarrollo-We-Mos-D1-Mini-ESP32-Wi-Fi-Bluetooth-BLE-Dimensiones-768x499.jpg)

# PCB Design

Look [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/tree/main/eagle) for details.

# References

* [How LED matrix was reverse engineered](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/REVERSEENGINEER.md)
