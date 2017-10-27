#include "MathTree.h"
#include<vector>
#include "MathKnowledge.h"
using namespace std;

//class definitions
MathKnowledge::MathKnowledge(string title, string description, MathTree*(*tForm)(MathTree*&))
{
	this->title = title;
	this->description = description;
	this->transform = tForm;
}

void MathKnowledge::setDescription(string description)
{
	this->description = description;
}

void MathKnowledge::setTitle(string title)
{
	this->title = title;
}

string MathKnowledge::getTitle()
{
	return this->title;
}

string MathKnowledge::getDescription()
{
	return this->description;
}