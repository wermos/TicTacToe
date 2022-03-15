#include "board.hpp"

State Board::checkWin() {
//TODO: Implement this function fully.
	for (auto& row : m_board) {
		for (auto& elem : row) {
			std::cout << elem << " ";
		}
		std::cout << '\n';
	}
}

void Board::setCell(std::size_t index, const Move m) {
	/**
	 * index must be an integer between 0 and 8, inclusive.
	 * This function simply sets the i'th cell to the required
	 * Move.
	 */
	m_board[index / 3][index % 3] = m;
}

void Board::printBoard() {
	for (auto& row : m_board) {
		for (auto& elem : row) {
			std::cout << elem << " ";
		}
		std::cout << '\n';
	}
}
