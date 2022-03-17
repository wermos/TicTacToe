#ifndef TREE_HPP
#define TREE_HPP

#include "tree_fwd.hpp"

class Tree {
	public:
		Tree() = default;

		void addNode(NodeType* parent, NodeType* child) {
			parent->children.push_back(child);
			//child.computeWeight();
		}

	private:
		Node* m_head = nullptr;
};

#endif // TREE_HPP
