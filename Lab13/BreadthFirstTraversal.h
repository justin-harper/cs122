#ifndef BREADTH_FIRST_TRAVERSAL
#define BREADTH_FIRST_TRAVERSAL

#include <iostream>
#include <queue>
#include "BinaryTreeTraversal.h"
using namespace std;

template <typename T>
class BreadthFirstTraversal : public BinaryTreeTraversal<T>
{
public:
	virtual void traverse(BinaryNode<T> *root)
	{

		//null node check
		if (root == nullptr)
		{
			return;
		}

		queue<BinaryNode<T> *> to_visit{};
		to_visit.push(root);
		while (to_visit.size() > 0)
		{
			BinaryNode<T> *current = to_visit.front();
			to_visit.pop();
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