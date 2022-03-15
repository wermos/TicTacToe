#include "board.hpp"

State Board::checkWin() {
	// There is no way to check for wins using a for-each loop, so we have to
	// settle for a classic index-based approach.

	// Checking for wins in the horizontal direction
	for (auto i = 0; i < 3; ++i) {
		if (m_board[i][0] == m_board[i][1] && m_board[i][1] == m_board[i][2]) {
			if (m_board[i][0] == Move::X) {
				return State::XWin;
			} else if (m_board[i][0] == Move::O) {
				return State::OWin;
			}
		}
	}

	// Checking for wins in the vertical direction
	for (auto j = 0; j < 3; ++j) {
		if (m_board[0][j] == m_board[1][j] && m_board[1][j] == m_board[2][j]) {
			if (m_board[0][j] == Move::X) {
				return State::XWin;
			} else if (m_board[0][j] == Move::O) {
				return State::OWin;
			}
		}
	}

	// Checking for wins in diagonal directions
	if (m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2]) {
		if (m_board[0][j] == Move::X) {
			return State::XWin;
		} else if (m_board[0][j] == Move::O) {
			return State::OWin;
		}
	} else if (m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0]) {
		if (m_board[0][j] == Move::X) {
			return State::XWin;
		} else if (m_board[0][j] == Move::O) {
			return State::OWin;
		}
	}

	// Finally, if we got this far, then neither player has won 
	if (isFull()) {
		return State::Draw;
	} else {
		return State::None;
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
			if (elem == Move::None) {
				std::cout << " ";
			} else if (elem == Move::X) {
				std::cout << "X";
			} else {
				std::cout << "O";
			}
			std::cout << " ";
		}
		std::cout << '\n';
	}
}

bool Board::isFull() {
	for (auto& row : m_board) {
		for (auto& elem : row) {
			if (elem == Move::None) {
				return true;
			}
		}
	}

	// then, none of the squares have the value of Move::None, meaning that
	// none of them are empty
	return false; 
}
