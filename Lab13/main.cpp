#include <iostream>
#include <string>
#include <istream>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include "BinaryNode.h"
#include "RandomNumberGenerator.h"
#include "InOrderTraversal.h"
#include "PreOrderTraversal.h"
#include "BstNode.h"
#include "BinarySearchTree.h"
#include "PostOrderTraversal.h"
#include "BreadthFirstTraversal.h"
#include "DepthFirstTraversal.h"
using namespace std;

int main()
{
	BinarySearchTree<int> tree{};
	tree.addElement(100);
	tree.addElement(75);
	tree.addElement(50);
	tree.addElement(25);
	tree.addElement(65);
	tree.addElement(85);
	tree.addElement(150);
	tree.addElement(125);
	tree.addElement(175);
	tree.addElement(110);
	tree.addElement(170);
	tree.addElement(190);
	cout << "height: " << tree.getHeight()-1 << "\t(expected: 3) " << endl;
	cout << "smaller than: " << tree.countSmallerThan(75) << "\t(expected: 3) " << endl;
	cout << "leaf nodes: " << tree.getNumberOfLeafNodes() << "\t(expected: 6) " << endl;
	cout << "nodes between 50 and 125: " << tree.outputRange(50, 125) << "\n\t       (expected: 50 65 75 85 100 110 125) " << endl;
    return 0;
}