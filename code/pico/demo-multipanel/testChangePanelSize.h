#pragma once

#include "command.h"
#include <sstream>
#include "FlashIAPBlockDevice.h"
#include "KVStore.h"
#include "TDBStore.h"
#include "mbed_power_mgmt.h"

class TestChangePanelSizeCommand : public Command {
  private:
    int width;
    int height;

    void reboot() {
      system_reset();
    }

    void persist_new_panel_size() {
      // 512KB block device, starting 1MB inside the flash
      FlashIAPBlockDevice bd(XIP_BASE + 1024 * 1024, 1024 * 512);
      mbed::TDBStore eeprom(&bd);
      int data[24];
      data[0] = width;
      data[1] = height;
      eeprom.init();
      delay(100);
      eeprom.reset();
      delay(200);
      eeprom.set("panelsize", data, sizeof(data), 0);
      delay(200);
    }

  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss1, ss2;
      ss1 << args.at(0);
      ss1 >> width;
      ss2 << args.at(1);
      ss2 >> height;
    }

    bool noExecute(DMD3 *canvas) override {
      persist_new_panel_size();
      reboot();
      return true;
    }
    void execute(DMD3 *canvas) override {}
};
