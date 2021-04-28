#include "modulesprokopenko.h"
#include <cmath>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include <limits>

forTask9_1 task9_1( char ball ){
    struct forTask9_1 result;
    switch (ball) {
    case 0: result.speed = L"< 0.3";
        result.character = L"Штиль";
        break;
    case 1: result.speed = L"0.3 - 1.5";
        result.character = L"Тихий";
        break;
    case 2: result.speed = L"1.6 - 3.4";
        result.character = L"Легкий";
        break;
    case 3: result.speed = L"3.5 - 5.4";
        result.character = L"Слабкий";
        break;
    case 4: result.speed = L"5.5 - 7.9";
        result.character = L"Помірний";
        break;
    case 5: result.speed = L"8.0 - 10.7";
        result.character = L"Свіжий";
        break;
    case 6: result.speed = L"10.8 - 13.8";
        result.character = L"Сильний";
        break;
    case 7: result.speed = L"13.9 - 17.1";
        result.character = L"Міцний";
        break;
    case 8: result.speed = L"17.2 - 20.7";
        result.character = L"Дуже міцний";
        break;
    case 9: result.speed = L"20.8 - 24.4";
        result.character = L"Шторм";
        break;
    case 10: result.speed = L"24.5 - 28.4";
        result.character = L"Сильний шторм";
        break;
    case 11: result.speed = L"28.5 - 32.6";
        result.character = L"Жорстокий шторм";
        break;
    case 12: result.speed = L"≥ 32.6";
        result.character = L"Ураган (Буревій)";
        break;
    default: result.speed = L"None";
        result.character = L"None";
        break;
    }
    return result;
}



double s_calculation(float x, float y, float z)
{
    double S = z * sin(pow(x,2) * y) + sqrt(fabs(z - 12 * x)) / pow(y,3);
    return S;
}

void consoleToUtf8()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    SetCurrentConsoleFontEx(GetStdHandle(STD_INPUT_HANDLE), FALSE, &cfi);
    _wsetlocale(LC_ALL,L"");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

forTask9_2 task9_2(int n, int m)
{
    forTask9_2 result;
    if(m < 0){
       result.nPowM += 1/(pow(n,abs(m)));
    }else{
       result.nPowM = pow(n,m);
    }
    if(n < 0){
       result.mPowN += 1/pow(m,abs(n));
    }else{
       result.mPowN = pow(m,n);
    }


    if ( n < m ){
        for ( int i = n; i <= m; i++)
            if (abs(i % 2) == 1)
                result.forNToM.push_back(i);
    }else{
        for ( int i = n; i >= m; i--)
            if (abs(i % 2) == 1)
                result.forNToM.push_back(i);
    }
    return result;
}

int task9_3(int N){
    int result = 0;
    bool flag = false;
    for (int n=sizeof(int)*8-1; n>-1; n--)  {
        if((N>>n)&1)
            if(!flag) {
                flag = true;
            }
        if (flag){
            if((N>>2)&1){
                result += ((N>>n)&1)? 1 : 0;
            }else{
                result += ((N>>n)&1)? 0 : 1;
            }
        }
    }
    return result;
}

std::wstring devInfo(){
    std::wstring info = L"╔══════════════════════════════════════════════════════╗\n"
                         "║Виконав студент групи КБ20 Прокопенко Єгор Сергійович©║\n"
                         "╚══════════════════════════════════════════════════════╝\n";
    return info;
}


void clearWcin(){
    std::wcin.clear();
    std::wcin.ignore(std::numeric_limits < std::streamsize > :: max(), '\n');
}

