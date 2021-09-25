#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cctype>


std::vector<int> CreateBoard() //function to create board
{
    // int row = 3; //setting number of rows to 3 for our 3x3 board
    // int col = 3; //setting number of cols to 3 for our 3x3 board

    // std::vector<std::vector<int> > vec(row, std::vector<int> (col, 0));
    // //init our 2d vector here 

    std::vector<int> vec;

    for(int i = 0; i < 9; i++){
        vec.push_back(0);
    }

    return vec;
}

// displays the board in a 3x3 fashion
void DisplayBoard(std::vector<int> vec){
    for(int i = 0; i < vec.size(); i += 3){
        std::cout << vec[i] << " ";
        std::cout << vec[i+1] << " ";
        std::cout << vec[i+2] << " ";
        std::cout << std::endl;
       
    }
}

int GetPlayerChoice() //function to take player input
{
    // initiallizing user input as a string prevents critical errors if they 
    // accidentally enter a letter or other symbol
    std::string input;
    int output = 0;
    bool correctChoice = false;

    // this loop runs until user inputs a correct integer
    while(!correctChoice){
        std::cout << "Where would you like to mark?: ";
        std::cin >> input;
        if(isdigit(input[0])){
            output = stoi(input);
            if(output < 1 || output > 9){
                std::cout << "Incorrect choice. Choose again." << std::endl;
            }
            else{
                correctChoice = true;
            }
        }
        else{
            std::cout << "Incorrect choice. Choose again." << std::endl;
        }
    }
    
    return output;
}

// places the users marker (1) in the desired location
std::vector<int> PlaceMarker(std::vector<int> vec, int choice){
    vec.at(choice - 1) = 1;
    return vec;
}

//takes a turn for the computer
std::vector<int> computerTurn(std::vector<int> vec){
    bool correctChoice = false;
    int choice;
    while(!correctChoice){
        srand (time(NULL));
        choice = rand() % 8;
        if(vec.at(choice) != 0){
            correctChoice = false;
        }
        else{
            vec.at(choice) = 2;
            correctChoice = true;
        }
    }
    return vec;
}

// this function checks if the game has been won
bool IsGameOver(std::vector<int> vec){

    // this checks if the board is full
    // if full, game is over and return true
    int isZero = 0;
    for(int i = 0; i < 9; i++){
        if(vec.at(i) == 0){
            isZero++;
        }
    }
    if(isZero == 0){
        return true;
    }

    // series of conditionals that check if there are 3 spaces in a row 
    // (checks if someone has won)
    if(vec.at(0) == vec.at(3) && vec.at(3) == vec.at(6) && vec.at(0) == vec.at(6) && vec.at(0) != 0 && vec.at(3) != 0){
        return true;
    }
    else if(vec.at(1) == vec.at(4) && vec.at(4) == vec.at(7) && vec.at(1) == vec.at(7) && vec.at(1) != 0 && vec.at(4) != 0){
        return true;
    }
    else if(vec.at(2) == vec.at(5) && vec.at(5) == vec.at(8) && vec.at(2) == vec.at(8) && vec.at(5) != 0 && vec.at(2) != 0){
        return true;
    }
    else if(vec.at(0) == vec.at(1) && vec.at(1) == vec.at(2) && vec.at(0) == vec.at(2) && vec.at(0) != 0 && vec.at(1) != 0){
        return true;
    }
    else if(vec.at(3) == vec.at(4) && vec.at(4) == vec.at(5) && vec.at(3) == vec.at(5) && vec.at(3) != 0 && vec.at(5) != 0){
        return true;
    }
    else if(vec.at(6) == vec.at(7) && vec.at(7) == vec.at(8) && vec.at(6) == vec.at(8) && vec.at(6) != 0 && vec.at(7) != 0){
        return true;
    }
    else if(vec.at(0) == vec.at(4) && vec.at(4) == vec.at(8) && vec.at(0) == vec.at(8) && vec.at(0) != 0 && vec.at(4) != 0){
        return true;
    }
    else if(vec.at(2) == vec.at(4) && vec.at(4) == vec.at(6) && vec.at(2) == vec.at(6) && vec.at(2) != 0 && vec.at(4) != 0){
        return true;
    }
    else{
        return false;
    }
}


int main(){

    //std::vector<std::vector<int> > vec = CreateBoard();
    std::vector<int> vec = CreateBoard();

    bool gameOver = false;
    bool correctChoice = false;
    int choice = 0;

    //this while loops runs until the game is won
    while(!gameOver){
        DisplayBoard(vec);
        correctChoice = false;

        // loop that doesnt exit until player chooses valid move
        while(!correctChoice){
            choice = GetPlayerChoice();
            if(vec.at(choice - 1) != 0){
                std::cout << "Cannot choose this location" << std::endl;
                correctChoice = false;
            }
            else{
                vec = PlaceMarker(vec, choice);
                correctChoice = true;
            }
        }
        gameOver = IsGameOver(vec);
        
        //if game isnt over, tis takes the turn for the computer
        if(!IsGameOver(vec)){
            vec = computerTurn(vec);
        }

    }

    // display winning board and game over message
    DisplayBoard(vec);
    std::cout << "Game Over!" << std::endl;
    return 0;
}
