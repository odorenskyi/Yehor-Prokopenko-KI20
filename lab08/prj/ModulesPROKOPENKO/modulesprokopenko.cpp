#include "modulesprokopenko.h"
#include <cmath>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <windows.h>
#include <wchar.h>
#include <locale.h>


double s_calculation(float x, float y, float z)
{
    double S = z * sin(pow(x,2) * y) + sqrt(fabs(z - 12 * x)) / pow(y,3);
    return S;
}

void consoleToUtf8()
{
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
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
