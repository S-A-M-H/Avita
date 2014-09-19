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
