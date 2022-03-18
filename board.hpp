#ifndef BOARD_HPP
#define BOARD_HPP

#include "tic_tac_toe_enum.hpp"
#include <vector>

class Board {
	public:
		Board() : m_board({Move::None, Move::None, Move::None},
				{Move::None, Move::None, Move::None},
				{Move::None, Move::None, Move::None})
		{}

		// This copy constructor does a deep copy
		Board(const Board& b) {
			for (auto i = 0; i < 3; ++i) {
				for (auto j = 0; j < 3; ++j) {
					m_board[i][j] = b.m_board[i][j];
				}
			}
		}

		State checkWin() const;

		bool isFull() const;
		
		void setCell(std::size_t index, Move m);

		std::vector<std::size_t> emptyCells() const;

		void printBoard() const;

	private:
		Move m_board[3][3];
};

#endif // BOARD_HPP

