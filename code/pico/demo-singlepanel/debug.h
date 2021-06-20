#pragma once

//#define DEBUG 1
#define DEBUG 0



#define debug_print(val) do { if (DEBUG) Serial.print(val); } while(0)
#define debug_println(val) do { if (DEBUG) Serial.println(val); } while(0)
