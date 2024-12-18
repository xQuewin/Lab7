#ifndef _Board
#define _Board

class Board {
public:
    Board();
    ~Board();

    void setBoard();
    void printBoard();

    bool checkShipPlacement(int size, int direction, int x, int y);
    void placeShip(int size, int direction, int x, int y);

    bool checkHit(int x, int y);
    bool checkIfAlreadyHit(int x, int y);

    void changePlayerBoard(int x, int y, char c);
    void AddShips();
    int shipSize(int shipNumber);

private:
    int shipsAdded = 0;
    bool placingShip = true;

    char board[10][10];
};

#endif // !_Board
