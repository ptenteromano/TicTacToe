#include <iostream>
#include "board.h"

using std::cout;
using std::endl;
using std::string;

// Create a new blank tic toc board
vector<vector<char>> Board::buildBoard()
{
  vector<vector<char>> board{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  return board;
}

// Display board to console
void Board::displayBoard(vector<vector<char>> board)
{
  string border = "+---+---+---+";
  cout << border << endl;

  for (int r = 0; r < DIMENSIONS; r++)
  {
    for (int c = 0; c < DIMENSIONS; c++)
      cout << '|' << ' ' << board[r][c] << ' ';
    cout << '|' << endl
         << border << endl;
  }
}
