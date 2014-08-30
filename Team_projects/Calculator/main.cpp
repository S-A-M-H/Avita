// This is and Open Source Project.
// Written by Avita group.
// Started at Thursday - 2014 28 August

#include "BaseConvert.h"
#include <iostream>
#include <cmath>
#include <string>


int main()
{
    std::string num = "0";
    int base1 = 10;
    int base2 = 10;
    std::cin>> num >> base1 >> base2;
    BaseConvert base_convert;
    if(base_convert.change(num, base1, base2))
        std::cout<<"Changed Successfully"<<std::endl;
    else
        std::cerr<<"ERROR: Bases should be bigger than one and be an Natural number"<<std::endl;
    std::cout<<"Num is : "<<base_convert.return_num()<<std::endl<<"Base 1 is : "<<base_convert.return_base1()<<std::endl<<"Base2 is : "<<base_convert.return_base2()<<std::endl;
    std::cin.ignore();
    std::cin.get();
    return 0;
}
