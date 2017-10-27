#include "MathNode.h"

#pragma once
class MathTree
{
	MathNode* root;
	string equation;
	string differentiationSymbol;

public:
	MathTree(string equation);
	MathTree();
	~MathTree();
	void buildTree();
	void simplifyTree(MathNode*);
	MathNode* getRoot();
	void displayTree();
	void printTree(MathNode * node);
	bool isSingleton();

	string MathTree::getDifferentialSymbol(void);

	void MathTree::setRoot(MathNode*);
	void MathTree::setDifferentiationSymbol(string);
};

