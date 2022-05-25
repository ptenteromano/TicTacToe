# TicTacToe with C++!

Using the GNU C++ command, in the root directory:

`g++ -std=c++17 tictactoe.cpp board/board.cpp game/game.cpp -o tictactoe; `

*Note: the c++17 flag is important, as some vector initializations are only valid in C++11+*

The above command will compile and link all object files into an executable file called `tictactoe`.
Run the executable from a terminal using `./tictactoe`.

This was built without OOP. Specifically built using procedural and functional programming.

The `game` and `board` object files contain only functions to build and process the 2D vector board and user input.

The primary program lives in `tictactoe.cpp`, keeping things slim and modular.
