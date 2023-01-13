/*
 * Knight Tour Program
 * This program with complete the knight tour by visiting 
 * all the places on a desired board noting the spots it has visited 
 * @author Alex Vierra 
 * @version CS 132 1/12/2023 1.0
 */
#include <iostream>
#include <iomanip>

//Board size control
const int ROW = 8;
const int COL = 8;
int CHESSBOARD[ROW][COL];
int NUMBER_OF_MOVES = 0;

bool moveKnight(int row, int col, int moveNumber);

void printChessBoard();

int main()
{
    moveKnight(0, 0, 1);
    printChessBoard();
    std::cout << std::endl << std::endl << std::setw(9) << "| " << "Number of tries | ";
    std::cout << std::endl << std::setw(13) << "< " << NUMBER_OF_MOVES << " > ";
}

/*
 * This will execute how many tries it takes to complete the knight tour
 * #param row: starting position 
 * #param col: starting position
 * #param moveNumber: placing starting move 
 * preconditions: this will calculate how many moves it takes to solve for a 8x8 board
 * post-conditions: print the complete  solved chessboard, and print how many tries it took
 * return true: is if Goal is met or if row and col pass condition
 * return false: if the row or col went out of bounds or the chessboard spot is taken or can't complete the tour
 */
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
    
    //increment tries 
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
    for (auto & y : CHESSBOARD)
    {
        std::cout << std::endl;
        for (int x = 0; x < COL; x++)
        {
            std::cout << " " << std::setw(2) << y[x] << " ";
        }
    }
}
