#pragma once
#include<string>
#include "MathNode.h"
#include "MathTree.h"
#include <iostream>
#include<vector>
using namespace std;

class MathKnowledge
{
  private:
	  string title;
	  string description;

  public:
	  MathKnowledge(string title, string description, MathTree* (*tform)(MathTree*&));

	  //transform
	  MathTree* (*transform)(MathTree*&);

      //Accessors
	  string getTitle();
	  string getDescription();

	  //Mutators
	  void setTitle(string title);
	  void setDescription(string description);
};
/*
typedef struct MathKnowledge
{
	string title;
	string description;
	MathTree* (*transform)(MathTree*);
	MathKnowledge(string title, string description, MathTree*(*transformIfApplicable)(MathTree*)) : title(title), description(description), transform(transform) {};
}MathKnowledge;

vector<MathKnowledge> buildSafeTransformKnowledgeVector(vector<MathKnowledge>);
*/