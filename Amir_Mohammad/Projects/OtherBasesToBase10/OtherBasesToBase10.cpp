#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <math.h>
#include <cmath>

using namespace std;

int get_number(char digit);
bool check(int base, string num);
int convert_base(int base, string num);

int main()
{
    string num;
    int base;
    cin>>base;
    cin>>num;
    if(check(base, num))
        cout<<convert_base(base, num)<<endl;
    else
        cerr<<endl<<"The Number Is Bigger than Base, Or its equal to base!"<<endl;
    cin.ignore();
    cin.get();


    return 0;
}

int get_number(char digit)
{
    if(digit == '0')
        return 0;
    else if(digit == '1')
        return 1;
    else if(digit == '2')
        return 2;
    else if(digit == '3')
        return 3;
    else if(digit == '4')
        return 4;
    else if(digit == '5')
        return 5;
    else if(digit == '6')
        return 6;
    else if(digit == '7')
        return 7;
    else if(digit == '8')
        return 8;
    else if(digit == '9')
        return 9;
    else if(digit == 'A')
        return 10;
    else if(digit == 'B')
        return 11;
    else if(digit == 'C')
        return 12;
    else if(digit == 'D')
        return 13;
    else if(digit == 'E')
        return 14;
    else if(digit == 'F')
        return 15;
    else if(digit == 'G')
        return 16;
    else if(digit == 'H')
        return 17;
    else if(digit == 'I')
        return 18;
    else if(digit == 'J')
        return 19;
    else if(digit == 'K')
        return 20;
    else if(digit == 'L')
        return 21;
    else if(digit == 'M')
        return 22;
    else if(digit == 'N')
        return 23;
    else if(digit == 'O')
        return 24;
    else if(digit == 'P')
        return 25;
    else if(digit == 'Q')
        return 26;
    else if(digit == 'R')
        return 27;
    else if(digit == 'S')
        return 28;
    else if(digit == 'T')
        return 29;
    else if(digit == 'U')
        return 30;
    else if(digit == 'V')
        return 31;
    else if(digit == 'W')
        return 32;
    else if(digit == 'X')
        return 33;
    else if(digit == 'Y')
        return 34;
    else if(digit == 'Z')
        return 35;
    else
        return -1;

}

bool check(int base, string num)
{
    for(int i = 0 ; i < num.length() ; i ++)
        if(get_number(num[i]) >= base)
            return false;
    return true;
}

int convert_base(int base, string num)
{
    int sum = 0;
    int price = num.length();
    for(int i = 0 ; i < num.length() ; i ++)
    {
        price --;
        sum += get_number(num[i])*pow(base, price);
    }
    return sum;
}
