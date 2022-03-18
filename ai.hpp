#ifndef AI_HPP
#define AI_HPP

#include <limits>
#include <cstdint> // for std::int8_t
#include <iostream>

#include "tic_tac_toe_enum.hpp"
#include "node.hpp"
#include "board.hpp"
#include "player.hpp"

class AI : public Player {
	public:
		AI() = default;

		std::size_t bestMove(Board currentBoard) {
			currentState.board = currentBoard;
			minimax(&currentState, neg_inf, pos_inf, 0, false);
			return bestMoveIndex;
		}

		std::int8_t minimax(
				Node* node, std::int8_t alpha, std::int8_t beta,
				std::size_t depth, bool maximizingPlayer) {
			if (node->board.isFull() || node->board.checkWin() != State::None) {
				if (maximizingPlayer) {
					// std::cout << "inside termination condition\n";
					return node->terminalNodeWeight(m_move);
				} else {
					// std::cout << "inside termination condition\n";
					return node->terminalNodeWeight(m_opponentMove); 
				}
			} else {
				std::int8_t value;
				if (maximizingPlayer) {
					value = neg_inf;

					Board newBoard;
					for (auto& index : node->board.emptyCells()) {
						newBoard = node->board; // making a deep copy
						newBoard.setCell(index, m_move);
						// newBoard.printBoard();
						Node childNode(node, {}, neg_inf, newBoard);
						node->children.push_back(&childNode);

						std::int8_t newWeight = minimax(&childNode, value, beta, depth + 1, false);
						if (newWeight > value) {
							// The AI is the maximizing player, so we only care about
							// our best move. We don't care what the best move for the
							// player is.
							bestMoveIndex = index;
							value = newWeight;
						}
						// std::cout << "inside while loop maximizing\n";
					}
				} else { // minimizing player
					value = pos_inf;

					Board newBoard;
					for (auto& index : node->board.emptyCells()) {
						newBoard = node->board; // making a deep copy
						newBoard.setCell(index, m_opponentMove);
						// newBoard.printBoard();
						Node childNode(node, {}, neg_inf, newBoard);
						node->children.push_back(&childNode);

						value = std::min(value, minimax(&childNode, alpha, value, depth + 1, true));

						// std::cout << "inside while loop minimizing\n";
					}
				}	
				return value;
			}
		}

	private:
		Node currentState;
		std::size_t bestMoveIndex;
		const static std::int8_t neg_inf = std::numeric_limits<std::int8_t>::min();
		const static std::int8_t pos_inf = std::numeric_limits<std::int8_t>::max();
};

#endif // AI_HPP
