#include<string>
#include<iostream>
using namespace std;
int main() {
    string stroka1;
    string stroka2;
    cin >> stroka1;

    for (int i = 0; i < stroka1.length(); i++) {
        if ('0' <= stroka1[i] && stroka1[i] <= '9') {
            stroka2 += to_string((int)stroka1[i]); //Если символ строки - цифра, то заменяем её     
        }
        else
            stroka2 += stroka1[i];// иначе просто переписываем то,что было
    }

    cout << stroka2;
    system("pause");
    return 0;
}