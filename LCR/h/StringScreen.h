//    Class by Tyler Downey
//    StringScreen Class
//    Creates a string-based full window display

#ifndef STRINGSCREEN_H
#define STRINGSCREEN_H

#include <iostream>
#include <vector>
#include "Constants.h"

using namespace std;

class StringScreen {
private:
    int width;
    int height;
    vector<pair<char, string>> replacement_registry;
    string *screen;

    string doReplacements(string s);

public:
    // Constructor. Initialize screen of size width, height * 2
    // The extra height is the buffer screen.
    StringScreen(int p_width, int p_height);

    // Loads a full screen from a constant
    void load(const string*);

    // Display the screen to console
    void display();

    // Return the character at point x,y
    char getchar(int p_x, int p_y);

    // Set character at point x,y to char
    void setchar(int p_x, int p_y, char p_char);

    // Draw text to screen
    void drawtext(int p_x, int p_y, string s);

    // Render an array of strings to the screen, clipping as needed
    void render(int p_x, int p_y, string *stringarray[]);

    // Clears the screen back to empty
    void clearscreen();

    // Saves the current screen to the buffer screen
    void savetobuffer();

    // Restores the screen to the snapshot saved in the buffer
    void restorefrombuffer();

    // Draws a line from x1,y1 to x2,y2
    void drawline(int x1, int y1, int x2, int y2, char c = BLACK_CHAR);

    // Draws a rectangle from x1,y1 to x2,y2
    void drawrect(int x1, int y1, int x2, int y2, char c = BLACK_CHAR);

    // Registers a character to be replaced with a string on display
    // Mostly used for extended ASCII, colors, etc.
    void registerReplacement(char to_replace, string replace_with);

    // Property getters
    // These properties CANNOT be changed after initialization
    int getwidth() const;
    int getheight() const;

};

#endif