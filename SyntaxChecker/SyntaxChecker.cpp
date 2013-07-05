#include "SyntaxChecker.h"
#include "Tokenizer.h"

namespace Interpeter
{
	namespace SyntaxChecker
	{

		

		SYNTAX_STATUS syntaxChecker(vector<Token> *tokenList)
		{
			unsigned i, j;

			bool newInstruction = true;

			for(i = 0; i < tokenList->size(); i++)
			{
				if(tokenList->at(i).type() == TOKEN_WORD)
				{
					
				}
			}
			return SE0;
		}

	}
}