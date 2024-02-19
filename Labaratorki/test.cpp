#include<iostream>
#include <sstream>

int main() {
    int arr[2];
    std::string str = "228 123";
    std::istringstream iss(str);
    iss >> arr[1];
    iss >> arr[0];
    std::cout << str << "\t" << arr[0] << arr[1];
}