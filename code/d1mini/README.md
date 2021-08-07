# Uploading software to D1 mini

### Prerequisite for Windows PC
1. Install Windows driver for D1 mini from [here](https://www.wemos.cc/en/latest/ch340_driver.html) 

### Use ESPHome Flasher (easiest method)

1. Download ESPHome Flasher [here](https://github.com/esphome/esphome-flasher/releases)
![ESPHome Flasher](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/images/esphomeflasher.jpg)

3. Download **d1mini.bin** binary file from [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/code/d1mini/d1mini.bin)
4. Flash.

### Use Arduino IDE (hard method)

See [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/code/d1mini/BUILDING.md)

# Usage

### Connecting to D1 mini webpage to control LED sign

There are two modes of operation to connect:

* **Captive portal mode** 
  
  When you first use the D1 mini for the first time with the uploaded software provided, you will enter captive portal mode.
  
  1. Connect to a Wifi SSID created by the D1 mini
  2. Go to http://192.168.4.1 (depending on your default browser, this may open automatically)


  Enter the Wifi network name (SSID) and password of your local wifi network, then click **Save and Connect**

  You now reconnect to your normal wifi network, and you will then need to find the IP address of the device on your network.
  Angry IP scanner is a good tool to use for this task. It should also display on the LED Matrix Panel.
  
* **Normal mode** 
  
  If you have done the captival portal mode and saved your wifi password, subsequent reboots of the D1 mini will
  attempt to connect to your local wifi network. The IP address should show up on the LED sign.  If it can't connect, you will fall back to captive portal mode.
  
  Enter the IP address in a web browser(Firefox/Chrome/Edge) and you should be able to control the LED sign.
