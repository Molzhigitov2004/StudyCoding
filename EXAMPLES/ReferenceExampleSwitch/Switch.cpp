#include <iostream>


void swap (int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    
    int a = 123, b = 456;
    std::cout << "a = " << a << " b = " << b << std::endl;
    swap(a,b);
    std::cout << "a = " << a << " b = " << b << std::endl;

    return 0;

}