#include <string>

using namespace std;

class Calculator
{
public:
	//Format: number:base1>base2
	//Reads expression parts into base1, base2 and number
	//Throws invalid_argument when input is not well-formed
	//Throws out_of_range when bases are not between 2 to 36
	Calculator(string expression);

	//Converts number from base1 to base base2
	//Returns a number in base2
	string Calculate();

private:
	int base1;
	int base2;

	//input number is assigned to a string because int just is able to represents numbers in base 10
	string number;

	bool isValidBaes(int base);
	bool isValidNumber(int base, string num);
	int getDecimalNumber(char digit);
	char getDigit(int number);
	int convertToBase10(int base, string number);
	string convertFromBase10(int base, int number);
};

