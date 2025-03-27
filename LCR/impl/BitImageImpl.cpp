//    Implementation by Tyler Downey
//    BitImage Class
//    An array of pixels that can be accurately rendered to screen
//    using ASCII characters

#include <iostream>
#include <cstring>
#include "../h/BitImage.h"
#include "../h/RenderedObject.h"

using namespace std;

BitImage::BitImage(int w, int h) {
    width = w;
    height = h;
    data = new unsigned char*[h];
    for(int i = 0; i < h; i++) {
        data[i] = new unsigned char[w];
    }
}

// Outputs an array of strings that can be drawn to StringScreen
void BitImage::render(StringScreen screen) {
    /*unsigned char block[CHARACTER_WIDTH][CHARACTER_HEIGHT];
    string* toreturn;

    toreturn = new string[height / CHARACTER_HEIGHT];

    for(int i = 0; i < height; i += CHARACTER_HEIGHT) {
        for(int j = 0; j < width; j += CHARACTER_WIDTH) {
            for(int y = 0; y < CHARACTER_HEIGHT; y++) {
                for(int x = 0; x < CHARACTER_WIDTH; x++) {
                    block[x][y] = (i+x<width & j+y<height)?data[i+x][j+y]:0;
                }
            }
            toreturn[i / CHARACTER_HEIGHT].push_back(translateToCharacter( block ));
        }
    }

    return toreturn;*/

};

// Translates a block of data into a character.
// A more ambitious version could mix colors or output more complex shapes
// This version is just Nearest Neighbor.
char BitImage::translateToCharacter(unsigned char d[CHARACTER_WIDTH][CHARACTER_HEIGHT]) const {

    return d[0][0];

};

void BitImage::loadData(unsigned char** d) {
    memcpy(data, d, width * height);
}

int BitImage::getWidth() const {
    return width;
}

int BitImage::getHeight() const {
   return height;
}
