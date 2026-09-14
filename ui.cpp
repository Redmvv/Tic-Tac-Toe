#include <iostream> 
#include <windows.h> 
#include "ui.h" 
using namespace std; 

  
   void printBoard(const char board[3][3]) {

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


 void printBanner() {

  cout << "\n\n"; 
    
 SetConsoleOutputCP(CP_UTF8);

 cout << "\033[96m";
 cout << R"(
╔═══════════════════════════════════════════════════════════════╗
║                                                               ║
)";
 
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
cout << R"(
╚═══════════════════════════════════════════════════════════════╝
)";
cout << "\033[0m"; 

 }


  void printGameInfo() {




    
  }