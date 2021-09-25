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
            std::cout << vec[i][j];
        }
        std::cout << std::endl;
       
    }
}

int GetPlayerChoice() //function to take player input
{
    int input;

        std::cout << "Where would you like to mark?: ";
        std::cin >> input;
        std::cout << input << std::endl;

    //each time this function is called, iterate turn_count, when turn_count reaches 9 turns, stop the game.
    return input;
}


int main(){

    std::vector<std::vector<int> > vec = CreateBoard();

    DisplayBoard(vec);
    GetPlayerChoice();
}
