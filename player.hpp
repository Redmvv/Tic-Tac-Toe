 #pragma once
 #include <string> 
 #include <version>

 struct Moves {

  short y; 
  short x; 
  char cellNumber; 

 }; 

  class Player {

  public:

  short moves_count = 0; 
  short score =  0;  
  char mark; 
  bool turn = false;
  bool remove = false;
  string name;
  string color;
  string colored_mark;
  vector<Moves> moves;  
  
  };
