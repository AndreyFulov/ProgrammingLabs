
#include <iostream>
using namespace std;
 
void rev(int);
 
 
int main()
{
    setlocale(LC_ALL, "Russian");
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