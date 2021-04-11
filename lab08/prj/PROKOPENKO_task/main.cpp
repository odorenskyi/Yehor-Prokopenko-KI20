#include <iostream>
#include <wchar.h>
#include <iomanip>
#include "modulesprokopenko.h"
#include <limits>
using namespace std;


wstring devInfo(){
    wstring info = L"╔══════════════════════════════════════════════════════╗\n"
                    "║Виконав студент групи КБ20 Прокопенко Єгор Сергійович©║\n"
                    "╚══════════════════════════════════════════════════════╝\n";
    return info;
}

bool aBCondition( wchar_t a,wchar_t b){
    bool result = a + 1 == b + 2;
    return result;
}

double validator(wstring number){
    if (number[0] == L'x' || number[0] == 'X')
        number = L"0" + number;
    // if the variable is an "inadequate" string of type "0bred56" then the function will return 0
    return std::stof(number);
}

double hexS_calculation(wstring x,wstring y, wstring z){
    // If the function with the given parameters does not exist, then 0 will be returned
    return s_calculation(validator(x),validator(y),validator(z));
}

int main(){
    consoleToUtf8();
    wcout << devInfo();
    wstring x = L"",y = L"",z = L"";
    wchar_t  a = L' ', b = L' ';
    wcout <<L"Введіть дійсне число x: ";
    wcin >> x;
    do {
        wcout <<L"Введіть дійсне число y: ";
        wcin >> y;
        if (validator(y) == 0)
            wcout << L"Введіть значення \"У\" ще раз (y≠0)." << endl;
    } while (validator(y) == 0);
    wcout <<L"Введіть дійсне число z: ";
    wcin >> z;
    wcout <<L"Введіть символ a: ";
    wcin >> a;
    cin.clear();
    wcin.ignore(numeric_limits < streamsize > ::max(), '\n');
    wcout <<L"Введіть символ b: ";
    wcin >> b;
    wcout << boolalpha << L"Результат логічного виразу: "<<aBCondition(a,b) << endl;
    wcout << L"Результат роботи модулю s_calculation: "<< hexS_calculation(x,y,z) << endl;
    system("pause");
    return 0;
}
