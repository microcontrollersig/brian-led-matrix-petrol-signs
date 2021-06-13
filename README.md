# Big LED Matrix from Petrol Pump Signage

#### Info

Here is the backside of one 16x16 panel up close and personal (Thanks to Brian D. for awesome shot).

![LED Panel](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/IMG_1820-redacted.jpg)

Important note: The 74HC245 operates at **3.3V**, and therefore any inputs connected to the 16-pin input connector has to operate at 3.3V.

Not the usual HUB08/HUB12/HUB40/HUB75 style setup. Inner workings [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/REVERSEENGINEER.md)

They usually come in 6 panels wide, 2 panels height (effectively becomes a 96x32 single-color LED matrix)

# Create PCB Controller for LED matrix

#### Bill of Materials

| Qty | |Code                                             | Where to Buy            | Optional |
| --- |---|-------------------------------------------------| ---------------------- | --------- |
| 1   | ![Pico](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/pico.jpg)|[Raspberry Pico](https://www.raspberrypi.org/documentation/rp2040/getting-started/) | [Pi Australia](https://raspberry.piaustralia.com.au/products/raspberry-pi-pico?variant=32587824070705)<br/>[Altronics](https://www.altronics.com.au/p/z6421-raspberry-pi-pico-microcontroller-board/)<br/>[Element 14](https://au.element14.com/raspberry-pi/raspberry-pi-pico/raspberry-pi-32bit-arm-cortex/dp/3643332)<br/>[Core Electronics](https://core-electronics.com.au/raspberry-pi-pico.html)|    N     |
| 1   | ![D1 mini](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/d1_mini_v3.1.0_1_16x16.jpg) | [ESP8266 Wemos D1 mini](https://www.wemos.cc/en/latest/d1/d1_mini.html)         | [Aliexpress - color: d1 mini](https://www.aliexpress.com/item/32651747570.html)  |    N     |
| 1   | ![16 Pin IDC](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/PP1138-16-pin-idc-locking-vertical-headerImageMain-515.jpg) | [16 Pin IDC Locking Vertical Header](https://www.jaycar.com.au/16-pin-idc-locking-vertical-header/p/PP1138) | Jaycar CAT.NO:PP1138| N | 
| 1   | ![Female Header](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/10pcs-lot-40P-female-header-1x40-Pin-2-54-Round-Female-Pin-Header-connector-1-40.jpg_Q90.jpg) | [Round Female Pin Header connector - snapable](https://www.aliexpress.com/item/32848204130.html)  | Aliexpress | Y | 


#### EAGLE Schematic for PCB Board
![schematic](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/eagle/Brians%20test%20board%2012-schematic.png)

#### EAGLE Board file for PCB Board

![board](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/eagle/Brians%20test%20board%2012.png)

### PCB Top Layer

![PCB Top Layer](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/eagle/jlcpcb-12-top.png)

#### PCB Bottom Layer

![PCB Bottom Layer](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/eagle/jlcpcb-12-bottom.png)

#### Raspberry Pi Pico

![pinout](https://www.raspberrypi-spy.co.uk/wp-content/uploads/2021/01/raspberry_pi_pico_pinout.png)

#### ESP8266 wemos d1 mini

![pinout](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/05/ESP8266-WeMos-D1-Mini-pinout-gpio-pin.png?w=715&quality=100&strip=all&ssl=1)

# Software

## Uploading code to Raspberry Pico

The purpose of the Raspberry Pico:

* update LED matrix 
* receive commands from the D1 mini via serial(RX).

You can either upload code using the Arduino IDE or simply use the binary file with extension **uf2**

Procedure for either method [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/tree/main/code/pico).

## Uploading code to D1 mini

You can either upload code using the Arduino IDE or using an ESP8266 flashing tool such as ESPHome Flasher and the binary file that ends with extension **bin**

Procedure for either method [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/tree/main/code/d1mini)

The purpose of the D1 mini:

* Present user with web interface for controlling LED matrix. 
* Send commands for the Pico to execute on the LED matrix via Serial(TX).

There are two modes of operation to connect:

* **Captive portal mode** 
  
  When you first use the D1 mini for the first time with the uploaded software provided, you will enter captive portal mode.
  
  Connect to a Wifi SSID created by the D1 mini
  
  Go to http://192.168.4.1 (depending on yout default browser, this may open automatically)


  Enter the username/password of your local wifi network, then click **Save and Connect**

  You now reconnect to your normal wifi network, and you will then need to find the IP address of the device on your network.
  Angry IP scanner is a good tool to use for this task. 
  
* **Normal mode** 
  
  If you have done the captival portal mode and saved your wifi password, subsequent reboots of the D1 mini will
  attempt to your wifi network. If it can't connect, you will fall back to captive portal mode.
  
  Else, if d1 mini establishes a wifi connection, you can then control the LED matrix with a webpage like the one below.
  
  

# References

* [How LED matrix was reverse engineered](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/REVERSEENGINEER.md)

* [Eagle file - schematic](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/eagle/Brians%20test%20board%2012.sch)

* [Eagle file - board](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/eagle/Brians%20test%20board%2012.brd)
