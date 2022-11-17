#ifndef TREE_NODE_HPP
# define TREE_NODE_HPP

#include <memory>

enum COLOR {
	BLACK,
	RED,
};

namespace ft {
 
	template<class T>
	class tree_node {

		public:
			typedef		T			value_type;
			typedef		tree_node*	node_pointer;

		public:
			node_pointer	left;
			node_pointer	right;
			node_pointer	parent;
			value_type		val;
			COLOR			color;
		
			tree_node() : val() {
				parent = NULL;
				left = NULL;
				right = NULL;
				color = RED;
			}

			tree_node( value_type val ) : val(val) {
				parent = NULL;
				left = NULL;
				right = NULL;
				color = RED;
			}
		
			// returns pointer to uncle
			node_pointer	uncle() {
				// If no parent or grandparent, then no uncle
				if (parent == NULL || parent->parent == NULL)
					return NULL;
				if (parent->isOnLeft()) // uncle on right
					return parent->parent->right;
				else // uncle on left
					return parent->parent->left;
			}
		
			// check if node is left child of parent
			bool	isOnLeft() { return this == parent->left; }
			
			// returns pointer to sibling
			node_pointer	sibling() {
				// sibling null if no parent
				if (parent == NULL)
					return NULL;
				if (isOnLeft())
					return parent->right;
				return parent->left;
			}
		
			// moves node down and moves given node in its place
			void	moveDown( node_pointer nParent ) {
				if (this->parent != NULL) {
					if (isOnLeft())
						parent->left = nParent;
					else
						parent->right = nParent;
				}
				nParent->parent = this->parent;
				this->parent = nParent;
			}
		
			bool	hasRedChild() {
				return ((left != NULL && left->color == RED) || (right != NULL && right->color == RED));
			}

	}; /* class tree_node */
} /* namespace ft */

#endif