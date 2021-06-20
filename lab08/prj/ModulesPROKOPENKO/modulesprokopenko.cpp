#include "modulesprokopenko.h"
#include <cmath>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include <limits>
#include <fstream>
#include <ctime>

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
    std::wstring info = L"╔════════════════════════════════════════════════════════════════════╗\n"
                         "║Розробник: Прокопенко Єгор Сергійович, ЦНТУ, м. Кропивницький, 2021©║\n"
                         "╚════════════════════════════════════════════════════════════════════╝\n";
    return info;
}


void clearWcin(){
    std::wcin.clear();
    std::wcin.ignore(std::numeric_limits < std::streamsize > :: max(), '\n');
}


errno_t task10_1(std::string inputFileName,  std::string outputFileName)
{
    std::wstring str = L"";
    std::wifstream inFile(inputFileName);
    if(inFile.is_open()){
        if(!inFile.eof()){
            getline(inFile,str);
        }
        inFile.close();
        
    }else{
        return 1; // Can`t open input file
    }
    
    std::wofstream outFile(outputFileName);
    if(outFile.is_open()){
        outFile << devInfo();
        
        std::wstring vignettes = L"\'\".,;:~`!-?[]{}ЁёЪъэЭ"; // 0..14 punctuation marks
        bool ukranianword = true;
        int letterInWord = 0;
        for(int i = 0; i < int(str.length()); i++){
            if (ukranianword){
                if( (str[i] < L'А' || str[i] > L'я' ) && (str[i] !=L'і' &&  str[i] !=L'І')){
                    ukranianword = false;
                    letterInWord = 0;

                    std::wofstream inFile(inputFileName,std::ios::app);
                    if(inFile.is_open()){
                        for(char j = 0; j < int(vignettes.length());j++){
                            if(i == 0 && str[i] == vignettes[j] && int(str.length()) == 1 && j < 16 ){
                                outFile << L"У вхідному файлі є тільки один знак пунктуації!"<<std::endl;
                                inFile << L"\nХай щастить!"<<std::endl;
                                break;

                            }else{
                                if(j+1 == 16 || int(str.length()) > 1){
                                    inFile << L"\nПерший космонавт України: Каденюк Леонід Костянтинович"<<std::endl;
                                    break;
                                }
                            }
                        }
                        inFile.close();
                    }else{
                        return 2; // Can`t open output file
                    }
                    break;
                }
            }else{
                break;
            }
            if(ukranianword){
                letterInWord += 1;
            }
        }
        if(letterInWord > 0){
            std::wstring  wordsInPoem  = L"ХАЙ ЩАСТИТЬ У ВАШІЙ ХАТІ, МАМО,"
                                         L"ВСІМ, ХТО ПЕРЕСТУПІТЬ ВАШ ПОРІГ:"
                                         L"ДОБРИМ ЛЮДЯМ, І ПТАХАМ ТАК САМО,"
                                         L"І КОТОВІ, ЩО В ТЕПЛІ ПРИЛІГ;"
                                         L"ХАЙ ЩАСТИТЬ КОЖНЕНЬКІЙ ДЕРЕВИНІ,"
                                         L"ЩО ДО ХАТИ ВІТИ ПРИТУЛЯ,"
                                         L"ХАЙ ЩАСТИТЬ МАЛЕСЕНЬКІЙ ТРАВИНІ"
                                         L"Й ВІТЕРЦЮ, ЩО ПРИЛІТА ЗДАЛЯ.";
            
            
            outFile << L"Кількість літер у слові \" " << str << " \" : " << std::to_wstring(letterInWord) << std::endl;
            std::wstring word = L"";
            
            
            for(int i = 0; i < int(str.length()); i++)
                if(str[i] >= L'а' && str[i] <= L'я'){
                    str[i] =  str[i] +  L'А' - L'а';
                }else{
                    if(str[i] == L'і')
                        str[i] = L'І';
                }
            
            for(int i = 0; i < int(wordsInPoem.length()); i++){
                if((wordsInPoem[i] >= L'А' && wordsInPoem[i] <= L'Я')  || wordsInPoem[i] == L'І'){
                    word += wordsInPoem[i];
                }else{
                    if(str == word){
                        
                        outFile << L"Введене слово є у вірші А. Тарана \"Хай щастить у Вашій хаті, Мамо!\"" << std::endl;;
                        break;
                    }else{
                        if(i+1 == int(wordsInPoem.length())){
                            outFile << L"Введого слова  немає у вірші А. Тарана \"Хай щастить у Вашій хаті, Мамо!\"" << std::endl; ;
                        }
                        word = L"";
                    }
                }
            }
        }else{
            outFile << L"У вхідному файлі немає Українського Слова!!!"<< std::endl;
        }
        
        outFile.close();
    }else{
        return 2; // can`t open output file
    }
    return 0;
}



errno_t task10_2( std::string inputFileName)
{
    std::wofstream inFile(inputFileName,std::ios::app);
    if(inFile.is_open()){
        std::wstring poem = L"Хай щастить у Вашій хаті, мамо,\n"
                            L"Всім, хто переступіть Ваш поріг:\n"
                            L"Добрим людям, і птахам так само,\n"
                            L"І котові, що в теплі приліг;\n"
                            L"Хай щастить кожненькій деревині,\n"
                            L"Що до хати віти притуля,\n"
                            L"Хай щастить малесенькій травині\n"
                            L"Й вітерцю, що приліта здаля.\n"
                            L"Ви завжди за всіх були дбайливі -\n"
                            L"Бо така ж та доля у вдови."
                            L"Бо ж як будуть всі навкруг щасливі,\n"
                            L"То щасливі будете і Ви.\n";
        inFile << std::endl << L"Вірш А.Тарана \"Хай щастить у Вашій хаті, мамо!\":\n" <<  poem << std::endl;
        time_t times = std::time(nullptr);
        inFile << L"Час дозапису :"  << std::asctime (std::localtime( &times ))<< std::endl;
        inFile.close();
        
    }else{
        return 1; // Can`t open input file
    }

    
    return 0;
}




errno_t task10_3(float x, float y, float z , unsigned int b, std::string outputFileName)
{
    std::wofstream outFile(outputFileName,std::ios::app);
    if(outFile.is_open()){
        bool flag = false;
        outFile << L"Результат роботи модулю s_calculation: " << s_calculation(x,y,z) << std::endl;
        outFile << L"Число "  << b << L" у двійковому коді: ";
        for(int i = sizeof(unsigned int)-1; i > -1; i--){
            if(!flag && (b>>i)&1)
                flag = true;
            
            if(flag)
                outFile << ((b>>i)&1);
        }
        outFile << std::endl;
    }else{
        return 2;
    }
    outFile.close();
    return 0;
}
