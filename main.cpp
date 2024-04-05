//Shreya Gogini
//p1.cpp
//A two-player Connect 4 game

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

void display_board(char [6][8], int, int); //prints the board
void player_turn(char[6][8], int); //executes the turns of the players
bool check_winner(char[6][8], int, int, char); //checks for the winner


int main(){
  //creates the game board
  char board[6][8];
  int col = 8;
  int row = 6;

  char player1 = 'X';
  char player2 = 'O';
 
  string replay = "y";

  cout << endl << "Connect 4!" << endl;

  //as long as the user wants to keep playing, the game will continue
  while(replay == "y"){
    int turn = 0; //counter for the turn the game is on
    for(int i = 0 ; i < row; i ++){
      for(int j = 0; j < col; j ++){
        board[i][j] = ' ';//sets an empty board for the first round of the game
      }
    }
    cout << endl << endl;
    display_board(board, col, row);
    bool winner = false;//sets a constraint for the duration of the game
     
    do{
      turn ++;
      cout << endl << endl;
      if(turn%2 != 0){
        player_turn(board, 1);//calls the player_turn function with player 1
        winner = check_winner(board, row, col, player1); // checks for winner
      }
      else {
        player_turn(board, 2);//calls the player_turn function with player 2
        winner = check_winner(board, row, col, player2); // checks for winner
      }
      display_board(board, col, row);
    } while(turn < 48 && winner == false);

    //If board is full, game ends in a draw
    if(turn == 48 && winner == false){
      cout<<"The game has ended in a draw. \n";
    }
    //Prints winner output
    if(winner){
      if(turn %2 != 0){
        cout << "Player '" << player1 << "' wins!\n";
      }
      else{
        cout << "Player '" << player2 << "' wins!\n";
      }
    }
    //asks user if they want to play another game
    cout << "Would you like to play again? (y/n)" << endl;
    cout << "> ";
    cin >> replay;

  }
  return 0;
  
}

//Prints board
void display_board(char board[6][8], int col, int row){
  for(int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      cout << "|" << board[i][j];
    }
    cout << "|";
    cout << endl;
    cout << "----------------" << endl;
  }
}

//Function for each player's turn
void player_turn(char board[6][8], int player){
  int choice = 0;

  //Gets column choice from player
  cout << "Player " << player << ", select a column number [0-7] " << endl;
  cin >> choice;

  
  while(!(choice >= 0 && choice <= 7)){
    cout << "Invalid choice, choose again: " << endl;
    cin >> choice;
  }
  
  
  bool empty = true;
  //Makes user pick again if the column is full
  if(board[0][choice] == 'X' || board[0][choice] == 'O'){
    cout << "Column is full. Enter another column:";
    cin >> choice;
  }
  //Populates the board with the player's token
  while(empty == true){
	if(board[5][choice] == ' '){//Checks for placement
      if(player == 1){
        board[5][choice] = 'X';
      }
      else if(player == 2){
        board[5][choice] = 'O';
      }
      empty = false;
	}
	else if (board[5][choice]!=' '){//Finds empty spot in column
      int i = 2;
      while(empty == true && i<=6){
        if(board[6-i][choice] == ' '){
          if(player == 1){
            board[6-i][choice] = 'X';
          }
          else if(player == 2){
            board[6-i][choice] = 'O';
			
          }
          empty = false;
        }
        i++;
      }
    }
  }
  
}

//Function check_winner to check for the winner
bool check_winner(char board[6][8], int row, int col, char player){
  bool winner = false;
  //Horizontal check
  for(int i = 0; i < row-3 && winner == false; i ++){
    //makes sure to stay within the bounds of the board
    for(int j = 0; j < col && winner == false; j++){
      if(board [i][j] == player && board[i+1][j] == player
         && board[i+2][j] == player && board[i+3][j] == player){
        winner = true;
      }
    }
  }
  //vertical check
  for(int m = 0; m < row && winner == false; m ++){
    for(int n = 0; n < col-3 && winner == false; n++){
      if(board [m][n] == player && board[m][n+1] == player
         && board[m][n+2] == player && board[m][n+3] == player){
        winner = true;
      }
    }
  }
  //returns true or false to either continue or end the game
  return winner;
}
