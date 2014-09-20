// This is and Open Source Project.
// Written by Avita group.
// Started at Thursday - 2014 28 August

#include "Calculator.h"

#include "BaseConvert.h"
#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>


int main()
{
	std::string expression;

	//101010:2>10 +

	//1010:1>39 !
	//1010:1:39 !
	//1010@:1<39 !

	std:: cin >> expression;

	try
	{
		Calculator calc(expression);

		cout << calc.Calculate() << endl;
	}
	catch(const invalid_argument &invalid_arg_exp)
	{
		std::cerr << invalid_arg_exp.what() << endl;
	}
	catch(const out_of_range &out_of_range_exp)
	{
		std::cerr << out_of_range_exp.what() << endl;
	}

    std::cin.ignore();
    std::cin.get();

	return 0;
}
