#include <iostream>
#include <vector>


std::vector<std::vector<int> > CreateBoard() //function to create board
{
    int row = 3; //setting number of rows to 3 for our 3x3 board
    int col = 3; //setting number of cols to 3 for our 3x3 board

    std::vector<std::vector<int> > vec(row, std::vector<int> (col, 0));
    //init our 2d vector here 
    return vec;
}

void DisplayBoard(std::vector<std::vector<int> > vec){
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec.size(); j++){
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
       
    }
}


int main(){

    std::vector<std::vector<int> > vec = CreateBoard();

    DisplayBoard(vec);

    std::cout << "Welcome to TicTacToe" << std::endl;
    
}
