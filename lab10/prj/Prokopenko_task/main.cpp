#include <iostream>
#include "modulesprokopenko.h"
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

void for10_3Task(){
    float x = 0,y = 0,z = 0;
    unsigned int b = 0;
    wcout << L"Відкрийте (створіть) файл input.txt запишить Українське Слово або знак пунктуації  та закрийте файл з збереженям змін" << endl;
    do{
        wcout <<L"Введіть дійсне число x: ";
        wcin >> x;
        if(wcin.fail()){
            wcout << L"Введені некоректні дані!"<< endl;
        }
    }while(wcin.fail());

    do{
        clearWcin();

        wcout <<L"Введіть дійсне число y: ";
        wcin >> y;
        if(wcin.fail() || y == 0){
            wcout << L"Введені некоректні дані!"<< endl;
            wcout << L"Введіть значення \"У\" ще раз (y≠0)." << endl;

        }
    }while(wcin.fail() || y == 0);

    do{
        clearWcin();

        wcout <<L"Введіть дійсне число z: ";
        wcin >> z;
        if(wcin.fail()){
            wcout << L"Введені некоректні дані!"<< endl;
        }
    }while(wcin.fail());

    do{
        clearWcin();
        int tmp = 0;
        wcout <<L"Введіть натуральне число b: ";
        wcin >> tmp;
        if(wcin.fail() || tmp != abs(tmp) || tmp == 0){
            wcout << L"Введені некоректні дані!"<< endl;
        }else{
            b = tmp;
        }
    }while(wcin.fail() || b == 0);

    task10_3(x,y,z,b);
    wcout << L"Результат виконання ПЗ зєявиться у файлі output.txt" << endl;

}
int main()
{
    consoleToUtf8();
    task10_1();
    task10_2();
    for10_3Task();
    system("pause");
    return 0;
}
