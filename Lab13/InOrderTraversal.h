#ifndef IN_ORDER_TRAVERSAL
#define IN_ORDER_TRAVERSAL

#include <iostream>
#include "BinaryTreeTraversal.h"
using namespace std;

template <typename T>
class InOrderTraversal : public BinaryTreeTraversal<T>
{
public:
	virtual void traverse(BinaryNode<T> *root)
	{
		//null node check
		if (root == nullptr)
		{
			return;
		}

		//process left
		traverse(root->getLeftChild());

		//process "us"
		cout << root->getValue() << " ";

		//process right
		traverse(root->getRightChild());
	}
};

#endif