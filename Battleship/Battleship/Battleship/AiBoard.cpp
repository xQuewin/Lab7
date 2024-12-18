#include "AiBoard.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

AiBoard::AiBoard()
{
    // Initialize the random seed
    srand(static_cast<unsigned int>(time(0)));
    resetBoard(); // Ensure the board is reset when an AI object is created
}

AiBoard::~AiBoard()
{
}

// Resets the board to all water '~'
void AiBoard::resetBoard()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            board[i][j] = '~';  // Water
        }
    }
}

// Sets the AI board to its initial state (this is called at the start of a new game)
void AiBoard::setBoard()
{
    resetBoard();
    aiAddShips(); // Optionally, you could call aiAddShips here to place ships after resetting
}

// Add ships to the AI's board (you can call this in setBoard as needed)
void AiBoard::aiAddShips()
{
    // Example for adding ships (you can refine this further based on your game logic)
    randomShipPlacement(5);  // Add a ship of size 5
    randomShipPlacement(4);  // Add a ship of size 4
    randomShipPlacement(3);  // Add a ship of size 3
    randomShipPlacement(3);  // Add another ship of size 3
    randomShipPlacement(2);  // Add a ship of size 2
}

// Place a ship of a certain size on the board randomly
void AiBoard::randomShipPlacement(int size)
{
    // Randomly place a ship
    int x, y, direction;
    bool placed = false;

    while (!placed)
    {
        x = rand() % 10;
        y = rand() % 10;
        direction = rand() % 2;  // 0 = horizontal, 1 = vertical

        if (validShipPlacement(size, direction, x, y))
        {
            for (int i = 0; i < size; i++)
            {
                if (direction == 0) // Horizontal
                    board[x][y + i] = 'S';
                else  // Vertical
                    board[x + i][y] = 'S';
            }
            placed = true;
        }
    }
}

// Check if a given position and size are valid for placing a ship
bool AiBoard::validShipPlacement(int size, int direction, int x, int y)
{
    // Check bounds and overlap with other ships
    if (direction == 0)  // Horizontal placement
    {
        if (y + size > 10) return false;
        for (int i = 0; i < size; i++)
            if (board[x][y + i] != '~') return false;
    }
    else  // Vertical placement
    {
        if (x + size > 10) return false;
        for (int i = 0; i < size; i++)
            if (board[x + i][y] != '~') return false;
    }
    return true;
}

// Check if a given position contains a ship (returns true if a ship is hit)
bool AiBoard::checkHit(int x, int y)
{
    return board[x][y] == 'S';
}

// Check if a position has already been attacked (whether it's a hit or miss)
bool AiBoard::checkIfAlreadyHit(int x, int y)
{
    return board[x][y] == 'H' || board[x][y] == 'M';
}

// Mark a spot on the AI's board as a hit or miss
void AiBoard::changeAiBoard(int x, int y, char c)
{
    board[x][y] = c;
}

// Print the AI's board (this could be useful for debugging)
void AiBoard::printBoard()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
