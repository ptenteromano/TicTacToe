#include <iostream>
#include "game.h"
#include "../board/board.h"

using std::cin;
using std::cout;
using std::endl;

// Game can only be between 1 and 9
bool Game::inRange(int move)
{
  return move >= 1 && move <= (Board::DIMENSIONS * Board::DIMENSIONS);
}

// Validate input from user
int Game::getValidPlayerMove(char player)
{
  cout << "Player '" << player << "' make your move! Select available numbers (1-9):" << endl;

  std::string input;
  cin >> input;

  while (input.size() > 1 || !inRange((int)input[0] - '0'))
  {
    cout << "Invalid move, try again: " << endl;
    cin >> input;
  }

  // Convert char to int properly
  return input[0] - '0';
}

// Get the row and column based on the move. Ensure it is unoccupied.
// Board is passed by reference to allow for the move to be made.
bool Game::makeMove(vector<vector<char>> &board, char player, int move)
{
  const int row = (move - 1) / Board::DIMENSIONS;
  const int col = (move - 1) % Board::DIMENSIONS;

  if (board[row][col] == 'X' || board[row][col] == 'O')
  {
    cout << "That space is already taken!" << endl;
    return false;
  }

  board[row][col] = player;
  return true;
}

// ------------------------------------------------
// ------------------ Conditions ------------------
// ------------------------------------------------

// Check all rows
bool Game::checkRows(vector<vector<char>> board, char player)
{
  for (int r = 0; r < Board::DIMENSIONS; r++)
  {
    bool rowWin = true;
    for (int c = 0; c < Board::DIMENSIONS; c++)
      if (board[r][c] != player)
      {
        rowWin = false;
        break;
      }
    if (rowWin)
      return true;
  }
  return false;
}

// Check all Columns
bool Game::checkColumns(vector<vector<char>> board, char player)
{
  for (int c = 0; c < Board::DIMENSIONS; c++)
  {
    bool colWin = true;
    for (int r = 0; r < Board::DIMENSIONS; r++)
      if (board[r][c] != player)
      {
        colWin = false;
        break;
      }
    if (colWin)
      return true;
  }
  return false;
}

// Check both diagonals
bool Game::checkDiagonals(vector<vector<char>> board, char player)
{
  // Top Left to Bottom Right
  bool diagWin = true;
  for (int i = 0; i < Board::DIMENSIONS; i++)
    if (board[i][i] != player)
    {
      diagWin = false;
      break;
    }
  if (diagWin)
    return true;

  // Top Right to Bottom Left
  diagWin = true;
  for (int i = 0; i < Board::DIMENSIONS; i++)
    if (board[i][Board::DIMENSIONS - i - 1] != player)
    {
      diagWin = false;
      break;
    }
  if (diagWin)
    return true;

  return false;
}

// Check all conditions or winning
bool Game::isWinner(vector<vector<char>> board, char player)
{
  return checkRows(board, player) || checkColumns(board, player) || checkDiagonals(board, player);
}
