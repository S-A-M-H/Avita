#include "Calculator.h"
#include <sstream>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>

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
	int numberInBase10 = convertToBase10(base1, number);

	return convertFromBase10(base2, numberInBase10);
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
	if(digit >= '0' && digit <= '9')
		return digit - '0';

	if (digit >= 'A' && digit <= 'Z')
		return (digit - 'A') + 10;

	//out of range value
	throw invalid_argument("Supplied number does not exists in any base numbers.");
}

char Calculator::getDigit(int number)
{
	if(number >= 0 && number <= 9)
		return '0' + number;

	if (number >= 10 && number <= 36)
	{
		//relative position in alphabet
		int charPosition = number - 10;

		return 'A' + charPosition;
	}

	//out of range value
	throw out_of_range("This number could not be represented in any equal character.");
}

int Calculator::convertToBase10(int base, string number)
{
	//formula: (ABC)X = (A * X^2) + (B * X^1) + (C * X^0)

	int sum = 0;
	int numberIndex = 0;

	int basePower = number.length() - 1;

	for (int i = basePower; i >= 0; i--)
	{
		char digit = number[numberIndex];

		sum += getDecimalNumber(digit) * ceil(pow(base, i));

		numberIndex++;
	}

	return sum;
}

string Calculator::convertFromBase10(int base, int number)
{
	//divide until quotient is zero
	//final result is final quotient and remainders from last step to first one

	vector<int> result;
	string digits;

	int remainder = number % base;
	int quotient = number / base;

	result.push_back(remainder);

	while(quotient != 0)
	{
		remainder = quotient % base;
		quotient = quotient / base;

		result.push_back(remainder);
	}

	reverse(result.begin(), result.end());

	for (int x : result)
	{
		char digit = getDigit(x);

		digits.push_back(digit);
	}

	return digits;
}
