# Sudoku-Grid-Solver

Solving suduko using backtracking in C++

# Algorithm Overview

The Brute Force Search algorithm searches the vacant cells in some sequence, adding the digits one at a time or going backwards when it discovers that the number is invalid. Placing the number "1" in the first cell and checking that it is permitted there would be how the program would solve a riddle. The algorithm moves on to the next cell and enters a "1" there if there are no violations (checking row, column, and box restrictions). If the "1" is found to be prohibited during the violation check, the value is advanced to "2". The algorithm advances back to the previous cell and leaves a cell blank if it finds a cell where none of the nine digits are permitted.
