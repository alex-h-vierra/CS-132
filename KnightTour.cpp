/*
 * @author Alex Vierra
 * Section A
 * Knight Tour Program
 * This program will complete the knight tour by visiting
 * all the places on a desired board noting the spots it has visited
 * with the user input the starting position are row, and col, and the output will be
 * the chessboard with number indicating legal moves as well as how many tries it took.
 * @version CS 132 1/12/2023 1.0
 */
#include <iostream>
#include <iomanip>
#include "Function prototypes.h"

int CHESSBOARD[ROW][COL];
int NUMBER_OF_MOVES = 0;

int main()
{
    moveKnight(0, 0, 1);
    printChessBoard();
    std::cout << std::endl << std::endl << std::setw(9) << "| " << "Number of tries | ";
    std::cout << std::endl << std::setw(13) << "< " << NUMBER_OF_MOVES << " > ";
}

bool moveKnight(int row, int col, int moveNumber)
{
    //checks to see if it's in the bounders
    if (row >= ROW || col >= COL || row < 0 || col < 0)
    {
        return false;
    }
    //checks to see if board has an open spot
    if (CHESSBOARD[row][col] != 0)
    {
        return false;
    }
    // checks if moveNumber has made it to end condition
    if (moveNumber == ROW * COL)
    {
        CHESSBOARD[row][col] = moveNumber;
        return true;
    }

    //prints to board once row and col have passed all the conditions
    CHESSBOARD[row][col] = moveNumber;

    //increment chess piece tries
    NUMBER_OF_MOVES++;

    //The move Types
    if (moveKnight(row + 1, col + 2, moveNumber + 1))
    {
        return true;
    }
    if (moveKnight(row + 2, col + 1, moveNumber + 1))
    {
        return true;
    }
    if (moveKnight(row + 2, col - 1, moveNumber + 1))
    {
        return true;
    }
    if (moveKnight(row + 1, col - 2, moveNumber + 1))
    {
        return true;
    }
    if (moveKnight(row - 1, col - 2, moveNumber + 1))
    {
        return true;
    }
    if (moveKnight(row - 2, col - 1, moveNumber + 1))
    {
        return true;
    }
    if (moveKnight(row - 2, col + 1, moveNumber + 1))
    {
        return true;
    }
    if (moveKnight(row - 1, col + 2, moveNumber + 1))
    {
        return true;
    }
        //if all fail set current position back to 0 and go through move list again
    else
    {
        CHESSBOARD[row][col] = 0;
        return false;
    }

}

/*
 * This will print the board once recursive function is done
 * return once chessboard is done printing
 */
void printChessBoard()
{
    for (auto &y: CHESSBOARD)
    {
        std::cout << std::endl;
        for (int x : y)
        {
            std::cout << " " << std::setw(2) << x << " ";
        }
    }
}

            //output from Knight Tour project
        // 1  38  59  36  43  48  57  52
        //60  35   2  49  58  51  44  47
        //39  32  37  42   3  46  53  56
        //34  61  40  27  50  55   4  45
        //31  10  33  62  41  26  23  54
        //18  63  28  11  24  21  14   5
        //9  30  19  16   7  12  25  22
        //64  17   8  29  20  15   6  13
        //
        //| Number of tries |
        //< 8250732 >
