#include <iostream>
#include <wchar.h>
#include <iomanip>
#include "modulesprokopenko.h"
#include <limits>
#include <cmath>
using namespace std;

bool aBCondition( wchar_t a,wchar_t b){
    bool result = a + 1 == b + 2;
    return result;
}

double validator(wstring number){
    for( int i = 0; i < (int)number.size();i++)
        if(number[i] == L'.')
            number[i] = L',';
    if (number[0] == L'x' || number[0] == 'X')
        number = L"0" + number;
    // if the variable is an "inadequate" string of type "0bred56" then the function will return 0
    return std::stod(number);
}

double hexS_calculation(wstring x,wstring y, wstring z){
    return s_calculation(validator(x),validator(y),validator(z));
}

int main(){
    consoleToUtf8();
    wcout << devInfo();
    wstring x = L"",y = L"",z = L"";
    wchar_t  a = L' ', b = L' ';
    wcout <<L"Введіть дійсне число x: ";
    wcin >> x;
    wcout <<L" Х у десятковій системі числення: "<< defaultfloat << validator(x)<< endl;

    if(fmod(validator(x),1) == 0){
        wcout<<L" Х у шіснадцятковій системі числення: 0x"<< dec << hex  << (int)floor(validator(x)) << defaultfloat<< endl;
    }else{
        wcout<<L" Х у шіснадцятковій системі числення: "<< hexfloat << validator(x) << defaultfloat<< endl;
    }
    do {
        wcout <<L"Введіть дійсне число y: ";
        wcin >> y;
        if (validator(y) == 0)
            wcout << L"Введіть значення \"У\" ще раз (y≠0)." << endl;
    } while (validator(y) == 0);
    wcout <<L" У у десятковій системі числення: " << defaultfloat << validator(y)<< endl;

    if(fmod(validator(y),1) == 0){
        wcout<<L" У у шіснадцятковій системі числення: 0x"<< hex << (int)floor(validator(y)) << defaultfloat<< endl;
    }else{
        wcout<<L" У у шіснадцятковій системі числення: "<< hexfloat << validator(y) << defaultfloat<< endl;
    }

    wcout <<L"Введіть дійсне число z: ";
    wcin >> z;
    wcout <<L" Z у десятковій системі числення: " <<validator(z)<< endl;
    if(fmod(validator(z),1) == 0){
        wcout<<L" Z у шіснадцятковій системі числення: 0x"<< hex << (int)floor(validator(z)) << defaultfloat<< endl;
    }else{
        wcout<<L" Z у шіснадцятковій системі числення: "<< hexfloat << validator(z) << defaultfloat<< endl;
    }


    wcout <<L"Введіть символ a: ";
    wcin >> a;
    wcin.clear();
    wcin.ignore(numeric_limits < streamsize > ::max(), '\n');
    wcout <<L"Введіть символ b: ";
    wcin >> b;
    wcout << boolalpha << L"Результат логічного виразу: "<<aBCondition(a,b) << endl;
    wcout << L"Результат роботи модулю s_calculation: "<< defaultfloat << hexS_calculation(x,y,z) << endl;
    system("pause");
    return 0;
}
