#ifndef BOARD_HPP
#define BOARD_HPP

#include "tic_tac_toe_enum.hpp"

class Board {
	public:
		Board() : m_board({{None, None, None}, {None, None, None}, {None, None, None}}) {}

		// Board(const Board& b) : m_board(b.m_board) {}

		State checkWin() const;

		bool isFull() const;
		
		void setCell(std::size_t index, const Move m);

		void printBoard() const;

	private:
		Move m_board[3][3];
};

#endif // BOARD_HPP

