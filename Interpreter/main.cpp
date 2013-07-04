#include <iostream>
#include "Tokenizer.h"

using namespace std;
using namespace Interpeter;
using namespace Tokenizer;

int main(int argc, char ** argv, char **envv)
{
	vector<Token> tokenList;
	if(argc == 2)
	{
		switch(tokenizer(argv[1], &tokenList))
		{
		case TE0:
			for(unsigned i = 0; i < tokenList.size(); i++)
			{
				cout<<tokenList[i].simulate();
			}
			cout<<endl;
			for(unsigned i = 0; i < tokenList.size(); i++)
			{
				cout<<tokenList[i].print()<<endl;
			}
			break;
		case TE1:
			cout<<"Source code dosn't exist";
			return false;
			break;
		case TE2:
			cout<<"Character not accepted";
			return false;
			break;
		}
	}
	else
		return false;
	system("pause");
	return true;
}
