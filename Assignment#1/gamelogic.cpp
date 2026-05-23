#include "gamelogic.h"
#include <iostream>

using namespace std;

logic::logic() {

    cout << "Logic object created!" << endl;

    smallCount = 0;
    mediumCount = 0;
    largeCount = 0;

}

void logic::introduction() {

    cout << "==========================" << endl;
    cout << " WORD UNSCRAMBLE GAME" << endl;
    cout << "==========================" << endl;

}