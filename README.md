# Big LED Matrix from Petrol Pump Signage

#### Info

Here is the backside of one 16x16 panel up close and personal (Thanks to Brian D. for awesome shot).

![LED Panel](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/IMG_1820-redacted.jpg)

Important note: The 74HC245 operates at **3.3V**, and therefore any inputs connected to the 16-pin input connector has to operate at 3.3V.

Not the usual HUB08/HUB12/HUB40/HUB75 style setup. Inner workings [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/REVERSEENGINEER.md)

They usually come in 6 panels wide, 2 panels height (effectively becomes a 96x32 single-color LED matrix)

# Create PCB Controller for LED matrix

#### Bill of Materials

| Qty | Code                                             | Where to Buy            | Optional |
| --- | -------------------------------------------------| ---------------------- |----------|
| 1   | [Raspberry Pico](https://www.raspberrypi.org/documentation/rp2040/getting-started/) | [Pi Australia](https://raspberry.piaustralia.com.au/products/raspberry-pi-pico?variant=32587824070705)<br/>[Altronics](https://www.altronics.com.au/p/z6421-raspberry-pi-pico-microcontroller-board/)<br/>[Element 14](https://au.element14.com/raspberry-pi/raspberry-pi-pico/raspberry-pi-32bit-arm-cortex/dp/3643332)<br/>[Core Electronics](https://core-electronics.com.au/raspberry-pi-pico.html)|    N     |
| 1   | [ESP8266 Wemos D1 mini](https://www.wemos.cc/en/latest/d1/d1_mini.html)         | [Aliexpress - color: d1 mini](https://www.aliexpress.com/item/32651747570.html)  |    N     |
| 1   | [16 Pin IDC Locking Vertical Header](https://www.jaycar.com.au/16-pin-idc-locking-vertical-header/p/PP1138) | Jaycar CAT.NO:PP1138| N | 

#### EAGLE Schematic for PCB Board
![schematic](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/eagle/Brians%20test%20board%2012-schematic.png)

#### EAGLE Board file for PCB Board

![board](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/eagle/Brians%20test%20board%2012.png)

### PCB Top Layer

#### PCB Bottom Layer

#### Raspberry Pi Pico

![pinout](https://www.raspberrypi-spy.co.uk/wp-content/uploads/2021/01/raspberry_pi_pico_pinout.png)

#### ESP8266 wemos d1 mini

![pinout](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/05/ESP8266-WeMos-D1-Mini-pinout-gpio-pin.png?w=715&quality=100&strip=all&ssl=1)

# References

* [How LED matrix was reverse engineered](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/REVERSEENGINEER.md)

* [Eagle file - schematic](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/eagle/Brians%20test%20board%2012.sch)

* [Eagle file - board](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/eagle/Brians%20test%20board%2012.brd)
