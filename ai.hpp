#ifndef AI_HPP
#define AI_HPP

#include <limits>
#include <cstdint> // for std::int8_t
#include <iostream>

#include "enum.hpp"
#include "node.hpp"
#include "board.hpp"

class AI {
	public:
		AI() = default;

		void setMove(const Move m) {
			m_move = m;
			if (m_move == Move::X) {
				m_opponentMove = Move::O;
			} else {
				m_opponentMove = Move::X;
			}
		}

		std::size_t bestMove(Board currentBoard) {
			currentState.board = currentBoard;
			minimax(&currentState, neg_inf, pos_inf, 0, true);
			return bestMoveIndex;
		}

		std::int8_t minimax(
				Node* node, std::int8_t alpha, std::int8_t beta,
				std::size_t depth, bool maximizingPlayer) {
			if (node->board.isFull() || node->board.state() != State::None) {
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

					for (auto& index : node->board.emptyCells()) {
						Board newBoard = node->board; // making a deep copy
						newBoard.setCell(index, m_move);
						std::cout << "Trial:\n";
						newBoard.print();
						std::cout << "\n";
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
						std::cout << "Value: " << value << '\n';
					}
				} else { // minimizing player
					value = pos_inf;

					for (auto& index : node->board.emptyCells()) {
						Board newBoard = node->board; // making a deep copy
						newBoard.setCell(index, m_opponentMove);
						std::cout << "Trial:\n";
						newBoard.print();
						std::cout << "\n";
						Node childNode(node, {}, neg_inf, newBoard);
						node->children.push_back(&childNode);

						value = std::min(value, minimax(&childNode, alpha, value, depth + 1, true));

						std::cout << "Value: " << value << '\n';
						// std::cout << "inside while loop minimizing\n";
					}
				}	
				return value;
			}
		}

	private:
		Node currentState;
		std::size_t bestMoveIndex;
		Move m_move;
		Move m_opponentMove;
		const static std::int8_t neg_inf = std::numeric_limits<std::int8_t>::min();
		const static std::int8_t pos_inf = std::numeric_limits<std::int8_t>::max();
};

#endif // AI_HPP
