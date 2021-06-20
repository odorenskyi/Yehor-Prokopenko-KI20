#ifndef MODULESPROKOPENKO_H
#define MODULESPROKOPENKO_H
#include<iostream>
#include<string>
#include <vector>


void clearWcin();

struct forTask9_2{
    double nPowM = 0;
    double mPowN = 0;
    std::vector<int> forNToM;
};

struct forTask9_1{
    std::wstring character = L"", speed = L"";
};
struct forTask9_2;
void consoleToUtf8();
double s_calculation(float x, float y, float z);
int task9_3(int N);
struct forTask9_1 task9_1(char ball);
struct forTask9_2 task9_2(int n, int m);
std::wstring devInfo();

errno_t task10_1(const std::string inputFileName = "input.txt",const std::string outputFileName = "output.txt" );
errno_t task10_2(const std::string inputFileName = "input.txt");
errno_t task10_3(float x, float y, float z , unsigned int b, const std::string outputFileName = "output.txt");


#endif // MODULESPROKOPENKO_H
