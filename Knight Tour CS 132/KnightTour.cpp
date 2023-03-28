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

const int ROW = 8;
const int COL = 8;

bool moveKnight(int row, int col, int moveNumber);
void printChessBoard();

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
    if (moveKnight(row + 1, col + 2, moveNumber + 1)){
        return true;
    }
    if (moveKnight(row + 2, col + 1, moveNumber + 1)){
        return true;
    }
    if (moveKnight(row + 2, col - 1, moveNumber + 1)){
        return true;
    }
    if (moveKnight(row + 1, col - 2, moveNumber + 1)){
        return true;
    }
    if (moveKnight(row - 1, col - 2, moveNumber + 1)){
        return true;
    }
    if (moveKnight(row - 2, col - 1, moveNumber + 1)){
        return true;
    }
    if (moveKnight(row - 2, col + 1, moveNumber + 1)){
        return true;
    }
    if (moveKnight(row - 1, col + 2, moveNumber + 1)){
        return true;
    }
        //if all fail set current position back to 0 and go through move list again
    else{
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