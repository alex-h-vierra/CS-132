#include <iostream>
#include <iomanip>

#define ROW 8
#define COL 8
int CHESSBOARD[ROW][COL];
int NUMBEROFMOVES = 0;

bool moveKnight(int row, int col, int moveNumber);

void printChessBoard();

int main()
{
    moveKnight(0, 0, 1);
    printChessBoard();
    std::cout << std::endl << NUMBEROFMOVES;
}

bool moveKnight(int row, int col, int moveNumber)
{

    if (row >= ROW || col >= COL || row < 0 || col < 0)
    {
        return false;
    }
    if (moveNumber == ROW * COL)
    {
        return true;
    }
    if (CHESSBOARD[row][col] == 0)
    {
        CHESSBOARD[row][col] = moveNumber;
    }
    else
    {
        return false;
    }
    if (moveKnight(row + 1, col + 2, moveNumber + 1)&& NUMBEROFMOVES++)
    {
        return true;
    }
    else if (moveKnight(row + 2, col + 1, moveNumber + 1) && NUMBEROFMOVES++)
    {
        return true;
    }
    else if (moveKnight(row + 2, col - 1, moveNumber + 1)&& NUMBEROFMOVES++)
    {
        return true;
    }
    else if (moveKnight(row + 1, col - 2, moveNumber + 1)&& NUMBEROFMOVES++)
    {
        return true;
    }
    else if (moveKnight(row - 1, col - 2, moveNumber + 1)&& NUMBEROFMOVES++)
    {
        return true;
    }
    else if (moveKnight(row - 2, col - 1, moveNumber + 1)&& NUMBEROFMOVES++)
    {
        return true;
    }
    else if (moveKnight(row - 2, col + 1, moveNumber + 1)&& NUMBEROFMOVES++)
    {
        return true;
    }
    else if (moveKnight(row + 2, col - 1, moveNumber + 1)&& NUMBEROFMOVES++)
    {
        return true;
    }
    else
    {
        CHESSBOARD[row][col] = 0;
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
