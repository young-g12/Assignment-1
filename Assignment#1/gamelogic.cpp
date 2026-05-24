#include "gamelogic.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <random>
#include <cstdlib>

using namespace std;

logic::logic() {

    cout << "Logic object created!" << endl;

    smallCount = 0;
    mediumCount = 0;
    largeCount = 0;

    numCorrect = 0;

    srand(time(0));

}

void logic::introduction() {

    cout << "==========================" << endl;
    cout << " WORD UNSCRAMBLE GAME" << endl;
    cout << "==========================" << endl;

}

bool logic::createLists() {

    ifstream file("dictionary.txt");

    if (!file) {

        cout << "Could not open dictionary.txt" << endl;

        return false;
    }

    string word;

    while (file >> word) {

        int length = word.length();

        if (length >= 4 && length <= 5) {

            smallWords[smallCount] = word;
            smallCount++;
        }

        else if (length >= 6 && length <= 7) {

            mediumWords[mediumCount] = word;
            mediumCount++;
        }

        else if (length >= 8) {

            largeWords[largeCount] = word;
            largeCount++;
        }
    }

    file.close();

    cout << "Words loaded successfully!" << endl;

    return true;
}

string logic::scrambler(string word) {

    string scrambled = word;

    shuffle(scrambled.begin(),
        scrambled.end(),
        default_random_engine(time(0)));

    return scrambled;
}

bool logic::playGame() {

    string answer;

    cout << endl;
    cout << "Unscramble the words!" << endl;

     //small words
    for (int i = 0; i < 2; i++) {

        int randomIndex = rand() % smallCount;

        string word = smallWords[randomIndex];

        string scrambled = scrambler(word);

        cout << endl;
        cout << "Scrambled word: "
            << scrambled << endl;

        cin >> answer;

        if (answer == word) {

            cout << "Correct!" << endl;

            numCorrect++;
        }

        else {

            cout << "Wrong! The word was: "
                << word << endl;
        }
    }

    //medium word
    for (int i = 0; i < 2; i++) {

        int randomIndex = rand() % mediumCount;

        string word = mediumWords[randomIndex];

        string scrambled = scrambler(word);

        cout << endl;
        cout << "Scrambled word: "
            << scrambled << endl;

        cin >> answer;

        if (answer == word) {

            cout << "Correct!" << endl;

            numCorrect++;
        }

        else {

            cout << "Wrong! The word was: "
                << word << endl;
        }
    }

    //large words
    int randomIndex = rand() % largeCount;

    string word = largeWords[randomIndex];

    string scrambled = scrambler(word);

    cout << endl;
    cout << "Final scrambled word: "
        << scrambled << endl;

    cin >> answer;

    if (answer == word) {

        cout << "Correct!" << endl;

        numCorrect++;
    }

    else {

        cout << "Wrong! The word was: "
            << word << endl;
    }

    return true;
}

void logic::end() {

    cout << endl;
    cout << "==========================" << endl;

    cout << "You got "
        << numCorrect
        << " words correct!" << endl;

    if (numCorrect <= 2) {

        cout << "You have the intelligence of a potato."
            << endl;
    }

    else if (numCorrect == 3) {

        cout << "You are pretty smart!"
            << endl;
    }

    else if (numCorrect == 4) {

        cout << "Genius level achieved!"
            << endl;
    }

    else if (numCorrect == 5) {

        cout << "You are the ultimate word master!"
            << endl;
    }
}