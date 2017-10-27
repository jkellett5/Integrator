#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string>
#include <sstream>
#include <vector>
#include "MathTree.h"
#include "MathKnowledge.h"
#include "MathKnowledgeCollection.h"


using namespace std;

void applySafeTransform(MathTree* problem, MathKnowledgeCollection collection)
{
	collection.walkThroughSafeTransforms(problem);//iterate through each transform until you cant complete anymore
}

MathTree* solveIntegral (MathTree * problem, MathKnowledgeCollection collection)
{
	bool done = false;

	while (!done)
	{
		applySafeTransform(problem, collection); //apply safe transform
		
		done = true;
		//done = checkForDone(unsolved);
		//applyHeuristicTransform(unsolved);
	}
	return problem;
}

int main() {

	//****Build Knowledge Information *****
	MathKnowledgeCollection collection = MathKnowledgeCollection();

	string input = "";

	// How to get a string/sentence with spaces
	cout << "Please enter an equation to integrate!";
	getline(cin, input);
	cout << "You entered: " << input << endl << endl;

	string working = input;

	MathTree problemTree = MathTree(working); //create Math Tree
	problemTree.buildTree();                  //build tree from input string
	problemTree.displayTree();
	problemTree.setDifferentiationSymbol("x");


	problemTree.simplifyTree(problemTree.getRoot()); //test 
	cout << "Base Yolo:" << problemTree.getRoot()->getBase() << endl;

	
	/*
	MathNode node1 = MathNode("Number", working);
	cout << " Yolo " << endl;
	node1.simplifyNode();
	*/
	MathTree* solved = solveIntegral(&problemTree, collection);
	solved->printTree(solved->getRoot());

	cout << solved->getRoot()->getBase() << endl;
	return 0;
}