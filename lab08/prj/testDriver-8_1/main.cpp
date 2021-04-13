#include <iostream>
#include "modulesprokopenko.h"
#include <cmath>
#include <string>
using namespace std;

int main()
{
    consoleToUtf8();
    double testArray[30] ={123,23,23,12.75,78,95,12.75,35,75,12,38,76,1,18,36,-1,-18,-78,245678123,456786456,-333568978,-666,-666,666,589,89,586,13,5,4} ;
    float x,y,z;
    double result = 0;
    wstring mesage;
    for (int i = 0; i < 30; i++){
        switch (i%3) {
        case 0: x = testArray[i];
            break;
        case 1: y = testArray[i];
            break;
        case 2: z = testArray[i];
            result = z * sin(pow(x,2) * y) + sqrt(fabs(z - 12 * x)) / pow(y,3) ;
            if (fabs(result - s_calculation(x,y,z)) < 0.0000001){
                mesage = L"passed! ";
            }
            else{
                mesage = L"Fail ";
            }
            wcout << L"Test case № "<< (i-i%3)/3 +1 << L" іs " << mesage <<  endl;
            break;
        }

    }
    system("pause");
    return 0;
}
