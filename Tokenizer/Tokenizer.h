#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

namespace Interpeter
{
	namespace Tokenizer
	{

		enum TOKEN_TYPE {
			TOKEN_WORD,				//	nome
			TOKEN_KEYWORD,			//	if end while
			TOKEN_METHOD_OPEN,		//	(
			TOKEN_METHOD_CLOSE,		//	)
			TOKEN_SCOPE_OPEN,		//	{
			TOKEN_SCOPE_CLOSE,		//	}
			TOKEN_ASSIGNMENT,		//	=
			TOKEN_TERMINATOR,		//	\n ;
			TOKEN_OPERATOR,			// + - * /
			TOKEN_STRING			// ' "
		};



		class Token
		{
		public:
			Token(TOKEN_TYPE type, string value);
			string print();
			string simulate();
			TOKEN_TYPE type();
			string val();
		private:
			TOKEN_TYPE _type;
			string _value;
		};


		enum TOKENIZER_STATUS { 
			TE0,	//	Status OK
			TE1,	//	Source code not exist
			TE2,	//	Character not accepted
		};

		TOKENIZER_STATUS tokenizer(char *path, vector<Token> *tokenList);
		TOKENIZER_STATUS readSource(string &source, vector<Token> *tokenList);


		

		

	}
}