#ifndef SUDOKU_H
#define SUDOKU_H


/* Pre-condition:  Filename is a valid path to a file that contains a 9x9 Sudoku grid.
                   Each line in the file is one row of the Sudoku board.
   Post-condition: The board is filled with characters, representing the digits, from the file. */
void load_board(const char* filename, char board[9][9]);

/* Pre-condition:  The board is a 9x9 2D array representing a Sudoku board.
   Post-condition: The board is output to the console in a sudoku format. */
void display_board(const char board[9][9]);

/* Pre-condition:  The board is a 9x9 2D array representing a Sudoku board.
   Post-condition: Returns true if the board does not have any empty squares. */
bool is_complete(const char board[9][9]);

/* Pre-condition:  The position is a valid character array, "A1", "I9".
                   The digit is a character in the range '1' to '9'.
                   The board is a 9x9 2D array representing a Sudoku board.
   Post-condtion:  If the move is valid, i.e. not out of bounds and conforming to sudoku rules, 
                   the board is updated and returns true else returns false without modification.*/
bool make_move(const char position[], char digit, char board[9][9]);

/* Pre-condition:  Filename is a valid path to a file that contains a 9x9 Sudoku grid.
                   The board is a 9x9 2D array representing a Sudoku board.
   Post-condition: If the board is saved to the file successfully it returns true, else returns false.  */
bool save_board(const char* filename, char board[9][9]);


/* Pre-condition:  The board is a 9x9 2D array representing a Sudoku board.
   Post-condition: If there is a solution, the board is updated and returns true,
                   else the board remains unmodified and returns false.*/
bool solve_board(char board[9][9]);


/* Pre-condition:  The board is a 9x9 2D array representing a Sudoku board, counter is initialise to 0.
   Post-condition: If there is a solution, the board is updated and returns true,
                   else the board remains unmodified and returns false. counter value is updated to represent number of recursive calls.*/

bool solve_board(char board[9][9], int &counter);

#endif
