#include <vector>

#ifndef GAME_H
#define GAME_H

using std::vector;

namespace Game
{
  bool inRange(int move);
  int getValidPlayerMove(char player);
  bool makeMove(vector<vector<char>> &board, char player, int move);

  bool checkRows(vector<vector<char>> board, char player);
  bool checkColumns(vector<vector<char>> board, char player);
  bool checkDiagonals(vector<vector<char>> board, char player);
  bool isWinner(vector<vector<char>> board, char player);
}

#endif
