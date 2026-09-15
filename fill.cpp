 #include <iostream> 
 #include <string>
 #include <array> 
 #include <limits>
 #include <thread>
 #include <chrono>
 #include <random>
 #include "fill.h"
 #include "ui.h"

  using namespace std; 

  #define REST "\033[0m"  
  #define RED "\033[31m"  
  #define BLUE "\033[34m"  

  class Player {

  public:

  short moves_count = 0; 
  short score =  0;  
  char mark; 
  bool turn = false;
  string name;
  string colored_mark;
  vector<char*> moves; 
  vector<pair<int, int>> pos; 
  
  };

  char board[3][3] = {

  '0', '1', '2', 
  '3', '4', '5',
  '6', '7', '8' 

 };
 
  short currentGame = 1;  
  Player player1; 
  Player player2; 
  
  void fillBanner() {

  clearScreen();
  printBanner();

  cout << "\n";
  cout << centerPad(11) << "\033[104m\033[1;30m FILL MODE \033[0m\n\n";
  cout << centerPad(13) << "\033[90mBEST OF THREE  |  GAME " << currentGame << "\033[0m\n\n";

  int visibleLen = (int)player1.name.size() + 1 + 1 + 6 + (int)player2.name.size() + 1 + 1;
  cout << centerPad(visibleLen)

   << player1.name << "\033[0m" << " " << player1.colored_mark
  << "  \033[97mVS\033[0m  "
  << player2.name << "\033[0m" << " " << player2.colored_mark
  << "\n\n";

  string scoreText = to_string(player1.score) + " - " + to_string(player2.score);
  cout << centerPad((int)scoreText.size()) << "\033[97m" << scoreText << "\033[0m\n\n";

 } 


  void checkWinner(Player *currentPlayer) {
 
  if (currentPlayer->moves_count < 3) return; 

//   else if (currentPlayer->moves_count == 3) {


//   }

} 
   
  void fillMode() {

  fillBanner(); 
  printBoard(board);

  while (currentGame <= 3) {
 
  for (int i = 1; i <= 9; ++i) {
 
  auto currentPlayer = (player1.turn ?  &player1 : &player2);  
  short move;
  
  cout << "\n  " << "\033[31m▸ \033[0m" << currentPlayer->name << "'s turn\n\n";
  cin >> move;  

  short row = move / 3; 
  short cloumn = move % 3;  

  board[row][cloumn] = currentPlayer->mark;
  currentPlayer->moves.push_back(&board[row][cloumn]);
  currentPlayer->moves_count++; 

  checkWinner(currentPlayer); 
  fillBanner();  
  printBoard(board); 

  player1.turn = !player1.turn;  

  }
  
  currentGame++;

  if (currentGame == 4 )  break;
  
  player1.moves.clear(); 
  player2.moves.clear();
  
  fillBanner();  
  resetBoard(board); 
  printBoard(board);

  }
  }
 
  void fill() {

  random_device random_device; 
  mt19937 random_engine{random_device()}; 
  uniform_int_distribution distribution{1, 2};
  short first = distribution(random_engine); 

  string nameOne; 
  string nameTwo; 

  cout << "\033[96m PLAYER1\033[0m Enter Your Name: "; 
  cin >> nameOne;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "\033[95m PLAYER2\033[0m Enter Your Name: "; 
  cin >> nameTwo;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

 if (first == 1) {

  player1.name =  "\033[95m" + nameOne + REST; 
  player1.turn = true;  
  player2.name =  "\033[96m" +  nameTwo + REST;
   
 }

 else {
 
  player1.name = "\033[96m" + nameTwo + REST;  
  player1.turn = true;  
  player2.name = "\033[95m" + nameOne + REST; 

 }

  cout << '\n';
  cout << ' '  << player1.name << REST << " will start!\n\n";
  cout << " Choose your mark [X/O] " <<  "\033[90m> \033[0m";
  cin  >> player1.mark;
  cout << '\n'; 
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  player1.mark = toupper(player1.mark);     

  if (player1.mark == 'X') {
  
  player1.colored_mark = string(RED) + player1.mark + REST; 
  player2.mark = 'O'; 
  player2.colored_mark = string(BLUE) + player2.mark + REST; 
 
 }

  else if (player1.mark == 'O') {

  player1.colored_mark = string(BLUE) + player1.mark + REST; 
  player2.mark = 'X';
  player2.colored_mark = string(RED) + player2.mark + REST; 

 }

 else {

  cout << RED << " Invalid choice." <<  REST << " X has been assigned to " << player1.name << REST << "\n\n";

  player1.mark = 'X'; 
  player1.colored_mark = string(RED) + player1.mark + REST; 
  player2.mark = 'O'; 
  player2.colored_mark = string(BLUE) + player2.mark + REST;  

  cout << " \033[90mPress Enter to continue... \033[0m";  
  cin.get();
  
  }

  fillMode(); 

  } 
