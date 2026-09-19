 #include <iostream> 
 #include <thread>
 #include <chrono>
 #include <windows.h> 
 #include "ui.h" 
 #include "fill.h"
 #include "slide.h"
 using namespace std; 
 
  string centerPad(int contentWidth, int fieldWidth, int consoleWidth) {

  int basePad = (consoleWidth - fieldWidth) / 2;
  int extra = (fieldWidth - contentWidth) / 2;

  if (extra < 0) extra = 0;

  return string(basePad + extra, ' ');

 }

  void printBoard(const char board[3][3]) {

    int consoleWidth = 120;
    int boardWidth = 23;
    int padding = (consoleWidth - boardWidth) / 2;   // fixed: removed "- 2"

    string pad(padding, ' ');

    cout << '\n';

    cout << pad << "       ║       ║       \n";
    cout << pad << "   ";

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
    cout << pad << "       ║       ║       \n";
    cout << pad << "═══════╬═══════╬═══════\n";
    cout << pad << "       ║       ║       \n";

    cout << pad << "   ";

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
    cout << pad << "       ║       ║       \n";
    cout << pad << "═══════╬═══════╬═══════\n";
    cout << pad << "       ║       ║       \n";

    cout << pad << "   ";

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
    cout << pad << "       ║       ║       \n";
    cout << '\n';

  }

  void resetBoard(char board[3][3]) {

  int count = 0;

  for (int row = 0; row < 3; row++) {
  for (int col = 0; col < 3; col++) {

  board[row][col] = '0' + count;
  count++;

  }
  }

 }

  void clearScreen() {

  cout << "\033[2J"; 

 }

   void printBanner() {

    cout << "\n\n";

    SetConsoleOutputCP(CP_UTF8);

    int consoleWidth = 120;
    int bannerWidth = 63;
    int padding = (consoleWidth - bannerWidth) / 2;

    cout << "\033[96m";
    cout << string(padding, ' ') << R"(╔═══════════════════════════════════════════════════════════════╗)" << '\n';
    cout << string(padding, ' ') << R"(║                                                               ║)" << '\n';

    cout << "\033[95m";
    cout << string(padding, ' ') << R"(║        _______         ______              ______             ║)" << '\n';
    cout << string(padding, ' ') << R"(║       /_  __(_)____   /_  __/___ ______   /_  __/___  ___     ║)" << '\n';
    cout << string(padding, ' ') << R"(║        / / / / ___/    / / / __ `/ ___/    / / / __ \/ _ \    ║)" << '\n';
    cout << string(padding, ' ') << R"(║       / / / / /__     / / / /_/ / /__     / / / /_/ /  __/    ║)" << '\n';
    cout << string(padding, ' ') << R"(║      /_/ /_/\___/    /_/  \__,_/\___/    /_/  \____/\___/     ║)" << '\n';
    cout << string(padding, ' ') << R"(║                                                               ║)" << '\n';

    cout << "\033[96m";
    cout << string(padding, ' ') << R"(╚═══════════════════════════════════════════════════════════════╝)" << '\n';

    cout << "\033[0m";

 }


  void restMenu() {
     
  clearScreen();
  SetConsoleOutputCP(CP_UTF8);
  
 cout << '\n'; 
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

  char mode;   
  cin >> mode;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << '\n'; 
  
  if (mode == '1') 

  fill(); 
  
  else if (mode == '2')

  slide(); 
  
  else if (mode == 'Q' || mode == 'q') return;

  else {
    
  cout << "\033[31m Invalid input\033[0m\n\n"; 
  this_thread::sleep_for(1s); 
  restMenu(); 
  
 }

 return; 

 } 
