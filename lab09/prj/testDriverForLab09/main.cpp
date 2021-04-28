#include <iostream>
#include "modulesprokopenko.h"
#include <cmath>
using namespace std;

void moduleTest9_1(){
    int task91[5] = {0,1,7,12,-6};
    struct forTask9_1 result;
    wstring mesage = L"";
    wcout << L"Testing the module task 9_1" << endl;
    for (int i = 0; i<5; i++){
        switch (task91[i]) {
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
        if (result.speed == task9_1(task91[i]).speed && result.character == task9_1(task91[i]).character ){
            mesage = L"passed! ";
        }
        else{
            mesage = L"Fail ";
        }
        wcout << L"Test case № "<< i+1 << L" іs " << mesage <<  endl;
    }
}
void moduleTest9_2(){
    wstring mesage = L"";
    bool vectorCondition = true;
    struct forTask9_2 result;
    int task92[5][2] = {{1,2},{1,1},{7,6},{12,-3},{-6,6}};
    int n = 0;
    int m = 0;
    wcout << L"Testing the module task 9_2" << endl;
    for(int i = 0; i<5; i++){
        vectorCondition = true;
        n = task92[i][0];
        m = task92[i][1];
        result.forNToM.clear();
        result.mPowN = 0;
        result.nPowM = 0;
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
            for ( int j = n; j <= m; j++)
                if (abs(j % 2) == 1)
                    result.forNToM.push_back(j);
        }else{
            for ( int j = n; j >= m; j--)
                if (abs(j % 2) == 1)
                    result.forNToM.push_back(j);
        }

        if( result.forNToM.size() == task9_2(n,m).forNToM.size()){
            for(int j = 0; j < (int)result.forNToM.size(); j++){
                if(result.forNToM[j] != task9_2(n,m).forNToM[j] )
                    vectorCondition = false;
            }

        }else{
            vectorCondition = false;
        }
        if (  vectorCondition && result.mPowN == task9_2(n,m).mPowN && result.nPowM == task9_2(n,m).nPowM ){
            mesage = L"passed! ";
        }
        else{
            mesage = L"Fail ";
        }
        wcout << L"Test case № "<< i+1 << L" іs " << mesage <<  endl;
    }
}

void moduleTest9_3(){
    wcout << L"Testing the module task 9_3" << endl;
    wstring mesage = L"";
    int result = 0;
    bool flag = false;
    int task93[5] = {1,2,3,4,0};
    for( int i = 0; i < 5; i++){
        result = 0;
        flag = false;
        for (int n=sizeof(int)*8-1; n>-1; n--)  {
            if((task93[i]>>n)&1)
                if(!flag) {
                    flag = true;
                }
            if (flag){
                if((task93[i]>>2)&1){
                    result += ((task93[i]>>n)&1)? 1 : 0;
                }else{
                    result += ((task93[i]>>n)&1)? 0 : 1;
                }
            }
        }

        if (result == task9_3(task93[i])){
            mesage = L"passed! ";
        }
        else{
            mesage = L"Fail ";
        }
        wcout << L"Test case № "<< i+1 << L" іs " << mesage <<  endl;
    }
}
int main()
{
    consoleToUtf8();
    moduleTest9_1();
    moduleTest9_2();
    moduleTest9_3();
    system("pause");
    return 0;
}
