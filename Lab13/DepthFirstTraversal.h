#ifndef DEPTH_FIRST_TRAVERSAL
#define DEPTH_FIRST_TRAVERSAL

#include <iostream>
#include <stack>
#include "BinaryTreeTraversal.h"
using namespace std;

template <typename T>
class DepthFirstTraversal : public BinaryTreeTraversal<T>
{
public:
	virtual void traverse(BinaryNode<T> *root)
	{

		//null node check
		if (root == nullptr)
		{
			return;
		}

		stack<BinaryNode<T> *> to_visit{};
		to_visit.push(root);
		while (to_visit.size() > 0)
		{
			BinaryNode<T> *current = to_visit.top();
			to_visit.pop();
			
			//AC Note: flip the order of these IF statements to convert into a Pre-order traversal (U-L-R)
			if (current->getLeftChild() != nullptr)
			{
				to_visit.push(current->getLeftChild());
			}
			if (current->getRightChild() != nullptr)
			{
				to_visit.push(current->getRightChild());
			}

			//output us
			cout << current->getValue() << " ";
		}
	}
};

#endif