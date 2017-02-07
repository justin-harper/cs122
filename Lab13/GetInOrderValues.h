#ifndef IN_ORDER_TRAVERSAL
#define IN_ORDER_TRAVERSAL

#include <iostream>
#include "BinaryTreeTraversal.h"
using namespace std;

template <typename T>
class InOrderTraversal : public BinaryTreeTraversal<T>
{
private:
	vector<T> _items;

public:

	vector<T> getItems()
	{
		return _items;
	}

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
		_items.push_back(root->getValue());

		//process right
		traverse(root->getRightChild());
	}
};

#endif