
#pragma once
#include "MBI5039.h"

#define PIN_DATA1 D2
#define PIN_DATA2 D1
#define PIN_DATA3 D6
#define PIN_DATA4 D8
#define PIN_CLK D7
#define PIN_LATCH D0
#define PIN_NOE D5

#define DEBUG 
//#define DEBUG

class DMD3;
//class String;

class Bitmap
{
public:
    Bitmap(int width, int height);
    ~Bitmap();

    bool isValid() const { return fb != 0; }

    typedef uint8_t Color;
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
        memset(fb, 0x00, size);
}

/**
 * \brief Destroys this bitmap.
 */
Bitmap::~Bitmap()
{
    if (fb)
        free(fb);
}

void Bitmap::clear(Color color)
{
    unsigned int size = _stride * _height;
    if (color == Black)
        memset(fb, 0x00, size);
    else
        memset(fb, 0xFF, size);
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

    if (ch == ' ') {
        // Font may not have space, or it is zero-width.  Calculate
        // the real size and fill the space.
        int spaceWidth = charWidth('n');
        fill(x, y, spaceWidth, height, !_textColor);
        return spaceWidth;
    }
    uint8_t first = fontFirstChar(_font);
    uint8_t count = fontCharCount(_font);
    uint8_t index = (uint8_t)ch;
    
  
    if (index < first || index >= (first + count))
        return 0;
    index -= first;
     // Serial.print(" new index:");
     //Serial.println(index);
    //uint8_t heightBytes = (height + 7) >> 3;;
    uint8_t heightBytes = 2;
    uint8_t width;
    const uint8_t *image;
    uint8_t image2;
  
    if (fontIsFixed(_font)) {
        // Fixed-width font.
        width = fontWidth(_font);
        image = ((const uint8_t *)_font) + 6 + (index -1) * width * 2 + 14;
      
      
        image2 = pgm_read_byte((const uint8_t *)_font + 6+32*10);

        
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
  
    
  
    for (uint8_t cx = 0; cx < width * 2; ++cx) {
        //for (uint8_t cy = 0; cy < heightBytes; ++cy) {
            uint8_t cy =1;
            uint8_t value = pgm_read_byte(image + cy * width + cx);
           
            int posn;
            if (heightBytes > 1 && cy == (heightBytes - 1))
                posn = height - 8;
            else
                posn = cy * 8;
            //Serial.print(" posn:");
            //Serial.println(posn);
            
            uint8_t yoffset = 0; 
      
            for (uint8_t bit = 0; bit < 8; ++bit) {
                if ((posn + bit) >= (cy * 8) && (posn + bit) <= height) {
                    /*
                    if (value & 0x01)
                        setPixel(x + cx, y + posn + bit, _textColor);
                    else
                        setPixel(x + cx, y + posn + bit, invColor);
                    */
              
                  
                  
                   if (cx % 2 == 1) 
                   {
                     yoffset = 8; 
                   }
                     
 
                  
                    if (value & 0x01) 
                        setPixel(cx/2 - 1 + x, y + yoffset + bit, _textColor);
                    else
                        setPixel(cx/2 - 1 + x, y + yoffset + bit, invColor);  
              
              
                }
                value >>= 1;
            }
        //}
    }
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

    void setMBI5039(MBI5039 *m);
    void setBrightness(float brightness);
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
 /*
void DMD3::loop()
{
    unsigned long currentTime = millis();
    if ((currentTime - lastRefresh) >= DMD3_REFRESH_MS) {
        lastRefresh = currentTime;
        refresh();
    }
}
*/

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

void DMD3::setBrightness(float b)
{
  mbi->setBrightness(b);
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

void DMD3::begin(uint8_t clock_pin, uint8_t latch_pin, uint8_t noe_pin, uint8_t data1_pin, uint8_t data2_pin, uint8_t data3_pin, uint8_t data4_pin)
{
  mbi = new MBI5039(clock_pin, latch_pin, noe_pin, data1_pin, data2_pin, data3_pin, data4_pin);

  pinMode(clock_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
  pinMode(noe_pin, OUTPUT);
  pinMode(data1_pin, OUTPUT);
  pinMode(data2_pin, OUTPUT);
  pinMode(data3_pin, OUTPUT);
  pinMode(data4_pin, OUTPUT);
  
  digitalWrite(noe_pin, HIGH);
  digitalWrite(clock_pin, LOW);
  digitalWrite(latch_pin, LOW);
  digitalWrite(data1_pin, LOW);
  digitalWrite(data2_pin, LOW);
  digitalWrite(data3_pin, LOW);
  digitalWrite(data4_pin, LOW);
}

void DMD3::print(String key, uint8_t data) 
{
  Serial.print(" ");
  Serial.print(key);
  Serial.print(": 0x");
  Serial.print(data >> 4, HEX);
  Serial.print(data & 0x0F, HEX); 
}

void DMD3::sendData(uint8_t *data1, uint8_t *data2, uint8_t *data3, uint8_t *data4, bool bitOrder) 
{

  
  if (bitOrder) {
    mbi->sendDataMSB(data1, data2, data3, data4);
  }

  else {
    mbi->sendDataLSB(data1, data2, data3, data4);
  }

  
  #ifdef DEBUG
  print("d1", *data1);
  print("d2", *data2);
  print("d3", *data3);
  print("d4", *data4);
  Serial.println();
  #endif
}

void DMD3::setMBI5039(MBI5039 *m) 
{
  mbi = m;
}

void DMD3::update() {
  uint8_t *ptr, *d1,*d2,*d3,*d4;
  
  ptr = fb;

  mbi->disable();

  //for (int i=0; i < _heightPanels; i++) 
  //{
  //  for (int j=0; j < _widthPanels; j++) 
  //  {
  //    d1 = ptr + 1 + 7 * _stride + DMD3_NUM_ROWS * _stride * j + DMD3_NUM_COLUMNS * i; 
  //    d2 = ptr + 1 + 15 * _stride + DMD3_NUM_ROWS * _stride * j + DMD3_NUM_COLUMNS * i;
  //    d3 = ptr + 7 * _stride + DMD3_NUM_ROWS * _stride * j + DMD3_NUM_COLUMNS * i;
  //    d4 = ptr + 15 * _stride + DMD3_NUM_ROWS * _stride * j + DMD3_NUM_COLUMNS * i; 
  //  }
  //}
  
  d1 = ptr + 1 + 7*_stride;
  d2 = ptr + 1 + 15 * _stride;
  d3 = ptr + 7 * _stride ;
  d4 = ptr + 15 * _stride ; 
    
  for (int i=0; i<4; i++) {
    sendData(d1,d2,d3,d4, true);
  
    d1 = d1 - _stride;
    d2 = d2 - _stride;
    d3 = d3 - _stride;
    d4 = d4 - _stride;
  
    sendData(d1,d2,d3,d4, false);

    d1 = d1 - _stride;
    d2 = d2 - _stride;
    d3 = d3 - _stride;
    d4 = d4 - _stride;    
    
  }


  mbi->latch();
  mbi->enable();
    
}
