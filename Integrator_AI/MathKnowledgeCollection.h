#pragma once
#include"MathKnowledge.h"

class MathKnowledgeCollection
{
    private:
		bool executedTransform;
		vector<MathKnowledge> safeTransformKnowledgeVector;
		vector<MathKnowledge> heuristicTransformKnowledgeVector;

    public:
		MathKnowledgeCollection();

		//Accessors
		bool getExecutedTransform();
		vector<MathKnowledge> getSafeTransformKnowledgeVector();
		vector<MathKnowledge> getHeuristicTransformKnowledgeVector(); 

		//Mutators
		void setExecutedTransform(bool value);

		void setSafeTransformKnowledgeVector(vector<MathKnowledge>);
		void setHeuristicTransformKnowledgeVector(vector<MathKnowledge>);
		void MathKnowledgeCollection::walkThroughSafeTransforms(MathTree*& problem);
};
//*****TRANSFORM VECTOR BUILDERS*********
vector<MathKnowledge> buildSafeTransformKnowledgeVector(vector<MathKnowledge> safeTransformKnowledgeVector);