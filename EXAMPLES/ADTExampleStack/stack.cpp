#include <stdexcept>
#include <ostream>
#include "stack.h"

stack::stack():
    stack_size(0),
    values(new int[5]),
    array_capacity(5)
{

}

stack::stack(const stack& stk):
values(new int[stk.array_capacity]),
    stack_size(stk.stack_size),
    array_capacity(stk.array_capacity)
{
    for(int i = 0; i < stk.stack_size; i++){
        values[i] = stk.values[i];
    }
}

stack::stack(std::initializer_list<int> ilist):
        stack_size(ilist.size()),
        values(new int[ilist.size()]),
        array_capacity(ilist.size())
    {
        size_t i = 0;
        for(int val : ilist){
            values[i] = val;
            ++i;
        }
    }

stack& stack::operator=(const stack& stk){
    if (this == &stk) {
        return *this;
    }

    delete[] values;
    values = new int[stk.array_capacity];
    array_capacity = stk.array_capacity;
    stack_size = stk.stack_size;
    for(int i = 0; i < stk.stack_size; i++){
        values[i] = stk.values[i];
    }
    return *this;
}

void stack::push(int val){ //What if no more free space in stack?
    if(stack_size == array_capacity){
    int *new_values = new int[2*array_capacity];
    for(int i = 0; i < stack_size; i++){
        new_values[i] = values[i];
    }
    delete[] values;
    values = new_values;
    }
    values[stack_size] = val;
    stack_size++;
}

int stack::peek() const{
    if (stack_size == 0) {
        throw std::out_of_range("Cannot peek an empty stack.");
    }
    return values[stack_size-1];
}

void stack::pop(){
    if (stack_size == 0) {
        throw std::out_of_range("Cannot pop an empty stack.");
    }
    stack_size--;
}

void stack::clear(){
    stack_size = 0;
}

size_t stack::size() const{
    return stack_size;
}

bool stack::empty() const{
    return(stack_size == 0);
}

void stack::print(std::ostream& out) const{
    out << "[";
    for(size_t i = 0; i < stack_size; i++){
        if(i > 0){
            out <<",";
        }
        out << values[i];
    }
    out << "]";
}

stack::~stack(){
    delete[] values;
}