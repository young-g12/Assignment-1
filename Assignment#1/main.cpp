// Assignment#1.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <chrono>

#include "gamelogic.h"

using namespace std;
using namespace chrono;

int main() {

    logic game;

    game.introduction();

    if (!game.createLists()) {

        return 1;
    }

    auto start = steady_clock::now();

    bool completed =
        game.playGame();

    auto end = steady_clock::now();

    auto elapsed =
        duration_cast<seconds>(end - start);

    cout << endl;
    cout << "==========================" << endl;

    cout << "Elapsed Time: "
        << elapsed.count()
        << " seconds"
        << endl;

    if (completed) {

        game.end();
    }

    else {

        cout << "Game Over!" << endl;
    }

    return 0;
}