//    Implementation by Tyler Downey
//    StringScreen Class
//    Creates a string-based full window display

#include "../h/StringScreen.h"
#include "../h/Constants.h"

string StringScreen::doReplacements(string s) {
    int t = 0;
    int pos = 0;
    string toreturn = s;
    for(pair<char, string> p : replacement_registry) {
        t = toreturn.find(p.first);
        pos = t;
        while(t != string::npos) {
            toreturn.replace(t, 1, p.second);
            t = toreturn.find(p.first, pos);
            pos = t;
        }
    }

    return toreturn;
}

StringScreen::StringScreen(int p_width, int p_height) {
    width = p_width;
    height = p_height;
    screen = new string[height * 2];
    for (int i = 0; i < height; i++) {
        screen[i] = string(width, ' ');
    };
    clearscreen();
    savetobuffer();
}

// Loads a full screen from a constant
void StringScreen::load(const string* arr) {
    for (int i = 0; i < height; i++) {
        screen[i] = arr[i];
    };
}

// Display the screen to console
void StringScreen::display() {
    for(int i = 0; i < height; i++) {
        cout << doReplacements(screen[i]);
        cout << endl;
    }
}

// Return the character at point x,y
char StringScreen::getchar(int p_x, int p_y) {
    return screen[p_y].at(p_x);
}

// Set character at point x,y to char
void StringScreen::setchar(int p_x, int p_y, char p_char) {
    if(p_y >= height || p_y < 0 || p_x > width || p_x < 0) return;
    screen[p_y].erase(p_x, 1);
    screen[p_y].insert(p_x, 1, p_char);
}

// Render an array of strings to the screen, clipping as needed
void StringScreen::render(int p_x, int p_y, string *stringarray[]) {

}

void StringScreen::drawtext(int p_x, int p_y, string s) {
    string ds = s;
    int dx = p_x;

    if (p_x > width) return;
    if (p_y > height) return;
    if (p_y < 0) return;
    if (p_x < 0 - (int)ds.length()) return;
    
    if ((int)ds.length() + p_x > width) ds = ds.substr(0, width - p_x);
    if (p_x < 0) {
        ds = ds.substr(0 - p_x, (int)ds.length());
        dx = 0;
    }
        
    for (int i = 0; i < (int)ds.length(); i++) {
        screen[p_y][dx + i] = (ds[i] == TRANS_CHAR) ? screen[p_y][dx + i] : ds[i];
    }
}

void StringScreen::registerReplacement(char to_replace, string replace_with) {
    replacement_registry.push_back(pair<char, string>(to_replace, replace_with));
}

// Clears the screen back to empty
void StringScreen::clearscreen() {
    for(int i = 0; i < height; i++) {
        screen[i].assign(string(width, ' '));
    }
}

// Saves the current screen to the buffer screen
void StringScreen::savetobuffer() {
    for(int i = 0; i < height; i++) {
        screen[height + i] = screen[i];
    }
}

// Restores the screen to the snapshot saved in the buffer
void StringScreen::restorefrombuffer() {
    for(int i = 0; i < height; i++) {
        screen[i] = screen[height + i];
    }
}

// Property getters
// These properties CANNOT be changed after initialization
int StringScreen::getwidth() const {
    return width;
}
    
int StringScreen::getheight() const {
    return height;
}

// Draws a line from x1,y1 to x2,y2
void StringScreen::drawline(int x1, int y1, int x2, int y2, char c) {
    
    setchar(x1, y1, c);
    
    // Special cases where x1 = x2 or y1 = y2
    if(y1 == y2) {
        if(x1 > x2) {
            for(int x = x2; x < x1; x++) {
                setchar(x, y1, c);
            }
        } else {
            for(int x = x1; x < x2; x++) {
                setchar(x, y1, c);
            }
        }
        return;
    }
    
    if(x1 == x2) {
        if(y1 > y2) {
            for(int y = y2; y < y1; y++) {
                setchar(x1, y, c);
            }
        } else {
            for(int y = y1; y < y2; y++) {
                setchar(x1, y, c);
            }
        }
        return;
    }
    
    double m = (static_cast<double>(y2) - static_cast<double>(y1)) / (static_cast<double>(x2) - static_cast<double>(x1));
    int y;
    int x;
    double error = (m>0)?0.5:-0.5;
    
    if(abs(m) > 1) {
        m = 1 / m;
        if(y1 < y2) {
            y = y1;
            x = x1;
            while(y < y2) {
                y += 1;
                error += m;
                if(error >= 1) {
                    x++;
                    error--;
                } else if(error <= -1) {
                    x--;
                    error++;
                };
                setchar(x, y, c);
            }
            return;
        }
        y = y2;
        x = x2;
        setchar(x, y, c);
        while(y < y1) {
            y += 1;
            error += m;
            if(error >= 1) {
                x++;
                error--;
            } else if(error <= -1) {
                x--;
                error++;
            };
            setchar(x, y, c);
        }
        return;
    }

    if(x1 < x2) {
        y = y1;
        x = x1;
        while(x < x2) {
            x += 1;
            error += m;
            if(error >= 1) {
                y++;
                error--;
            } else if(error <= -1) {
                y--;
                error++;
            };
            setchar(x, y, c);
        }
        return;
    }
    y = y2;
    x = x2;
    setchar(x, y, c);
    while(x < x1) {
        x += 1;
        error += m;
        if(error >= 1) {
            y++;
            error--;
        } else if(error <= -1) {
            y--;
            error++;
        };
        setchar(x, y, c);
    }
    return;
};

void StringScreen::drawrect(int x1, int y1, int x2, int y2, char c) {
    drawline(x1, y1, x2, y1, c);
    drawline(x1, y1, x1, y2, c);
    drawline(x2, y1, x2, y2, c);
    drawline(x2, y2, x1, y2, c);
};