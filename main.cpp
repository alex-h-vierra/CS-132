#include <iostream>
#include <iomanip>

#define ROW 5
#define COL 5
int CHESSBOARD[ROW][COL];

bool moveKnight(int row, int col, int moveNumber);
void printChessBoard();

int main()
{
    moveKnight(0, 0, 1);
    printChessBoard();
}

bool moveKnight(int row, int col, int moveNumber)
{
    int moveTries = 0;
    if (moveNumber == ROW * COL)
    {
        return true;
    }
    if (CHESSBOARD[row][col] == 0)
    {
        CHESSBOARD[row][col] = moveNumber;
    }
    if (row > ROW && col > COL, row < 0, col < 0 && CHESSBOARD[row][col] == 0)
    {
        return false;
    }
    if (moveKnight(row + 1, col + 2, moveNumber + 1))
    {
        moveTries + 1;
        return true;
    }
    else if (moveKnight(row + 2, col + 1, moveNumber + 1))
    {
        moveTries + 1;
        return true;
    }
    else if (moveKnight(row + 2, col - 1, moveNumber + 1))
    {
        moveTries + 1;
        return true;
    }
    else if (moveKnight(row + 1, col - 2, moveNumber + 1))
    {
        moveTries + 1;
        return true;
    }
    else if (moveKnight(row - 1, col - 2, moveNumber + 1))
    {
        moveTries + 1;
        return true;
    }
    else if (moveKnight(row - 2, col - 1, moveNumber + 1))
    {
        moveTries + 1;
        return true;
    }
    else if (moveKnight(row - 2, col + 1, moveNumber + 1))
    {
        moveTries + 1;
        return true;
    }
    else if (moveKnight(row + 2, col - 1, moveNumber + 1))
    {
        moveTries + 1;
        return true;
    }
    else
    {
        CHESSBOARD[row][col] = 0;
        return false;
    }
}

void printChessBoard()
{
    for (int y = 0; y < ROW; y++)
    {
        std::cout << std::endl;
        for (int x = 0; x < COL; x++)
        {
            std::cout << std::setw(3) << CHESSBOARD[y][x];
        }
    }
}
