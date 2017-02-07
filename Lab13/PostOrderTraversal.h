#ifndef POST_ORDER_TRAVERSAL
#define POST_ORDER_TRAVERSAL
#include <iostream>
#include "BinaryTreeTraversal.h"
using namespace std;

template <typename T>
class PostOrderTraversal : public BinaryTreeTraversal<T>
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

		//process right
		traverse(root->getRightChild());

		//process "us"
		cout << root->getValue() << " ";
	}
};

#endif