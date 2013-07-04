#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Tokenizer.h"

using namespace std;

using namespace Interpeter;
using namespace Tokenizer;

namespace Interpeter
{
	namespace SyntaxChecker
	{

		class World
		{
		public:
		private:
			string _name;
			int _id;
		};


		enum SYNTAX_STATUS { 
			SE0	//	Status OK
		};

		SYNTAX_STATUS syntaxChecker(vector<Token> *tokenList);

	}

}