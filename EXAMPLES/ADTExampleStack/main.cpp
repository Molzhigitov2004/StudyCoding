#include <iostream>
#include "stack.h"
int main(){
    stack stk1 = {11,22,33,44};
    stack stk2;

    stk2.push(99);
    stk2.push(88);
    stk2.push(77);
   
    int val = stk2.peek();
    std::cout << "I saw " << val << "on stk2" << std::endl;

    stack stk3(stk2);
    stk2.pop();

    std::cout <<stk1 << std::endl;
    std::cout <<stk2 << std::endl;
    std::cout <<stk3 << std::endl;

    return 0;
}