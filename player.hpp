#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "tic_tac_toe_enum.hpp"

// This class sets up an interface for the two types of players: the ai and
// the user.
class Player {
	public:
		Player() = default;

		void setMove(const Move m) {
			m_move = m;
		}

	protected:
		Move m_move;
};

#endif // PLAYER_HPP
