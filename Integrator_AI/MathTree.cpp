#include "MathTree.h"
#include <sstream>
#include <iostream>

MathTree::MathTree(string iEquation)
{
	root = NULL;
	equation = iEquation;

}

MathTree::MathTree()
{
	root     = NULL;
	equation = "";

}

MathTree::~MathTree()
{
}

MathNode* MathTree::getRoot()
{
	return this->root;
}

string MathTree::getDifferentialSymbol(void)
{
	return this->differentiationSymbol;
}

bool MathTree::isSingleton()
{
	if (root->getChildOne() == NULL && root->getChildTwo() == NULL)
		return true;
	return false;
}

void MathTree::setRoot(MathNode* node)
{
	this->root = node;
}

void MathTree::setDifferentiationSymbol(string symbol)
{
	this->differentiationSymbol = symbol;
}

void MathTree::buildTree()
{
	//simplify parenthesis

	//from left to right find first number
	std::istringstream iss(equation);

	std::string var;

	MathNode* nodePtr = root;

	cout << "Debug:";
	while (iss >> var) // attempt extraction then test if stream is good
	{
		cout << var;
		// if string is not an operator, it is a variable or a number
		if (var == "*" || var == "/" || var == "+" || var == "-")
		{
			cout << "Operator";
			if (nodePtr != NULL)
			{
				MathNode* Temp = new MathNode(string("Operator"), var);
				Temp->addChild(nodePtr);
				nodePtr->setParent(Temp);
				cout << "created Parent";
				nodePtr = Temp;
				root = nodePtr;
			}
			//else error
		}
		else //assume number
		{
			//check if number
			//add number to node as a child
			cout << "Adding Child";
			if (nodePtr != NULL)
			{
				MathNode* tempChild = new MathNode("Number", var);
				tempChild->setParent(nodePtr);
				nodePtr->addChild( tempChild);
			}
			else
				nodePtr = ( new MathNode("Number", var));

		}
	}
	this->setRoot(nodePtr);
}

void MathTree::displayTree()
{
	if (root != NULL)
	{
		cout << endl << endl << "Displaying Tree: " <<endl << "Root: " << endl;
		printTree(root);
	}
	else
		cout << "Root is Null" << endl;
	  
}

void MathTree::printTree(MathNode * node)
{
	if (node == NULL)
		return;

	cout << node->getType() << " : " << node->getValue();
	if (node->getParent() != NULL)
	{
		cout << " Parent is : " << node->getParent()->getType() << " : " << node->getParent()->getValue();
	}
	cout << endl;
	printTree(node->getChildOne());
	printTree(node->getChildTwo());
}

void MathTree::simplifyTree(MathNode* node)
{
	if(node == NULL)
		return;

	if (node != NULL)
	{
		node->simplifyNode();
	}

	if (node->getChildOne() != NULL)
	{
		simplifyTree(node->getChildOne());
	}
	if (node->getChildTwo() != NULL)
	{
		simplifyTree(node->getChildTwo());
	}
}