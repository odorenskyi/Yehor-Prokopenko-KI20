#include <iostream>
#include <wchar.h>
#include <fstream>
#include "modulesprokopenko.h"
using namespace std;

int main()
{
    consoleToUtf8();
    wstring writeInInputFile [6] {L",",L"\'\'",L"мамо",L"МаМо",L"Хочу скласти екзамен із БМТП на найвищу оцінку!!!"};
    float dataForTask10_3 [6][4] {{1,1,1,1},{1,5,1,4},{0,5,0,5},{5,6,8,7},{1,5,6,4},{4,58,7,2}};
    wcout << L"Тестування модулю task10_1" << endl;
    for (int i = 0; i < 6; i++){;
        wcout << L"Tast case №"<< i+1 <<" : " ;
        wfstream file ("input.txt",ios::out);
        if(!file.is_open()){
            wcout << "Falied !!!  Помилка! Hе вдається створити вхiдний файл!" << endl;
        }else{
            file << writeInInputFile[i];
            file.close();
            switch (task10_1()) {
            case 1:
                wcout << "Falied !!!  Помилка! Hе відкривається вхiдний файл!" << endl;
                break;
            case 2:
                wcout << "Falied !!!  Помилка! Hе відкривається вихідний файл!" << endl;
                break;
            default:
                wcout << "Passed!" << endl;
            }
        }
    }



    wcout << L"Тестування модулю task10_2" << endl;
    for (int i = 0; i < 6; i++){
        wcout << L"Tast case №"<< i+1 <<" : " ;
        wfstream file ("input.txt",ios::out);
        if(!file.is_open()){
            wcout << "Falied !!!  Помилка! Hе вдається створити вхiдний файл!" << endl;
        }else{
            file << writeInInputFile[i];
            file.close();
            switch (task10_2("input.txt")) {
            case 1:
                wcout << "Falied !!!  Помилка! Hе відкривається вхiдний файл!" << endl;
                break;
            case 2:
                wcout << "Falied !!!  Помилка! Hе відкривається вихідний файл!" << endl;
                break;
            default:
                wcout << "Passed!" << endl;
            }
        }
    }

    wcout << L"Тестування модулю task10_3" << endl;

    for (int i = 0; i < 6; i++)
    {
        wcout << L"Tast case №"<< i+1 <<" : " ;
        wfstream file ("input.txt",ios::out);

            file << writeInInputFile[i];
            file.close();
            switch (task10_3(dataForTask10_3[i][0],dataForTask10_3[i][1],dataForTask10_3[i][2],dataForTask10_3[i][3])) {
            case 1:
                wcout << "Falied !!!  Помилка! Hе відкривається вхiдний файл!" << endl;
                break;
            case 2:
                wcout << "Falied !!!  Помилка! Hе відкривається вихідний файл!" << endl;
                break;
            default:
                wcout << "Passed!" << endl;

        }
    }
    system("pause");
    return 0;
}
