 #include <iostream> 
 #include <string>
 #include <array> 
 #include <limits>
 #include <random>
 #include "fill.h"

 using namespace std; 

 #define REST "\033[0m"  
 #define RED "\033[31m"  
 #define BLUE "\033[34m"  

  class Player {

  public:
  char mark; 
  bool turn = false; 
  string name;
  string color;
  string colored_mark; 
  
  };

  
   char board[3][3] = {

    '0', '1', '2', 
    '3', '4', '5',
    '6', '7', '8' 

  };

  
   void printBoard() {

    cout << '\n';

    cout << "       ║       ║       \n";

    cout << "   ";
    if (board[0][0] == 'X') cout << "\033[91mX\033[0m";
    else if (board[0][0] == 'O') cout << "\033[94mO\033[0m";
    else cout << board[0][0];

    cout << "   ║   ";

    if (board[0][1] == 'X') cout << "\033[91mX\033[0m";
    else if (board[0][1] == 'O') cout << "\033[94mO\033[0m";
    else cout << board[0][1];

    cout << "   ║   ";

    if (board[0][2] == 'X') cout << "\033[91mX\033[0m";
    else if (board[0][2] == 'O') cout << "\033[94mO\033[0m";
    else cout << board[0][2];

    cout << "   \n";
    cout << "       ║       ║       \n";
    cout << "═══════╬═══════╬═══════\n";
    cout << "       ║       ║       \n";

    cout << "   ";
    if (board[1][0] == 'X') cout << "\033[91mX\033[0m";
    else if (board[1][0] == 'O') cout << "\033[94mO\033[0m";
    else cout << board[1][0];

    cout << "   ║   ";

    if (board[1][1] == 'X') cout << "\033[91mX\033[0m";
    else if (board[1][1] == 'O') cout << "\033[94mO\033[0m";
    else cout << board[1][1];

    cout << "   ║   ";

    if (board[1][2] == 'X') cout << "\033[91mX\033[0m";
    else if (board[1][2] == 'O') cout << "\033[94mO\033[0m";
    else cout << board[1][2];

    cout << "   \n";
    cout << "       ║       ║       \n";
    cout << "═══════╬═══════╬═══════\n";
    cout << "       ║       ║       \n";

    cout << "   ";
    if (board[2][0] == 'X') cout << "\033[91mX\033[0m";
    else if (board[2][0] == 'O') cout << "\033[94mO\033[0m";
    else cout << board[2][0];

    cout << "   ║   ";

    if (board[2][1] == 'X') cout << "\033[91mX\033[0m";
    else if (board[2][1] == 'O') cout << "\033[94mO\033[0m";
    else cout << board[2][1];

    cout << "   ║   ";

    if (board[2][2] == 'X') cout << "\033[91mX\033[0m";
    else if (board[2][2] == 'O') cout << "\033[94mO\033[0m";
    else cout << board[2][2];

    cout << "   \n";

    cout << "       ║       ║       \n";
    cout << '\n';
}


 void clearScreen() {

  cout << "\033[2J";

 }

 void fill() {

  random_device random_device; 
  mt19937 random_engine{random_device()}; 
  uniform_int_distribution distribution{1, 2};
  short first = distribution(random_engine); 

  Player player1; 
  Player player2; 
  string nameOne; 
  string nameTwo; 

  cout << "\033[96m PLAYER1\033[0m Enter Your Name: "; 
  cin >> nameOne;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "\033[95m PLAYER2\033[0m Enter Your Name: "; 
  cin >> nameTwo;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

 if (first == 1) {

  player1.name = nameOne; 
  player2.name = nameTwo;
  player1.turn = true;  
  player1.color = "\033[96m";
  player2.color = "\033[95m"; 

 }

 else {
 
  player1.name = nameTwo; 
  player2.name = nameOne;
  player1.turn = true;  
  player1.color = "\033[96m"; 
  player2.color = "\033[95m"; 

 }

  cout << '\n'; 
  cout << player1.color << player1.name << REST << " Choose Your Mark [X/O] ";  
  cin  >> player1.mark;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  player1.mark = toupper(player1.mark);     

  if (player1.mark == 'X') {
  
    player2.mark = 'O'; 
    player2.colored_mark = string(BLUE) + player2.mark + REST; 
    player1.colored_mark = string(RED) + player1.mark + REST;
      
 }

  else {

  player2.mark = 'X';
  player2.colored_mark = string(RED) + player2.mark + REST;
  player1.colored_mark = string(BLUE) + player1.mark + REST; 

 }


  cout << player1.color << player1.name << REST << '\n';

  printBoard();

  for (int i = 0; i < 9; ++i) {

  int move;
  cin >> move;

  int r = move / 3;
  int c = move % 3;

  board[r][c] = player1.mark;

  clearScreen();
  printBoard();

 }

  cout << "\n";
 
 
 }
