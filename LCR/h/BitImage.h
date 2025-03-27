//    Class by Tyler Downey
//    BitImage Class
//
//    An array of pixels that can be accurately rendered to screen
//    using ASCII characters

#ifndef BITIMAGE_H
#define BITIMAGE_H
#include "RenderedObject.h"
#include "Constants.h"

class BitImage: public RenderedObject {
private:
    int width;
    int height;
    unsigned char** data;
public:

    BitImage(int w, int h);

    // Outputs an array of strings that can be drawn to StringScreen
    void render(StringScreen screen);

    // Translates a block of data into a character.
    char translateToCharacter(unsigned char d[CHARACTER_WIDTH][CHARACTER_HEIGHT]) const;

    void loadData(unsigned char** d);

    int getWidth() const;

    int getHeight() const;

};

#endif