#ifndef AiBoard_h
#define AiBoard_h

class AiBoard
{
public:
    AiBoard();
    ~AiBoard();

    void aiAddShips();
    void setBoard();  // Add this method
    bool checkHit(int x, int y);
    bool checkIfAlreadyHit(int x, int y);
    void changeAiBoard(int x, int y, char c);
    void printBoard();

private:
    char board[10][10];
    bool validShipPlacement(int size, int direction, int x, int y);
    void randomShipPlacement(int size);
    void resetBoard();
};

#endif // AiBoard_h
