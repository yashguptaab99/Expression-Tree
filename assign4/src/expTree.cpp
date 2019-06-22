//============================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 1
// Problem Statement: Construct an expression tree from postfix/prefix expression and perform
//                    recursive and non- recursive In-order, pre-order and post-order traversals.
//============================================================================

#include "expTree.h"
#include<string>
#include<iostream>
#include<malloc.h>
using namespace std;
#include "stack.h"

int tree::length(char postfix[50])
{
	int i=0;
	while(postfix[i]!='\0')
	{
		i++;
	}
	return i;
}

node_tree* tree:: create(char x)
{
	node_tree *p=new node_tree;
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
int isoperator(char x)
{
      if(  (x== '+') || (x == '-') || (x == '*') || (x == '/') || (x == '^')  )
            return 1;
      else
            return 0;
}

void tree :: construct_tree_postorder(char postfix[50])
{
	int v,len;
	stack<node_tree*>s;
	node_tree *temp;
	len = length(postfix);
	int i=0;
	while(postfix[i]!='\0')
	{
		char x=postfix[i];

		if(!isoperator(x))
		{
			temp=create(x);
			s.push(temp);
		}
		else
		{
			temp=create(x);
			temp->right=s.pop();
			temp->left=s.pop();
			s.push(temp);
		}
		i++;
	}
	root=s.pop();
	v=validity(root,len);
	if(v==0)
	{
		root = NULL;
	}
}

void tree :: construct_tree_preorder(char prefix[50])
{
	int v;
	stack<node_tree*>s;
	node_tree *temp=NULL;
	int i=0;
		int len=length(prefix);

		for(i=len-1;i>=0;i--)
		{
			char x=prefix[i];
			if(!isoperator(x))
			{
				temp=create(x);
				s.push(temp);
			}
			else
			{
				temp=create(x);
				temp->left=s.pop();
				temp->right=s.pop();
				s.push(temp);
			}
		}
		root=s.pop();
		v=validity(root,len);
		if(v==0)
		{
			root = NULL;
		}
}

int tree::validity(node_tree* temp,int len)
{
	int i=0,len1;
	char infix[50]={};
	temp = root;
	stack<node_tree*> stack;
	if(temp == NULL)
	{
		cout<<"Empty Tree/n";
	}
	while(temp != NULL || stack.isEmpty() == 0)
	{
		while(temp != NULL)
		{
			stack.push(temp);
			temp = temp->left;
		}
		if(stack.isEmpty() == 0)
		{
			temp = stack.pop();
			infix[i]=temp->data;
			i++;
		}
		temp = temp->right;
	}

	len1 = length(infix);
	if(isValid(infix)==1)
	{
		if(isValid1(infix)==1 && len==len1)
		{
			cout<<"\n\tExpression Accepted Successfully\n";
			return 1;
		}
		else
		{
			cout<<"\n\tERROR : INVALID EXPRESSION\n";
			return 0;
		}
	}
	else
	{
		cout<<"\n\tERROR : INVALID EXPRESSION\n";
		return 0;
	}

}

int tree :: isOperator(char temp)
{
	if(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^' || temp == '%')
	{
		return 1;
	}
	else
		return 0;
}

int tree :: isOperand(char temp)
{
	if(((float)temp>=65 && (float)temp<=90) || ((float)temp>=97 && (float)temp<=122))
	{
		return 1;
	}
	else
		return 0;
}

int tree :: isValid(char exp[50])
{
	int cnt_openb=0;
	int cnt_closeb=0;
	int cnt_operand=0;
	int cnt_operator =0;
	int exp_size = length(exp);
	if(exp == NULL)
	{
		cout<<"\tExpression not entered\nPlease enter the expression first\n";
		return 0;
	}
	else
	{
		int loop_pf=0;
		while(loop_pf<exp_size)
		{
			if(exp[loop_pf]==')')
			{
				cnt_closeb++;
			}
			else if(exp[loop_pf] == '(')
			{
				cnt_openb++;
			}

			if(isOperand(exp[loop_pf])==1)
			{
				cnt_operand++;
			}
			else if(isOperator(exp[loop_pf])==1)
			{
				cnt_operator++;
			}

			if(isOperand(exp[loop_pf])||isOperator(exp[loop_pf]) || exp[loop_pf] == '(' || exp[loop_pf] == ')')
			{
				loop_pf++;
			}
			else
				break;
		}
		if((loop_pf == exp_size) && (cnt_openb == cnt_closeb) && (cnt_operand == (cnt_operator+1)))
		{
			return 1;
		}
		else
			return 0;
	}
}

int tree :: isValid1(char exp[50])
{
	int loop_pf = 1;
	int exp_size = length(exp);
	while(loop_pf<exp_size)
	{
		if(isOperand(exp[loop_pf-1]) && isOperand(exp[loop_pf]))
		{
			return 0;
		}
		if(isOperator(exp[loop_pf-1]) && isOperator(exp[loop_pf]))
		{
			return 0;
		}
		loop_pf++;
	}
	return 1;
}
void tree::inorder_rec(node_tree* temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		if(temp!=NULL)
		{
			inorder_rec(temp->left);
			cout<<temp->data;
			inorder_rec(temp->right);
		}
	}

}

void tree::preorder_rec(node_tree* temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{

		if(temp!=NULL)
		{
			cout<<temp->data;
			preorder_rec(temp->left);
			preorder_rec(temp->right);
		}
	}
}

void tree::	postorder_rec(node_tree* temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		if(temp!=NULL)
		{
			postorder_rec(temp->left);
			postorder_rec(temp->right);
			cout<<temp->data;
		}
	}
}
void tree::display_rec()
{
	temp=root;
	cout<<"\n\n\t\tInorder   :";
	inorder_rec(temp);
	temp=root;
	cout<<"\n\n\t\tPreorder  :";
	preorder_rec(temp);
	temp=root;
	cout<<"\n\n\t\tPostorder :";
	postorder_rec(temp);
}
void tree :: inorder_non_recurs(node_tree *root)
{
	node_tree *temp;
	temp = root;
	stack<node_tree*> stack;
	if(temp == NULL)
	{
		cout<<"Empty Tree/n";
	}
	while(temp != NULL || stack.isEmpty() == 0)
	{
		while(temp != NULL)
		{
			stack.push(temp);
			temp = temp->left;
		}
		if(stack.isEmpty() == 0)
		{
			temp = stack.pop();
			cout<<temp->data;
		}
		temp = temp->right;
	}
}

void tree :: preorder_non_recurs(node_tree *root)
{
	node_tree *temp;
	temp = root;
	stack<node_tree*> stack;
	if(temp == NULL)
	{
		cout<<"Empty Tree/n";
	}
	while(temp != NULL || stack.isEmpty() == 0)
	{
		while(temp != NULL)
		{
			cout<<temp->data;
			stack.push(temp);
			temp = temp->left;
		}
		if(stack.isEmpty() == 0)
		{
			temp = stack.pop();
		}
		temp = temp->right;
	}
}

void tree :: postrder_non_recurs(node_tree *root)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{

		stack<node_tree*>s1;
		node_tree*temp=root;
		node_tree*previous=NULL;
		if(temp==NULL)
		{
			cout<<"\nEmpty tree";
			return;
		}

		s1.push(temp);
		while(! s1.isEmpty())
		{

			temp=s1.pop();
			if(temp->left==NULL && temp->right==NULL)
			{
				previous =temp;
				cout<<temp->data;
			}
			else if(temp->left==previous || temp->right==previous)
			{
				previous=temp;
				cout<<temp->data;
			}
			else
			{
				s1.push(temp);
				if(temp->right != NULL)
					s1.push(temp->right);
				if(temp->left != NULL)
					s1.push(temp->left);
			}
		}
	}
}

void tree::display_iterative()
{
	cout<<"\n\n\t\tInorder    :";
	inorder_non_recurs(root);
	cout<<"\n\n\t\tPre order  :";
	preorder_non_recurs(root);
	cout<<"\n\n\t\tPost order :";
	postrder_non_recurs(root);

}
tree::tree()
{
	root=NULL;
	temp=NULL;
}
tree::~tree()
{
}
