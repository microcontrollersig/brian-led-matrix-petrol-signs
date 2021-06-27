# Reverse Engineering Brian's Petrol Pump LED Matrix

Here is the backside of one 16x16 panel up close and personal (Thanks to Brian D. for awesome shot).

![LED Panel](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/IMG_1820-redacted.jpg)

Important note: The 74HC245 operates at **3.3V**, and therefore any inputs connected to the 16-pin input connector has to operate at 3.3V.

## Takeaways from Image

1. 16 pin input connector on left, direction of data flow indicated by arrow on PCB silkscreen.
2. The major components are:

   - MBI5039 constant current sink driver (reference [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/MBI5039%20Datasheet.pdf) )
   - 74HC245 octal bi-directional buffer (reference [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/74HC_HCT245.pdf) )
   - possibly a regulator like LM2576 (reference [here](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/blob/main/lm2576.pdf) )

## Pinouts

**74HC245**

![74HC245 pinout](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/74HC245-pinout.png)

**MBI5039**

![MBI5039 pinout](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/mbi5039-pinout.png)

The pin marked R-EXT is connected to an external resistor, an easy way to identify other pins such as GND and VCC.

![MBI5039 timing diagram](https://github.com/microcontrollersig/brian-led-matrix-petrol-signs/raw/main/MBI5039-timing.png)

## Schematic (browseable) - represents left half of 16x16 panel (accuracy needs to be verfied) 

![LED Schematic](https://raw.githubusercontent.com/microcontrollersig/brian-led-matrix-petrol-signs/main/circuitnew.svg)
