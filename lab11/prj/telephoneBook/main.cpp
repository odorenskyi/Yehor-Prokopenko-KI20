#include <iostream>
#include <prj_11_lib.h>
#include <windows.h>
#include <map>
using namespace std;


void greenTextInConsole(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void showMenu(){
    cout << "==================================================================================" << endl;;
    cout << "| Розроблено студентами групи КБ-20: Прокопенко Є.С., Ховренко Є.Д., Кривда О.С. |" << endl;
    cout << "| Програма для роботи із електроним довідником телефонних кодів міст України     |" << endl;
    cout << "==================================================================================" << endl << endl;
    cout << "Список команд:" <<endl;
    cout << "1: Пошук запису в довіднику за введеним кодом міста;" <<endl;
    cout << "2: Пошук запису в довіднику за введеною назвою міста;" <<endl;
    cout << "3: Виведення всього довідника на екран;" <<endl;
    cout << "4: Виведення всього довідника у текстовий файл \"Довідник телефонних кодів міст України.txt\";" <<endl;
    cout << "5: Додавання нового запису у довідник;" << endl;
    cout << "6: Видалення запису із довідника за введеним кодом міста;" << endl;
    cout << "7: Видалення запису із довідника за введеною назвою міста;" << endl;
    cout << "0: Завершеня роботи програми." << endl<<endl;

}
int inputInt(string message){
    int code = 0;
    do{
        if (cin.fail()|| code < 0){
            cout << "Введена невірно команда або дані!\nБудь ласка спробуйте ще раз! " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits < std::streamsize > :: max(), '\n');
        }
        cout << message << endl;
        cout << "Ваш код:>";
        cin >> code;
    }while(cin.fail()|| code < 0);
    return code;
}
void goToMenu(map<string,int> &cityCode){
    int cmd = 0;
    do{
        if (cin.fail()){
            cout << "Введена невірно команда або дані!\nБудь ласка спробуйте ще раз! " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits < std::streamsize > :: max(), '\n');
        }
        cout << "Для повернення до головного меню введіть 1 , а для завершення роботи програми будь яку іншу цифру" << endl;
        cout << "Введіть номер команди:>";
        cin >> cmd;
    }while(cin.fail());
    if(cmd == 1){
        system("cls");
        showMenu();
    }else{
        saveFile(cityCode);
        exit(0);
    }
}
void comand1(map<string,int> &cityCode){
    map<string,int> result = search(inputInt("Введіть телефонний код, щоб дізнатися що це за місто. "),cityCode);
    if(result.empty()){
        cout << "Нажаль Вашому коду не відповідає жодна запис у телефонній книзі"<< endl;

    }else{
        cout << "Запис знайдено!"<< endl<< endl;
        showPhoneBookConcole(result);
        cout<< endl;
    }
}

void comand2(map<string,int> &cityCode){
    cout << "Введіть Ваше місто (з великої літери), щоб дізнатися його код. "<< endl;
    cout << "Ваше місто:>";
    string city;
    cin >> city;
    map<string,int> result = search(city,cityCode);
    if(result.empty()){
        cout << "Нажаль Вашому місту не відповідає жодна запис у телефонній книзі"<< endl;

    }else{
        cout << "Запис знайдено!"<< endl<< endl;
        showPhoneBookConcole(result);
        cout<< endl;
    }
}
void comand5(map<string,int> &cityCode){
    cout << "Введіть місто!" << endl;
    cout << "Ваше місто:>";
    string city;
    cin >> city;
    int code = 0;
    do{
        if (cin.fail() || code < 0){
            cout << "Введена невірно команда або дані!\nБудь ласка спробуйте ще раз! " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits < std::streamsize > :: max(), '\n');
        }
        cout << "Введіть телефонний код, для міста \""<< city <<"\""<< endl;
        cout << "Ваш код:>";
        cin >> code;
    }while(cin.fail() || code < 0);

    addNewCIty(city,code,cityCode);
}


void comand7(map<string,int> &cityCode){
    cout << "Введіть Ваше місто (з великої літери), яке ви бажаете видалити. "<< endl;
    cout << "Ваше місто:>";
    string city;
    cin >> city;

    removeCity(city,cityCode);
}


void comand(map<string,int> &cityCode){
    int cmd = 0;
    while(true){
        do{
            if (cin.fail() || cmd < 0 || cmd > 7){
                cout << "Введена невірно команда або дані!\nБудь ласка спробуйте ще раз! " << endl;
                cin.clear();
                cin.ignore(std::numeric_limits < std::streamsize > :: max(), '\n');
            }
            cout << "Введіть номер команди:>";
            cin >> cmd;
        }while(cin.fail() || cmd < 0 || cmd > 7);

        switch (cmd) {
        case 0:
            saveFile(cityCode);
            exit(0);
            break;
        case 1:
            comand1(cityCode);
            break;
        case 2:
            comand2(cityCode);
            break;
        case 3:
            cout << endl;
            showPhoneBookConcole(cityCode);

            break;
        case 4:
            showPhoneBookFile("Довідник телефонних кодів міст України.txt",cityCode);
            cout << "Файл \"Довідник телефонних кодів міст України.txt\" був успішно створений.\nФайл знаходиться у тій же директорії що і цей застосунок! " << endl;
            break;
        case 5:
            comand5(cityCode);
            break;
        case 6:
            removeCity(inputInt("Введіть телефонний код, щоб видалити всі міста із таким кодом. "),cityCode);
            break;
        case 7:
            comand7(cityCode);
            break;
        }
        goToMenu(cityCode);
    }
}

int main()
{
    greenTextInConsole();
    showMenu();
    map<string,int> cityCode = readPhoneBook() ;
    comand(cityCode);
    return 0;
}
