# Uploading software to D1 mini

### Prerequisite for Windows PC
1. Download Windows driver for D1 mini from [here](https://www.wemos.cc/en/latest/ch340_driver.html) 
2. Unzip CH341SER_WIN_3.5.ZIP .
3. Open the CH341SER_WIN_3.5 folder and run SETUP.EXE

Alternatively, a copy of the windows driver is also included in the zip file you download in the next step.

### Use ESPHome Flasher (easiest method)

1. Need to complete steps from [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/README.md#Software)
2. Find **d1mini.bin** inside the unzipped folder you downloaded in previous step.
4. Open ESPHome-Flasher
    - Select Serial port
    - On the Firmware line, click **Browse** and open the **d1mini.bin** file
    - Press **Flash ESP** button
    - Wait for firmare to upload, don't close the program yet, go down to the section **Need to configure D1 mini**     

### Use Arduino IDE (hard method)

See [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/code/d1mini/BUILDING.md)

# Need to configure D1 mini

After you click **Flash ESP** and the firmwware is uploaded, the D1 mini will restart and boot for the first time.

The first thing that happens is that it creates a Wifi network called **brianLEDPanels** with an IP address of **192.168.4.1** 

Here are the steps you need to take to complete firmware installation on D1 mini:

1. Connect to the wifi network **brianLEDPanels**
2. Open a browser and type **192.168.4.1**
3. You should see this screen:
   
   ![Captive Portal](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/images/captive.jpg)
   
5. Enter your Wifi network name and password under the primary wifi network section, and optionally, you can give a secondary
   /alternate wifi network
5. Click **Save & Connect**
6. If all goes well, you should see this screen:

   ![Captive Wifi success](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/images/captivewifisaved.jpg)

7. Success. Now connect to either the Primary or Secondary wifi networks, and you should now see the IP address show up in 
   the ESPHomeFlasher logs.
8. Enter the IP address in the browser and if you get a webpage back, installation is complete.


