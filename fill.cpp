 #include <iostream> 
 #include <string> 
 #include "fill.h"
 #include <random>
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
  
  cout << "\033[95m PLAYER2\033[0m Enter Your Name: "; 
  cin >> nameTwo;

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

  player1.mark = toupper(player1.mark);     

  if (player1.mark == 'X')  {
  
    player2.mark = 'O'; 
    player2.colored_mark = string(BLUE) + player2.mark + REST; 
    player1.colored_mark = string(RED) + player1.mark + REST;
      
 }

  else {

    player2.mark = 'X';
    player2.colored_mark = string(RED) + player2.mark + REST;
    player1.colored_mark = string(BLUE) + player1.mark + REST; 

 }


  cout << player1.colored_mark << " " << player2.colored_mark; 

  cout << '\n'; 
     
 }
