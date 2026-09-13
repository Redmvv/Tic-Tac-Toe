  #include <iostream>
  #include <random>
  #include <string>
  #include <windows.h>
  #include "fill.h"
  #include "slide.h"

  using namespace std; 

  int main() {

  char mode; 
 
  cout << '\n'; 
    
  SetConsoleOutputCP(CP_UTF8);

 cout << "\033[96m";
 cout << R"(
╔═══════════════════════════════════════════════════════════════╗
║                                                               ║
)";
 
 cout << "\033[95m";
 cout << "\033[95m";

 cout << R"(
║      _______         ______              ______               ║
║     /_  __(_)____   /_  __/___ ______   /_  __/___  ___       ║
║      / / / / ___/    / / / __ `/ ___/    / / / __ \/ _ \      ║
║     / / / / /__     / / / /_/ / /__     / / / /_/ /  __/      ║
║    /_/ /_/\___/    /_/  \__,_/\___/    /_/  \____/\___/       ║
║                                                               ║
)";

cout << "\033[96m";

cout << "\033[96m";
cout << R"(
╚═══════════════════════════════════════════════════════════════╝
)";

 cout << "\033[1;95m";
 cout << "\n GAME MENU\n\n";
 cout << "\033[95m"; 
 cout << " [1]";
 cout << "\033[96m"; 
 cout << " FILL \n";

 cout << "\033[95m";
 cout << " [2]";
 cout << "\033[96m";
 cout << " SLIDE \n";

 cout << "\033[95m";
 cout << " [Q]";
 cout << "\033[96m";
 cout << " Quit\n";

 cout << "\033[0m";  
 cout << '\n'; 

  cin >> mode;
  cout << '\n'; 
  
  if (mode == '1') 

  fill(); 
  
  else if (mode == '2')

  slide(); 
  
  else if (mode == 'Q' || mode == 'q') return 0;

  else cout << "\033[31m Invalid input\033[0m\n\n"; 

  

  return 0; 

}
