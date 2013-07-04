#include "Tokenizer.h"
namespace Interpeter
{
	namespace Tokenizer
	{
		
		Token::Token(TOKEN_TYPE type, string value)
		{
			this->_type = type;
			this->_value = value;
		}
		string Token::print()
		{
			string tmp = "Token : ";
			switch(this->_type)
			{
			case TOKEN_WORLD:
				tmp += "TOKEN_WORLD";
				tmp += " = " + this->_value;
				break;
			case TOKEN_METHOD_OPEN:
				tmp += "TOKEN_METHOD_OPEN";
				break;
			case TOKEN_METHOD_CLOSE:
				tmp += "TOKEN_METHOD_CLOSE";
				break;
			case TOKEN_SCOPE_OPEN:
				tmp += "TOKEN_SCOPE_OPEN";
				break;
			case TOKEN_SCOPE_CLOSE:
				tmp += "TOKEN_SCOPE_CLOSE";
				break;
			case TOKEN_ASSIGNMENT:
				tmp += "TOKEN_ASSIGNMENT";
				break;
			case TOKEN_TERMINATOR:
				tmp += "TOKEN_TERMINATOR";
				break;
			case TOKEN_OPERATOR:
				tmp += "TOKEN_OPERATOR";
				break;
			case TOKEN_STRING:
				tmp += "TOKEN_STRING";
				tmp += " = '" + this->_value + "'";
				break;
			}
			return tmp;
		}
		string Token::simulate()
		{
			string tmp;
			switch(this->_type)
			{
			case TOKEN_WORLD:
				tmp += this->_value;
				break;
			case TOKEN_METHOD_OPEN:
				tmp += "(";
				break;
			case TOKEN_METHOD_CLOSE:
				tmp += ")";
				break;
			case TOKEN_SCOPE_OPEN:
				tmp += "\n{";
				break;
			case TOKEN_SCOPE_CLOSE:
				tmp += "}\n";
				break;
			case TOKEN_ASSIGNMENT:
				tmp += "=";
				break;
			case TOKEN_TERMINATOR:
				tmp += "\n";
				break;
			case TOKEN_OPERATOR:
				tmp += this->_value;
				break;
			case TOKEN_STRING:
				tmp += "'" + this->_value + "'";
				break;
			}
			return tmp;
		}




		TOKENIZER_STATUS tokenizer(char *path, vector<Token> *tokenList)
		{
			
			ifstream sourceFile(path);
			
			stringstream buffer;
			string source;

			ifstream::pos_type size;
			if(sourceFile.is_open())
			{
				buffer << sourceFile.rdbuf();
				source = string(buffer.str());
				source += " ";
				sourceFile.close();
				return readSource(source, tokenList);
			}
			else
				return TE1;
		}

		TOKENIZER_STATUS readSource(string &source, vector<Token> *tokenList)
		{
			bool inlineComment = false,
				comment = false,
				writeWord = false,
				inString = false;
			
			string world = "";
			

			unsigned long souceLen = source.length() - 1;

			

			for(unsigned long i = 0; i < souceLen; i++)
			{
				if(inString)
				{
					if(	source[i] == '"' || source[i] == '\'' )
					{
						inString = false;
						tokenList->push_back(Token(TOKEN_STRING,world));
						world = "";
					}
					else
						world += source[i];

				}
				else if(inlineComment)
				{
					if(	source[i] == '\n' )
						inlineComment = false;
				}
				else if(comment)
				{
					if(	source[i] == '*' && source[i+1] == '/'  )
						comment = false;
				}
				else if(!writeWord)
				{
					if(	source[i] == ' ' || source[i] == '\t' )
						continue;
					if( (source[i] >= 'a' && source[i] <= 'z') || (source[i] >= 'A' && source[i] <= 'Z') || (source[i] >= '0' && source[i] <= '9') )
					{
						writeWord = true;
						world += source[i];
					}
					else if( source[i] == '(')
					{
						tokenList->push_back(Token(TOKEN_METHOD_OPEN, ""));
					}
					else if( source[i] == ')')
					{
						tokenList->push_back(Token(TOKEN_METHOD_CLOSE, ""));
					}
					else if( source[i] == '{')
					{
						tokenList->push_back(Token(TOKEN_SCOPE_OPEN, ""));
					}
					else if( source[i] == '}')
					{
						tokenList->push_back(Token(TOKEN_SCOPE_CLOSE, ""));
					}
					else if( source[i] == '=')
					{
						tokenList->push_back(Token(TOKEN_ASSIGNMENT, ""));
					}
					else if( source[i] == ';' ||  source[i] == '\n')
					{
						tokenList->push_back(Token(TOKEN_TERMINATOR, ""));
					}
					else if( source[i] == '\r' &&  source[i + 1] == '\n')
					{
						tokenList->push_back(Token(TOKEN_TERMINATOR, ""));
						i++;
					}
					else if( source[i] == '/' && source[i+1] == '/')
					{
						inlineComment = true;
					}
					else if( source[i] == '/' && source[i+1] == '*')
					{
						comment = true;
					}
					else if( source[i] == '/' || source[i] == '*' || source[i] == '+' || source[i] == '-')
					{
						tokenList->push_back(Token(TOKEN_OPERATOR, source.substr(i,1)));
					}
					else if( source[i] == '"' || source[i] == '\'' )
					{
						inString = true;
					}
					else
						return TE2;	//	Character not accepted
				}
				else
				{
					if( (source[i] >= 'a' && source[i] <= 'z') || (source[i] >= 'A' && source[i] <= 'Z') || (source[i] >= '0' && source[i] <= '9') )
					{
						world += source[i];
					}
					else
					{
						tokenList->push_back(Token(TOKEN_WORLD,world));
						world = "";
						writeWord = false;

						if(	source[i] == ' ' || source[i] == '\t' )
							continue;
						else if( source[i] == '(')
						{
							tokenList->push_back(Token(TOKEN_METHOD_OPEN, ""));
						}
						else if( source[i] == ')')
						{
							tokenList->push_back(Token(TOKEN_METHOD_CLOSE, ""));
						}
						else if( source[i] == '{')
						{
							tokenList->push_back(Token(TOKEN_SCOPE_OPEN, ""));
						}
						else if( source[i] == '}')
						{
							tokenList->push_back(Token(TOKEN_SCOPE_CLOSE, ""));
						}
						else if( source[i] == '=')
						{
							tokenList->push_back(Token(TOKEN_ASSIGNMENT, ""));
						}
						else if( source[i] == ';' ||  source[i] == '\n')
						{
							tokenList->push_back(Token(TOKEN_TERMINATOR, ""));
						}
						else if( source[i] == '\r' &&  source[i + 1] == '\n')
						{
							tokenList->push_back(Token(TOKEN_TERMINATOR, ""));
							i++;
						}
						else if( source[i] == '/' && source[i+1] == '/')
						{
							inlineComment = true;
						}
						else if( source[i] == '/' && source[i+1] == '*')
						{
							comment = true;
						}
						else if( source[i] == '/' || source[i] == '*' || source[i] == '+' || source[i] == '-')
						{
							tokenList->push_back(Token(TOKEN_OPERATOR, source.substr(i,1)));
						}
						else if( source[i] == '"' || source[i] == '\'' )
						{
							inString = true;
						}
						else
							return TE2;	//	Character not accepted
					}
				}
			}
			return TE0;
		}



	}
}