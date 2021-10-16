#pragma once

#include <Arduino.h>
#include "command.h"
#include "test1command.h"
#include "test2command.h"
#include "test3command.h"
#include "test4command.h"
#include "test5command.h"
#include "test6command.h"
#include "test7command.h"
#include "test8command.h"
#include "test9command.h"
#include "test10command.h"
#include "test11command.h"
#include "testidle.h"
#include "testIPAddress.h"
#include "testTwoRowText.h"
#include "testSimpleScroll.h"
#include "testDebug.h"
#include "testTimeout.h"
#include "testSingleTextWithFont.h"
#include "testTwoTextWithFont.h"
#include "testSingleGenericText.h"
#include "testTwoGenericText.h"
#include "testBrightness.h"
#include "testSetPixel.h"


class CommandList
{
  public:
    std::vector<Command*> registerCommands() {
      std::vector<Command*> commands;
      Command *nothingCommand = new NullCommand();
      for (int i=0; i<255; i++) {
        commands.push_back(nothingCommand);
      }

      // Add Commands here
      
      Test1Command *test1 = new Test1Command();
      commands['0'] = test1;  

      Test2Command *test2 = new Test2Command();
      commands['1'] = test2;  

      Test3Command *test3 = new Test3Command();
      commands['2'] = test3;        
      
      Test4Command *test4 = new Test4Command();
      commands['3'] = test4;  

      Test5Command *test5 = new Test5Command();
      commands['4'] = test5;  

      Test6Command *test6 = new Test6Command();
      commands['5'] = test6;     

      Test7Command *test7 = new Test7Command();
      commands['6'] = test7;   

      Test8Command *test8 = new Test8Command();
      commands['7'] = test8;   

      Test9Command *test9 = new Test9Command();
      commands['8'] = test9;               

      Test10Command *test10 = new Test10Command();
      commands['9'] = test10;  

      Test11Command *test11 = new Test11Command();
      commands['a'] = test11;  

      TestIdleCommand *testidle = new TestIdleCommand();
      commands['@'] = testidle;    

      TestIPAddressCommand *testIPAddress = new TestIPAddressCommand();
      commands['I'] = testIPAddress;

      TestTwoRowTextCommand *testTwoRowText = new TestTwoRowTextCommand();
      commands['*'] = testTwoRowText;     

      TestSimpleScrollCommand *testSimpleScrollCommand = new TestSimpleScrollCommand();
      commands['S'] = testSimpleScrollCommand;        

      TestDebugCommand *testDebugCommand = new TestDebugCommand();
      commands['D'] = testDebugCommand;  

      TestTimeoutCommand *testTimeoutCommand = new TestTimeoutCommand();
      commands['O'] = testTimeoutCommand; 

      TestSingleTextWithFontCommand *testSingleTextWithFontCommand = new TestSingleTextWithFontCommand();
      commands['G'] = testSingleTextWithFontCommand; 

      TestTwoTextWithFontCommand *testTwoTextWithFontCommand = new TestTwoTextWithFontCommand();
      commands['H'] = testTwoTextWithFontCommand; 

      TestSingleGenericTextCommand *testSingleGenericTextCommand = new TestSingleGenericTextCommand();
      commands['Z'] = testSingleGenericTextCommand; 

      TestTwoGenericTextCommand *testTwoGenericTextCommand = new TestTwoGenericTextCommand();
      commands['T'] = testTwoGenericTextCommand; 

      TestBrightnessCommand *testBrightnessCommand = new TestBrightnessCommand();
      commands['B'] = testBrightnessCommand; 

      TestSetPixelCommand *testSetPixelCommand = new TestSetPixelCommand();
      commands['P'] = testSetPixelCommand; 
 
      return commands;
    }


};
