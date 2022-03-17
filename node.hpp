#ifndef TREE_FWD_HPP
#define TREE_FWD_HPP

#include <type_traits>
#include <vector>
#include <limits>

// IMPLEMENT LATER
/**
// A lean struct which simply stores the diff between any two
// successive board configurations. This allows us to greatly save
// on the amount of memory being used to construct the game tree.
struct Diff {
	Move m;
	std::size_t index;
};
*/

// Using an std::int8_t for our enum means that our weights can vary from -128
// to 127, inclusive.
enum Weight : std::int8_t {
	PlayerWin = -100, // the worst scenario; deserves the lowest score
	Draw = 0,         // this scenario gets a lower score than the case where the
					  // game hasn't ended yet because if Draw > None, then the
					  // minimax algorithm would prefer a Draw over continuing the
					  // game, which is not in our best interest.
	None = 1,         // None means the game hasn't ended yet. For the reasons
					  // mentioned above, None > Draw.
	AIWin = 100,      // the best scenario; deserves the highest score
	//operator std::int8_t(const Weight& w) {
	//	return static_cast<std::underlying_type<Weight>>(w);
	//}
};

/**
std::underlying_type<Weight> operator+(Weight w1, Weight w2) {
	return static_cast<std::underlying_type<Weight>>(w1) + static_cast<std::underlying_type<Weight>>(w2);
}

std::int8_t operator+(const std::int8_t w1, Weight w2) {
	return w1 + static_cast<std::underlying_type<Weight>>(w2);
}

std::int8_t operator+(Weight w1, const std::int8_t w2) {
	return static_cast<std::underlying_type<Weight>>(w1) + w2;
}*/

// asdf
struct Node {
	Node* parent = nullptr;
	std::vector<Node*> children;
	std::int8_t weight; // stores how favorable the current board position is
	//Diff d; // stores the difference between the previous board position and the current one
	Board board;
	//Move maximizingMove;
	// the move we want to maximize the value for; this is in essence the AI's move

	std::int8_t terminalNodeWeight(Move maximizingMove) {
		if (board.checkWin() == State::XWin && maximizingMove == Move::X) {
			weight = Weight::AIWin;
		} else if (board.checkWin() == State::OWin && maximizingMove == Move::O) {
			weight = Weight::PlayerWin;
		} else if (board.checkWin() == State::OWin && maximizingMove == Move::X) {
			weight = Weight::AIWin;
		} else if (board.checkWin() == State::XWin && maximizingMove == Move::O) {
			weight = Weight::PlayerWin;
		} else if (board.isFull()) {
			weight = Weight::Draw;
		} else {
			weight = Weight::None;
		}
		return weight;
	}

	/**
	std::int8_t maximalNodeWeight() {
		return std::max_element(children.begin(), children.end(),
				[](const Node& n1, const Node& n2) -> bool {
					return n1.weight < n2.weight;
				});
	}

	std::int8_t minimalNodeWeight() {
		return std::min_element(children.begin(), children.end(),
				[](const Node& n1, const Node& n2) -> bool {
					return n1.weight < n2.weight;
				});
	}*/
};

#endif // TREE_FWD_HP
