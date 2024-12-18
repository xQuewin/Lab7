/*
Cole Fortune
Computer Science Fall 2024
Due: 12/3/2024
Lab Name : Battleship
Description : Make a simple battleship game
*/


#include "gameStart.h"
#include <iostream>
using namespace std;

void rules();

int main() {
    gameStart game;
    cout << "Welcome to Battleship" << endl;
    cout << "1. Play" << endl;
    cout << "2. Rules" << endl;
    cout << "3. Exit" << endl;

    bool InputActive;
    int choice;

    InputActive = true;

    while (InputActive) {
        cout << "Please input your choice: ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3) {
            cout << "Invalid Input, please try again." << endl;
            cin.clear();
            cin.ignore();
        }
        else {
            switch (choice) {
            case 1:
                game.startGame();
                break;
            case 2:
                rules();
                break;
            case 3:
                return 0;
                break;
            default:
                break;
            }
        }
    }

    return 0;
}

void rules() {
    cout << "Welcome to Battleship!" << endl;
    cout << "In this game, you will compete against the computer to sink each other's ships." << endl;
    cout << "The game is played on a 10x10 grid." << endl;
    cout << "You will have five ships to place on the grid:" << endl;
    cout << "  - Carrier (size 5)" << endl;
    cout << "  - Battleship (size 4)" << endl;
    cout << "  - Cruiser (size 3)" << endl;
    cout << "  - Submarine (size 3)" << endl;
    cout << "  - Destroyer (size 2)" << endl;
    cout << "To place your ships, you will provide the starting coordinates and the direction (horizontal or vertical)." << endl;
    cout << "The computer will place its ships randomly on the grid." << endl;
    cout << "During the game, you and the computer will take turns guessing the coordinates of each other's ships." << endl;
    cout << "If you hit a ship, you will see 'H' on the grid; if you miss, it will be marked with 'M'." << endl;
    cout << "The game continues until one player sinks all of the other player's ships." << endl;
    cout << "Good luck, and may the best strategist win!" << endl;
}
