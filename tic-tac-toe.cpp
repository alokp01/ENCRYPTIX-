#include <iostream>
#include <string>
using namespace std;

//Tic Tac Toe Game!
static void printBoard(string board[3][3]){
    for(int i = 0; i< 3; i++){
        for(int j = 0; j< 3; j++){
            cout << " | " + board[j][i] + " |";
        }
        cout << "\n";
    }
}
static void playGame(string board[3][3], string choice, int box){
    switch(box){
        case 1: board[0][0] = choice;
        break;
        case 2: board[1][0] = choice;
        break;
        case 3: board[2][0] = choice;
        break;
        case 4: board[0][1] = choice;
        break;
        case 5: board[1][1] = choice;
        break;
        case 6: board[2][1] = choice;
        break;
        case 7: board[0][2] = choice;
        break;
        case 8: board[1][2] = choice;
        break;
        case 9: board[2][2] = choice;
        break;
    }
}
static bool winner(string board[3][3]){
        if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
            return true;
        } else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != "") {
            return true;
        } else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != "") {
            return true;
        } else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != "") {
            return true;
        } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != "") {
            return true;
        } else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != "") {
            return true;
        } else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != "") {
            return true;
        } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != "") {
            return true;
        }
    return false;

}
int main() {
    string board[3][3];
    string choice;
    string choice2;
    int turn = 0;
    int box;
    cout << "Lets play Tic Tac Toe! \n" << "Which letter do you want to use?\n" << "Type 'X' for X and 'O' for O:" << endl;
    cin >> choice;
    while(choice != "X" && choice != "O"){
        cout << "Your choice was invalid. Please enter X or O"<< endl;
        cin >> choice;
    }
    if(choice == "X") {
        cout << "Player 2 will be O" << endl;
        choice2 = "O";
    }else if(choice == "O"){
        cout << "Player 2 will be X" << endl;
        choice2 = "X";
    }

    while(turn < 5) {
        cout << "Player 1. Please state the number of the box you would like to place the " + choice + " in." << endl;
        printBoard(board);
        cin >> box;
        playGame(board, choice, box);
        if(winner(board)){
            cout << "Congrats! We have a winner!" << endl;
            printBoard(board);
            return 0;
        }
        cout << "Player 2. Please state the number of the box you would like to place the " + choice2 + " in." << endl;
        printBoard(board);
        cin >> box;
        playGame(board, choice2, box);
        if(winner(board)){
            cout << "Congrats! We have a winner!" << endl;
            printBoard(board);
            return 0;
        }
        turn++;

    }
    cout << "Tie Game!" << endl;
    return 0;
}
