#include<iostream>
#include<ctime>
#include<map>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

enum Position {
    Top_Left = 1,
    Top_Middle,
    Top_Right,
    Middle_Left,
    Center,
    Middle_Right,
    Bottom_Left,
    Bottom_Middle,
    Bottom_Right
};



int main()
{

    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player= 'X';
    char computer= 'O';
    bool running = true;

    drawBoard(spaces);

    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running=false;
            break;
        }
        else if (checkTie(spaces)){
            running=false;
            break;
        }


        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running=false;
            break;
        }
        else if (checkTie(spaces)){
            running=false;
            break;
        }
    }






    return 0;
}

void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
};
void playerMove(char *spaces, char player){
    std::string input;
    bool validInput = false;

    std::map<std::string, Position> positionMap;
    positionMap["A1"] = Top_Left;
    positionMap["A2"] = Top_Middle;
    positionMap["A3"] = Top_Right;
    positionMap["B1"] = Middle_Left;
    positionMap["B2"] = Center;
    positionMap["B3"] = Middle_Right;
    positionMap["C1"] = Bottom_Left;
    positionMap["C2"] = Bottom_Middle;
    positionMap["C3"] = Bottom_Right;

    
    while (!validInput) {
        std::cout << "Enter a position to place your marker (A1-A3 for the top row, B1-B3 for the middle and C1-C3 for the last row):\n";
        std::getline(std::cin, input);  

        
    auto it = positionMap.find(input);
        if (it == positionMap.end()) {
            std::cout << "Invalid position. Please enter a valid position (A1-A3 for the top row, B1-B3 for the middle and C1-C3 for the last row).\n";
        }
        else {
            int index = it->second - 1;  
            if (spaces[index] == ' ') {
                spaces[index] = player;
                validInput = true;  
            } else {
                std::cout << "The spot is already marked. Pick another one." << std::endl;
            }
        }
    }
}
void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));

    while (true){
        number = rand() %9;
        if (spaces[number]==' '){
            spaces[number]=computer;
            break;
        }
    }

};
bool checkWinner(char *spaces, char player, char computer){
    if ((spaces[0]!=' ') && spaces[0]==spaces[1]&& spaces[1]==spaces[2]){
        spaces[0]==player? std::cout <<"YOU WIN!\n": std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[3]!=' ') && spaces[3]==spaces[4]&& spaces[4]==spaces[5]){
        spaces[3]==player? std::cout <<"YOU WIN!\n": std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[6]!=' ') && spaces[6]==spaces[7]&& spaces[7]==spaces[8]){
        spaces[6]==player? std::cout <<"YOU WIN!\n": std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[0]!=' ') && spaces[0]==spaces[3]&& spaces[3]==spaces[6]){
        spaces[0]==player? std::cout <<"YOU WIN!\n": std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[1]!=' ') && spaces[1]==spaces[4]&& spaces[4]==spaces[7]){
        spaces[1]==player? std::cout <<"YOU WIN!\n": std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[2]!=' ') && spaces[2]==spaces[5]&& spaces[5]==spaces[8]){
        spaces[2]==player? std::cout <<"YOU WIN!\n": std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[0]!=' ') && spaces[0]==spaces[4]&& spaces[4]==spaces[8]){
        spaces[0]==player? std::cout <<"YOU WIN!\n": std::cout << "YOU LOSE!\n";
    }
    else if ((spaces[2]!=' ') && spaces[2]==spaces[4]&& spaces[4]==spaces[6]){
        spaces[2]==player? std::cout <<"YOU WIN!\n": std::cout << "YOU LOSE!\n";
    }
    else{
        return false;
    }

    return true;

};
bool checkTie(char *spaces){
    for (int i=0; i<9; i++){
        if(spaces[i]==' '){
            return false;
        }
    }
    std::cout << "ITS A TIE!\n";
    return true;
};