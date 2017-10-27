#include<string>
using namespace std;

#pragma once
class MathNode
{
  private: 
	  string type;
	  bool sign;
	  string base;
	  string baseType; //Number or Variable
	  float power;
	  float coefficient;
	  int numValue;
	  string value;
	  MathNode * parent;
	  MathNode * childOne;
	  MathNode * childTwo;
	  bool isSolved = false;
  public:
	  MathNode(string iType, string iBase, string iBaseType, int iNumValue, string iValue, MathNode* iParent, MathNode* iChildOne, MathNode* iChildTwo, bool sign);
	  MathNode(string iType, string iValue);
	  MathNode();
	  ~MathNode();

	  string MathNode::getType();

	  string MathNode::getBase();

	  int MathNode::getNumValue();

	  string MathNode::getValue();

	  MathNode* MathNode::getParent();

	  MathNode* MathNode::getChildOne();

	  MathNode* MathNode::getChildTwo();
	  bool MathNode::getIsSolved();

	  float MathNode::getPower();
	  float MathNode::getCoefficient();

	  //Setters
	  void MathNode::setParent(MathNode* node);
	  void MathNode::setChildOne(MathNode* node);
	  void MathNode::setChildTwo(MathNode* node);
	  void MathNode::setIsSolved(bool status);

	  bool MathNode::addChild(MathNode*);
	  bool MathNode::nodeIsOperator();
	  void MathNode::simplifyNode(); //takes the complicated string input expression, and dissolved the result into a term(if applicable) with a base, coefficient, sign, and power.
	  bool MathNode::isVariable();
	  bool MathNode::isNumber();
	  void MathNode::takeAntiderivative(string);

};

