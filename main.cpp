#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============= Pre-supplied functions =============\n\n";

  cout << "Calling load_board():\n";
  load_board("easy.dat", board);

  cout << '\n';
	cout << "Displaying Sudoku board with display_board():\n";
  display_board(board);
  cout << "Done!\n\n";
 

  cout << "=================== Question 1 ===================\n\n";
    
  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";
  
  cout << "=================== Question 2 ===================\n\n";

  load_board("easy.dat", board);
  cout << "Putting '1' into I8 is";
  if(!make_move("I8", '1', board)) {
    cout << "NOT ";
  }
  cout << " a valid move. \n";


  const int TEST_COUNT = 8;
  const char* test_positions[TEST_COUNT] = {"A0", "A10", "K5", "A2", "H1", "I9", "A5", "C4"};
  char test_digits[TEST_COUNT] = {'4', '5', '6', '1', '2', '9', '4', '4'};
  const char* expected_outputs[TEST_COUNT] = {
    "Expected - Invalid: A0 is out of range.",
    "Expected - Invalid: A10 is out of range.",
    "Expected - Invalid: K5 is out of range.",
    "Expected - Invalid: '1' already exists in row A.",
    "Expected - Invalid: '2' already exists in column 1.",
    "Expected - Invalid: '9' already exists in bottom-right grid.",
    "Expected - Valid.",
    "Expected - Invalid: '4' now in same grid after updates."
};
  
  
for(int idx = 0; idx < TEST_COUNT; idx++) {
  cout << "Putting '" << test_digits[idx] << "' into " << test_positions[idx] << " is ";
  if (!make_move(test_positions[idx], test_digits[idx], board)) {
    cout << "NOT ";
  }
  cout << "a valid move. " << expected_outputs[idx] << "\n";
}
 
  cout << "=================== Question 3 ===================\n\n";

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board)) {
    cout << "Save board to 'easy-copy.dat' successful.\n";
  }
  else {
    cout << "Save board failed.\n";
  }
  cout << '\n'; 


  cout << "=================== Question 4 ===================\n\n";
 
  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:\n";
    display_board(board);
  }
  else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  
  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';
  
  
  // write more tests
  load_board("easy.dat", board);
  make_move("A1", '5', board);
  make_move("A3", '9', board);
  if (solve_board(board)) {
    cout << "The modified 'easy' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found for the modified easy board.\n";
  }
  cout << '\n';

  load_board("easy-solution.dat", board);
  if (solve_board(board)) {
    cout << "The solved easy board board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found for the solved easy board.\n";
  }
  cout << '\n';
  
  cout << "=================== Question 5 ===================\n\n";

  int counter = 0;
  
  load_board("mystery1.dat", board);
  if (solve_board(board, counter)) {
    cout << "It took " << counter << " recursive calls to complete" << endl;
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  counter = 0;

  load_board("mystery2.dat", board);
  if (solve_board(board, counter)) {
    cout << "It took " << counter << " recursive calls to complete" << endl;
    display_board(board);
  } else {
    cout << " A solution cannot be found.\n";
  }
  cout << '\n';

  counter = 0;
  
  load_board("mystery3.dat", board);
  if (solve_board(board, counter)) {
    cout << "It took " << counter << " recursive calls to complete" << endl;
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';
  
  return 0;
}
