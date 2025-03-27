#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#define _USE_MATH_DEFINES
#include <math.h>
#include "h/Cube3D.h"
#include "h/StringScreen.h"
#include "assets/gfx.h"
#include "h/SceneManager.h"
#include "h/Scenes.cpp"

using namespace std;

const chrono::milliseconds FRAME_LENGTH = 150ms;

int main() {
    
    chrono::milliseconds frame_start;
    chrono::milliseconds frame_delta;
    srand(chrono::system_clock::now().time_since_epoch().count());
    SceneManager::init(100, 20, new TitleScene());
    GameManager::initialize();

    SceneManager::getScreen()->registerReplacement(BLACK_CHAR, BLACK_CHAR_REP);
    SceneManager::getScreen()->registerReplacement(RED_CHAR, RED_CHAR_REP);
    SceneManager::getScreen()->registerReplacement(BLUE_CHAR, BLUE_CHAR_REP);
    SceneManager::getScreen()->registerReplacement(YELLOW_CHAR, YELLOW_CHAR_REP);
    SceneManager::getScreen()->registerReplacement(R_CHAR, R_CHAR_REP);
    SceneManager::getScreen()->registerReplacement(L_CHAR, L_CHAR_REP);
    SceneManager::getScreen()->registerReplacement(C_CHAR, C_CHAR_REP);
    SceneManager::getScreen()->registerReplacement(GREEN_CHAR, GREEN_CHAR_REP);
    SceneManager::getScreen()->registerReplacement(CYAN_CHAR, CYAN_CHAR_REP);
    SceneManager::getScreen()->registerReplacement(PINK_CHAR, PINK_CHAR_REP);

    
    while (true) {
        frame_start = chrono::duration_cast<chrono::milliseconds>(
            chrono::system_clock::now().time_since_epoch());

        SceneManager::process(frame_start);
        //testcube.render(SceneManager::getScreen());


        // Smooths the framerate
        frame_delta = chrono::duration_cast<chrono::milliseconds>(
            chrono::system_clock::now().time_since_epoch());
        frame_delta = frame_delta - frame_start;
        if (frame_delta < FRAME_LENGTH)
            this_thread::sleep_for(chrono::milliseconds(FRAME_LENGTH - frame_delta));
    }

    
    return 0;
    
}
