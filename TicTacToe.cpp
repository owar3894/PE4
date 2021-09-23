#include <iostream>
#include <vector>


void CreateBoard() //function to create board
{
    int row = 3; //setting number of rows to 3 for our 3x3 board
    int col = 3; //setting number of cols to 3 for our 3x3 board

    std::vector<std::vector<int> > vec(row, std::vector<int> (col, 0));
    //init our 2d vector here
  
}


int main()
{
    CreateBoard();

}
