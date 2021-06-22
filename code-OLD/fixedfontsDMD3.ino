#include <inttypes.h>
#include <avr/pgmspace.h>

class DMD3;
class String;




#define SystemFont5x7 System5x7

static const uint8_t System5x7[] PROGMEM = {
    0x0, 0x0, // size of zero indicates fixed width font, actual length is width * height
    0x05, // width
    0x07, // height
    0x20, // first char
    0x60, // char count

    // Fixed width; char width table not used !!!!

    // font data
    0x00, 0x00, 0x00, 0x00, 0x00,// (space)
	0x00, 0x00, 0x5F, 0x00, 0x00,// !
	0x00, 0x07, 0x00, 0x07, 0x00,// "
	0x14, 0x7F, 0x14, 0x7F, 0x14,// #
	0x24, 0x2A, 0x7F, 0x2A, 0x12,// $
	0x23, 0x13, 0x08, 0x64, 0x62,// %
	0x36, 0x49, 0x55, 0x22, 0x50,// &
	0x00, 0x05, 0x03, 0x00, 0x00,// '
	0x00, 0x1C, 0x22, 0x41, 0x00,// (
	0x00, 0x41, 0x22, 0x1C, 0x00,// )
	0x08, 0x2A, 0x1C, 0x2A, 0x08,// *
	0x08, 0x08, 0x3E, 0x08, 0x08,// +
	0x00, 0x50, 0x30, 0x00, 0x00,// ,
	0x08, 0x08, 0x08, 0x08, 0x08,// -
	0x00, 0x60, 0x60, 0x00, 0x00,// .
	0x20, 0x10, 0x08, 0x04, 0x02,// /
	0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
	0x00, 0x42, 0x7F, 0x40, 0x00,// 1
	0x42, 0x61, 0x51, 0x49, 0x46,// 2
	0x21, 0x41, 0x45, 0x4B, 0x31,// 3
	0x18, 0x14, 0x12, 0x7F, 0x10,// 4
	0x27, 0x45, 0x45, 0x45, 0x39,// 5
	0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
	0x01, 0x71, 0x09, 0x05, 0x03,// 7
	0x36, 0x49, 0x49, 0x49, 0x36,// 8
	0x06, 0x49, 0x49, 0x29, 0x1E,// 9
	0x00, 0x36, 0x36, 0x00, 0x00,// :
	0x00, 0x56, 0x36, 0x00, 0x00,// ;
	0x00, 0x08, 0x14, 0x22, 0x41,// <
	0x14, 0x14, 0x14, 0x14, 0x14,// =
	0x41, 0x22, 0x14, 0x08, 0x00,// >
	0x02, 0x01, 0x51, 0x09, 0x06,// ?
	0x32, 0x49, 0x79, 0x41, 0x3E,// @
	0x7E, 0x11, 0x11, 0x11, 0x7E,// A
	0x7F, 0x49, 0x49, 0x49, 0x36,// B
	0x3E, 0x41, 0x41, 0x41, 0x22,// C
	0x7F, 0x41, 0x41, 0x22, 0x1C,// D
	0x7F, 0x49, 0x49, 0x49, 0x41,// E
	0x7F, 0x09, 0x09, 0x01, 0x01,// F
	0x3E, 0x41, 0x41, 0x51, 0x32,// G
	0x7F, 0x08, 0x08, 0x08, 0x7F,// H
	0x00, 0x41, 0x7F, 0x41, 0x00,// I
	0x20, 0x40, 0x41, 0x3F, 0x01,// J
	0x7F, 0x08, 0x14, 0x22, 0x41,// K
	0x7F, 0x40, 0x40, 0x40, 0x40,// L
	0x7F, 0x02, 0x04, 0x02, 0x7F,// M
	0x7F, 0x04, 0x08, 0x10, 0x7F,// N
	0x3E, 0x41, 0x41, 0x41, 0x3E,// O
	0x7F, 0x09, 0x09, 0x09, 0x06,// P
	0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
	0x7F, 0x09, 0x19, 0x29, 0x46,// R
	0x46, 0x49, 0x49, 0x49, 0x31,// S
	0x01, 0x01, 0x7F, 0x01, 0x01,// T
	0x3F, 0x40, 0x40, 0x40, 0x3F,// U
	0x1F, 0x20, 0x40, 0x20, 0x1F,// V
	0x7F, 0x20, 0x18, 0x20, 0x7F,// W
	0x63, 0x14, 0x08, 0x14, 0x63,// X
	0x03, 0x04, 0x78, 0x04, 0x03,// Y
	0x61, 0x51, 0x49, 0x45, 0x43,// Z
	0x00, 0x00, 0x7F, 0x41, 0x41,// [
	0x02, 0x04, 0x08, 0x10, 0x20,// "\"
	0x41, 0x41, 0x7F, 0x00, 0x00,// ]
	0x04, 0x02, 0x01, 0x02, 0x04,// ^
	0x40, 0x40, 0x40, 0x40, 0x40,// _
	0x00, 0x01, 0x02, 0x04, 0x00,// `
	0x20, 0x54, 0x54, 0x54, 0x78,// a
	0x7F, 0x48, 0x44, 0x44, 0x38,// b
	0x38, 0x44, 0x44, 0x44, 0x20,// c
	0x38, 0x44, 0x44, 0x48, 0x7F,// d
	0x38, 0x54, 0x54, 0x54, 0x18,// e
	0x08, 0x7E, 0x09, 0x01, 0x02,// f
	0x08, 0x14, 0x54, 0x54, 0x3C,// g
	0x7F, 0x08, 0x04, 0x04, 0x78,// h
	0x00, 0x44, 0x7D, 0x40, 0x00,// i
	0x20, 0x40, 0x44, 0x3D, 0x00,// j
	0x00, 0x7F, 0x10, 0x28, 0x44,// k
	0x00, 0x41, 0x7F, 0x40, 0x00,// l
	0x7C, 0x04, 0x18, 0x04, 0x78,// m
	0x7C, 0x08, 0x04, 0x04, 0x78,// n
	0x38, 0x44, 0x44, 0x44, 0x38,// o
	0x7C, 0x14, 0x14, 0x14, 0x08,// p
	0x08, 0x14, 0x14, 0x18, 0x7C,// q
	0x7C, 0x08, 0x04, 0x04, 0x08,// r
	0x48, 0x54, 0x54, 0x54, 0x20,// s
	0x04, 0x3F, 0x44, 0x40, 0x20,// t
	0x3C, 0x40, 0x40, 0x20, 0x7C,// u
	0x1C, 0x20, 0x40, 0x20, 0x1C,// v
	0x3C, 0x40, 0x30, 0x40, 0x3C,// w
	0x44, 0x28, 0x10, 0x28, 0x44,// x
	0x0C, 0x50, 0x50, 0x50, 0x3C,// y
	0x44, 0x64, 0x54, 0x4C, 0x44,// z
	0x00, 0x08, 0x36, 0x41, 0x00,// {
	0x00, 0x00, 0x7F, 0x00, 0x00,// |
	0x00, 0x41, 0x36, 0x08, 0x00,// }
	0x08, 0x08, 0x2A, 0x1C, 0x08,// ->
	0x08, 0x1C, 0x2A, 0x08, 0x08 // <-

};


//#define ArialFont10x14 Arial_14

#define ArialFont16x16 Arial16x16

const static uint8_t Arial16x16[] PROGMEM = {
    0x0, 0x0, // size
    0x10, // width
    0x10, // height
    0x20, // first char
    0x60, // char count  
  
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char  
0x00, 0x00, 0x00, 0x00, 0xFE, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char !
0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char "
0x20, 0x02, 0x20, 0x1E, 0xF0, 0x03, 0x2E, 0x02, 0x20, 0x02, 0x20, 0x1E, 0xF0, 0x03, 0x2E, 0x02, 0x20, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char #
0x00, 0x00, 0x38, 0x04, 0x44, 0x08, 0x42, 0x10, 0xFF, 0x3F, 0x82, 0x10, 0x82, 0x08, 0x0C, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char $
0x00, 0x00, 0x3C, 0x00, 0x42, 0x00, 0x42, 0x00, 0x42, 0x18, 0x3C, 0x06, 0x80, 0x01, 0x70, 0x00, 0x0C, 0x0F, 0x82, 0x10, 0x80, 0x10, 0x80, 0x10, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char %
0x00, 0x00, 0x00, 0x07, 0x9C, 0x08, 0x62, 0x10, 0xC2, 0x10, 0x22, 0x11, 0x1C, 0x0A, 0x00, 0x04, 0x00, 0x0A, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char &
0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char '
0x00, 0x00, 0xE0, 0x0F, 0x1C, 0x70, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char (
0x00, 0x00, 0x02, 0x80, 0x1C, 0x70, 0xE0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char )
0x04, 0x00, 0x34, 0x00, 0x0E, 0x00, 0x34, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char *
0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0xF0, 0x07, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char +
0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ,
0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char -
0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char .
0x00, 0x18, 0x80, 0x07, 0x78, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char /
0x00, 0x00, 0xF8, 0x07, 0x04, 0x08, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x04, 0x08, 0xF8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 0
0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x08, 0x00, 0x04, 0x00, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 1
0x00, 0x00, 0x08, 0x10, 0x04, 0x18, 0x02, 0x14, 0x02, 0x12, 0x02, 0x11, 0xC6, 0x10, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 2
0x00, 0x00, 0x08, 0x0C, 0x04, 0x08, 0x42, 0x10, 0x42, 0x10, 0x62, 0x10, 0xBC, 0x08, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 3
0x00, 0x03, 0x80, 0x02, 0x40, 0x02, 0x30, 0x02, 0x08, 0x02, 0x04, 0x02, 0xFE, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 4
0x00, 0x00, 0x70, 0x04, 0x2E, 0x08, 0x22, 0x10, 0x22, 0x10, 0x22, 0x10, 0x42, 0x08, 0x82, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 5
0x00, 0x00, 0xF8, 0x07, 0x44, 0x08, 0x22, 0x10, 0x22, 0x10, 0x22, 0x10, 0x44, 0x08, 0x88, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 6
0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x1C, 0xC2, 0x03, 0x32, 0x00, 0x0E, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 7
0x00, 0x00, 0x18, 0x07, 0xA4, 0x08, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0xA4, 0x08, 0x18, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 8
0x00, 0x00, 0x78, 0x04, 0x84, 0x08, 0x02, 0x11, 0x02, 0x11, 0x02, 0x11, 0x84, 0x08, 0xF8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 9
0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char :
0x00, 0x00, 0x10, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ;
0x00, 0x00, 0x80, 0x00, 0x40, 0x01, 0x40, 0x01, 0x20, 0x02, 0x20, 0x02, 0x20, 0x02, 0x10, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char <
0x00, 0x00, 0x20, 0x02, 0x20, 0x02, 0x20, 0x02, 0x20, 0x02, 0x20, 0x02, 0x20, 0x02, 0x20, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char =
0x00, 0x00, 0x10, 0x04, 0x20, 0x02, 0x20, 0x02, 0x20, 0x02, 0x40, 0x01, 0x40, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char >
0x00, 0x00, 0x18, 0x00, 0x04, 0x00, 0x02, 0x00, 0x02, 0x17, 0x82, 0x00, 0x44, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ?
0x00, 0x00, 0xC0, 0x0F, 0x30, 0x10, 0x08, 0x20, 0x84, 0x47, 0x44, 0x48, 0x22, 0x90, 0x12, 0x90, 0x12, 0x90, 0x12, 0x88, 0x22, 0x9F, 0xF2, 0x90, 0x04, 0x90, 0x04, 0x48, 0x18, 0x44, 0xE0, 0x23,  // Code for char @
0x00, 0x00, 0x00, 0x18, 0x00, 0x07, 0xE0, 0x01, 0x1C, 0x01, 0x02, 0x01, 0x1C, 0x01, 0xE0, 0x01, 0x00, 0x07, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char A
0x00, 0x00, 0xFE, 0x1F, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0xA6, 0x08, 0x18, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char B
0x00, 0x00, 0xF0, 0x03, 0x08, 0x04, 0x04, 0x08, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x04, 0x08, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char C
0x00, 0x00, 0xFE, 0x1F, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x04, 0x08, 0x08, 0x04, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char D
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x3F, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char E
0x00, 0x00, 0xFE, 0x1F, 0x82, 0x00, 0x82, 0x00, 0x82, 0x00, 0x82, 0x00, 0x82, 0x00, 0x82, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char F
0x00, 0x00, 0xF0, 0x03, 0x08, 0x04, 0x04, 0x08, 0x02, 0x10, 0x02, 0x10, 0x82, 0x10, 0x82, 0x10, 0x84, 0x08, 0x88, 0x04, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char G
0x00, 0x00, 0xFE, 0x1F, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char H
0x00, 0x00, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char I
0x00, 0x00, 0x00, 0x0E, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0xFE, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char J
0x00, 0x00, 0xFE, 0x1F, 0x00, 0x01, 0x80, 0x00, 0x40, 0x00, 0xE0, 0x00, 0x10, 0x01, 0x08, 0x06, 0x04, 0x08, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char K
0x00, 0x00, 0xFE, 0x1F, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char L
0x00, 0x00, 0xFE, 0x1F, 0x0C, 0x00, 0x30, 0x00, 0xC0, 0x00, 0x00, 0x07, 0x00, 0x18, 0x00, 0x07, 0xC0, 0x00, 0x30, 0x00, 0x0C, 0x00, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char M
0x00, 0x00, 0xFE, 0x1F, 0x04, 0x00, 0x18, 0x00, 0x20, 0x00, 0xC0, 0x00, 0x00, 0x01, 0x00, 0x06, 0x00, 0x08, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char N
0x00, 0x00, 0xF0, 0x03, 0x08, 0x04, 0x04, 0x08, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x04, 0x08, 0x08, 0x04, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char O
0x00, 0x00, 0xFE, 0x1F, 0x82, 0x00, 0x82, 0x00, 0x82, 0x00, 0x82, 0x00, 0x82, 0x00, 0x82, 0x00, 0x44, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char P
0x00, 0x00, 0xF0, 0x03, 0x08, 0x04, 0x04, 0x08, 0x02, 0x10, 0x02, 0x10, 0x02, 0x14, 0x02, 0x14, 0x04, 0x08, 0x08, 0x1C, 0xF0, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char Q
0x00, 0x00, 0xFE, 0x1F, 0x82, 0x00, 0x82, 0x00, 0x82, 0x00, 0x82, 0x00, 0x82, 0x01, 0x82, 0x06, 0x44, 0x08, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char R
0x00, 0x00, 0x18, 0x04, 0x24, 0x08, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0x82, 0x10, 0x82, 0x10, 0x84, 0x08, 0x08, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char S
0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0xFE, 0x1F, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char T
0x00, 0x00, 0xFE, 0x07, 0x00, 0x08, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x08, 0xFE, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char U
0x00, 0x00, 0x06, 0x00, 0x38, 0x00, 0xC0, 0x01, 0x00, 0x06, 0x00, 0x18, 0x00, 0x06, 0xC0, 0x01, 0x38, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char V
0x06, 0x00, 0x78, 0x00, 0x80, 0x07, 0x00, 0x18, 0x00, 0x07, 0xE0, 0x00, 0x1C, 0x00, 0x02, 0x00, 0x1C, 0x00, 0xE0, 0x00, 0x00, 0x07, 0x00, 0x18, 0x80, 0x07, 0x78, 0x00, 0x06, 0x00, 0x00, 0x00,  // Code for char W
0x00, 0x10, 0x02, 0x08, 0x04, 0x04, 0x18, 0x03, 0xA0, 0x00, 0x40, 0x00, 0xA0, 0x00, 0x18, 0x03, 0x04, 0x04, 0x02, 0x08, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char X
0x02, 0x00, 0x0C, 0x00, 0x10, 0x00, 0x60, 0x00, 0x80, 0x1F, 0x60, 0x00, 0x10, 0x00, 0x0C, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char Y
0x00, 0x10, 0x02, 0x18, 0x02, 0x16, 0x02, 0x11, 0xC2, 0x10, 0x22, 0x10, 0x1A, 0x10, 0x06, 0x10, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char Z
0x00, 0x00, 0xFE, 0xFF, 0x02, 0x80, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char [
0x06, 0x00, 0x78, 0x00, 0x80, 0x07, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char BackSlash
0x02, 0x80, 0x02, 0x80, 0xFE, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ]
0x40, 0x00, 0x30, 0x00, 0x0C, 0x00, 0x02, 0x00, 0x0C, 0x00, 0x30, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ^
0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char _
0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char `
0x00, 0x00, 0x40, 0x0E, 0x20, 0x11, 0x10, 0x11, 0x10, 0x11, 0x90, 0x10, 0x90, 0x08, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char a
0x00, 0x00, 0xFE, 0x1F, 0x20, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x08, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char b
0x00, 0x00, 0xC0, 0x07, 0x20, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char c
0x00, 0x00, 0xC0, 0x07, 0x20, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x08, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char d
0x00, 0x00, 0xC0, 0x07, 0x20, 0x09, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x20, 0x09, 0xC0, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char e
0x10, 0x00, 0xFC, 0x1F, 0x12, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char f
0x00, 0x00, 0xC0, 0x47, 0x20, 0x88, 0x10, 0x90, 0x10, 0x90, 0x10, 0x90, 0x20, 0x48, 0xF0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char g
0x00, 0x00, 0xFE, 0x1F, 0x20, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char h
0x00, 0x00, 0xF2, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char i
0x00, 0x80, 0xF2, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char j
0x00, 0x00, 0xFE, 0x1F, 0x00, 0x02, 0x00, 0x01, 0x80, 0x01, 0x40, 0x06, 0x20, 0x08, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char k
0x00, 0x00, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char l
0x00, 0x00, 0xF0, 0x1F, 0x20, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0xE0, 0x1F, 0x20, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char m
0x00, 0x00, 0xF0, 0x1F, 0x20, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char n
0x00, 0x00, 0xC0, 0x07, 0x20, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x08, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char o
0x00, 0x00, 0xF0, 0xFF, 0x20, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x08, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char p
0x00, 0x00, 0xC0, 0x07, 0x20, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x08, 0xF0, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char q
0x00, 0x00, 0xF0, 0x1F, 0x20, 0x00, 0x10, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char r
0x00, 0x00, 0xE0, 0x08, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x20, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char s
0x10, 0x00, 0xFC, 0x1F, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char t
0x00, 0x00, 0xF0, 0x0F, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x08, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char u
0x30, 0x00, 0xC0, 0x00, 0x00, 0x07, 0x00, 0x18, 0x00, 0x07, 0xC0, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char v
0x30, 0x00, 0xC0, 0x07, 0x00, 0x18, 0x00, 0x07, 0xC0, 0x00, 0x30, 0x00, 0xC0, 0x00, 0x00, 0x07, 0x00, 0x18, 0xC0, 0x07, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char w
0x10, 0x10, 0x20, 0x08, 0xC0, 0x06, 0x00, 0x01, 0xC0, 0x06, 0x20, 0x08, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char x
0x70, 0x00, 0x80, 0x81, 0x00, 0x8E, 0x00, 0x70, 0x00, 0x0E, 0xC0, 0x01, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char y
0x10, 0x10, 0x10, 0x18, 0x10, 0x16, 0x10, 0x11, 0xD0, 0x10, 0x30, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char z
0x00, 0x01, 0x00, 0x01, 0xFC, 0x7E, 0x02, 0x80, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char {
0x00, 0x00, 0xFE, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char |
0x02, 0x80, 0x02, 0x80, 0xFC, 0x7E, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char }
0x80, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ~
0xFE, 0x0F, 0x02, 0x08, 0x02, 0x08, 0xFE, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   // Code for char 
};



class Bitmap
{
public:
    Bitmap(int width, int height);
    ~Bitmap();

    bool isValid() const { return fb != 0; }

    typedef uint8_t Color;
    typedef PGM_VOID_P ProgMem;
    typedef PGM_VOID_P Font;

    static const Color Black  = 1;
    static const Color White  = 0;
    static const Color NoFill = 2;

    int width() const { return _width; }
    int height() const { return _height; }
    int stride() const { return _stride; }
    int bitsPerPixel() const { return 1; }

    uint8_t *data() { return fb; }
    const uint8_t *data() const { return fb; }

    void clear(Color color = Black);

    Color pixel(int x, int y) const;
    void setPixel(int x, int y, Color color);

    void drawLine(int x1, int y1, int x2, int y2, Color color = White);
    void drawRect(int x1, int y1, int x2, int y2, Color borderColor = White, Color fillColor = NoFill);
    void drawFilledRect(int x1, int y1, int x2, int y2, Color color = White);
    void drawCircle(int centerX, int centerY, int radius, Color borderColor = White, Color fillColor = NoFill);
    void drawFilledCircle(int centerX, int centerY, int radius, Color color = White);

    void drawBitmap(int x, int y, const Bitmap &bitmap, Color color = White);
    void drawBitmap(int x, int y, Bitmap::ProgMem bitmap, Color color = White);
    void drawInvertedBitmap(int x, int y, const Bitmap &bitmap);
    void drawInvertedBitmap(int x, int y, Bitmap::ProgMem bitmap);

    Font font() const { return _font; }
    //void setFont(Font font) { _font = font; }
    void setFont(Font font);

    Color textColor() const { return _textColor; }
    //void setTextColor(Color color) { _textColor = color; }

    void drawText(int x, int y, const char *str, int len = -1);
    void drawText(int x, int y, const String &str, int start = 0, int len = -1);

    int drawChar(int x, int y, char ch);

    int charWidth(char ch) const;
    int textWidth(const char *str, int len = -1) const;
    int textWidth(const String &str, int start = 0, int len = -1) const;
    int textHeight() const;

    void copy(int x, int y, int width, int height, Bitmap *dest, int destX, int destY);
    void fill(int x, int y, int width, int height, Color color);
    void fill(int x, int y, int width, int height, Bitmap::ProgMem pattern, Color color = White);

    void scroll(int dx, int dy, Color fillColor = Black);
    void scroll(int x, int y, int width, int height, int dx, int dy, Color fillColor = Black);

    void invert(int x, int y, int width, int height);

private:
    // Disable copy constructor and operator=().
    Bitmap(const Bitmap &) {}
    Bitmap &operator=(const Bitmap &) { return *this; }

    int _width;
    int _height;
    int _stride;
    uint8_t *fb;
    Font _font;
    Color _textColor;

    friend class DMD3;

    void blit(int x1, int y1, int x2, int y2, int x3, int y3);
    void drawCirclePoints(int centerX, int centerY, int radius, int x, int y, Color borderColor, Color fillColor);
};

inline void Bitmap::drawFilledRect(int x1, int y1, int x2, int y2, Color color)
{
    drawRect(x1, y1, x2, y2, color, color);
}

inline void Bitmap::drawFilledCircle(int centerX, int centerY, int radius, Color color)
{
    drawCircle(centerX, centerY, radius, color, color);
}

inline void Bitmap::drawInvertedBitmap(int x, int y, const Bitmap &bitmap)
{
    drawBitmap(x, y, bitmap, Black);
}

inline void Bitmap::drawInvertedBitmap(int x, int y, Bitmap::ProgMem bitmap)
{
    drawBitmap(x, y, bitmap, Black);
}

inline void Bitmap::scroll(int dx, int dy, Color fillColor)
{
    scroll(0, 0, _width, _height, dx, dy, fillColor);
}

/**
 * \class Bitmap Bitmap.h <Bitmap.h>
 * \brief Represents a monochrome bitmap within main memory.
 *
 * Bitmaps are a rectangular arrangement of width() x height() pixels,
 * with each pixel set to either \ref Black or \ref White.  The co-ordinate
 * system has origin (0, 0) at the top-left of the bitmap.
 *
 * Functions within this class can be used to draw various shapes into
 * the bitmap's data() buffer; e.g. drawLine(), drawRect(), drawBitmap(),
 * drawText(), clear(), fill(), etc.
 *
 * \sa DMD
 */

/**
 * \typedef Bitmap::Color
 * \brief Type that represents the color of a pixel in a bitmap.
 *
 * \sa Black, White
 */

/**
 * \typedef Bitmap::ProgMem
 * \brief Type that represents a bitmap within program memory.
 */

/**
 * \typedef Bitmap::Font
 * \brief Type that represents a font within program memory.
 */

/**
 * \var Bitmap::Black
 * \brief Color value corresponding to "black".
 */

/**
 * \var Bitmap::White
 * \brief Color value corresponding to "white".  If the bitmap is
 * displayed on a LED array, then it may have a different physical color.
 *
 * Note: while the value of this constant is 1, the bitmap itself stores
 * white pixels as 0 and black as 1 because the DMD display uses 1 to
 * indicate a pixel being off.
 */

/**
 * \var Bitmap::NoFill
 * \brief Special color value that is used with drawRect() and drawCircle()
 * to indicate that the interior of the shape should not be filled.
 * For all other uses, \ref NoFill is equivalent to \ref White.
 */

/**
 * \brief Constructs a new in-memory bitmap that is \a width x \a height
 * pixels in size.
 *
 * \sa width(), height(), isValid()
 */
Bitmap::Bitmap(int width, int height)
    : _width(width)
    , _height(height)
    , _stride((width + 7) / 8)
    , fb(0)
    , _font(0)
    , _textColor(White)
{
    // Allocate memory for the framebuffer and clear it (1 = pixel off).
    unsigned int size = _stride * _height;
    fb = (uint8_t *)malloc(size);
    if (fb)
        memset(fb, 0x00, size); //Non-inverting mode
}

/**
 * \brief Destroys this bitmap.
 */
Bitmap::~Bitmap()
{
    if (fb)
        free(fb);
}

/**
 * \fn bool Bitmap::isValid() const
 * \brief Returns true if the memory for this bitmap is valid; false otherwise.
 *
 * This function can be called just after the constructor to determine if
 * the memory for the bitmap was allocated successfully.
 */

/**
 * \fn int Bitmap::width() const
 * \brief Returns the width of the bitmap in pixels.
 *
 * \sa height(), stride(), bitsPerPixel()
 */

/**
 * \fn int Bitmap::height() const
 * \brief Returns the height of the bitmap in pixels.
 *
 * \sa width(), bitsPerPixel()
 */

/**
 * \fn int Bitmap::stride() const
 * \brief Returns the number of bytes in each line of the bitmap's data() buffer.
 *
 * \sa width(), bitsPerPixel(), data()
 */

/**
 * \fn int Bitmap::bitsPerPixel() const
 * \brief Returns the number of bits per pixel for the bitmap; always 1.
 *
 * \sa width(), height()
 */

/**
 * \fn uint8_t *Bitmap::data()
 * \brief Returns a pointer to the start of the bitmap's data buffer.
 *
 * The data is organized as height() lines of stride() bytes, laid out
 * horizontally across the extent of width() pixels.  The most significant
 * bit in each byte has the lowest x value.
 *
 * Note: bits within the data are 1 for \ref Black and 0 for \ref White,
 * which is the reverse of the constant values.  This differs from pixel()
 * which returns the correct constant.
 *
 * \sa pixel(), stride()
 */

/**
 * \fn const uint8_t *Bitmap::data() const
 * \brief Returns a constant pointer to the start of the bitmap's data buffer.
 * \overload
 */

/**
 * \brief Clears the entire bitmap to the specified \a color.
 *
 * \sa fill()
 */
void Bitmap::clear(Color color)
{
    unsigned int size = _stride * _height;
    if (color == Black)
        memset(fb, 0xFF, size);
    else
        memset(fb, 0x00, size);
}

/**
 * \brief Returns the color of the pixel at (\a x, \a y); either \ref Black
 * or \ref White.
 *
 * Returns \a Black if \a x or \a y is out of range.
 *
 * \sa setPixel(), data()
 */
Bitmap::Color Bitmap::pixel(int x, int y) const
{
    if (((unsigned int)x) >= ((unsigned int)_width) ||
            ((unsigned int)y) >= ((unsigned int)_height))
        return Black;
    uint8_t *ptr = fb + y * _stride + (x >> 3);
    if (*ptr & ((uint8_t)0x80) >> (x & 0x07))
        return Black;
    else
        return White;
}

/**
 * \brief Sets the pixel at (\a x, \a y) to \a color.
 *
 * \sa pixel()
 */
void Bitmap::setPixel(int x, int y, Color color)
{
    if (((unsigned int)x) >= ((unsigned int)_width) ||
            ((unsigned int)y) >= ((unsigned int)_height))
        return;     // Pixel is off-screen.
    uint8_t *ptr = fb + y * _stride + (x >> 3);
    if (color)
        *ptr &= ~(((uint8_t)0x80) >> (x & 0x07));
    else
        *ptr |= (((uint8_t)0x80) >> (x & 0x07));
}

/**
 * \brief Draws a line from (\a x1, \a y1) to (\a x2, \a y2) in \a color.
 *
 * \sa drawRect(), drawCircle()
 */
void Bitmap::drawLine(int x1, int y1, int x2, int y2, Color color)
{
    // Midpoint line scan-conversion algorithm from "Computer Graphics:
    // Principles and Practice", Second Edition, Foley, van Dam, et al.
    int dx = x2 - x1;
    int dy = y2 - y1;
    int xstep, ystep;
    int d, incrE, incrNE;
    if (dx < 0) {
        xstep = -1;
        dx = -dx;
    } else {
        xstep = 1;
    }
    if (dy < 0) {
        ystep = -1;
        dy = -dy;
    } else {
        ystep = 1;
    }
    if (dx >= dy) {
        d = 2 * dy - dx;
        incrE = 2 * dy;
        incrNE = 2 * (dy - dx);
        setPixel(x1, y1, color);
        while (x1 != x2) {
            if (d <= 0) {
                d += incrE;
            } else {
                d += incrNE;
                y1 += ystep;
            }
            x1 += xstep;
            setPixel(x1, y1, color);
        }
    } else {
        d = 2 * dx - dy;
        incrE = 2 * dx;
        incrNE = 2 * (dx - dy);
        setPixel(x1, y1, color);
        while (y1 != y2) {
            if (d <= 0) {
                d += incrE;
            } else {
                d += incrNE;
                x1 += xstep;
            }
            y1 += ystep;
            setPixel(x1, y1, color);
        }
    }
}

/**
 * \brief Draws a rectangle from (\a x1, \a y1) to (\a x2, \a y2), with the
 * outline in \a borderColor and the interior filled with \a fillColor.
 *
 * If \a fillColor is \ref NoFill, then the interior is not filled.
 *
 * \sa drawFilledRect(), drawLine(), drawCircle(), fill()
 */
void Bitmap::drawRect(int x1, int y1, int x2, int y2, Color borderColor, Color fillColor)
{
    int temp;
    if (x1 > x2) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        temp = y1;
        y1 = y2;
        y2 = temp;
    }
    if (fillColor == borderColor) {
        fill(x1, y1, x2 - x1 + 1, y2 - y1 + 1, fillColor);
    } else {
        drawLine(x1, y1, x2, y1, borderColor);
        if (y1 < y2)
            drawLine(x2, y1 + 1, x2, y2, borderColor);
        if (x1 < x2)
            drawLine(x2 - 1, y2, x1, y2, borderColor);
        if (y1 < (y2 - 1))
            drawLine(x1, y2 - 1, x1, y1 + 1, borderColor);
        if (fillColor != NoFill)
            fill(x1 + 1, y1 + 1, x2 - x1 - 1, y2 - y1 - 1, fillColor);
    }
}

/**
 * \fn void Bitmap::drawFilledRect(int x1, int y1, int x2, int y2, Color color)
 * \brief Draws a filled rectangle from (\a x1, \a y1) to (\a x2, \a y2)
 * in \a color.
 *
 * This is a convenience function that is equivalent to
 * drawRect(\a x1, \a y1, \a x2, \a y2, \a color, \a color).
 *
 * \sa drawRect(), drawFilledCircle()
 */

/**
 * \brief Draws a circle with a specific center (\a centerX, \a centerY)
 * and \a radius, with the outline in \a borderColor and the interior
 * filled with \a fillColor.
 *
 * If \a fillColor is \ref NoFill, then the interior is not filled.
 *
 * \sa drawFilledCircle(), drawLine(), drawRect()
 */
void Bitmap::drawCircle(int centerX, int centerY, int radius, Color borderColor, Color fillColor)
{
    // Midpoint circle scan-conversion algorithm using second-order
    // differences from "Computer Graphics: Principles and Practice",
    // Second Edition, Foley, van Dam, et al.
    if (radius < 0)
        radius = -radius;
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    int deltaE = 3;
    int deltaSE = 5 - 2 * radius;
    drawCirclePoints(centerX, centerY, radius, x, y, borderColor, fillColor);
    while (y > x) {
        if (d < 0) {
            d += deltaE;
            deltaE += 2;
            deltaSE += 2;
        } else {
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            --y;
        }
        ++x;
        drawCirclePoints(centerX, centerY, radius, x, y, borderColor, fillColor);
    }
}

/**
 * \fn void Bitmap::drawFilledCircle(int centerX, int centerY, int radius, Color color)
 * \brief Draws a filled circle with a specific center (\a centerX, \a centerY)
 * and \a radius in \a color.
 *
 * This is a convenience function that is equivalent to
 * drawCircle(\a centerX, \a centerY, \a radius, \a color, \a color).
 *
 * \sa drawCircle(), drawFilledRect()
 */

/**
 * \brief Draws \a bitmap at (\a x, \a y) in \a color.
 *
 * Bits that are set to \ref White in the \a bitmap are drawn with \a color.
 * Bits that are set to \ref Black in the \a bitmap are drawn with the
 * inverse of \a color.  The pixel at (\a x, \a y) will be the top-left
 * corner of the drawn image.
 *
 * Note: \a bitmap must not be the same as this object or the behaviour will
 * be undefined.  To copy a region of a bitmap to elsewhere within the
 * same bitmap, use copy() instead.
 *
 * \sa drawInvertedBitmap(), copy()
 */
void Bitmap::drawBitmap(int x, int y, const Bitmap &bitmap, Color color)
{
    int w = bitmap.width();
    int s = bitmap.stride();
    int h = bitmap.height();
    Color invColor = !color;
    for (uint8_t by = 0; by < h; ++by) {
        const uint8_t *line = bitmap.data() + by * s;
        uint8_t mask = 0x80;
        uint8_t value = *line++;
        for (uint8_t bx = 0; bx < w; ++bx) {
            if (value & mask)
                setPixel(x + bx, y + by, invColor);
            else
                setPixel(x + bx, y + by, color);
            mask >>= 1;
            if (!mask) {
                mask = 0x80;
                value = *line++;
            }
        }
    }
}

/**
 * \brief Draws \a bitmap at (\a x, \a y) in \a color.
 *
 * The \a bitmap must point to program memory.  The first two bytes are the
 * width and height of the bitmap in pixels.  The rest of the data contains
 * the pixels for the bitmap, with lines byte-aligned.
 *
 * Bits that are 1 in the \a bitmap are drawn with \a color.  Bits that are
 * 0 in the \a bitmap are drawn with the inverse of \a color.  The pixel at
 * (\a x, \a y) will be the top-left corner of the drawn image.
 *
 * \sa drawInvertedBitmap(), fill()
 */
void Bitmap::drawBitmap(int x, int y, Bitmap::ProgMem bitmap, Color color)
{
    uint8_t w = pgm_read_byte(bitmap);
    uint8_t s = (w + 7) >> 3;
    uint8_t h = pgm_read_byte(bitmap + 1);
    Color invColor = !color;
    for (uint8_t by = 0; by < h; ++by) {
        const uint8_t *line = ((const uint8_t *)bitmap) + 2 + by * s;
        uint8_t mask = 0x80;
        uint8_t value = pgm_read_byte(line);
        for (uint8_t bx = 0; bx < w; ++bx) {
            if (value & mask)
                setPixel(x + bx, y + by, color);
            else
                setPixel(x + bx, y + by, invColor);
            mask >>= 1;
            if (!mask) {
                mask = 0x80;
                ++line;
                value = pgm_read_byte(line);
            }
        }
    }
}

/**
 * \fn void Bitmap::drawInvertedBitmap(int x, int y, const Bitmap &bitmap)
 * \brief Draws \a bitmap at (\a x, \a y) in inverted colors.
 *
 * This is a convenience function that is equivalent to
 * drawBitmap(\a x, \a y, \a bitmap, \ref Black).
 *
 * \sa drawBitmap()
 */

/**
 * \fn void Bitmap::drawInvertedBitmap(int x, int y, Bitmap::ProgMem bitmap)
 * \brief Draws \a bitmap at (\a x, \a y) in inverted colors.
 *
 * This is a convenience function that is equivalent to
 * drawBitmap(\a x, \a y, \a bitmap, \ref Black).
 *
 * \sa drawBitmap()
 */

/**
 * \fn Font Bitmap::font() const
 * \brief Returns the currently selected font, or null if none selected.
 *
 * \sa setFont(), drawText(), drawChar(), charWidth()
 */

/**
 * \fn void Bitmap::setFont(Font font)
 * \brief Sets the \a font for use with drawText() and drawChar().
 *
 * \code
 * #include <DejaVuSans9.h>
 *
 * display.setFont(DejaVuSans9);
 * display.drawText(0, 0, "Hello");
 * \endcode
 *
 * New fonts can be generated with <a href="https://code.google.com/p/glcd-arduino/downloads/detail?name=GLCDFontCreator2.zip&can=2&q=">GLCDFontCreator2</a>.
 *
 * \sa font(), drawText(), drawChar()
 */

/**
 * \fn Color Bitmap::textColor() const
 * \brief Returns the color that will be used for drawing text with
 * drawText() and drawChar().  The default is \ref White.
 *
 * \sa setTextColor(), drawText(), drawChar()
 */

/**
 * \fn void Bitmap::setTextColor(Color textColor)
 * \brief Sets the \a color that will be used for drawing text with
 * drawText() and drawChar().
 *
 * \sa textColor(), drawText(), drawChar()
 */

#define fontIsFixed(font)   (pgm_read_byte((font)) == 0 && \
                             pgm_read_byte((font) + 1) == 0)
#define fontWidth(font)     (pgm_read_byte((font) + 2))
#define fontHeight(font)    (pgm_read_byte((font) + 3))
#define fontFirstChar(font) (pgm_read_byte((font) + 4))
#define fontCharCount(font) (pgm_read_byte((font) + 5))

/**
 * \brief Draws the \a len characters of \a str at (\a x, \a y).
 *
 * If \a len is less than zero, then the actual length of \a str will be used.
 *
 * The position (\a x, \a y) will be the upper-left pixel of the first
 * character that is drawn.
 *
 * \sa drawChar(), textColor(), font()
 */
void Bitmap::drawText(int x, int y, const char *str, int len)
{
    if (!_font)
        return;
    uint8_t height = fontHeight(_font);
    if (len < 0)
        len = strlen(str);
    while (len-- > 0) {
        x += drawChar(x, y, *str++);
        if (len > 0) {
            fill(x, y, 1, height, !_textColor);
            ++x;
        }
        if (x >= _width)
            break;
    }
}

/**
 * \brief Draws \a len characters starting at \a start from \a str to the
 * screen at (\a x, \a y).
 *
 * If \a len is less than zero, then the actual length of \a str will be used.
 *
 * The position (\a x, \a y) will be the upper-left pixel of the first
 * character that is drawn.
 *
 * \sa drawChar(), textColor(), font()
 */
void Bitmap::drawText(int x, int y, const String &str, int start, int len)
{
    if (!_font)
        return;
    uint8_t height = fontHeight(_font);
    if (len < 0)
        len = str.length() - start;
    while (len-- > 0) {
        x += drawChar(x, y, str[start++]);
        if (len > 0) {
            fill(x, y, 1, height, !_textColor);
            ++x;
        }
        if (x >= _width)
            break;
    }
}

/**
 * \brief Draws a single character \a ch at (\a x, \a y).
 *
 * Returns the width of the character in pixels so that higher-order functions
 * like drawText() can advance \a x to the location of the next character
 * to be drawn.  The width does not include inter-character spacing.
 *
 * The position (\a x, \a y) will be the upper-left pixel of the drawn
 * character.
 *
 * \sa drawText(), textColor(), font(), charWidth()
 */
int Bitmap::drawChar(int x, int y, char ch)
{
    
    uint8_t height = fontHeight(_font);

    /*
    if (ch == ' ') {
        // Font may not have space, or it is zero-width.  Calculate
        // the real size and fill the space.
        int spaceWidth = charWidth('n');
        fill(x, y, spaceWidth, height, !_textColor);
        return spaceWidth;
    }
    */
    uint8_t first = fontFirstChar(_font);
    uint8_t count = fontCharCount(_font);
    uint8_t index = (uint8_t)ch;
    
    
    Serial.print("first:");
    Serial.print(first);
    Serial.print(" count:");
     Serial.print(count);
    Serial.print(" index:");
     Serial.print(index);
    
  
    if (index < first || index >= (first + count))
        return 0;
    index -= first;
    
     Serial.print(" new index:");
     Serial.print(index);
    uint8_t heightBytes = (height + 7) >> 3;;
    //uint8_t heightBytes = 2;
   
    uint8_t width;
    const uint8_t *image;

  
    if (fontIsFixed(_font)) {
        // Fixed-width font.
        width = fontWidth(_font);
        //Serial.print("index:");
        //Serial.println(index);
        Serial.print(" heightbytes:");
        Serial.print(heightBytes);
        Serial.print(" width:");
        Serial.print(width);
        Serial.print(" height:");
        Serial.println(height);
        
         
        //image = ((const uint8_t *)_font) + 6 + index * heightBytes * width;
        //image = ((const uint8_t *)_font) + 6 + (index -1) * width * 2 + 14;
        int fontCharOffset = 6 + index*heightBytes*width;
        image = ((const uint8_t *)_font) + fontCharOffset;
        Serial.print(" char:");
        Serial.print(ch);
        Serial.print(" font char offset:");
        Serial.print(fontCharOffset);
        //Serial.print(" column:");
        //Serial.print("0x");
        //Serial.print(pgm_read_byte((const uint8_t *)_font + fontCharOffset + 2) , HEX);
        
      
   
        //Serial.print("imagecount:");
        //Serial.println(6 + (index -1) * width * 2 + 14);
        //Serial.print("imagecount:");
        //Serial.println( 6 + index  * width );
        //Serial.print("image: 0x");
        //Serial.println(*image, HEX);
        //Serial.print("data: 0x");
        //Serial.println(pgm_read_byte(image), HEX);
        
    } else {
        // Variable-width font.
        width = pgm_read_byte(_font + 6 + index);
        image = ((const uint8_t *)_font) + 6 + count;
        for (uint8_t temp = 0; temp < index; ++temp) {
            // Scan through all previous characters to find the starting
            // location for this one.
            image += pgm_read_byte(_font + 6 + temp) * heightBytes;
        }
    }
    if ((x + width) <= 0 || (y + height) <= 0)
        return width;   // Character is off the top or left of the screen.
    Color invColor = !_textColor;
  
    Serial.println();

    int i=0;
    
    for (uint8_t j = 0; j < width * heightBytes; j++) { // Width
      uint8_t data = pgm_read_byte(image + j);
            
      /*
      Serial.print(" i:");
      Serial.print(i);
      Serial.print(" j:");
      Serial.print(j);
      Serial.print(" data:");
      Serial.print("0x");
      Serial.print(data, HEX);
      Serial.println();
      */
      
      //if ((i == heightBytes - 1) && heightBytes > 1) {
      //  offsetboo = height - 8;
      //}
      //Serial.print(" offset:");
      //Serial.println(offsetboo);
      
      
      
      /*
      for (uint8_t k = 0; k < 8; k++) {
        if (data & (1 << k)) 
          setPixel(x + j, y + offsetboo + k, White);
        else
          setPixel(x + j, y + offsetboo + k, Black);          
      }
      */
      
      
      
    //}
      for (uint8_t k = 0; k < 8; k++) {
        if (data & (1 << k)) 
          setPixel(x + j/heightBytes , y + i*8 + k, White);
        else
          setPixel(x + j/heightBytes, y + i*8 + k, Black);          
      }
      
      if (++i == heightBytes){
        i=0;
        
      }
      
      
    }
  
 /*
// last but not least, draw the character
  for (uint8_t j = 0; j < width; j++) { // Width
    for (uint8_t i = bytes - 1; i < 254; i--) { // Vertical Bytes
      uint8_t data = pgm_read_byte(font + index + j + (i * width));
      int offset = (i * 8);
      if ((i == bytes - 1) && bytes > 1) {
        offset = header.height - 8;
      }
      for (uint8_t k = 0; k < 8; k++) { // Vertical bits
        if ((offset+k >= i*8) && (offset+k <= header.height)) {
          if (data & (1 << k)) {
              if(inverse) {
                setPixel(x + j, y + offset + k, GRAPHICS_OFF);
              } else {
                setPixel(x + j, y + offset + k, GRAPHICS_ON);
              }
          } else {
              if(inverse) {
                  setPixel(x + j, y + offset + k, GRAPHICS_ON);
              } else {
                  setPixel(x + j, y + offset + k, GRAPHICS_OFF);
              }
          }
        }
      }
    }
  } 
 */
    
    return width;
}

/**
 * \brief Returns the width in pixels of \a ch in the current font().
 *
 * Returns zero if font() is not set, or \a ch is not present in font().
 *
 * \sa drawChar(), font(), textWidth(), textHeight()
 */
int Bitmap::charWidth(char ch) const
{
    uint8_t index = (uint8_t)ch;
    if (!_font)
        return 0;
    uint8_t first = fontFirstChar(_font);
    uint8_t count = fontCharCount(_font);
    if (index == ' ')
        index = 'n';    // In case the font does not contain space.
    if (index < first || index >= (first + count))
        return 0;
    if (fontIsFixed(_font))
        return fontWidth(_font);
    else
        return pgm_read_byte(_font + 6 + (index - first));
}

/**
 * \brief Returns the width in pixels of the \a len characters of \a str
 * in the current font(), including inter-character spacing.
 *
 * If \a len is less than zero, then the actual length of \a str will be used.
 *
 * \sa drawText(), charWidth(), textHeight()
 */
int Bitmap::textWidth(const char *str, int len) const
{
    int width = 0;
    if (len < 0)
        len = strlen(str);
    while (len-- > 0) {
        width += charWidth(*str++);
        if (len > 0)
            ++width;
    }
    return width;
}

/**
 * \brief Returns the width in pixels of the \a len characters of \a str
 * in the current font(), starting at \a start, including inter-character
 * spacing.
 *
 * If \a len is less than zero, then the actual length of \a str will be used.
 *
 * \sa drawText(), charWidth(), textHeight()
 */
int Bitmap::textWidth(const String &str, int start, int len) const
{
    int width = 0;
    if (len < 0)
        len = str.length() - start;
    while (len-- > 0) {
        width += charWidth(str[start++]);
        if (len > 0)
            ++width;
    }
    return width;
}

/**
 * \brief Returns the height in pixels of the current text drawing font();
 * or zero if font() is not set.
 *
 * \sa font(), charWidth(), textWidth()
 */
int Bitmap::textHeight() const
{
    if (_font)
        return fontHeight(_font);
    else
        return 0;
}

/**
 * \brief Copies the \a width x \a height pixels starting at top-left
 * corner (\a x, \a y) to (\a destX, \a destY) in the bitmap \a dest.
 *
 * The \a dest bitmap can be the same as this object, in which case the copy
 * will be performed in a manner that correctly handles overlapping regions.
 *
 * If some part of the source region is outside the bounds of this object,
 * then the value \ref Black will be copied to \a dest for those pixels.
 * This can be used to produce a behaviour similar to scroll() when
 * \a bitmap is the same as this object.
 *
 * \sa drawBitmap(), fill(), scroll()
 */
void Bitmap::copy(int x, int y, int width, int height, Bitmap *dest, int destX, int destY)
{
    if (dest == this) {
        // Copying to within the same bitmap, so copy in a direction
        // that will prevent problems with overlap.
        blit(x, y, x + width - 1, y + height - 1, destX, destY);
    } else {
        // Copying to a different bitmap.
        while (height > 0) {
            for (int tempx = 0; tempx < width; ++tempx)
                dest->setPixel(destX + tempx, destY, pixel(x + tempx, y));
            ++y;
            ++destY;
            --height;
        }
    }
}

/**
 * \brief Fills the \a width x \a height pixels starting at top-left
 * corner (\a x, \a y) with \a color.
 *
 * \sa copy(), clear(), invert(), drawRect()
 */
void Bitmap::fill(int x, int y, int width, int height, Color color)
{
    while (height > 0) {
        for (int temp = 0; temp < width; ++temp)
            setPixel(x + temp, y, color);
        ++y;
        --height;
    }
}

/**
 * \brief Fills the \a width x \a height pixels starting at top-left
 * corner (\a x, \a y) with the contents of \a pattern.
 *
 * The \a pattern must point to program memory.  The first two bytes are the
 * width and height of the pattern in pixels.  The rest of the data contains
 * the pixels for the pattern, with lines byte-aligned.
 *
 * Bits that are 1 in the \a pattern are drawn with \a color.  Bits that are
 * 0 in the \a pattern are drawn with the inverse of \a color.
 *
 * \sa drawBitmap(), clear(), invert()
 */
void Bitmap::fill(int x, int y, int width, int height, Bitmap::ProgMem pattern, Color color)
{
    uint8_t w = pgm_read_byte(pattern);
    uint8_t s = (w + 7) >> 3;
    uint8_t h = pgm_read_byte(pattern + 1);
    if (!w || !h)
        return;
    Color invColor = !color;
    for (int tempy = 0; tempy < height; ++tempy) {
        const uint8_t *startLine = ((const uint8_t *)pattern) + 2 + (tempy % h) * s;
        const uint8_t *line = startLine;
        uint8_t mask = 0x80;
        uint8_t value = pgm_read_byte(line++);
        int bit = 0;
        for (int tempx = 0; tempx < width; ++tempx) {
            if (value & mask)
                setPixel(x + tempx, y + tempy, color);
            else
                setPixel(x + tempx, y + tempy, invColor);
            if (++bit >= w) {
                mask = 0x80;
                line = startLine;
                value = pgm_read_byte(line++);
                bit = 0;
            } else {
                mask >>= 1;
                if (!mask) {
                    mask = 0x80;
                    value = pgm_read_byte(line++);
                }
            }
        }
    }
}

/**
 * \fn void Bitmap::scroll(int dx, int dy, Color fillColor)
 * \brief Scrolls the entire contents of the bitmap by \a dx and \a dy.
 *
 * If \a dx is 2 and \a dy is -1, then the region will be scrolled two
 * pixels to the right and one pixel up.  Pixels that are uncovered
 * by the scroll are filled with \a fillColor.
 *
 * \sa copy(), fill()
 */

/**
 * \brief Scrolls the \a width x \a height pixels starting at top-left
 * corner (\a x, \a y) by \a dx and \a dy.
 *
 * If \a dx is 2 and \a dy is -1, then the region will be scrolled two
 * pixels to the right and one pixel up.  Pixels that are uncovered
 * by the scroll are filled with \a fillColor.
 *
 * \sa copy(), fill()
 */
void Bitmap::scroll(int x, int y, int width, int height, int dx, int dy, Color fillColor)
{
    // Bail out if no scrolling at all.
    if (!dx && !dy)
        return;

    // Clamp the scroll region to the extents of the bitmap.
    if (x < 0) {
        width += x;
        x = 0;
    }
    if (y < 0) {
        height += y;
        y = 0;
    }
    if ((x + width) > _width)
        width = _width - x;
    if ((y + height) > _height)
        height = _height - y;
    if (width <= 0 || height <= 0)
        return;

    // Scroll the region in the specified direction.
    if (dy < 0) {
        if (dx < 0)
            blit(x - dx, y - dy, x + width - 1 + dx, y + height - 1 + dy, x, y);
        else
            blit(x, y - dy, x + width - 1 - dx, y + height - 1 + dy, x + dx, y);
    } else {
        if (dx < 0)
            blit(x - dx, y, x + width - 1 + dx, y + height - 1 - dy, x, y + dy);
        else
            blit(x, y, x + width - 1 - dx, y + height - 1 - dy, x + dx, y + dy);
    }

    // Fill the pixels that were uncovered by the scroll.
    if (dy < 0) {
        fill(x, y + height + dy, width, -dy, fillColor);
        if (dx < 0)
            fill(x + width + dx, y, -dx, height + dy, fillColor);
        else if (dx > 0)
            fill(x, y, dx, height + dy, fillColor);
    } else if (dy > 0) {
        fill(x, y, width, -dy, fillColor);
        if (dx < 0)
            fill(x + width + dx, y + dy, -dx, height - dy, fillColor);
        else if (dx > 0)
            fill(x, y + dy, dx, height - dy, fillColor);
    } else if (dx < 0) {
        fill(x + width + dx, y, -dx, height, fillColor);
    } else if (dx > 0) {
        fill(x, y, dx, height, fillColor);
    }
}

/**
 * \brief Inverts the \a width x \a height pixels starting at top-left
 * corner (\a x, \a y).
 *
 * \sa fill()
 */
void Bitmap::invert(int x, int y, int width, int height)
{
    while (height > 0) {
        for (int tempx = x + width - 1; tempx >= x; --tempx)
            setPixel(tempx, y, !pixel(tempx, y));
        --height;
        ++y;
    }
}

void Bitmap::blit(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (y3 < y1 || (y1 == y3 && x3 <= x1)) {
        for (int tempy = y1; tempy <= y2; ++tempy) {
            int y = y1 - tempy + y3;
            int x = x3 - x1;
            for (int tempx = x1; tempx <= x2; ++tempx)
                setPixel(x + tempx, y, pixel(tempx, tempy));
        }
    } else {
        for (int tempy = y2; tempy >= y1; --tempy) {
            int y = y1 - tempy + y3;
            int x = x3 - x1;
            for (int tempx = x2; tempx >= x1; --tempx)
                setPixel(x + tempx, y, pixel(tempx, tempy));
        }
    }
}

void Bitmap::drawCirclePoints(int centerX, int centerY, int radius, int x, int y, Color borderColor, Color fillColor)
{
    if (x != y) {
        setPixel(centerX + x, centerY + y, borderColor);
        setPixel(centerX + y, centerY + x, borderColor);
        setPixel(centerX + y, centerY - x, borderColor);
        setPixel(centerX + x, centerY - y, borderColor);
        setPixel(centerX - x, centerY - y, borderColor);
        setPixel(centerX - y, centerY - x, borderColor);
        setPixel(centerX - y, centerY + x, borderColor);
        setPixel(centerX - x, centerY + y, borderColor);
        if (fillColor != NoFill) {
            if (radius > 1) {
                drawLine(centerX - x + 1, centerY + y, centerX + x - 1, centerY + y, fillColor);
                drawLine(centerX - y + 1, centerY + x, centerX + y - 1, centerY + x, fillColor);
                drawLine(centerX - x + 1, centerY - y, centerX + x - 1, centerY - y, fillColor);
                drawLine(centerX - y + 1, centerY - x, centerX + y - 1, centerY - x, fillColor);
            } else if (radius == 1) {
                setPixel(centerX, centerY, fillColor);
            }
        }
    } else {
        setPixel(centerX + x, centerY + y, borderColor);
        setPixel(centerX + y, centerY - x, borderColor);
        setPixel(centerX - x, centerY - y, borderColor);
        setPixel(centerX - y, centerY + x, borderColor);
        if (fillColor != NoFill) {
            if (radius > 1) {
                drawLine(centerX - x + 1, centerY + y, centerX + x - 1, centerY + y, fillColor);
                drawLine(centerX - x + 1, centerY - y, centerX + x - 1, centerY - y, fillColor);
            } else if (radius == 1) {
                setPixel(centerX, centerY, fillColor);
            }
        }
    }
}

void Bitmap::setFont(Font font) { _font = font; }

class DMD3 : public Bitmap
{
public:
    explicit DMD3(int widthPanels = 1, int heightPanels = 1);
    ~DMD3();

    bool doubleBuffer() const { return _doubleBuffer; }
    void setDoubleBuffer(bool doubleBuffer);
    void swapBuffers();
    void swapBuffersAndCopy();

    void loop();
    void refresh();

    void enableTimer1();
    void disableTimer1();

    void enableTimer2();
    void disableTimer2();

    static Color fromRGB(uint8_t r, uint8_t g, uint8_t b);
  
    void debugPixelLine(unsigned int y, char *buf);
    void getD1BankData();
    void refreshData();
    void print(String key, uint8_t data);

private:
    // Disable copy constructor and operator=().
    DMD3(const DMD3 &other) : Bitmap(other) {}
    DMD3 &operator=(const DMD3 &) { return *this; }

    bool _doubleBuffer;
    uint8_t phase;
    uint8_t *fb0;
    uint8_t *fb1;
    uint8_t *displayfb;
    unsigned long lastRefresh;
    int _widthPanels, _heightPanels;
};

/**
 * \class DMD DMD.h <DMD.h>
 * \brief Handle large dot matrix displays composed of LED's.
 *
 * This class is designed for use with
 * <a href="http://www.freetronics.com/dmd">Freetronics Large Dot Matrix
 * Displays</a>.  These displays have 512 LED's arranged in a 32x16 matrix
 * and controlled by an SPI interface.  The displays are available in
 * red, blue, green, yellow, and white variations (for which this class
 * always uses the constant \ref White regardless of the physical color).
 *
 * \section dmd_drawing Drawing
 *
 * DMD inherits from Bitmap so that any of the drawing functions in that
 * class can be used to draw directly to dot matrix displays.  The following
 * example initializes a single display panel and draws a rectangle and a
 * circle into it at setup time:
 *
 * \code
 * #include <DMD.h>
 *
 * DMD display;
 *
 * void setup() {
 *     display.drawRect(5, 2, 27, 13);
 *     display.drawCircle(16, 8, 4);
 * }
 * \endcode
 *
 * The display must be updated frequently from the application's main loop:
 *
 * \code
 * void loop() {
 *     display.loop();
 * }
 * \endcode
 *
 * \section dmd_interrupts Interrupt-driven display refresh
 *
 * The loop() method simplifies updating the display from the application's
 * main loop but it can sometimes be inconvenient to arrange for it to be
 * called regularly, especially if the application wishes to use
 * <tt>delay()</tt> or <tt>delayMicroseconds()</tt>.
 *
 * DMD provides an asynchronous display update mechanism using Timer1
 * interrupts.  The application turns on interrupts using enableTimer1()
 * and then calls refresh() from the interrupt service routine:
 *
 * \code
 * #include <DMD.h>
 *
 * DMD display;
 *
 * ISR(TIMER1_OVF_vect)
 * {
 *     display.refresh();
 * }
 *
 * void setup() {
 *     display.enableTimer1();
 * }
 * \endcode
 *
 * If Timer1 is already in use by some other part of your application,
 * then Timer2 can be used as an alternative interrupt source:
 *
 * \code
 * #include <DMD.h>
 *
 * DMD display;
 *
 * ISR(TIMER2_OVF_vect)
 * {
 *     display.refresh();
 * }
 *
 * void setup() {
 *     display.enableTimer2();
 * }
 * \endcode
 *
 * DMD can also be used with third-party timer libraries such as
 * <a href="http://code.google.com/p/arduino-timerone/downloads/list">TimerOne</a>:
 *
 * \code
 * #include <DMD.h>
 * #include <TimerOne.h>
 *
 * DMD display;
 *
 * void refreshDisplay()
 * {
 *     display.refresh();
 * }
 *
 * void setup() {
 *     Timer1.initialize(5000);
 *     Timer1.attachInterrupt(refreshDisplay);
 * }
 * \endcode
 *
 * \section dmd_double_buffer Double buffering
 *
 * When using interrupts, the system can sometimes exhibit "tearing" artifacts
 * where half-finished images are displayed because an interrupt fired in
 * the middle of a screen update.
 *
 * This problem can be alleviated using double buffering: all rendering is done
 * to an off-screen buffer that is swapped onto the screen once it is ready
 * for display.  Rendering then switches to the other buffer that is now
 * off-screen.  The following example demonstrates this:
 *
 * \code
 * #include <DMD.h>
 *
 * DMD display;
 *
 * ISR(TIMER1_OVF_vect)
 * {
 *     display.refresh();
 * }
 *
 * void setup() {
 *     display.setDoubleBuffer(true);
 *     display.enableTimer1();
 * }
 *
 * void loop() {
 *     updateDisplay();
 *     display.swapBuffers();
 *     delay(50);   // Delay between frames.
 * }
 *
 * void updateDisplay() {
 *     // Draw the new display contents into the off-screen buffer.
 *     display.clear();
 *     ...
 * }
 * \endcode
 *
 * The downside of double buffering is that it uses twice as much main memory
 * to manage the contents of the screen.
 *
 * \section dmd_multi Multiple panels
 *
 * Multiple panels can be daisy-chained together using ribbon cables.
 * If there is a single row of panels, then they must be connected
 * to the Arduino board as follows:
 *
 * \image html dmd-4x1.png
 *
 * If there are multiple rows of panels, then alternating rows are
 * flipped upside-down so that the short ribbon cables provided by
 * Freetronics reach (this technique is thanks to Chris Debenham; see
 * http://www.adebenham.com/category/arduino/dmd/ for more details):
 *
 * \image html dmd-4x2.png
 *
 * This technique can be repeated for as many rows as required, with the
 * bottom row always right-way-up:
 *
 * \image html dmd-4x3.png
 *
 * DMD automatically takes care of flipping the data for panels in the
 * alternating rows.  No special action is required by the user except
 * to physically connect the panels as shown and to initialize the DMD
 * class appropriately:
 *
 * \code
 * #include <DMD.h>
 *
 * DMD display(4, 2);   // 4 panels wide, 2 panels high
 * \endcode
 */

// Pins on the DMD connector board.
#define DMD3_PIN_PHASE_LSB       6       // A
#define DMD3_PIN_PHASE_MSB       7       // B
#define DMD3_PIN_LATCH           8       // SCLK
#define DMD3_PIN_OUTPUT_ENABLE   9       // nOE
#define DMD3_PIN_SPI_SS          SS      // SPI Slave Select
#define DMD3_PIN_SPI_MOSI        MOSI    // SPI Master Out, Slave In (R)
#define DMD3_PIN_SPI_MISO        MISO    // SPI Master In, Slave Out
#define DMD3_PIN_SPI_SCK         SCK     // SPI Serial Clock (CLK)

// Dimension information for the display.
#define DMD3_NUM_COLUMNS         16      // Number of columns in a panel.
#define DMD3_NUM_ROWS            16      // Number of rows in a panel.

// Refresh times.
#define DMD3_REFRESH_MS          4
#define DMD3_REFRESH_US          4000

/**
 * \brief Constructs a new dot matrix display handler for a display that
 * is \a widthPanels x \a heightPanels in size.
 *
 * Note: the parameters to this constructor are specified in panels,
 * whereas width() and height() are specified in pixels.
 *
 * \sa width(), height()
 */
DMD3::DMD3(int widthPanels, int heightPanels)
    : Bitmap(widthPanels * DMD3_NUM_COLUMNS, heightPanels * DMD3_NUM_ROWS)
    , _doubleBuffer(false)
    , phase(0)
    , fb0(0)
    , fb1(0)
    , displayfb(0)
    , lastRefresh(millis())
{
    // Both rendering and display are to fb0 initially.
    fb0 = displayfb = fb;

    // Initialize SPI to MSB-first, mode 0, clock divider = 2.
    pinMode(DMD3_PIN_SPI_SCK, OUTPUT);
    pinMode(DMD3_PIN_SPI_MOSI, OUTPUT);
    pinMode(DMD3_PIN_SPI_SS, OUTPUT);
    digitalWrite(DMD3_PIN_SPI_SCK, LOW);
    digitalWrite(DMD3_PIN_SPI_MOSI, LOW);
    digitalWrite(DMD3_PIN_SPI_SS, HIGH);
    SPCR |= _BV(MSTR);
    SPCR |= _BV(SPE);
    SPCR &= ~(_BV(DORD));   // MSB-first
    SPCR &= ~0x0C;          // Mode 0
    SPCR &= ~0x03;          // Clock divider rate 2
    SPSR |= 0x01;           // MSB of clock divider rate

    // Initialize the DMD-specific pins.
    pinMode(DMD3_PIN_PHASE_LSB, OUTPUT);
    pinMode(DMD3_PIN_PHASE_MSB, OUTPUT);
    pinMode(DMD3_PIN_LATCH, OUTPUT);
    pinMode(DMD3_PIN_OUTPUT_ENABLE, OUTPUT);
    digitalWrite(DMD3_PIN_PHASE_LSB, LOW);
    digitalWrite(DMD3_PIN_PHASE_MSB, LOW);
    digitalWrite(DMD3_PIN_LATCH, LOW);
    digitalWrite(DMD3_PIN_OUTPUT_ENABLE, LOW);
    digitalWrite(DMD3_PIN_SPI_MOSI, HIGH);
      
    _widthPanels = widthPanels;
    _heightPanels = heightPanels;
}

/**
 * \brief Destroys this dot matrix display handler.
 */
DMD3::~DMD3()
{
    if (fb0)
        free(fb0);
    if (fb1)
        free(fb1);
    fb = 0; // Don't free the buffer again in the base class.
}

/**
 * \fn bool DMD::doubleBuffer() const
 * \brief Returns true if the display is double-buffered; false if
 * single-buffered.  The default is false.
 *
 * \sa setDoubleBuffer(), swapBuffers(), refresh()
 */

/**
 * \brief Enables or disables double-buffering according to \a doubleBuffer.
 *
 * When double-buffering is enabled, rendering operations are sent to a
 * memory buffer that isn't currently displayed on-screen.  Once the
 * application has completed the screen update, it calls swapBuffers()
 * to display the current buffer and switch rendering to the other
 * now invisible buffer.
 *
 * Double-buffering is recommended if refresh() is being called from an
 * interrupt service routine, to prevent "tearing" artifacts that result
 * from simultaneous update of a single shared buffer.
 *
 * This function will allocate memory for the extra buffer when
 * \a doubleBuffer is true.  If there is insufficient memory for the
 * second screen buffer, then this class will revert to single-buffered mode.
 *
 * \sa doubleBuffer(), swapBuffers(), refresh()
 */
void DMD3::setDoubleBuffer(bool doubleBuffer)
{
    if (doubleBuffer != _doubleBuffer) {
        _doubleBuffer = doubleBuffer;
        if (doubleBuffer) {
            // Allocate a new back buffer.
            unsigned int size = _stride * _height;
            fb1 = (uint8_t *)malloc(size);

            // Clear the new back buffer and then switch to it, leaving
            // the current contents of fb0 on the screen.
            if (fb1) {
                memset(fb1, 0xFF, size);
                cli();
                fb = fb1;
                displayfb = fb0;
                sei();
            } else {
                // Failed to allocate the memory, so revert to single-buffered.
                _doubleBuffer = false;
            }
        } else if (fb1) {
            // Disabling double-buffering, so forcibly switch to fb0.
            cli();
            fb = fb0;
            displayfb = fb0;
            sei();

            // Free the unnecessary buffer.
            free(fb1);
            fb1 = 0;
        }
    }
}

/**
 * \brief Swaps the buffers that are used for rendering to the display.
 *
 * When doubleBuffer() is false, this function does nothing.
 * Otherwise the front and back rendering buffers are swapped.
 * See the description of setDoubleBuffer() for more information.
 *
 * The new rendering back buffer will have undefined contents and will
 * probably need to be re-inialized with clear() or fill() before
 * drawing to it.  The swapBuffersAndCopy() function can be used instead
 * to preserve the screen contents from one frame to the next.
 *
 * \sa swapBuffersAndCopy(), setDoubleBuffer()
 */
void DMD3::swapBuffers()
{
    if (_doubleBuffer) {
        // Turn off interrupts while swapping buffers so that we don't
        // accidentally try to refresh() in the middle of this code.
        cli();
        if (fb == fb0) {
            fb = fb1;
            displayfb = fb0;
        } else {
            fb = fb0;
            displayfb = fb1;
        }
        sei();
    }
}

/**
 * \brief Swaps the buffers that are used for rendering to the display
 * and copies the former back buffer contents to the new back buffer.
 *
 * Normally when swapBuffers() is called, the new rendering back buffer
 * will have undefined contents from two frames prior and must be cleared
 * with clear() or fill() before writing new contents to it.
 * This function instead copies the previous frame into the new
 * rendering buffer so that it can be updated in-place.
 *
 * This function is useful if the screen does not change much from one
 * frame to the next.  If the screen changes a lot between frames, then it
 * is usually better to explicitly clear() or fill() the new back buffer.
 *
 * \sa swapBuffers(), setDoubleBuffer()
 */
void DMD3::swapBuffersAndCopy()
{
    swapBuffers();
    if (_doubleBuffer)
        memcpy(fb, displayfb, _stride * _height);
}

/**
 * \brief Performs regular display refresh activities from the
 * application's main loop.
 *
 * \code
 * DMD3 display;
 *
 * void loop() {
 *     display.loop();
 * }
 * \endcode
 *
 * If you are using a timer interrupt service routine, then call
 * refresh() in response to the interrupt instead of calling loop().
 *
 * \sa refresh()
 */
void DMD3::loop()
{
    unsigned long currentTime = millis();
    if ((currentTime - lastRefresh) >= DMD3_REFRESH_MS) {
        lastRefresh = currentTime;
        refresh();
    }
}

// Send a single byte via SPI.
static inline void spiSend(byte value)
{
    SPDR = value;
    while (!(SPSR & _BV(SPIF)))
        ;   // Wait for the transfer to complete.
}

// Flip the bits in a byte.  Table generated by genflip.c
static const uint8_t flipBits[256] PROGMEM = {
    0x00, 0x80, 0x40, 0xC0, 0x20, 0xA0, 0x60, 0xE0, 0x10, 0x90, 0x50, 0xD0,
    0x30, 0xB0, 0x70, 0xF0, 0x08, 0x88, 0x48, 0xC8, 0x28, 0xA8, 0x68, 0xE8,
    0x18, 0x98, 0x58, 0xD8, 0x38, 0xB8, 0x78, 0xF8, 0x04, 0x84, 0x44, 0xC4,
    0x24, 0xA4, 0x64, 0xE4, 0x14, 0x94, 0x54, 0xD4, 0x34, 0xB4, 0x74, 0xF4,
    0x0C, 0x8C, 0x4C, 0xCC, 0x2C, 0xAC, 0x6C, 0xEC, 0x1C, 0x9C, 0x5C, 0xDC,
    0x3C, 0xBC, 0x7C, 0xFC, 0x02, 0x82, 0x42, 0xC2, 0x22, 0xA2, 0x62, 0xE2,
    0x12, 0x92, 0x52, 0xD2, 0x32, 0xB2, 0x72, 0xF2, 0x0A, 0x8A, 0x4A, 0xCA,
    0x2A, 0xAA, 0x6A, 0xEA, 0x1A, 0x9A, 0x5A, 0xDA, 0x3A, 0xBA, 0x7A, 0xFA,
    0x06, 0x86, 0x46, 0xC6, 0x26, 0xA6, 0x66, 0xE6, 0x16, 0x96, 0x56, 0xD6,
    0x36, 0xB6, 0x76, 0xF6, 0x0E, 0x8E, 0x4E, 0xCE, 0x2E, 0xAE, 0x6E, 0xEE,
    0x1E, 0x9E, 0x5E, 0xDE, 0x3E, 0xBE, 0x7E, 0xFE, 0x01, 0x81, 0x41, 0xC1,
    0x21, 0xA1, 0x61, 0xE1, 0x11, 0x91, 0x51, 0xD1, 0x31, 0xB1, 0x71, 0xF1,
    0x09, 0x89, 0x49, 0xC9, 0x29, 0xA9, 0x69, 0xE9, 0x19, 0x99, 0x59, 0xD9,
    0x39, 0xB9, 0x79, 0xF9, 0x05, 0x85, 0x45, 0xC5, 0x25, 0xA5, 0x65, 0xE5,
    0x15, 0x95, 0x55, 0xD5, 0x35, 0xB5, 0x75, 0xF5, 0x0D, 0x8D, 0x4D, 0xCD,
    0x2D, 0xAD, 0x6D, 0xED, 0x1D, 0x9D, 0x5D, 0xDD, 0x3D, 0xBD, 0x7D, 0xFD,
    0x03, 0x83, 0x43, 0xC3, 0x23, 0xA3, 0x63, 0xE3, 0x13, 0x93, 0x53, 0xD3,
    0x33, 0xB3, 0x73, 0xF3, 0x0B, 0x8B, 0x4B, 0xCB, 0x2B, 0xAB, 0x6B, 0xEB,
    0x1B, 0x9B, 0x5B, 0xDB, 0x3B, 0xBB, 0x7B, 0xFB, 0x07, 0x87, 0x47, 0xC7,
    0x27, 0xA7, 0x67, 0xE7, 0x17, 0x97, 0x57, 0xD7, 0x37, 0xB7, 0x77, 0xF7,
    0x0F, 0x8F, 0x4F, 0xCF, 0x2F, 0xAF, 0x6F, 0xEF, 0x1F, 0x9F, 0x5F, 0xDF,
    0x3F, 0xBF, 0x7F, 0xFF
};

/**
 * \brief Refresh the display.
 *
 * This function must be called at least once every 5 milliseconds
 * for smooth non-flickering update of the display.  It is usually
 * called by loop(), but can also be called in response to a
 * timer interrupt.
 *
 * If this function is called from an interrupt service routine,
 * then it is recommended that double-buffering be enabled with
 * setDoubleBuffer() to prevent "tearing" artifacts that result
 * from simultaneous update of a single shared buffer.
 *
 * \sa loop(), setDoubleBuffer(), enableTimer1()
 */
void DMD3::refresh()
{
    // Bail out if there is a conflict on the SPI bus.
    if (!digitalRead(DMD3_PIN_SPI_SS))
        return;

    // Transfer the data for the next group of interleaved rows.
    int stride4 = _stride * 4;
    uint8_t *data0;
    uint8_t *data1;
    uint8_t *data2;
    uint8_t *data3;
    bool flipRow = ((_height & 0x10) == 0);
    for (int y = 0; y < _height; y += 16) {
        if (!flipRow) {
            // The panels in this row are the right way up.
            data0 = displayfb + _stride * (y + phase);
            data1 = data0 + stride4;
            data2 = data1 + stride4;
            data3 = data2 + stride4;
            for (int x = _stride; x > 0; --x) {
                spiSend(*data3++);
                spiSend(*data2++);
                spiSend(*data1++);
                spiSend(*data0++);
            }
            flipRow = true;
        } else {
            // The panels in this row are upside-down and reversed.
            data0 = displayfb
		 + _stride * (y + 16 - phase) - 1;
            data1 = data0 - stride4;
            data2 = data1 - stride4;
            data3 = data2 - stride4;
            for (int x = _stride; x > 0; --x) {
                spiSend(pgm_read_byte(&(flipBits[*data3--])));
                spiSend(pgm_read_byte(&(flipBits[*data2--])));
                spiSend(pgm_read_byte(&(flipBits[*data1--])));
                spiSend(pgm_read_byte(&(flipBits[*data0--])));
            }
            flipRow = false;
        }
    }

    // Latch the data from the shift registers onto the actual display.
    //digitalWrite(DMD3_PIN_OUTPUT_ENABLE, LOW);
    pinMode(DMD3_PIN_OUTPUT_ENABLE,INPUT);
    digitalWrite(DMD3_PIN_LATCH, HIGH);
    digitalWrite(DMD3_PIN_LATCH, LOW);
    if (phase & 0x02)
        digitalWrite(DMD3_PIN_PHASE_MSB, HIGH);
    else
        digitalWrite(DMD3_PIN_PHASE_MSB, LOW);
    if (phase & 0x01)
        digitalWrite(DMD3_PIN_PHASE_LSB, HIGH);
    else
        digitalWrite(DMD3_PIN_PHASE_LSB, LOW);
    pinMode(DMD3_PIN_OUTPUT_ENABLE,OUTPUT);
    //digitalWrite(DMD3_PIN_OUTPUT_ENABLE, HIGH);
    phase = (phase + 1) & 0x03;
}

/**
 * \brief Enables Timer1 overflow interrupts for updating this display.
 *
 * The application must also provide an interrupt service routine for
 * Timer1 that calls refresh():
 *
 * \code
 * #include <DMD3.h>
 *
 * DMD3 display;
 *
 * ISR(TIMER1_OVF_vect)
 * {
 *     display.refresh();
 * }
 *
 * void setup() {
 *     display.enableTimer1();
 * }
 * \endcode
 *
 * If timer interrupts are being used to update the display, then it is
 * unnecessary to call loop().
 *
 * \sa refresh(), disableTimer1(), enableTimer2(), setDoubleBuffer()
 */
void DMD3::enableTimer1()
{
    // Number of CPU cycles in the display's refresh period.
    unsigned long numCycles = (F_CPU / 2000000) * DMD3_REFRESH_US;

    // Determine the prescaler to be used.
    #define TIMER1_RESOLUTION  65536UL
    uint8_t prescaler;
    if (numCycles < TIMER1_RESOLUTION) {
        // No prescaling required.
        prescaler = _BV(CS10);
    } else if (numCycles < TIMER1_RESOLUTION * 8) {
        // Prescaler = 8.
        prescaler = _BV(CS11);
        numCycles >>= 3;
    } else if (numCycles < TIMER1_RESOLUTION * 64) {
        // Prescaler = 64.
        prescaler = _BV(CS11) | _BV(CS10);
        numCycles >>= 6;
    } else if (numCycles < TIMER1_RESOLUTION * 256) {
        // Prescaler = 256.
        prescaler = _BV(CS12);
        numCycles >>= 8;
    } else if (numCycles < TIMER1_RESOLUTION * 1024) {
        // Prescaler = 1024.
        prescaler = _BV(CS12) | _BV(CS10);
        numCycles >>= 10;
    } else {
        // Too long, so set the maximum timeout.
        prescaler = _BV(CS12) | _BV(CS10);
        numCycles = TIMER1_RESOLUTION - 1;
    }

    // Configure Timer1 for the period we want.
    TCCR1A = 0;
    TCCR1B = _BV(WGM13);
    uint8_t saveSREG = SREG;
    cli();
    ICR1 = numCycles;
    SREG = saveSREG;    // Implicit sei() if interrupts were on previously.
    TCCR1B = (TCCR1B & ~(_BV(CS12) | _BV(CS11) | _BV(CS10))) | prescaler;

    // Turn on the Timer1 overflow interrupt.
    TIMSK1 |= _BV(TOIE1);
}

/**
 * \brief Disables Timer1 overflow interrupts.
 *
 * \sa enableTimer1()
 */
void DMD3::disableTimer1()
{
    // Turn off the Timer1 overflow interrupt.
    TIMSK1 &= ~_BV(TOIE1);
}

/**
 * \brief Enables Timer2 overflow interrupts for updating this display.
 *
 * The application must also provide an interrupt service routine for
 * Timer2 that calls refresh():
 *
 * \code
 * #include <DMD3.h>
 *
 * DMD3 display;
 *
 * ISR(TIMER2_OVF_vect)
 * {
 *     display.refresh();
 * }
 *
 * void setup() {
 *     display.enableTimer2();
 * }
 * \endcode
 *
 * If timer interrupts are being used to update the display, then it is
 * unnecessary to call loop().
 *
 * \sa refresh(), disableTimer2(), enableTimer1(), setDoubleBuffer()
 */
void DMD3::enableTimer2()
{
    // Configure Timer2 for the period we want.  With the prescaler set
    // to 128, then 256 increments of Timer2 gives roughly 4 ms between
    // overflows on a system with a 16 MHz clock.  We adjust the prescaler
    // accordingly for other clock frequencies.
    TCCR2A = 0;
    if (F_CPU >= 32000000)
        TCCR2B = _BV(CS22) | _BV(CS21); // Prescaler = 256
    else if (F_CPU >= 16000000)
        TCCR2B = _BV(CS22) | _BV(CS20); // Prescaler = 128
    else if (F_CPU >= 8000000)
        TCCR2B = _BV(CS22);             // Prescaler = 64
    else
        TCCR2B = _BV(CS21) | _BV(CS20); // Prescaler = 32

    // Reset Timer2 to kick off the process.
    TCNT2 = 0;

    // Turn on the Timer2 overflow interrupt (also turn off OCIE2A and OCIE2B).
    TIMSK2 = _BV(TOIE2);
}

/**
 * \brief Disables Timer2 overflow interrupts.
 *
 * \sa enableTimer2()
 */
void DMD3::disableTimer2()
{
    // Turn off the Timer2 overflow interrupt.
    TIMSK2 &= ~_BV(TOIE2);
}

/**
 * \brief Converts an RGB value into a pixel color value.
 *
 * Returns \ref White if any of \a r, \a g, or \a b are non-zero;
 * otherwise returns \ref Black.
 *
 * This function is provided for upwards compatibility with future
 * displays that support full color.  Monochrome applications should
 * use the \ref Black and \ref White constants directly.
 */
DMD3::Color DMD3::fromRGB(uint8_t r, uint8_t g, uint8_t b)
{
    if (r || g || b)
        return White;
    else
        return Black;
}

void DMD3::debugPixelLine(unsigned int y, char *buf) {
    char *currentPixel = buf;
  for(int x=0;x < width();x++) {
    bool set = pixel(x,y);
    if(set) {
      *currentPixel='[';
      //currentPixel++;
      //*currentPixel=']';
    } else {
        *currentPixel='_';
        //currentPixel++;
        //*currentPixel='_';
    }
    currentPixel++;
  }
  //*currentPixel ='\n';
  currentPixel++;
  *currentPixel = '\0'; // nul terminator
}

void DMD3::refreshData() 
{
  //uint8_t *ptr = fb;
  
  /*
  for (int i=0; i<32; i++) {
    Serial.print("0x");
    Serial.print(*ptr >> 4, HEX);
    Serial.println(*ptr & 0x0F, HEX);
    ptr++;
  }
  */
  
  /*
  uint8_t *d1, *d2, *d3, *d4;
  uint8_t xoffset = 2* (_widthPanels - 1);
  uint8_t yoffset = 0;
  uint8_t *panel = fb + xoffset;
  
  d3 = panel + 7*2*_widthPanels;
  d4 = panel + 15*2*_widthPanels;
  d1 = d3 + 1;
  d2 = d4 + 1;
  
    Serial.print("0x");
    Serial.print(*d1 >> 4, HEX);
    Serial.println(*d1 & 0x0F, HEX);  
  */
  
  
}

void DMD3::print(String key, uint8_t data) 
{
  Serial.print(" ");
  Serial.print(key);
  Serial.print(": 0x");
  Serial.print(data >> 4, HEX);
  Serial.print(data & 0x0F, HEX); 
}

void DMD3::getD1BankData() 
{
  byte toprow = 0x00;
  byte bottomrow = 0x00;
  
   uint8_t *ptr = fb;
   print("d1:", *ptr);
  
  /*
  for (int i=8; i<16; i++) {
    if (pixel(i, 2*bank)) {
      toprow = toprow | 1<<(15-i);
    }
    
    
  }
  
  Serial.print("top: 0b");
  Serial.println(toprow, BIN);
  */
}

DMD3 display(1,1);

void setup()
{
  Serial.begin(9600);
  char buf[100];
  display.setFont(SystemFont5x7);
  //display.setFont(ArialFont16x16);
  //for (int j=0; j<10; j++)
  //display.setPixel(0,0,DMD3::White);
  display.drawChar(0,0,'A');
  //display.drawChar(0,0,'0');
  //display.drawChar(80,0,'E' ); //#=35 , "=34
  //display.drawText(0,0,"192");
  
  
  for (int i=0; i<16; i++) {
    display.debugPixelLine(i, buf);
    Serial.println(buf);
    
  }
  
  
  
  
}

void loop()
{

}
