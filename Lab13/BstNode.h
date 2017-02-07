#ifndef BST_NODE_H
#define BST_NODE_H

#include "BinaryNode.h"
#include "Bag.h"
template <typename T>
class BstNode : public BinaryNode<T>, public Bag<T>
{
private:

	//counter used to determine if we should remove from the left or the right
	int _remove_counter = 0;

	BstNode<T> *getLeftBstChild()
	{
		return dynamic_cast<BstNode *>(getLeftChild());
	}

	const BstNode<T> *getLeftBstChild() const
	{
		return dynamic_cast<const BstNode *>(getLeftChild());
	}

	BstNode<T> *getRightBstChild()
	{
		return dynamic_cast<BstNode *>(getRightChild());
	}

	const BstNode<T> *getRightBstChild() const
	{
		return dynamic_cast<const BstNode *>(getRightChild());
	}

public:

	//removes the smallest value from the BST
	BstNode<T> * removeSmallest()
	{
		//are we the smallest
		if (getLeftChild() == nullptr)
		{
			BstNode<T> *result = nullptr;

			//do we have a right child?
			if (getRightChild() != nullptr)
			{
				result = getRightBstChild();
			}
			delete this;

			//returning a result allows parent nodes to be reconfigured when
			//one of their children gets deleted.
			return result;
		}
		else
		{
			setLeftChild(getLeftBstChild()->removeSmallest());
		}
	}

	//removes the smallest value from the BST
	BstNode<T> * removeLargest()
	{
		//are we the largest
		if (getRightChild() == nullptr)
		{
			BstNode<T> *result = nullptr;

			//do we have a left child?
			if (getLeftChild() != nullptr)
			{
				result = getLeftBstChild();
			}
			delete this;

			//returning a result allows parent nodes to be reconfigured when
			//one of their children gets deleted.
			return result;
		}
		else
		{
			setRightChild(getRightBstChild()->removeLargest());
		}
	}

	T& getSmallestValueRec()
	{
		//do we not have a left child?
		if (getLeftBstChild() == nullptr)
		{
			return getValue();
		}
		else
		{
			return getLeftBstChild()->getSmallestValueRec();
		}
	}

	T& getLargestValueRec()
	{
		//do we not have a right child?
		if (getRightBstChild() == nullptr)
		{
			return getValue();
		}
		else
		{
			return getRightBstChild()->getLargestValueRec();
		}
	}

	T& getSmallestValue()
	{
		BstNode<T> *current = this;
		while (current->getLeftBstChild() != nullptr)
		{
			current = current->getLeftBstChild();
		}
		return current->getValue();
	}

	T& getLargestValue()
	{
		BstNode<T> *current = this;
		while (current->getRightBstChild() != nullptr)
		{
			current = current->getRightBstChild();
		}
		return current->getValue();
	}

	virtual void addElement(T item)
	{
		BstNode<T> *node = new BstNode<T>{};
		node->setValue(item);
		return addChild(node);
	}

	virtual BstNode<T>* removeElement(T item)
	{
		//are we the item to remove?
		if (getValue() == item)
		{
			_remove_counter++;

			//when %2 == 1, remove from the left.  Otherwise, remove from the right
			if (_remove_counter % 2)
			{
				//get largest value from our left child, if possible
				if (getLeftChild() != nullptr)
				{
					setValue(getLeftBstChild()->getLargestValue());
					getLeftBstChild()->removeLargest();
					return this;
				}
				else
				{
					//else: we only have one child.  Delete us and return our right child.
					//Note: this should work even when we don't have a right child.
					BstNode<T> *result = getRightBstChild();
					delete this;
					return result;
				}
			}
			else
			{
				//pull smallest value from right child, if possible
				if (getRightChild() != nullptr)
				{
					setValue(getRightBstChild()->getSmallestValue());
					getRightBstChild()->removeSmallest();
					return this;
				}
				else
				{
					BstNode<T> *result = getLeftBstChild();
					delete this;
					return result;
				}
			}
		}
		//we're not the item to remove
		else if (getValue() > item)
		{
			//are we larger than the item?  Send to the left
			setLeftChild(getLeftBstChild()->removeElement(item));
		}
		else
		{
			//we must be smaller than the item, send to right child
			setRightChild(getRightBstChild()->removeElement(item));
		}
		return this;
	}

	virtual bool isEmpty() const
	{
		return false;
	}

	virtual int getSize() const
	{
		int count = 0;
		if (isLeaf() == true)
		{
			count = 1;
		}
		else
		{
			if (getRightChild() != nullptr)
			{
				count += 1 + getRightBstChild()->getSize();
			}
			if (getLeftChild() != nullptr)
			{
				count += 1 + getLeftBstChild()->getSize();
			}
		}
		return count;
	}

	virtual void addChild(BstNode<T> *node)
	{
		//guard against null values
		if (node == nullptr)
		{
			return;
		}

		//is the new node's value less than us?
		if (getValue() > node->getValue())
		{
			//do we already have a left child?
			if (getLeftChild() != nullptr)
			{
				//if so, send off to the child
				getLeftBstChild()->addChild(node);
			}
			else
			{
				//guess not.  In this case, this node will be our left child
				setLeftChild(node);
			}
		}
		else
		{
			//ELSE: the new node's value is greater than us
			//do we already have a right child?
			if (getRightChild() != nullptr)
			{
				//if so, send off to our child
				getRightBstChild()->addChild(node);
				//getRightBstChild()->addChild(node);
			}
			else
			{
				//guess not.  Make this node our new right child
				setRightChild(node);
			}
		}
	}
};

#endif