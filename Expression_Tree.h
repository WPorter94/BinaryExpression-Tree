//Copyright 2021
#ifndef EXPRESSION_TREE_H_
#define EXPRESSION_TREE_H_

#include <string>
#include <iosfwd>
#include "Binary_Tree.h"
#include <sstream>
using std::atoi;
/** Class to model an expression using a binary tree */
class Expression_Tree {
public:
	Expression_Tree() {}
	~Expression_Tree() {}
	void read_expression_tree(std::istream&);
	int evaluate() const;
private:
	int evaluate(const Binary_Tree<std::string>&) const;
	Binary_Tree<std::string> the_tree;

};

void Expression_Tree::read_expression_tree(std::istream& in) {
	in >> the_tree;
}
int Expression_Tree::evaluate() const {
	return evaluate(the_tree);
}
int Expression_Tree::evaluate(const Binary_Tree<std::string>& temp) const {
	int total = 0;
	if (temp.is_leaf() == true) {
		total = atoi(temp.get_data().c_str());
	}
	else
	 {

		int l = evaluate(temp.get_left_subtree());
		int r = evaluate(temp.get_right_subtree());

		char op = temp.get_data().at(0);


		switch (op) {

		case '+':
			total = l + r;
			break;
		case '-':
			total = l - r;
			break;
		case '*':
			total = l * r;
			break;
		case '/':
			total = l / r;
			break;
		/*case '^':
			total = l;
			for (int i = 0; i < r; i++) {
				total = total * l;
			}
			break;*/
		}
	}

	return total;
}

#endif
