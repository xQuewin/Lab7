#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    setBoard();
}

Board::~Board() {}

void Board::setBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '~';
        }
    }
}

void Board::printBoard() {
    cout << "  ";
    for (int i = 0; i < 10; i++) {
        cout << " " << i + 1;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 10; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool Board::checkShipPlacement(int size, int direction, int x, int y) {
    if (direction == 0) { // Horizontal
        if (y + size > 10) return false; // Ship doesn't fit horizontally
        for (int i = 0; i < size; i++) {
            if (board[x][y + i] != '~') return false; // Overlaps with another ship
        }
    }
    else { // Vertical
        if (x + size > 10) return false; // Ship doesn't fit vertically
        for (int i = 0; i < size; i++) {
            if (board[x + i][y] != '~') return false; // Overlaps with another ship
        }
    }
    return true;
}

void Board::placeShip(int size, int direction, int x, int y) {
    if (direction == 0) { // Horizontal
        for (int i = 0; i < size; i++) {
            board[x][y + i] = 'S';
        }
    }
    else { // Vertical
        for (int i = 0; i < size; i++) {
            board[x + i][y] = 'S';
        }
    }
}

bool Board::checkHit(int x, int y) {
    if (board[x][y] == 'S') {
        board[x][y] = 'H'; // Mark hit
        return true;
    }
    return false;
}

bool Board::checkIfAlreadyHit(int x, int y) {
    return (board[x][y] == 'H' || board[x][y] == 'M');
}

void Board::changePlayerBoard(int x, int y, char c) {
    board[x][y] = c;
}

void Board::AddShips() {
    // Implement user input to place ships
    int x, y, direction;
    cout << "Enter position and orientation for your ships:" << endl;

    // Example of adding a Carrier
    cout << "Placing Carrier (size 5)" << endl;
    do {
        cout << "Enter starting coordinates (x y): ";
        cin >> x >> y;
        cout << "Enter direction (0 for horizontal, 1 for vertical): ";
        cin >> direction;
    } while (!checkShipPlacement(5, direction, x - 1, y - 1));
    placeShip(5, direction, x - 1, y - 1);

    // Repeat for other ships...
}

int Board::shipSize(int shipNumber) {
    switch (shipNumber) {
    case 1: return 5; // Carrier
    case 2: return 4; // Battleship
    case 3: return 3; // Cruiser
    case 4: return 3; // Submarine
    case 5: return 2; // Destroyer
    default: return 0;
    }
}

