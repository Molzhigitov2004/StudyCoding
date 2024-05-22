#ifndef STACK_H_
#define STACK_H_

#include <ostream>

class stack {
    int *values;
    size_t stack_size;
    size_t array_capacity;
public:

    stack();//Creates empty stack


    stack(const stack& stk);//Copy constructor


    stack(std::initializer_list<int> ilist);//Initializer list constructor


    stack& operator=(const stack& stk);//Copy assignment


    void push(int val);//Insert an item at the top of the stack


    int peek() const;// Returns value of the topmost item of the stack
                     // Throws an exception if the stack is empty
    void pop();

    void clear();//removes everything from the stack

    size_t size() const;//returns size of the stack

    bool empty() const;// Checks if stack is empty

    void print(std::ostream& out) const;// Prints all contents of stack

    ~stack();//Destructor
};

inline std::ostream& operator<<(std::ostream& out, const stack& stk) {
    stk.print(out);
    return out;
}

#endif /* STACK_H_ */