#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <string>

using namespace std;

class logic {

public:

    logic();

    void introduction();

    bool createLists();

    string scrambler(string word);

    bool playGame();

private:

    string smallWords[50];
    string mediumWords[50];
    string largeWords[50];

    int smallCount;
    int mediumCount;
    int largeCount;

    int numCorrect;

};

#endif