#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTreeTraversal.h"
#include "BstNode.h"
#include "Bag.h"
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;
template<typename T>
class BinarySearchTree : public Bag<T>
{
private:
	BstNode<T> *_root = nullptr;

	void deleteNode(BinaryNode<T> *node)
	{
		if (node != nullptr)
		{
			deleteNode(node->getLeftChild());
			deleteNode(node->getRightChild());
			delete node;
		}
	}

	//TODO: implement me!
	int getHeightHelper(BinaryNode<T> *root)
	{
		if (root == nullptr){
			return 0;
		}

		int left = getHeightHelper(root->getLeftChild());
		int right = getHeightHelper(root->getRightChild());

		/*if (left > right){
			return  left;
		}
		else{
			return right;
		}*/
		int max = std::max(left, right);
		return 1 + max;


	/*	BinaryNode<T>* left = root->getLeftChild();
		BinaryNode<T>* right = root->getRightChild();
		int max = std::max(left.getValue(), right.getValue());
		return 1 + max;*/

	}

	//TODO: implement me!
	int leafNodeHelper(BinaryNode<T> *root)
	{
		if (root == nullptr){
			return 0;
		}

		if (root->getLeftChild() == nullptr && root->getRightChild() == nullptr){
			return 1;
		}
		else{
			return leafNodeHelper(root->getLeftChild()) + leafNodeHelper(root->getRightChild());
		}
	}

	//TODO: implement me!
	int countSmallerThanHelper(BinaryNode<T> *root, T value)
	{


		int num = 0;
		stack<BinaryNode<T>*> stack;
		BinaryNode<T> *current = root;
		while (!stack.empty() || current){
			if (current){
				stack.push(current);
				current = current->getLeftChild();
			}
			else{
				current = stack.top();
				stack.pop();
				if (current->getValue() < value){
					num++;
				}
				current = current->getRightChild();
			}
		}
		return num;

	
	/*	if (root == nullptr)
		{
			return -1;
		}
		else if (value <= root->getValue())
		{
			return countSmallerThanHelper(root->getLeftChild(), value);
		}
		else if (value > root->getValue())
		{
			int t = countSmallerThanHelper(root->getRightChild(), value);
			return t > root->getValue() ? t : root->getValue();
		}

		return -1;*/
	}

	//TODO: implement me!
	string outputRangeHelper(BinaryNode<T> *root, T start, T end)
	{
		//int num = 0;
		stringstream s;
		stack<BinaryNode<T>*> stack;
		BinaryNode<T> *current = root;
		while (!stack.empty() || current){
			if (current){
				stack.push(current);
				current = current->getLeftChild();
			}
			else{
				current = stack.top();
				stack.pop();
				if (current->getValue() <= end && current->getValue()>=start){
				//	num++;
					s << current->getValue() << " ";
					//s = s + (current->getValue()).str();
				}
				current = current->getRightChild();
			}
		}
		return s.str();
	}

public:

	BinarySearchTree()
	{
	}

	~BinarySearchTree()
	{
		deleteNode(_root);
	}

	int getHeight()
	{
		return getHeightHelper(_root);
	}

	int getNumberOfLeafNodes()
	{
		return leafNodeHelper(_root);
	}

	int countSmallerThan(T value)
	{
		return countSmallerThanHelper(_root, value);
	}

	string outputRange(T begin, T end)
	{
		return outputRangeHelper(_root, begin, end);
	}

	void addElement(T value)
	{
		if (_root == nullptr)
		{
			_root = new BstNode<T>{};
			_root->setValue(value);
		}
		else
		{
			_root->addElement(value);
		}
	}

	virtual bool isEmpty() const
	{
		if (_root != nullptr)
		{
			return _root->isLeaf();
		}
		return false;
	}

	virtual int getSize() const
	{
		if (_root != nullptr)
		{
			return _root->getSize();
		}
		return 0;
	}

	void traverse(BinaryTreeTraversal<T> &traversal)
	{
		traversal.traverse(_root);
	}


	void removeElement(T item)
	{
		BstNode<T> *new_root = _root->removeElement(item);
		_root = new_root;
	}
};

#endif