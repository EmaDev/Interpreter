#include <iostream>
#include "Tokenizer.h"

using namespace std;
using namespace Interpeter;
using namespace Tokenizer;

int main(int argc, char ** argv, char **envv)
{

	if(argc == 2)
	{
		switch(tokenizer(argv[1]))
		{
		case TE0:
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

	return true;
}
