//This header file Wrote for Open Source Calculation project of Avita Group.
// base converter header file.
//Written by Avita group.
//Started at Thursday - 2014 28 August.

#ifndef BaseConvert_h // Gard
#define BaseConvert_h 1 // Gard

#include <string>
#include <string.h>

class BaseConvert
{
private:
    std::string num; // number that we want to convert it to different bases
    int base1; // first base
    int base2; // second base
public:
    BaseConvert(); // default constructor;
    BaseConvert(std::string _num, int _base1, int _base2); // constructor with values for "num", "base1". "base2"
    std::string getNum(); // return num;
    int getBase1(); // return base1
    int getBase2(); // return base2
    bool setNum(std::string _num); // num = _num;
    bool setBase1(int _base1); // base1 = _base1
    bool setBase2(int _base2); // base2 = _base2
    bool _set(std::string _num, int base1, int base2); // change all members value, using functions "change_num", "change_base1", "change_base2"
    std::string convert(std::string _num, int _base1, int base2); // TODO
};

BaseConvert::BaseConvert()
{
    num = '-1';
    base1 = -1;
    base2 = -1;
}
BaseConvert::BaseConvert(std::string _num, int _base1, int _base2)
{
    num = _num;
    base1 = _base1;
    base2 = _base2;
}
std::string BaseConvert::getNum()
{
    if(num == "-1")
        return "Number is not valid";
    else
        return num;
}
int BaseConvert::getBase1()
{
    if(base1 == NULL || base1 == -1)
        return NULL;
    else
        return base1;
}
int BaseConvert::getBase2()
{
    if(base2 == NULL || base2 == -1)
        return NULL;
    else
        return base2;
}
bool BaseConvert::setNum(std::string _num)
{
    num = _num;
    return true;
}
bool BaseConvert::setBase1(int _base1)
{
    if(_base1 && _base1 > 1)
    {
        base1 = _base1;
        return true;
    }
    else
        return false;
}
bool BaseConvert::setBase2(int _base2)
{
    if(_base2 && _base2 > 1)
    {
        base2 = _base2;
        return true;
    }
    else
        return false;
}
bool BaseConvert::_set(std::string _num, int base1, int base2)
{
    setNum(_num);
    setBase1(base1);
    setBase2(base2);
    return true;
}

#endif // BaseConvert_h
