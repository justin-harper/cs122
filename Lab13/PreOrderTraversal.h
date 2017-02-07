#ifndef PRE_ORDER_TRAVERSAL
#define PRE_ORDER_TRAVERSAL
#include <iostream>
#include "BinaryTreeTraversal.h"
using namespace std;
template <typename T>
class PreOrderTraversal : public BinaryTreeTraversal<T>
{
public:
	virtual void traverse(BinaryNode<T> *root)
	{
		//make sure root isn't null
		if (root == nullptr)
		{
			return;
		}

		//we visit "us"
		cout << root->getValue() << " ";

		//we visit the "left"
		traverse(root->getLeftChild());

		//we visit the "right"
		traverse(root->getRightChild());
	}
};

#endif