#include <iostream>
#include <windows.h>
enum Floors {
    LIVING, COMMERCIAL
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Floors building[51];
    for(int i=0;i<(sizeof(building)/sizeof(*building));i++) {
        if(i == 0 || i == 1 || i ==2 || i == 50 || i%10==0) {
            building[i] = COMMERCIAL;
        }else{
            building[i] = LIVING;
        }
    }
    int in;
    std::cout << "Введите этаж отбытия:" << std::endl;
    std::cin >> in;
    int out;
    std::cout << "Введите этаж прибытия:" << std::endl;
    std::cin >> out;
    int res = 0;
    if(in < out) {
        for(int i = in; i <= out; i++){
            switch (building[i])
            {
            case LIVING:
                res+= 1;
                break;
            case COMMERCIAL:
                res+=2;
                break;
            default:
                break;
            }
        }
    }else{
        for(int i = in; i >= out; i--){
            switch (building[i])
            {
            case LIVING:
                res+= 1;
                break;
            case COMMERCIAL:
                res+=2;
                break;
            default:
                break;
            }
        }
    }
    std::cout<<"Расчетное время поездки: " << res << std::endl;
}