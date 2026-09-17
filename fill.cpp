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

  struct Moves {

  short y; 
  short x; 

 }; 

  class Player {

  public:

  short moves_count = 0; 
  short score =  0;  
  char mark; 
  bool turn = false;
  string name;
  string color;
  string colored_mark;
  vector<Moves> moves;  
  
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
  
  cout << centerPad(visibleLen) << player1.color
  << player1.name << "\033[0m" << " " << player1.colored_mark
  << "  \033[97mVS\033[0m  " << player2.color
  << player2.name << "\033[0m" << " " << player2.colored_mark
  << "\n\n";

  string scoreText = to_string(player1.score) + " - " + to_string(player2.score);
  cout << centerPad((int)scoreText.size()) << "\033[97m" << scoreText << "\033[0m\n\n";

 } 

  bool checkWinner(Player *currentPlayer) {
 
  switch (currentPlayer->moves_count) {  
 
  case 3: {

  float x1 = currentPlayer->moves[0].x;
  float x2 = currentPlayer->moves[1].x;
  float x3 = currentPlayer->moves[2].x;

  float y1 = currentPlayer->moves[0].y;
  float y2 = currentPlayer->moves[1].y;
  float y3 = currentPlayer->moves[2].y;

  if (x1 == x2  && x1 == x3 && x2 == x3 || y1 == y2  && y1 == y3 && y2 == y3 ) return true; 

  else if ((y2-y1) / (x2-x1) == (y3-y2)/ (x3-x2)) return true;  

  break; 

  }

  case 4:  {

  float x1 = currentPlayer->moves[0].x;
  float x2 = currentPlayer->moves[1].x;
  float x3 = currentPlayer->moves[2].x;
  float x4 = currentPlayer->moves[3].x;

  float y1 = currentPlayer->moves[0].y;
  float y2 = currentPlayer->moves[1].y;
  float y3 = currentPlayer->moves[2].y;
  float y4 = currentPlayer->moves[3].y;
 
  if (x1 == x2  && x1 == x4 && x2 == x4 || y1 == y2  && y1 == y4 && y2 == y4 ) return true; 

  else if ((y2-y1) / (x2-x1) == (y4-y2)/ (x4-x2)) return true;  
 
  if (x1 == x3  && x1 == x4 && x3 == x4 || y1 == y3  && y3 == y4 && y3 == y4 ) return true; 

  else if ((y3-y1) / (x3-x1) == (y4-y3)/ (x4-x3)) return true;  
 
  if (x2 == x3  && x2 == x4 && x3 == x4 || y2 == y3  && y2 == y4 && y3 == y4 ) return true; 

  else if ((y3-y2) / (x3-x2) == (y4-y3)/ (x4-x3)) return true;  

  break;

  }

  case 5: {

  float x1 = currentPlayer->moves[0].x;
  float x2 = currentPlayer->moves[1].x;
  float x3 = currentPlayer->moves[2].x;
  float x4 = currentPlayer->moves[3].x;
  float x5 = currentPlayer->moves[4].x;

  float y1 = currentPlayer->moves[0].y;
  float y2 = currentPlayer->moves[1].y;
  float y3 = currentPlayer->moves[2].y;
  float y4 = currentPlayer->moves[3].y;
  float y5 = currentPlayer->moves[4].y;
 
  if (x1 == x2  && x1 == x5 && x2 == x5 || y1 == y2  && y1 == y5 && y2 == y5 ) return true; 

  else if ((y2-y1) / (x2-x1) == (y5-y2)/ (x5-x2)) return true;  
   
  if (x1 == x3  && x1 == x5 && x3 == x5 || y1 == y3  && y1 == y5 && y3 == y5 ) return true; 

  else if ((y3-y1) / (x3-x1) == (y5-y3)/ (x5-x3)) return true; 

  if (x1 == x4  && x1 == x5 && x4 == x5 || y1 == y4  && y1 == y5 && y4 == y5 ) return true; 

  else if ((y4-y1) / (x4-x1) == (y5-y4)/ (x5-x4)) return true;  
   
  if (x2 == x4  && x2 == x5 && x4 == x5 || y2 == y4  && y2 == y5 && y4 == y5 ) return true; 

  else if ((y4-y2) / (x4-x2) == (y5-y4)/ (x5-x4)) return true;  

  if (x3 == x4  && x3 == x5 && x4 == x5 || y3 == y4  && y3 == y5 && y4 == y5 ) return true; 

  else if ((y4-y3) / (x4-x3) == (y5-y4)/ (x5-x4)) return true;  

 if (x2 == x3  && x2 == x5 && x3 == x5 || y2 == y3  && y2 == y5 && y3 == y5 ) return true; 

  else if ((y3-y2) / (x3-x2) == (y5-y3)/ (x5-x3)) return true;

  break;

  }

  default: return false;

  } 

  return false; 

  }

  int getMove(const char board[3][3], Player *currentPlayer) {

  int move;

  while (true) {
  cin >> move;

  bool badInput = cin.fail() || move < 0 || move > 8;
  bool taken = false;

  if (!badInput) {

  int row = move / 3, col = move % 3;
  taken = (board[row][col] == 'X' || board[row][col] == 'O');

  }

  if (badInput || taken) {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  fillBanner();  
  printBoard(board);

  cout << "\n  " << "\033[31m▸ \033[0m" << currentPlayer->color << currentPlayer->name << REST << "'s turn\n";

  string msg = badInput ? "Invalid input. Pick a number 0-8." : "That cell is already taken.";
  cout << "\n  \033[90m▸ \033[0m\033[91m" << msg << "\033[0m\n\n";

  }
   
  else return move;
   
 }
 
 }

  void fillMode() {

  fillBanner(); 
  printBoard(board);
  
  bool winner;

  while (currentGame <= 3) {

  winner = false;
 
  for (int i = 1; i <= 9; ++i) {
    
  auto currentPlayer = (player1.turn ? &player1 : &player2);  
  
  cout << "\n  " << "\033[31m▸ \033[0m" << currentPlayer->color << currentPlayer->name << REST << "'s turn\n";
  short move = getMove(board, currentPlayer);

  short row = move  / 3; 
  short cloumn = move  % 3;  

  board[row][cloumn] = currentPlayer->mark;
  currentPlayer->moves.push_back({row, cloumn}); 
  currentPlayer->moves_count++; 
 
  winner = checkWinner(currentPlayer); 

  if (winner) {

  currentPlayer->score++;

  fillBanner();  
  printBoard(board); 

  string winText = currentPlayer->name + " TAKES GAME " + to_string(currentGame);

  cout << "\n" << centerPad((int)winText.size())
  << currentPlayer->color << currentPlayer->name << "\033[0m"
  << " TAKES GAME " << currentGame << "\n\n";

  this_thread::sleep_for(2.5s); 
  break;

  }

  fillBanner();  
  printBoard(board); 

  player1.turn = !player1.turn;  

  }

  if (!winner) {

  int tieLen = (int)player1.name.size() + (int)player2.name.size() + 15; 

  cout << "\n" << centerPad(tieLen)
  << player1.color << player1.name << "\033[0m"
  << " AND "
  << player2.color << player2.name << "\033[0m"
  << " TIE GAME " << currentGame << "\n\n";
  this_thread::sleep_for(2.5s);

 }

  currentGame++;

  if (currentGame == 4 )  break;
  
  player1.moves.clear(); 
  player2.moves.clear();
  player1.moves_count = 0; 
  player2.moves_count = 0; 

  fillBanner();  
  resetBoard(board); 
  printBoard(board);

}

  currentGame--;
  fillBanner(); 
  printBoard(board);

 if (player1.score > player2.score) {

  string matchText = player1.name + " WINS THE MATCH";

  cout << "\n" << centerPad((int)matchText.size())
  << player1.color << player1.name << "\033[0m"
  << " WINS THE MATCH\n\n";

 }

  else if (player2.score > player1.score) {

  string matchText = player2.name + " WINS THE MATCH";
   
  cout << "\n" << centerPad((int)matchText.size())
  << player2.color << player2.name << "\033[0m"
  << " WINS THE MATCH\n\n";

 }

  else {

 int matchTieLen = (int)player1.name.size() + (int)player2.name.size() + 15;

  cout << "\n" << centerPad(matchTieLen)
  << player1.color << player1.name << "\033[0m"
  << " AND "
  << player2.color << player2.name << "\033[0m"
  << " TIE THE MATCH\n\n";

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

  player1.name =  nameOne;  
  player1.color = "\033[96m"; 
  player1.turn = true;  
  player2.name =  nameTwo;
  player2.color = "\033[95m"; 
   
 }

 else {
 
  player1.name =  nameTwo;
  player1.color = "\033[95m";   
  player1.turn = true;  
  player2.name =   nameOne;
  player2.color = "\033[96m";  

 }

  cout << '\n';
  cout << ' ' << player1.color << player1.name << REST << " will start!\n\n";
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

  cout << RED << " Invalid choice." <<  REST << " X has been assigned to " <<  player1.color << player1.name << REST << "\n\n";

  player1.mark = 'X'; 
  player1.colored_mark = string(RED) + player1.mark + REST; 
  player2.mark = 'O'; 
  player2.colored_mark = string(BLUE) + player2.mark + REST;  

  cout << " \033[90mPress Enter to continue... \033[0m";  
  cin.get();
  
  }

  fillMode(); 

  } 
