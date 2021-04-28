#include <iostream>
#include <wchar.h>
#include <limits>
#include "modulesprokopenko.h"
#include<cmath>
using namespace std;

void fS_calculation(){
    float x = 0,y = 0,z = 0;
    do{
        clearWcin();

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
        if(wcin.fail()){
            wcout << L"Введені некоректні дані!"<< endl;
        }
    }while(wcin.fail());

    do{
        clearWcin();

        wcout <<L"Введіть дійсне число z: ";
        wcin >> z;
        if(wcin.fail()){
            wcout << L"Введені некоректні дані!"<< endl;
        }
    }while(wcin.fail());


    wcout << L"Результат роботи модулю s_calculation: " << s_calculation(x,y,z) << endl;
}
void fTask9_1(){
    int n = 0;
    do{
        clearWcin();

        wcout <<L"Введіть бал сили вітру за шкалою Бофорта: ";
        wcin >> n;
        if(wcin.fail() || !(n>-1 && n < 13)){
            wcout << L"Введені некоректні дані!"<< endl;
            wcout << L"Бал сили вітру за шкалою Бофорта повинний бути у таких межах ball Є[0;12]!!!\n";
        }
    }while(wcin.fail() || !(n>-1 && n < 13));
    wcout << L"Швидкість вітру у таких межах (м/с): " << task9_1(n).speed << endl;
    wcout << L"Характеристика вітру : " << task9_1(n).character << endl;
}
void fTask9_2(){
    int n = 0 , m = 0;
    do{
        clearWcin();

        wcout <<L"Введіть ціле число n: ";
        wcin >> n;
        if(wcin.fail()){
            wcout << L"Введені некоректні дані!"<< endl;
        }
    }while(wcin.fail());

    do{
        clearWcin();

        wcout <<L"Введіть ціле число m: ";
        wcin >> m;
        if(wcin.fail()){
            wcout << L"Введені некоректні дані!"<< endl;
        }
    }while(wcin.fail());
    wcout << L"n^m: " << task9_2(n,m).nPowM << endl;
    wcout << L"m^n: " << task9_2(n,m).mPowN << endl;


    if (!task9_2(n,m).forNToM.empty()){
        wcout << L"Непарні числа від " << n <<L" до "<< m << L" :";
        for ( int i:task9_2(n,m).forNToM)
            wcout <<" " << i ;
        wcout <<"."<<endl;
    }else{
        wcout << L"Непарні числа в діапазоні від " << n <<L" до "<< m << L" не існують!" << endl;
    }

}

void fTask9_3(){
    int n = 0;
    do{
        clearWcin();

        wcout <<L"Введіть натуральне число N: ";
        wcin >> n;
        if(wcin.fail() || !(n>-1 && n < 8001)){

            wcout << L"Введені некоректні дані!"<< endl;
            wcout << L"Число N повиннo бути цілим та лежати у таких межах [0;8000]!!!\n";
        }
    }while(wcin.fail() || !(n>-1 && n < 8001));
    if((n>>2)&1){
        wcout <<L"Кількість бітових одиниць у веденому числі: "<< task9_3(n) << endl;
    }else{
        wcout <<L"Кількість бітових нулів у введеному числі: "<< task9_3(n) << endl;
    }
}
void info(){
    wcout << L"Введіть одну із команд:\n"
             L"u - викликається функція s_calculation()\n"
             L"o - функція задачі 9.1\n"
             L"р - функція задачі 9.2\n"
             L"a - функція задачі 9.3" << endl;
    wcout << L"Ваша команда: ";
}

int main()
{
    consoleToUtf8();

    wchar_t comand = L' ';

    while(true) {
        system("cls");
        wcout << devInfo() << endl;
        info();
        wcin >> comand;
        clearWcin();

        switch (comand) {
        case L'u':
            fS_calculation();
            exit(system("pause"));
            break;
        case L'o':
        case L'о':
            fTask9_1();
            exit(system("pause"));
            break;
        case L'p':
        case L'р':
            fTask9_2();
            exit(system("pause"));
            break;
        case L'a':
        case L'а':
            fTask9_3();
            exit(system("pause"));
            break;
        default:
            wcout <<L"\aПомилка! \nНевірно введена команда!!! \nДля завершення введіть команду 'S' або 's', для перезапуску - будь-що інше!" << endl;
            wcout << L"Ваша команда: ";
            clearWcin();
            wcin >> comand;
            clearWcin();

            if(comand == L's' || comand == L'S'){
                exit(system("pause"));
            }else{
                system("cls");
            }
            break;
        }

    }
    return 0;
}
