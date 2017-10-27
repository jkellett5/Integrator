#include"MathKnowledgeCollection.h"

MathKnowledgeCollection::MathKnowledgeCollection()
{
	this->executedTransform = false;
	this->safeTransformKnowledgeVector = buildSafeTransformKnowledgeVector(this->safeTransformKnowledgeVector);

}

//Accessors
bool MathKnowledgeCollection::getExecutedTransform()
{
	return this->executedTransform;
}
vector<MathKnowledge> MathKnowledgeCollection::getSafeTransformKnowledgeVector()
{
	return this->safeTransformKnowledgeVector;
}
vector<MathKnowledge> MathKnowledgeCollection::getHeuristicTransformKnowledgeVector()
{
	return this->heuristicTransformKnowledgeVector;
}

//Mutators
void MathKnowledgeCollection::setExecutedTransform(bool value)
{
	this->executedTransform = value;
}

void MathKnowledgeCollection::setSafeTransformKnowledgeVector(vector<MathKnowledge> stkv)
{
	this->safeTransformKnowledgeVector = stkv;
}
void MathKnowledgeCollection::setHeuristicTransformKnowledgeVector(vector<MathKnowledge> htkv)
{
	this->heuristicTransformKnowledgeVector = htkv;
}

void MathKnowledgeCollection::walkThroughSafeTransforms(MathTree*& problem)
{
	for (vector<MathKnowledge>::iterator it = this->safeTransformKnowledgeVector.begin(); it != this->safeTransformKnowledgeVector.end(); it++)
	{
		*problem = *it->transform(problem);
	}
}

//*************************Safe transforms and builder**************************

//transform a simple power function by taking the anti-derivative if applicable
MathTree* powerFuncTrans(MathTree*& tree)
{
	cout << "Running Power function" << endl;
	if (tree->isSingleton())// if the tree is a singleton
	{
		cout << "Tree is singleton" << endl;
		MathTree* tempTree = new MathTree();
		tempTree->setRoot(tree->getRoot());
		tempTree->getRoot()->takeAntiderivative(tree->getDifferentialSymbol());
		tempTree->getRoot()->setIsSolved(true);

	}
	// if base is a variable
	return tree;
}


vector<MathKnowledge> buildSafeTransformKnowledgeVector(vector<MathKnowledge> safeTransformKnowledgeVector)
{
	//create simplePowerFunction transform fact
	MathKnowledge m1(string("Simple Power Function Transform"), string("Yolo"), &powerFuncTrans);
	safeTransformKnowledgeVector.push_back(m1);

	return safeTransformKnowledgeVector;
}

//*****************Heuristic Transforms and Builder**********************