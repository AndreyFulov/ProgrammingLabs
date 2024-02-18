    
#include <iostream>
#include <windows.h>
using namespace std;
 
void rev(int);
 
 
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int N;
 
    cout << "Введите N: ";
    cin >> N;
    rev(N);
 
    cout << endl;
    system("pause");
    return 0;
}
 
void rev(int x)
{
    cout << x % 10 << " ";
    if (x >=10)
        rev(x / 10);    
    
}