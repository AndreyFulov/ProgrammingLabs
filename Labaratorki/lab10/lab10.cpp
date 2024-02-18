#include<string>
#include<iostream>
using namespace std;
int main() {
    string stroka1;
    string stroka2;
    cin >> stroka1;
    bool isChanging = false;
    for (int i = 0; i < stroka1.length(); i++) {
        if(isChanging) {
            stroka2 += to_string((int)stroka1[i]);
            
        }
        if(stroka1[i] == '\'') {
            isChanging = !isChanging;
        } 
        else
            stroka2 += stroka1[i];// иначе просто переписываем то,что было
    }

    cout << stroka2;
    system("pause");
    return 0;
}