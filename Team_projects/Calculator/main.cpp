// This is an Open Source and Free Project (GPLv3).
// Written by Avita group.
// Started at Thursday - 2014 28 August

#include "Calculator.h"

#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>

void calculateExpression(std::string expression)
{
	try
	{
		Calculator calc(expression);

		cout << calc.Calculate() << endl;
	}
	catch(const invalid_argument &invalid_arg_exp)
	{
		cerr << invalid_arg_exp.what() << endl;
	}
	catch(const out_of_range &out_of_range_exp)
	{
		cerr << out_of_range_exp.what() << endl;
	}
}

int main()
{
	string expression;

	cout
		<< "Enter your base calculation request in the following format: number:base1>base2" << endl
		<< "Enter q when you were done." << endl
		<< endl;

	cin >> expression;

	while (expression != "q")
	{
		calculateExpression(expression);

		cin >> expression;
	}

	cin.ignore();

	cout << "Press any key to exit..." << endl;

	cin.get();

	return 0;
}
