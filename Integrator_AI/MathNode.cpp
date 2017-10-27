#include "MathNode.h"
#include <iostream>
#include <algorithm>
#include <string>

MathNode::MathNode(string iType, string iBase, string iBaseType, int iNumValue, string iValue, MathNode* iParent, MathNode* iChildOne, MathNode* iChildTwo, bool iSign)
{
	type = iType;
	base = iBase;
	baseType = iBaseType;
	numValue = iNumValue;
	value = iValue;
	parent = iParent;
	childOne = iChildOne;
	childTwo = iChildTwo;
	sign = iSign; // False for Negative, True for Positive
	isSolved = false;
}

//Operator Node constructor
MathNode::MathNode(string iType, string iValue)
{
	type = string(iType);
	base = "";
	baseType = "";
	numValue = NULL;
	value = iValue;
	parent = NULL;
	childOne = NULL;
	childTwo = NULL;
	sign = NULL;
	isSolved = false;
}

MathNode::MathNode()
{
	type = "";
	base = "";
	baseType = "";
	numValue = NULL;
	value = "";
	parent = NULL;
	childOne = NULL;
	childTwo = NULL;
	sign = NULL;
	isSolved = false;
}

MathNode::~MathNode()
{
	parent = NULL;
}

//getters

string MathNode::getType()
{
	if (this == NULL)
		return "";
	return type;
}

string MathNode::getBase()
{
	return base;
}

int MathNode::getNumValue()
{
	return numValue;
}

string MathNode::getValue()
{
	return value;
}

MathNode* MathNode::getParent()
{
	return parent;
}

MathNode* MathNode::getChildOne()
{
	return childOne;
}

MathNode* MathNode::getChildTwo()
{
	return childTwo;
}

float MathNode::getPower()
{
	return this->power;
}

float MathNode::getCoefficient()
{
	return this->coefficient;
}

bool MathNode::getIsSolved()
{
	return this->isSolved;
}

bool MathNode::addChild(MathNode* newChild)
{
	if (childOne == NULL)//add node to child one
	{
		setChildOne(newChild);
		cout << "Child One" << flush;
	}
	else if (childTwo == NULL)// add node to child
	{
		setChildTwo(newChild);
		cout << "Child Two"<< flush;
	}
	else
		return false;
	return true;
}

void MathNode::setParent(MathNode* node)
{
	parent = node;
}

void MathNode::setChildOne(MathNode* node)
{
	childOne = node;
}

void MathNode::setChildTwo(MathNode* node)
{
	childTwo = node;
}

void MathNode::setIsSolved(bool status)
{
	this->isSolved = status;
}

bool MathNode::nodeIsOperator()
{
	if (this->type == "Operator")
		return true;
	return false;
}

void MathNode::simplifyNode()
{
	if (nodeIsOperator())
		return;
	cout << "Simplifying Node" << endl;
	//copy value into temporary variable and strip parenthesis

	//default values unless evidence found to the contrary
	sign = true;
	this->power = 1.0;

	int pos = value.find("-");
	if (pos != 0) //check for sign
	{
		sign = false;
	}


	cout << "Sign: " << sign << endl;

	int powerPos = this->value.find("^"); 
	cout << value << endl;
	cout << "PowerPos: " << powerPos << endl;
	if (powerPos != -1)//check for power
	{
		string powerValue = this->value.substr(powerPos + 1, (value.length() - powerPos));
		cout << "Value of Power : " << powerValue << endl;
		int floatPos = powerValue.find(".");//check if float or integer
		if (floatPos == 0)//integer
		{
			this->power = stof(powerValue);//attempt to convert result to an integer
		}
		else // float
		{
			this->power = stof(powerValue);//attempt to convert result to a float
		}
		
	}
	string valueTemp = string(value);
	string variable;
	cout << "Checking for Variables in :" << valueTemp << endl;
	for (string::iterator iter = valueTemp.begin(); iter != valueTemp.end(); iter++)
	{
		if ((*iter) == '^' && false)//remove everything after the power sign
		{
			break;
	    }
		else if (isalpha((*iter)))
		{
			variable += (*iter); 
			this->baseType = "Variable";
			this->base = variable;
		}
			
	}
	
	cout << variable << endl;
	if (any_of(begin(valueTemp), end(valueTemp), ::isalpha))//find variable coefficient
	{
		int coefPos = value.find(this->base);
		if (coefPos > 0) 
		{
			float coef = stof(value.substr(0, coefPos)); //get coefficient
			this->coefficient = coef;
			cout << "Coefficient: " << coef << endl;
		}
		else 
		{
			this->coefficient = 1.0;
			cout << "Coefficient: " << this->coefficient << endl;
		}
	}
	else// numerical Base -- set base to 1 and determine coefficient
	{
		this->base = "1";//check for number base
		this->baseType = "Numerical";
		string valueTemp2 = value;
		remove_if(begin(valueTemp2), end(valueTemp2),[](char c) { return (c == '.') ||::isdigit(c); });
		float coef = stof(valueTemp2); //retrieve coefficient
		this->coefficient = coef;
		cout << "Numerical Base: " << this->base << endl;
		cout << "Coefficient " << coef << endl;
	}
	

}

bool MathNode::isVariable()
{
	return std::none_of(this->base.begin(), this->base.end(), ::isdigit);
}

bool MathNode::isNumber()
{
	return std::all_of(this->base.begin(), this->base.end(), ::isdigit);
}

void MathNode::takeAntiderivative(string differentiationVariable)
{
	if (this->isNumber())//if number, just make it a variable with the same coefficient
	{
		this->baseType = "Variable"; //make the type a variable
		this->type = "Variable";
		this->base = differentiationVariable;
		this->power = 1.0;
		this->value = to_string(this->coefficient) + differentiationVariable;
	}
	//if variable
}