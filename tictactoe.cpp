#include <iostream>
#include "board/board.h"
#include "game/game.h"

using std::cout;
using std::endl;

vector<vector<char>> setup();
void playGame(vector<vector<char>> board);

int main()
{
  vector<vector<char>> board = setup();
  playGame(board);
  cout << "Thanks for playing!" << endl;
}

// Welcome and initialize the board
vector<vector<char>> setup()
{
  cout << "Welcome to Tic-Tac-Toe, let's play!" << endl;
  cout << "Press enter to continue" << endl;
  std::string input;
  getline(std::cin, input);

  vector<vector<char>> board = Board::buildBoard();
  Board::displayBoard(board);

  return board;
}

// Play the entire game
void playGame(vector<vector<char>> board)
{
  char player = 'X';
  int count = 0;
  const int totalMoves = Board::DIMENSIONS * Board::DIMENSIONS;

  while (count < totalMoves)
  {
    while (!Game::makeMove(board, player, Game::getValidPlayerMove(player)))
      ;
    Board::displayBoard(board);

    if (Game::isWinner(board, player))
    {
      cout << "Player '" << player << "' wins!" << endl;
      return;
    }

    player == 'X' ? player = 'O' : player = 'X';
    count++;
  }

  cout << "It's a draw! Try playing again." << endl;
  return;
}
