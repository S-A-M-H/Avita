//This header file Wrote for Open Source Calculation project of Avita Group.
// Tempreture converter header file.
//Written by Avita group.
//Started at Friday - 2014 29 August.

#ifndef TempretureConverter_h // Gard
#define TempretureConverter_h 1 // Gard

class Tempretur
{
private:
    double temp1; // first temprutre that should convert
    double temp2; // converted temprutre
    char type1; // 1st type of conversation
    char type2; // 2nd type of conversation
public:
    Tempretur(); // default constructor
    Tempretur(double _temp1, char _type); // 2nd constructor with argument
    double return_temp1(); // return temp1;
    double return_temp2(); // return temp2;
    char return_type1(); // return type;
    char return_type2(); // return type2;
    bool change_temp1(double _temp1); // temp1 = _temp1;
    bool change_temp2(double _temp2); // temp2 = _temp2;
    bool change_type1(char _type1); // type1 = _type1;
    bool change_type2(char _type2); // type2 = _type2
    bool change(double _temp1, double _temp2, char _type1, char _type2); // change completely using functions "change_temp1", "change_temp2", "change_type";
    bool convert(double _temp1, double _temp2, char _type1, char _type2); //TODO
};

Tempretur::Tempretur()
{
    temp1 = -1;
    temp2 = -1;
    type1 = 'I';
    type2 = 'I';
}
Tempretur::Tempretur(double _temp1, char _type1)
{
    temp1 = _temp1;
    type1 = _type1;
}
double Tempretur::return_temp1()
{
    return temp1;
}
double Tempretur::return_temp2()
{
    return temp2;
}
char Tempretur::return_type1()
{
    return type1;
}
char Tempretur::return_type2()
{
    return type2;
}
bool Tempretur::change_temp1(double _temp1)
{
    temp1 = _temp1;
}
bool Tempretur::change_temp2(double _temp2)
{
    temp2 = _temp2;
}
bool Tempretur::change_type1(char _type1)
{
    type1 = _type1;
}
bool Tempretur::change_type2(char _type2)
{
    type2 = _type2;
}
bool Tempretur::change(double _temp1, double _temp2, char _type1, char _type2)
{
    change_temp1(_temp1);
    change_temp2(_temp2);
    change_type1(_type1);
    change_type2(_type2);
}

#endif // TempretureConverter_h
