//============================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 1
// Problem Statement: Construct and expression tree from postfix/prefix expression and perform
//                    recursive and non- recursive In-order, pre-order and post-order traversals.
//============================================================================

#ifndef TREE_H
#define TREE_H
#include "stack.cpp"
#include<string>

struct node_tree
{
	node_tree *left;
	node_tree *right;
	char data;
};

class tree
{
	node_tree *root;
	node_tree *temp;
	stack <node_tree*>s;
	public:

		tree();
		~tree();

		void display_iterative();
		void construct_tree_preorder(char[]);
		void display_rec();

		int validity(node_tree*,int);
		int isValid1(char[]);
		int isValid(char[]);
		int isOperator(char);
		int isOperand(char);

		void inorder_rec(node_tree*);
		void postorder_rec(node_tree*);
		void preorder_rec(node_tree*);
		void preorder_non_recurs(node_tree*);
		int length(char[]);
		node_tree * create(char);
		void inorder_non_recurs(node_tree*);
		void construct_tree_postorder(char[]);
		void postrder_non_recurs(node_tree*);
};

#endif
