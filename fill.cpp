 #include <iostream> 
 #include <string>
 #include <array> 
 #include <limits>
 #include <random>
 #include "fill.h"
 #include "ui.h"

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
  
  };

  
  char board[3][3] = {

  '0', '1', '2', 
  '3', '4', '5',
  '6', '7', '8' 

 };

  
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
  player1.color = "\033[96m";
  player1.turn = true;  
  
  player2.name = nameTwo;
  player2.color = "\033[95m"; 

 }

 else {
 
  player1.name = nameTwo; 
  player1.color = "\033[96m"; 
  player1.turn = true;  

  player2.name = nameOne;
  player2.color = "\033[95m"; 

 }

  cout << '\n'; 
  cout << player1.color << player1.name << REST << " Choose Your Mark [X/O] ";  
  cin  >> player1.mark;
  cout << '\n'; 
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  player1.mark = toupper(player1.mark);     

  if (player1.mark == 'X') {
  
  player2.mark = 'O'; 
 
 }

  else if (player1.mark == 'O') {

  player2.mark = 'X';
 
 }


 else {

  cout << RED << " Invalid choice." <<  REST << " X has been assigned to " << player1.color << player1.name << REST << '\n';

  player1.mark = 'X'; 
  player2.mark = 'O'; 
   
 }

  clearScreen();
  printBanner(); 
  printBoard(board);

  for (int i = 0; i < 9; ++i) {

  int move;
  cin >> move;

  int r = move / 3;
  int c = move % 3;

  board[r][c] = player1.mark;

  clearScreen();
  printBanner(); 
  printBoard(board);

 }

  cout << "\n";
 
 
 }
