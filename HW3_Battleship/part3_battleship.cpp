/* Assignment: 3 part 'C'
Author: Noa Shem Tov
*/

#include <iostream>
#include <cstdlib>

using namespace std;
//size of the board 10 X 10
#define SIZE 10
//for the lottery, %10 the result can be between 0 and 9
#define ROW_OR_COL 10
//the firs row or col is 0
#define FIRST_ROW_COL 0
//the last row or col is 9
#define LAST_ROW_COL 9
//0 = VERTICAL 1 = HORIZONTAL
#define VERTICAL 0
// FOR THE VERTICAL or HORIZONTAL 0 or 1, %2 can be 0 or 1
#define POS 2
//amount of submarines
#define AMOUNT_OF_SABMARINE 5
//the size of the submarines
#define SUBMARINE_5 5
#define SUBMARINE_4 4
#define SUBMARINE_3 3
#define SUBMARINE_2 2
//means sea in the board
#define EMPTY '0'
//the user type -1 to end the game
#define END_GAME -1
// s means submarines
#define SUBMARINE 'S'
//for the print board
#define HIT 'X'
#define MISS '~'
#define LOCATION_NOT_SELECTED ' '
//flags
#define YES 'Y'
#define NO 'N'

void BuildGameBoard(char [][SIZE]);//Build the game board 10 X 10 with the submarines
//void printGameBoard(char [][SIZE]);
void InitializationMat(char [][SIZE]);//Initialization the Mat with '0'
void PlacementSubmarines(char [][SIZE]);//Placing the submarines on board
bool CheckAndPlacementSub(char [][SIZE],int sizeSub);//put 1 submarine on the board
bool checksRows(char [][SIZE] ,int row,int col,int sizeSub);//Checks the row itself and the two rows adjacent to it
bool checksCols(char [][SIZE] ,int row,int col,int sizeSub);//Checks the col itself and the two cols adjacent to it
bool Row(char GameBoardMat [][SIZE],int row,int col,int endOfSub);//checks whether a cell is caught in the row itself
void PlacingSubmarineHorizontal(char GameBoardMat[], int col, int sizeSub);//placing a submarine horizontally
bool Col(char GameBoardMat [][SIZE],int row,int col,int endOfSub);//checks whether a cell is caught in the col itself
void PlacingSubmarineVertical(char [][SIZE],int row,int col,int sizeSub);//placing a submarine vertically
void GamePlay_ChooseLocation(char [][SIZE]);//check if the user want to play or to end the game
void GamePlay_CheckingPlace( char GameBoardMat [][SIZE], int row, int col);//checks the location if it hit or missed or reselected the same location and updates the board
void GamePlay_PrintBoard(char GameBoardMat [][SIZE]);//print the board
bool CheckBoard(char GameBoardMat [][SIZE]);//If the user managed to hit all the submarines

int main()
{
    char GameBoardMat [SIZE][SIZE];//the game board, for the start it will be full of '0'
    srand((unsigned)time(NULL)); // Initialization of random
    BuildGameBoard(GameBoardMat);//build the game board
    return 0;
}//main
void BuildGameBoard(char GameBoardMat[][SIZE])//Build the game board 10 X 10
{
    InitializationMat(GameBoardMat);//Initialization the Mat with '0'
    PlacementSubmarines(GameBoardMat);//Positions the submarines and starts the game
}//BuildGameBoard
void InitializationMat(char GameBoardMat[][SIZE])
{
    for (int row = 0; row < SIZE; ++ row)
        for (int col = 0; col < SIZE; ++ col)
            GameBoardMat[row][col] = EMPTY;//Initialization the Mat with '0'
}
/*void printGameBoard(char GameBoardMat [][SIZE])//for me
{
    for (int row = 0; row < SIZE; ++ row)
    {
        for (int col = 0; col < SIZE; ++col)
            cout<<GameBoardMat[row][col] << " ";
        cout<<endl;
    }
}//printGameBoard
 */
void PlacementSubmarines(char GameBoardMat [][SIZE])
{
    //Each size of a submarine is a compartment in the array and every other submarine iteration is placed on the board
    int SizeSubmarineArray[AMOUNT_OF_SABMARINE] = {SUBMARINE_5,SUBMARINE_4,SUBMARINE_3,SUBMARINE_3,SUBMARINE_2};
    for(int i = 0; i < AMOUNT_OF_SABMARINE;i++ )
        while(!(CheckAndPlacementSub(GameBoardMat,SizeSubmarineArray[i])));//Placing the submarine
    //printGameBoard(GameBoardMat);//for me
    GamePlay_ChooseLocation(GameBoardMat);//the game process, choosing a location and checking the location

}//PlacementSubmarine
bool CheckAndPlacementSub(char GameBoardMat [][SIZE],int sizeSub)
{
    int row = rand() % ROW_OR_COL;//Row number lottery
    int col = rand() % ROW_OR_COL;//Col number lottery
    int positionOfSub = rand() % POS;//VERTICAL = 0, HORIZONTAL = 1
    if (positionOfSub == VERTICAL)
    {
        //if it goes beyond the boundaries of the array,One minus because it generalizes the location itself
        if ((row + (sizeSub - 1)) >= SIZE)
            return false;
        else
            return checksCols(GameBoardMat,row,col,sizeSub);//Checks the col itself and the two cols adjacent to it
    }//if
    else
    {
        //If it goes beyond the boundaries of the array,One minus because it generalizes the location itself
        if ((col + (sizeSub - 1)) >= SIZE)
            return false;
        else
            return checksRows(GameBoardMat,row,col,sizeSub);//Checks the row itself and the two rows adjacent to it
    }//else
}//PlacementSub
bool checksRows(char GameBoardMat [][SIZE],int row,int col,int sizeSub)
{
   // Checks the row itself and the two rows adjacent to it to prevent two submarines from being attached
   //If the row is equal to 0 or 9 then it automatically returns truth to the line before and after respectively because there is nothing to check
    if(Row(GameBoardMat,row-1,col-1,col + sizeSub))
        if(Row(GameBoardMat,row,col-1,col + sizeSub ))
            if(Row(GameBoardMat,row + 1,col-1,col + sizeSub))
            {
                //Placing the Submarine Horizontally
                PlacingSubmarineHorizontal(GameBoardMat[row],col, col + sizeSub);
                return true;
            }//if
    return false;
}//checksRows
bool Row(char GameBoardMat [][SIZE],int row,int col,int endOfSub)
{
    if(row < FIRST_ROW_COL || row > LAST_ROW_COL)//if the line is in the corner there is 2 lines to check instead 3
        return true;
    if(col < FIRST_ROW_COL)//if the col the user type == 0
        col++;
    for (int i = col; (i <= endOfSub) && (i < SIZE) ; ++i)
        if(GameBoardMat[row][i] != EMPTY)//empty == new cell = it ok to put the submarine there else, no
            return false;
    return true;
}//Row
void PlacingSubmarineHorizontal(char GameBoardMat[], int col, int sizeSub)
{
    //Placing the Submarine Horizontally
    for(int i = col; i < sizeSub; i++)
        GameBoardMat[i] = SUBMARINE;//in the cell will be 'S' which means submarine
}//PlacingSubmarineHorizontal
bool checksCols(char GameBoardMat [][SIZE],int row,int col,int sizeSub)
{
    // Checks the col itself and the two cols adjacent to it to prevent two submarines from being attached
    //If the col is equal to 0 or 9 then it automatically returns truth to the col before and after respectively because there is nothing to check
    if(Col(GameBoardMat,row-1,col-1,row + sizeSub))
        if(Col(GameBoardMat,row-1,col,row + sizeSub))
            if(Col(GameBoardMat,row-1,col+1,row + sizeSub))
            {
                //Placing the Submarine vertically
                PlacingSubmarineVertical(GameBoardMat,row,col, row + sizeSub);
                return true;
            }//if
    return false;
}//checksCols
bool Col(char GameBoardMat [][SIZE],int row,int col,int endOfSub)
{
    if(col < FIRST_ROW_COL || col > LAST_ROW_COL)//if the col is the corners 0 or 9 there is 2 check instead 3
        return true;
    if(row < FIRST_ROW_COL)//if the line == 0
        row++;
    for (int i = row; (i <= endOfSub) && (i < SIZE) ; ++i)
        if(GameBoardMat[i][col] != EMPTY)//empty == new cell = it ok to put the submarine there else, no
            return false;
    return true;
}
void PlacingSubmarineVertical(char GameBoardMat [][SIZE],int row,int col,int sizeSub)
{
    //Placing the Submarine Vertically
    for (int i = row; i < sizeSub ; ++i)
        GameBoardMat[i][col] = SUBMARINE;//in the cell will be 'S' which means submarine
}//PlacingSubmarineVertical
void GamePlay_ChooseLocation(char GameBoardMat [][SIZE])
{
    int row,col;//row and col that the user typed
    char wantToPlay = 'Y'; // Y for want to play and N for don't want == flag
    cout << endl << "Please press two integers between 0 and 9 press, -1 -1 to end the game" << endl;
    while (wantToPlay == 'Y')
    {
        cin>>row>>col;
        if(row == END_GAME && col == END_GAME)
        {
            cout << "See you next time!" << endl;
            wantToPlay = 'N';
        }//if
        else
        {
            if(row < FIRST_ROW_COL || col < FIRST_ROW_COL || row > LAST_ROW_COL || col > LAST_ROW_COL)
                cout<<"Illegal values, please try again."<< endl;
            else
            {
                wantToPlay = 'N';
                GamePlay_CheckingPlace(GameBoardMat,row,col);//check if it is hit or miss
            }//else
        }//else
    }//while
}//GamePlay
void GamePlay_CheckingPlace( char GameBoardMat [][SIZE], int row, int col)
{
    if(GameBoardMat[row][col] == SUBMARINE)
    {
        cout<<"Hit"<<endl;
        GameBoardMat[row][col] = HIT;//set the cell
        GamePlay_PrintBoard(GameBoardMat);//print the board with the places that has been chosen by the user
        if (CheckBoard(GameBoardMat))//If all submarines have been damaged, The game is over and an appropriate message will be printed
        {
            cout << "Congratulation you win!" << endl;
            return;
        }//if
    }//if
    else
    {
        if(GameBoardMat[row][col] == EMPTY)
        {
            cout << "Miss" << endl;
            GameBoardMat[row][col] = MISS;//set the cell
            GamePlay_PrintBoard(GameBoardMat);//print the board with the places that has been chosen by the user
        }//if
        else
            cout << "This location has already been selected" << endl;
    }//else
    GamePlay_ChooseLocation(GameBoardMat);//if not, the user need to type again row and col, -1 for exit
}//GamePlay_CheckingPlace
void GamePlay_PrintBoard(char GameBoardMat [][SIZE])
{
    for (int row = 0; row < SIZE; ++row)
    {
        for (int col = 0; col < SIZE; ++col)
        {
            if (GameBoardMat[row][col] == EMPTY || GameBoardMat[row][col] == SUBMARINE)
                cout << LOCATION_NOT_SELECTED << " ";//when the user didn't choose this cell will be print space
            else
                cout<<GameBoardMat[row][col]<<" ";//if the location has been chosen will be print the value in the cell
                //it can be X for hit or ~ for miss
        }//for
        cout<<endl;
    }//for
}//GamePlay_PrintBoard
bool CheckBoard(char GameBoardMat [][SIZE])
{
    for (int row = 0; row < SIZE; ++row)
    {
        for (int col = 0; col < SIZE; ++col)
        {
            //if the user really guessed all the locations of the submarine there is no longer a marking 'S'
            if(GameBoardMat[row][col] == SUBMARINE)
                return false;
        }//for
    }//for
    return true;
}//CheckBoard
