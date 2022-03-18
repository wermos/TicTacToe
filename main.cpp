#include <iostream>

#include "tic_tac_toe_enum.hpp"
#include "board.hpp"
#include "player.hpp"
#include "ai.hpp"

int main() {
	std::cout << "Would you prefer to be X or O? ";
	char playerChoice;
	std::cin >> playerChoice;

	Move playerMove, AIMove;
	if (playerChoice == 'X') {
		playerMove = Move::X;
		AIMove = Move::O;
	} else {
		playerMove = Move::O;
		AIMove = Move::X;
	}
	
	Board gameBoard;
	AI ai;
	ai.setMove(AIMove);

	State gameState = State::None;
	while (!gameBoard.isFull() && gameState == State::None) {
		gameState = gameBoard.checkWin();

		if (gameState == State::XWin) {
			if (playerMove == Move::X) {
				std::cout << "Congratulations, you have beat the AI. Ugh.\n";
			} else {
				std::cout << "Ha ha ha! My AI has bested you!\n";
			}
		} else if (gameState == State::OWin) {
			if (playerMove == Move::O) {
				std::cout << "Congratulations, you have beat the AI. Ugh.\n";
			} else {
				std::cout << "Ha ha ha! My AI has bested you!\n";
			}
		} else if (gameState == State::Draw) {
			std::cout << "It appears that you were as good as my AI. Well done.\n";
		} else {
			// ask the player for input
			std::cout << "Enter the next place you want to place your move: ";
			std::size_t move;
			std::cin >> move;

			gameBoard.setCell(move, playerMove);
			gameBoard.printBoard();
			std::cout << "\n\n";
			gameBoard.setCell(ai.bestMove(gameBoard), AIMove);
			gameBoard.printBoard();
		}
	}
}
