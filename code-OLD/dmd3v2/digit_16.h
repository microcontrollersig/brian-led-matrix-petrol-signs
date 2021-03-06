
static const uint8_t digit_16[] PROGMEM = {

    0x30, 0x3A, // size ????  48 x 58
    0x0A, // width 10
    0x10, // height 16
    0x2D, // first char
    0x12, // char count

// char widths
    
0x06,// -
0x03,// .
0x07,// '/'
0x0A, // 0
0x0A, // 1
0x0A, // 2
0x0A, // 3
0x0A, // 4
0x0A, // 5
0x0A, // 6
0x0A, // 7
0x0A, // 8
0x0A, // 9
0x03, // :
0x03, // ;
0x08, // >
0x06, // =
0x08, // <

// font data
0x80, 0x80, 0x80, 0x80, 0x80, 0x80,  
0x01, 0x01, 0x01, 0x01, 0x01, 0x01,   // -

0x00, 0x00, 0x00, 
0x38, 0x38, 0x38,  // .

0x00, 0x00, 0x00, 0x80, 0xE0, 0x38, 0x0E,
0xE0, 0x38, 0x0E, 0x03, 0x00, 0x00, 0x00, // /

0xFC, 0xFE, 0x07, 0x03, 0x03, 0x03, 0x03, 0x07, 0xFE, 0xFC,
0x3F, 0x7F, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0x7F, 0x3F,  // 0

0x00, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0xFF, 0xFF, 0xFF, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, // 1

0x1C, 0x1E, 0x07, 0x03, 0x03, 0x03, 0x03, 0x87, 0xFF, 0xFC,
0xC0, 0xE0, 0xF0, 0xF8, 0xDC, 0xCE, 0xC7, 0xC3, 0xC1, 0xC0, // 2

0x1C, 0x1E, 0x07, 0x03, 0x03, 0x83, 0x83, 0xC7, 0xFF, 0x7E,
0x78, 0x78, 0xE0, 0xC0, 0xC0, 0xC1, 0xC1, 0xC3, 0x7F, 0x3E, // 3

0x00, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0xFF, 0xFF,
0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0xFF, 0xFF, // 4

0x7F, 0x7F, 0x63, 0x63, 0x63, 0x63, 0x63, 0xE3, 0xE3, 0xC3,
0x78, 0x78, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0x7F, 0x3F, // 5

0xFC, 0xFE, 0xE7, 0x63, 0x63, 0x63, 0x63, 0xE3, 0xE7, 0xC6,
0x7F, 0x7F, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0x7F, 0x3F, // 6

0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0xE3, 0xFB, 0x3F, 0x0F,
0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0x0F, 0x01, 0x00, 0x00, // 7

0x7C, 0xFE, 0xE7, 0xC3, 0xC3, 0xC3, 0xC3, 0xE7, 0xFF, 0x7E,
0x7F, 0x7F, 0xE1, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0x7F, 0x3F, //8

0xFC, 0xFE, 0x07, 0x03, 0x03, 0x03, 0x03, 0x07, 0xFF, 0xFE,
0x71, 0x73, 0xE7, 0xC6, 0xC6, 0xC6, 0xC6, 0xE3, 0x7F, 0x3F, //9

0x1C, 0x1C, 0x1C, 
0x38, 0x38, 0x38,  //:

0x1C, 0x1C, 0x1C, 
0x38, 0xB8, 0x78,  // ;

0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 
0x00, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x70, // <

0x18, 0x18, 0x18, 0x18, 0x18, 0x18,   
0x18, 0x18, 0x18, 0x18, 0x18, 0x18,    // =

0x07, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0, 0x80,
0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03, 0x01, 0x00, // >

};
