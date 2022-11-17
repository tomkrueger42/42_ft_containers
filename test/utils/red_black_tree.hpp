#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <iostream>
# include <memory>
# include <queue>

# include "log_colors.hpp"
# include "tree_node.hpp"
# include "../iterator/tree_iterator.hpp"
# include "../iterator/tree_reverse_iterator.hpp"
# include "pair.hpp"

/*
	Rules That Every Red-Black Tree Follows: 
	1.	Every node has a colour either red or black.
	2.	The root of the tree is always black.
	3.	There are no two adjacent red nodes (A red node cannot have a red parent or red child).
	4.	Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
	5.	All leaf nodes are black nodes. (NULL)
*/

namespace ft {

	template<class Value, class Compare, class Alloc = std::allocator<Value> >
	class RBTree {
		public:
			typedef				Value													value_type;

			typedef				tree_node<value_type>									Node;
			typedef				tree_node<value_type> *									node_pointer;

			typedef				Alloc													pair_allocator_type;
			typedef typename	Alloc::template rebind<Node>::other						node_allocator_type;
			typedef				Compare													key_compare;

			typedef				ft::tree_iterator<Node, value_type>						iterator;
			typedef				ft::tree_reverse_iterator<iterator>						reverse_iterator;
			typedef				ft::tree_iterator<Node, const value_type, value_type>	const_iterator;
			typedef				ft::tree_reverse_iterator<const_iterator>				const_reverse_iterator;

		private:
			Node					_end;
			node_pointer			_root;
			key_compare				_compare;
			node_allocator_type		_alloc_node;
			pair_allocator_type		_alloc_pair;
			
			// left rotates the given node
			void	leftRotate( node_pointer x ) {
				// new parent will be node's right child
				node_pointer	nParent = x->right;
			
				// update root if current node is root
				if (x == _root)
					_root = nParent;

				x->moveDown(nParent);

				// connect x with new parent's left element
				x->right = nParent->left;
				// connect new parent's left element with node
				// if it is not null
				if (nParent->left != NULL)
					nParent->left->parent = x;
			
				// connect new parent with x
				nParent->left = x;
			}
			
			void	rightRotate( node_pointer x ) {
				// new parent will be node's left child
				node_pointer	nParent = x->left;
			
				// update root if current node is root
				if (x == _root)
					_root = nParent;
			
				x->moveDown(nParent);
			
				// connect x with new parent's right element
				x->left = nParent->right;
				// connect new parent's right element with node
				// if it is not null
				if (nParent->right != NULL)
					nParent->right->parent = x;
			
				// connect new parent with x
				nParent->right = x;
			}
			
			void	swapColors( node_pointer x1, node_pointer x2 ) {
				COLOR	temp;
				temp = x1->color;
				x1->color = x2->color;
				x2->color = temp;
			}

			void	swapNodes( node_pointer u, node_pointer v ) {
				Node tmp_v;

				// swap these nodes
				tmp_v.parent = v->parent;
				tmp_v.left = v->left;
				tmp_v.right = v->right;
				v->left = u->left;
				v->right = u->right;
				v->parent = u->parent;
				if (tmp_v.left == u)
					u->left = v;
				else
					u->left = tmp_v.left;
				if (tmp_v.right == u)
					u->right = v;
				else
					u->right = tmp_v.right;
				u->parent = tmp_v.parent;

				// set childs parents
				if (v->left != NULL)
					v->left->parent = v;
				if (v->right != NULL)
					v->right->parent = v;
				if (u->left != NULL)
					u->left->parent = u;
				if (u->right != NULL)
					u->right->parent = u;

				if (u->parent != NULL && u->parent->left == v)
					u->parent->left = u;
				if (u->parent != NULL && u->parent->right == v)
					u->parent->right = u;
				if (v->parent != NULL && v->parent->left == u)
					v->parent->left = v;
				if (v->parent != NULL && v->parent->right == u)
					v->parent->right = v;

				if (v == getRoot())
					_root = u;
				else if (u == getRoot())
					_root = v;
			}
			
			// fix red red at given node
			void	fixRedRed( node_pointer x ) {
				// if x is root color, make it black and return
				if (x == _root) {
					x->color = BLACK;
					return;
				}
			
				// initialize parent, grandparent, uncle
				node_pointer	parent = x->parent;
				node_pointer	grandparent = parent->parent;
				node_pointer	uncle = x->uncle();
			
				if (parent->color == RED) {
					if (uncle != NULL && uncle->color == RED) {
						// uncle red, perform recoloring and recurse
						parent->color = BLACK;
						uncle->color = BLACK;
						grandparent->color = RED;
						fixRedRed(grandparent);
					}
					else {
						// Else perform LR, LL, RL, RR
						if (parent->isOnLeft()) {
							if (x->isOnLeft()) {
								// for left right
								swapColors(parent, grandparent);
							}
							else {
								leftRotate(parent);
								swapColors(x, grandparent);
							}
							// for left left and left right
							rightRotate(grandparent);
						}
						else {
							if (x->isOnLeft()) {
								// for right left
								rightRotate(parent);
								swapColors(x, grandparent);
							}
							else {
								swapColors(parent, grandparent);
							}
					
							// for right right and right left
							leftRotate(grandparent);
						}
					}
				}
			}
			
			// find node that do not have a left child
			// in the subtree of the given node
			node_pointer	successor( node_pointer x ) {
				node_pointer	temp = x;
			
				while (temp->left != NULL)
					temp = temp->left;
			
				return temp;
			}
			
			// find node that replaces a deleted node in BST
			node_pointer	BSTreplace( node_pointer x ) {
				// when node have 2 children
				if (x->left != NULL && x->right != NULL)
					return successor(x->right);
			
				// when leaf
				if (x->left == NULL && x->right == NULL)
					return NULL;
			
				// when single child
				if (x->left != NULL)
					return x->left;
				else
					return x->right;
			}
			
			// deletes the given node
			void	deleteNode( node_pointer v ) {
				// LOG_CYAN("TO DELETE :" << v->val.first);
				node_pointer	u = BSTreplace(v);

				// True when u and v are both black
				bool	uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK));
				node_pointer	parent = v->parent;

				if (u == NULL) {
					// u is NULL therefore v is leaf
					if (v == _root) {
						// v is root, making root null
						_root = NULL;
					}
					else {
						if (uvBlack) {
							// u and v both black
							// v is leaf, fix double black at v
							fixDoubleBlack(v);
						}
						else {
							// u or v is red
							if (v->sibling() != NULL) {
								// sibling is not null, make it red"
								v->sibling()->color = RED;
							}
						}
						// delete v from the tree
						if (v->isOnLeft())
							parent->left = NULL;
						else
							parent->right = NULL;
					}
					_alloc_node.deallocate(v, 1);
					return;
				}
				if (v->left == NULL || v->right == NULL) {
					// v has 1 child
					if (v == _root) {
						// v is root, assign the value of u to v, and delete u
						_alloc_pair.construct(&v->val, u->val);
						// v->val = u->val;
						v->left = v->right = NULL;
						_alloc_node.deallocate(u, 1);
					}
					else {
						// Detach v from tree and move u up
						if (v->isOnLeft())
							parent->left = u;
						else
							parent->right = u;
						_alloc_node.deallocate(v, 1);
						u->parent = parent;
						if (uvBlack) {
							// u and v both black, fix double black at u
							fixDoubleBlack(u);
						}
						else {
							// u or v red, color u black
							u->color = BLACK;
						}
					}
					return;
				}
				// v has 2 children, swap values with successor and recurse
				swapNodes(u, v);
				deleteNode(v);
			}
			
			void	fixDoubleBlack( node_pointer x ) {
				if (x == _root) {
					// Reached root
					return;
				}
			
				node_pointer	sibling = x->sibling();
				node_pointer	parent = x->parent;
				if (sibling == NULL) {
					// No sibiling, double black pushed up
					fixDoubleBlack(parent);
				}
				else {
					if (sibling->color == RED) {
						// Sibling red
						parent->color = RED;
						sibling->color = BLACK;
						if (sibling->isOnLeft()) {
							// left case
							rightRotate(parent);
						}
						else {
							// right case
							leftRotate(parent);
						}
						fixDoubleBlack(x);
					}
					else {
						// Sibling black
						if (sibling->hasRedChild()) {
							// at least 1 red children
							if (sibling->left != NULL && sibling->left->color == RED) {
								if (sibling->isOnLeft()) {
									// left left
									sibling->left->color = sibling->color;
									sibling->color = parent->color;
									rightRotate(parent);
								}
								else {
									// right left
									sibling->left->color = parent->color;
									rightRotate(sibling);
									leftRotate(parent);
								}
							}
							else {
								if (sibling->isOnLeft()) {
									// left right
									sibling->right->color = parent->color;
									leftRotate(sibling);
									rightRotate(parent);
								}
								else {
									// right right
									sibling->right->color = sibling->color;
									sibling->color = parent->color;
									leftRotate(parent);
								}
							}
							parent->color = BLACK;
						}
						else {
							// 2 black children
							sibling->color = RED;
							if (parent->color == BLACK)
								fixDoubleBlack(parent);
							else
								parent->color = BLACK;
						}
					}
				}
			}
			
			// prints level order for given node
			void	levelOrder( node_pointer x ) {
				if (x == NULL) {
					// return if node is null
					return;
				}
			
				// queue for level order
				std::queue<node_pointer>	q;
				node_pointer				curr;
			
				// push x
				q.push(x);
			
				while (!q.empty()) {
					// while q is not empty
					// dequeue
					curr = q.front();
					q.pop();
				
					// print node value
					std::cout << curr->val << " ";
				
					// push children to queue
					if (curr->left != NULL)
						q.push(curr->left);
					if (curr->right != NULL)
						q.push(curr->right);
				}
			}

			void	inorder( node_pointer x ) {
				if (x == NULL)
					return;
				inorder(x->left);
				std::cout << x->val.first <<  "/" << x->val.second << std::endl;
				inorder(x->right);
			}

			bool	hintIsUseful( value_type n, node_pointer pos ) {
				if ((_compare(n, _root->val) && _compare(pos->val, _root->val)) || (_compare(_root->val, n) && _compare(_root->val, pos->val))) {
					if ((!pos->isOnLeft() && _compare(pos->parent->val, n)) || (pos->isOnLeft() && _compare(n, pos->parent->val))) {
						if ((!pos->parent->isOnLeft() && (_compare(pos->parent->parent->val, n) || pos->parent == _root)) || 
							(pos->parent->isOnLeft() && (_compare(n, pos->parent->parent->val) || pos->parent == _root))) {
								return true;
							}
					}
				}
				return false;
			}
		
		public:
			/* constructor */
			RBTree() { _root = NULL; }

			/* operator overload */
			RBTree &		operator=( const RBTree &in ) {
				_alloc_pair.construct(&this->_end.val, in._end.val);
				this->_end.left = in._end.left;
				this->_end.right = in._end.right;
				this->_end.parent = in._end.parent;
				this->_end.color = in._end.color;
				this->_root = in._root;
				this->_root->parent = &_end;
				this->_compare = in._compare;
				this->_alloc_node = in._alloc_node;
				this->_alloc_pair = in._alloc_pair;
				return *this;
			}

			/* iterator */
			reverse_iterator 		rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }

			reverse_iterator		rend() { return reverse_iterator(begin()); }
			const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

			iterator				end() {
				if (_root == NULL) {
					return iterator(&_end);
				}
				return iterator(&_end);
			}

			const_iterator			end() const {
				if (_root == NULL) {
					return const_iterator(_root);
				}
				return const_iterator(_root->parent);
			}

			iterator				begin() {
				if (_root == NULL)
					return iterator(_root);
				node_pointer	tmp = _root;
				while (tmp->left != NULL)
					tmp = tmp->left;
				return iterator(tmp);
			}

			const_iterator			begin() const {
				if (_root == NULL)
					return const_iterator(_root);
				node_pointer	tmp = _root;
				while (tmp->left != NULL)
					tmp = tmp->left;
				return const_iterator(tmp);
			}
			/* iterator */
			
			int				erase( iterator position ) { return deleteByVal(*position); }

			node_pointer	getRoot() const { return _root; }

			size_t			max_size() const { return _alloc_node.max_size(); }
			
			// searches for given value
			// if found returns the node (used for delete)
			// else returns the last node while traversing (used in insert)
			node_pointer	search( value_type n, const node_pointer start ) const {
				node_pointer	temp = start;
				while (temp != NULL) {
					if (_compare(n, temp->val)) {
						if (temp->left == NULL)
							break;
						else
							temp = temp->left;
					}
					else if (!_compare(n, temp->val) && !_compare(temp->val, n)) {
						break;
					}
					else {
						if (temp->right == NULL)
							break;
						else
							temp = temp->right;
					}
				}
				return temp;
			}
			
			// inserts the given value to tree
			ft::pair<iterator, bool>	insert( value_type n ) {
				node_pointer	newNode = _alloc_node.allocate(1);
				_alloc_pair.construct(&newNode->val, n);
				newNode->left = NULL;
				newNode->right = NULL;
				newNode->parent = NULL;
				newNode->color = RED;
				if (_root == NULL) {
					// when root is null
					// simply insert value at root
					newNode->color = BLACK;
					_root = newNode;
					_root->parent = &_end;
					_end.left = _root;
					_end.right = NULL;
				}
				else {
					node_pointer	temp = search(n, _root);
				
					if (!_compare(temp->val, n) && !_compare(n, temp->val)) {
						// return if value already exists
						_alloc_node.deallocate(newNode, 1);
						return (ft::make_pair<iterator, bool>(iterator(temp), false));
					}
				
					// if value is not found, search returns the node
					// where the value is to be inserted
				
					// connect new node to correct node
					newNode->parent = temp;
				
					if (_compare(n, temp->val))
						temp->left = newNode;
					else
						temp->right = newNode;
				
					// fix red red voilaton if exists
					fixRedRed(newNode);
				}
				return (ft::make_pair<iterator, bool>(iterator(newNode), true));
			}

			// inserts the given value to tree
			ft::pair<iterator, bool>	insert_hint( value_type n, node_pointer pos ) {
				node_pointer	newNode = _alloc_node.allocate(1);
				_alloc_pair.construct(&newNode->val, n);
				newNode->color = RED;
				newNode->left = NULL;
				newNode->right = NULL;
				newNode->parent = NULL;
				if (_root == NULL) {
					// when root is null
					// simply insert value at root
					newNode->color = BLACK;
					_root = newNode;
					_root->parent = &_end;
					_end.left = _root;
					_end.right = NULL;
				}
				else {
					node_pointer	temp;
					if (hintIsUseful(n, pos))
						temp = search(n, pos);
					else
						temp = search(n, _root);
				
					if (!_compare(temp->val, n) && !_compare(n, temp->val)) {
						// return if value already exists
						_alloc_node.deallocate(newNode, 1);
						return (ft::make_pair<iterator, bool>(iterator(temp), false));
					}
				
					// if value is not found, search returns the node
					// where the value is to be inserted
				
					// connect new node to correct node
					newNode->parent = temp;
				
					if (_compare(n, temp->val))
						temp->left = newNode;
					else
						temp->right = newNode;
				
					// fix red red voilaton if exists
					fixRedRed(newNode);
				}
				return (ft::make_pair<iterator, bool>(iterator(newNode), true));
			}
			
			// utility function that deletes the node with given value
			int	deleteByVal( value_type n ) {
				if (_root == NULL) {
					// Tree is empty
					return 0;
				}
			
				node_pointer	v = search(n, _root);
				// node_pointer	u;
			
				if (!(!_compare(v->val, n) && !_compare(n, v->val))) {
					// No node found to delete
					return 0;
				}
			
				deleteNode(v);
				return 1;
				// _end->left = _root;
			}

			/* print functions */
			void	print_rb_tree(const std::string & prefix, node_pointer x, bool isleft) const {
				if (x) {
					std::cout << prefix;
					std::cout << (isleft ? "├──" : "└──");
					if (x->color == BLACK)
						std::cout << "\033[1;30m" << x->val.first << "\033[0m";
					else
						std::cout << "\033[1;31m" << x->val.first << "\033[0m";
					std::cout << std::endl;
					print_rb_tree(prefix + (isleft ? "│   " : "    "), x->left, true);
					print_rb_tree(prefix + (isleft ? "│   " : "    "), x->right, false);
				}
			}

			// prints inorder of the tree
			void	printInOrder() {
				std::cout << "Inorder: " << std::endl;
				if (_root == NULL)
					std::cout << "Tree is empty" << std::endl;
				else {
					inorder(_root);
					std::cout << std::endl;
				}
			}
			
			// prints level order of the tree
			void	printLevelOrder() {
				std::cout << "Level order: " << std::endl;
				if (_root == NULL)
					std::cout << "Tree is empty" << std::endl;
				else {
					levelOrder(_root);
					std::cout << std::endl;
				}
			}
			/* print functions */
	}; /* class tree */

} /* namespace ft */

#endif