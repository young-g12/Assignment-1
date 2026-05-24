// Assignment#1.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>

#include "GAMELOGIC.H"

#include <chrono>

#include <ctime>

using namespace std;
using namespace chrono;

int main() {

    logic game;

    game.introduction();

    if (!game.createLists()) {

        return 1;
    }

    bool completed = game.playGame();

    if (completed) {

        game.end();
    }

    return 0;
}
