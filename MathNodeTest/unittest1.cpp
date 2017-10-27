#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Integrator_AI/MathNode.h"
#include "../Integrator_AI/MathNode.cpp"
#include "../Integrator_AI/MathTree.h"
#include "../Integrator_AI/MathTree.cpp"
#include <iostream>
#include "../Integrator_AI/MathKnowledge.h"
#include "../Integrator_AI/MathKnowledge.cpp"
#include "../Integrator_AI//MathKnowledgeCollection.h"
#include "../Integrator_AI//MathKnowledgeCollection.cpp"
#include "../Integrator_AI/main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathNodeTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(term_Test_1)
		// Creates a mathnode, and tests that the simplify method interprests and stores its components correctly
		{
			//Create a mathNode with 2x^2 as the result, test the assignment and simplication
			MathNode node1 = MathNode("Number", "2x^3");
			node1.simplifyNode();
			//Logger::WriteMessage("Yolo");
			//cout << "Yolo" << endl << endl;
			Assert::AreEqual(node1.getBase(), std::string("x"), L"Node Equivalence");
			Assert::AreEqual(node1.getPower(), float(3.0), L"Power Equivalence");
			Assert::AreEqual(node1.getCoefficient(), float(2.0), L"Coefficient Equivalence");
		}
		TEST_METHOD(term_Test_2)
			// Creates a mathnode, and tests that the simplify method interprests and stores its components correctly
		{
			//Create a mathNode with 2x^2 as the result, test the assignment and simplication
			MathNode node1 = MathNode("Number", "x");
			node1.simplifyNode();
			//Logger::WriteMessage("Yolo");
			//cout << "Yolo" << endl << endl;
			Assert::AreEqual(node1.getBase(), std::string("x"), L"Node Equivalence");
			Assert::AreEqual(node1.getPower(), float(1.0), L"Power Equivalence");
			Assert::AreEqual(node1.getCoefficient(), float(1), L"Coefficient Equivalence");
		}
		TEST_METHOD(term_Test_3)
			// Creates a mathnode, and tests that the simplify method interprests and stores its components correctly
		{
			//Create a mathNode with 2x^2 as the result, test the assignment and simplication
			MathNode node1 = MathNode("Number", "4");
			node1.simplifyNode();
			cout << string(node1.getBase()) << endl;
			//cout << "Yolo" << endl << endl;
			Assert::AreEqual(node1.getBase(), std::string("1"), L"Node Equivalence");
			Assert::AreEqual(node1.getPower(), float(1.0), L"Power Equivalence");
			Assert::AreEqual(node1.getCoefficient(), float(4), L"Coefficient Equivalence");
		}
		TEST_METHOD(term_Test_4)
			// Creates a mathnode, and tests that the simplify method interprests and stores its components correctly
		{
			//Create a mathNode with 2x^2 as the result, test the assignment and simplication
			MathNode node1 = MathNode("Number", "4.5");
			node1.simplifyNode();
			cout << string(node1.getBase()) << endl;
			//cout << "Yolo" << endl << endl;
			Assert::AreEqual(node1.getBase(), std::string("1"), L"Node Equivalence");
			Assert::AreEqual(node1.getPower(), float(1.0), L"Power Equivalence");
			Assert::AreEqual(node1.getCoefficient(), float(4.5), L"Coefficient Equivalence");
		}

		TEST_METHOD(term_Test_5)
			// Creates a mathnode, and tests that the simplify method interprests and stores its components correctly
		{
			//Create a mathNode with 2x^2 as the result, test the assignment and simplication
			MathNode node1 = MathNode("Number", "4.5x");
			node1.simplifyNode();
			cout << string(node1.getBase()) << endl;
			//cout << "Yolo" << endl << endl;
			Assert::AreEqual(node1.getBase(), std::string("x"), L"Node Equivalence");
			Assert::AreEqual(node1.getPower(), float(1.0), L"Power Equivalence");
			Assert::AreEqual(node1.getCoefficient(), float(4.5), L"Coefficient Equivalence");
		}

		TEST_METHOD(operator_Test_1)
			// Creates a mathnode, and tests that a simple + operator is stored correctly
		{
			//Create a mathNode with 2x^2 as the result, test the assignment and simplication
			MathNode node1 = MathNode("Operator", "+");
			node1.simplifyNode();
			Assert::AreEqual(node1.getType(), std::string("Operator"), L"Node Equivalence");
			Assert::AreEqual(node1.getValue(), std::string("+"), L"Node Equivalence");
		}

		TEST_METHOD(knowledge_test_1_integrate_constant)
		{
			MathKnowledgeCollection collection = MathKnowledgeCollection();
			string working = "5";

			MathTree problemTree = MathTree(working); //create Math Tree
			problemTree.setDifferentiationSymbol("x");
			problemTree.buildTree();                  //build tree from input string
			problemTree.displayTree();

			problemTree.simplifyTree(problemTree.getRoot()); //test 

			MathTree* solved = solveIntegral(&problemTree, collection);

			cout << solved->getRoot()->getBase() << endl;

			if (solved->getRoot() != NULL)
			{
				Assert::AreEqual(solved->getRoot()->getBase(), std::string("x"), L"Base of integral");
			}
			else
				Assert::Fail;
			//Assert::AreEqual(solved->getRoot()->getCoefficient(), float(5.0));

		}
	};
}