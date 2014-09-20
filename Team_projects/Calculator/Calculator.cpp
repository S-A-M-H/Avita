#include "Calculator.h"
#include <sstream>
#include <stdio.h>
#include <stdexcept>

Calculator::Calculator(string expression)
{
	char colon, gSign, numberBuffer[32];

	//http://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm
	//http://www.cplusplus.com/reference/cstdio/sscanf/
	int filledCount = sscanf(expression.c_str(), "%[0-9a-zA-Z]%c%d%c%d", numberBuffer, &colon, &base1, &gSign, &base2);

	if(filledCount < 5 || colon != ':' || gSign != '>')
		throw invalid_argument("Supplied expression is not in the correct format. number:base1>base2");

	if( !isValidBaes(base1) || !isValidBaes(base2))
		throw out_of_range("Supplied bases are not in correct range. 2 <= base <= 36");

	if(!isValidNumber(base1, numberBuffer))
		throw out_of_range("A digit that is smaller than the base is expected.");

	number = string(numberBuffer);
}

string Calculator::Calculate()
{
	throw exception();
}

bool Calculator::isValidBaes(int base)
{
	return base >= 2 && base <= 36;
}

bool Calculator::isValidNumber(int base, string num)
{
	for(int i = 0 ; i < num.length() ; i ++)
	{
		if(getDecimalNumber(num[i]) >= base)
		{
			return false;
		}
	}

	return true;
}

int Calculator::getDecimalNumber(char digit)
{
	switch (digit)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	case 'G':
		return 16;
	case 'H':
		return 17;
	case 'I':
		return 18;
	case 'J':
		return 19;
	case 'K':
		return 20;
	case 'L':
		return 21;
	case 'M':
		return 22;
	case 'N':
		return 23;
	case 'O':
		return 24;
	case 'P':
		return 25;
	case 'Q':
		return 26;
	case 'R':
		return 27;
	case 'S':
		return 28;
	case 'T':
		return 29;
	case 'U':
		return 30;
	case 'V':
		return 31;
	case 'W':
		return 32;
	case 'X':
		return 33;
	case 'Y':
		return 34;
	case 'Z':
		return 35;
	default:
		throw invalid_argument("Supplied number does not exists in any base numbers.");
	}
}