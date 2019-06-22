//==============================================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 1
// Problem Statement: Construct and expression tree from postfix/prefix expression and perform
//                    recursive and non- recursive In-order, pre-order and post-order traversals.
//==============================================================================================

#ifndef STACK_H_
#define STACK_H_

template<class T>
class stack
{
	 struct node
	{
		T data;
		struct node* link;
	};

	node* top;
	int count;

public:
	stack();
	void push(T);
	T pop();
	bool isEmpty();
	void stackCount();
	T peep();
	void display();
	virtual ~stack();
};

#endif /* STACK_H_ */






