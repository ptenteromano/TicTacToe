#include <vector>

#ifndef BOARD_H
#define BOARD_H

using std::vector;

namespace Board
{
  const int DIMENSIONS = 3;
  vector<vector<char>> buildBoard();
  void displayBoard(vector<vector<char>> board);
}

#endif
