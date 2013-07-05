#include "SyntaxChecker.h"

namespace Interpeter
{
	namespace SyntaxChecker
	{

		char *keywords[] = {
			"if",
			"end",
			"while",
			"for",
			"import"
		};

		SYNTAX_STATUS syntaxChecker(vector<Token> *tokenList)
		{
			for(unsigned i = 0; i < tokenList->size(); i++)
			{
				
			}
			return SE0;
		}

	}
}