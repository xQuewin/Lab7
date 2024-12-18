#include "gameStart.h"
#include <iostream>
#include "Board.h"
#include "AiBoard.h"
#include <iomanip>
using namespace std;

gameStart::gameStart() {
    Player.setBoard();
    AI.setBoard();
}

gameStart::~gameStart() {}

void gameStart::startGame() {
    playerWin = false;
    aiWin = false;

    Player.AddShips();
    Player.printBoard();
    AI.aiAddShips(); // AI ship placement

    while (!checkWin()) {
        playerTurn();
    }
}

void gameStart::playerTurn() {
    cout << "Player's Turn" << endl;
    Player.printBoard();

    int x, y;
    char comma;
    cout << "Enter the x,y coordinates you would like to attack (x,y): ";
    cin >> y >> comma >> x;

    if (x < 1 || x > 10 || y < 1 || y > 10) {
        cout << "Invalid coordinates, try again" << endl;
        playerTurn();
    }
    else if (AI.checkIfAlreadyHit(x - 1, y - 1)) {
        cout << "You already attacked this spot. Try again!" << endl;
        playerTurn();
    }
    else {
        if (AI.checkHit(x - 1, y - 1)) {
            cout << "Hit!" << endl;
            AiHitsLeft--;
        }
        else {
            cout << "Miss!" << endl;
        }
    }

    // AI Turn
    cout << "AI's Turn" << endl;
    x = rand() % 10;
    y = rand() % 10;
    if (Player.checkIfAlreadyHit(x, y)) {
        cout << "AI already attacked this spot. AI is choosing a new spot." << endl;
        playerTurn();
    }
    else {
        if (Player.checkHit(x, y)) {
            cout << "AI Hit!" << endl;
            PlayerHitsLeft--;
        }
        else {
            cout << "AI Miss!" << endl;
        }
    }

    checkWin(); // Check win after each turn
}

bool gameStart::checkWin() {
    if (AiHitsLeft == 0) {
        playerWin = true;
        cout << "Player Wins!" << endl;
        restart();
        return true;
    }
    else if (PlayerHitsLeft == 0) {
        aiWin = true;
        cout << "AI Wins!" << endl;
        restart();
        return true;
    }
    return false;
}

void gameStart::restart() {
    char choice;
    cout << "Would You like to play again? (y/n): ";
    cin >> choice;
    if (choice == 'y') {
        startGame();
    }
    else {
        quit = true;
    }
}

void gameStart::printPlayerAttackBoard() {
    cout << "  ";
    for (int i = 0; i < 10; i++) {
        cout << " " << i + 1;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 10; j++) {
            cout << "~ ";
        }
        cout << endl;
    }
}
