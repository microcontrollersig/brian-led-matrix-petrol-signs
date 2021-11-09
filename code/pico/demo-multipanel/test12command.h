#pragma once

#include "command.h"
#include "qrcode.h"

class Test12Command : public Command
{
  private:
    unsigned long timeStart = 0UL;

  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 200) {
        clearSerialMonitor();
        canvas->clear();

        QRCode qrcode;
        qrcode.mode = MODE_ALPHANUMERIC;
        byte qrcodeBytes[qrcode_getBufferSize(1)];
        qrcode_initText(&qrcode, qrcodeBytes, 1, ECC_LOW, "HELLO");

        for (uint8_t y = 0; y < qrcode.size; y++) {
          for (uint8_t x = 0; x < qrcode.size; x++) {
            if (qrcode_getModule(&qrcode, x, y)) {
              canvas->setPixel(x, y);
              //Serial.print("**");
            } else {
              //Serial.print("  ");
            }
          }
          //Serial.print("\n");
        }

        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
