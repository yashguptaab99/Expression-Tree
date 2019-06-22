//============================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 1
// Problem Statement: Construct and expression tree from postfix/prefix expression and perform
//                    recursive and non- recursive In-order, pre-order and post-order traversals.
//============================================================================

#include <iostream>
using namespace std;
#include "expTree.h"

int main()
{
	char postfix[50]={};
	char prefix[50]={};
	tree t;
	char ch;
	do
	{

		cout<<"\n\n\t****Welcome Menu!****"<<endl;
		cout<<"\n\n\t1.Postfix expression\n\n\t2.Prefix expression\n\n\t3.Display iterative\n\n\t4.Display recursive\n\n\t5.Exit"<<endl;
		cout<<"\nEnter your choice :";
		cin>>ch;
		switch(ch)
		{
			case '1':
				cout<<"\n\t\tEnter postfix :";
				cin>>postfix;
				t.construct_tree_postorder(postfix);
				break;
			case '2':
				cout<<"\n\t\tEnter prefix :";
				cin>>prefix;
				t.construct_tree_preorder(prefix);
				break;
			case '3':
				t.display_iterative();
				break;
			case '4':
				t.display_rec();
				break;
			case '5':
				cout<<"\n\n\t\tExiting...."<<endl;
				break;
			default:
				cout<<"\n\n\t\tInvalid choice please enter correct choice!!!!!!!";
				break;
		}
	}while(ch!='5');
	return 0;
}
