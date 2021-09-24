#include <iostream>
#include <vector>


void CreateBoard() //function to create board
{
    int row = 3; //setting number of rows to 3 for our 3x3 board
    int col = 3; //setting number of cols to 3 for our 3x3 board

    std::vector<std::vector<int> > vec(row, std::vector<int> (col, 0));
    //init our 2d vector here
  
}

void DisplayBoard() //function to display the board
{
    //init our row, col, and 2d vector
    int row = 3;
    int col = 3;
        
    std::vector<std::vector<int> > vec(row, std::vector<int> (col, 0));

    for(int i = 0; i < 3; i++) //iterate through rows
    {
        for(int j = 0; j < 3; j++) //iterate through cols
        {
            std::cout << vec[i][j] << " "; //print our board
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

    
    return input;
    }

int main()
{
    CreateBoard();
    DisplayBoard();
    GetPlayerChoice();

}
