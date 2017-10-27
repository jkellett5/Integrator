#include<string>
#include<stdlib.h>
using namespace std;

typedef struct knowledge
{
	string title;
	string integration(int power, string variable) { int nPower = power + 1; string result = "(" + variable + "^" + itoa(nPower) + ")/" + itoa(nPower); return result; };
	string description;
	knowledge(string title, string description) : title(title), description(description) {}
}knowledge;

static const knowledge knowledge_table[1] = {{"Power Function","Rule for Power Functions"}};


