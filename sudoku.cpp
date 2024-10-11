#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"
#include <cctype> 

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in) {
    cout << "Failed!\n";
  }
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }
  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3)) {
    cout << "  +===========+===========+===========+\n";
  } else {
    cout << "  +---+---+---+---+---+---+---+---+---+\n";
  }
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|\n";
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) {
    cout << (char) ('1'+r) << "   ";
  }
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */
// Q1
bool is_complete(const char board[9][9]) {
  for (int row_idx = 0; row_idx < 9; row_idx++) {
    for (int col_idx = 0; col_idx < 9; col_idx++) {
      if (board[row_idx][col_idx] < '1' || board[row_idx][col_idx] > '9') {
	return false;
      }
    }
  }
  return true;
}

//Q2 helper functions
bool is_out_of_range(const char position[]) {
    int col_idx;
    if (position[0] < 'A' || position[0] > 'I') {
      return true;
    }   

   // Ensure only 2 characters are provided and the second one is a digit
    if (position[2] != '\0' || !isdigit(position[1])) {
      return true;
    }

    // Will give integer column index
    col_idx = position[1] - '1';
    return col_idx < 0 || col_idx > 8;
}

bool row_valid(const char position[], char digit, const char board[9][9]) {
  // Will give integer row index
  int row_idx = position[0] - 'A';

  for (int col_idx = 0; col_idx < 9; col_idx++) {
    if (digit == board[row_idx][col_idx]) {
      return false;
    }
  }  
  return true;
}

bool col_valid(const char position[], char digit, const char board[9][9]) {
  int col_idx = position[1] - '1';
  
  for (int row_idx = 0; row_idx < 9; row_idx++) {
    if (digit == board[row_idx][col_idx]) {
      return false;
    }
  }  
  return true;
}
 
bool grid_valid(const char position[], char digit, const char board[9][9]) {
  int grid_row_start, grid_col_start;
  // Determines which grid the position is in.
  grid_row_start = (position[0] - 'A') / 3;
  grid_col_start = (position[1] - '1') / 3;

  // Determines the exclusive edges of the grid 
  int grid_row_end, grid_col_end;
  grid_row_end = (grid_row_start + 1) * 3; 
  grid_col_end = (grid_col_start + 1) * 3; 

  // Iterates through 3x3 grid based on the start and end points.
  for (int row_idx = grid_row_start * 3; row_idx < grid_row_end; row_idx++) {
    for (int col_idx = grid_col_start * 3; col_idx < grid_col_end; col_idx++) {
      if (digit == board[row_idx][col_idx]) {
	return false;
      }
    }
  }  
  return true;
}

bool is_move_valid(const char position[], char digit, const char board[9][9]) {
  return row_valid(position, digit, board) && col_valid(position, digit, board) && grid_valid(position, digit, board);
}

// Q2
bool make_move(const char position[], char digit, char board[9][9]) {
  if(is_out_of_range(position) || !(is_move_valid(position, digit, board))){
    return false;
  }
  int row_idx = position[0] - 'A';
  int col_idx = position[1] - '1';
  board[row_idx][col_idx] = digit;
  return true;
}


//Q3
bool save_board(const char* filename, char board[9][9]) {
  ofstream out(filename);
  
  if (!out) {
    return false;
  }

  for (int row_idx = 0; row_idx < 9; row_idx++) {
    for (int col_idx = 0; col_idx < 9; col_idx++) {
      assert(board[row_idx][col_idx] == '.' || isdigit(board[row_idx][col_idx]));
      out << board[row_idx][col_idx];
    }
    out << "\n";
  }

  out.close();

  if (out.fail()) {
    return false;
  }
  return true;
}

//Q4
bool find_empty_square(int &row_idx, int &col_idx, const char board[9][9]) {
  for (row_idx = 0; row_idx < 9; row_idx++) {
    for (col_idx = 0; col_idx < 9; col_idx++) {
      if ('.' == board[row_idx][col_idx]) {
	return true;
      }
    }
  }
  return false;
}


bool solve_board(char board[9][9]) {
  int count = 0;
  return solve_board(board, count);
}

bool solve_board(char board[9][9], int &counter) {
    int row_idx, col_idx;

    counter++;
    
    // The function edits row_idx, col_idx to be the next blank position
    if (!find_empty_square(row_idx, col_idx, board)) {
        return true;
    }
    
    for (char digit = '1'; digit <= '9'; digit++) {
      // Size 3 to include '\0'
      char position[3];
	
      //Converts integer to string position e.g. 02 to "A3"
      position[0] = 'A' + row_idx; 
      position[1] = '1' + col_idx; 
	
      if (make_move(position, digit, board)) {
	if (solve_board(board, counter)) {
	  return true;  // If the recursive call returns true, then a solution was found.
	}
	
        // If no solution was found, backtrack by resetting the square.
        board[row_idx][col_idx] = '.'; 
      }
    }
    return false;
}
