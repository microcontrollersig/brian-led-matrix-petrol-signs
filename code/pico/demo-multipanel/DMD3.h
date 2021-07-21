#pragma once

#include "MBI5039.h"






class DMD3;
//class String;

class Bitmap
{
public:
    Bitmap(int width, int height);
    ~Bitmap();

    bool isValid() const { return fb != 0; }

    typedef uint8_t Color;

    #if defined(ARDUINO_ARCH_RP2040)
      #define PGM_VOID_P const void *
    #endif

    typedef PGM_VOID_P ProgMem;
    typedef PGM_VOID_P Font;

    static const Color White  = 0;
    static const Color Black  = 1;
    static const Color NoFill = 2;

    int width() const { return _width; }
    int height() const { return _height; }
    int stride() const { return _stride; }
    int bitsPerPixel() const { return 1; }

    uint8_t *data() { return fb; }
    const uint8_t *data() const { return fb; }

    void clear(Color color = Black);

    Color pixel(int x, int y) const;
    void setPixel(int x, int y, Color color = White);
    void clearPixel(int x, int y);

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

    void drawText(int x, int y, const char *str, bool rightPadding = false, int len = -1);
    void drawText(int x, int y, const String &str, int start = 0, int len = -1);

int drawCharVariable(int x, int y, char ch);
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


class DMD3 : public Bitmap
{
public:
    explicit DMD3(int widthPanels = 1, int heightPanels = 1);
    ~DMD3();

    bool doubleBuffer() const { return _doubleBuffer; }
    void setDoubleBuffer(bool doubleBuffer);
    void swapBuffers();
    void swapBuffersAndCopy();

    void setMBI5039(MBI5039 *m);
    void setBrightness(uint8_t brightness);
    uint8_t getBrightness();
    void begin(uint8_t clock_pin, uint8_t latch_pin, uint8_t noe_pin, uint8_t data1_pin, uint8_t data2_pin, uint8_t data3_pin, uint8_t data4_pin);

    void loop();
    void refresh();
    void update();
    void sendData(uint8_t *data1, uint8_t *data2, uint8_t *data3, uint8_t *data4, bool bitOrder);
  
    void enableTimer1();
    void disableTimer1();

    void enableTimer2();
    void disableTimer2();

    static Color fromRGB(uint8_t r, uint8_t g, uint8_t b);
  
    void debugPixelLine(unsigned int y, char *buf);
    void getD1BankData(uint8_t bank);
    void refreshData();
    void print(String key, uint8_t data);
    void sendOneBit(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t mask);
    void clockData(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, bool bitOrder);
  
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
    MBI5039 *mbi;
};

// Dimension information for the display.
#define DMD3_NUM_COLUMNS         16      // Number of columns in a panel.
#define DMD3_NUM_ROWS            16      // Number of rows in a panel.
