#include <iostream>


class stack {
////////////////////////////
struct ListNode{
    int value;
    ListNode* next;

    ListNode(int x):
    value(x),
    next(nullptr){}
};
////////////////////////////
    ListNode *head;
    size_t stack_size;
    public:
    stack():
    head (nullptr),
    stack_size(0){}

    void push(int x){
        ListNode* new_top = new ListNode(x);
        
        new_top->next = head;
        head = new_top;

        stack_size++;
    }

    void pop(){
        if(!head){
            throw std::out_of_range("Stack is empty");
        }
        
        ListNode* old_top = head;
        head = head->next;
        delete old_top;

        stack_size--;
    }


    ~stack(){
        ListNode* cur = head;
        while(cur){
            ListNode* next = cur->next;
            delete(cur);
            cur = next;
        }
    }
    //exercise
    stack(const stack& other) {
        if(other.head == nullptr){
            return;
        }
        head = nullptr;
        stack_size = 0;

        this->head = new ListNode(other.head->value);
        ListNode* This_Current = head;
        stack_size++;

        for(ListNode* Current = other.head->next; Current != nullptr; Current = Current->next){
            This_Current->next = new ListNode(Current->value);
            This_Current = This_Current->next;
            stack_size++;
        }
    }
//exercise
    stack(std::initializer_list<int> ilist) {
        stack_size = 0;
        head = nullptr;
        const int* temp = ilist.begin();
        while (temp != ilist.end()){
            push(*temp);
            temp++;
            stack_size++;
        }
    }

    void printStack() const {
        ListNode* cur = head;
        while (cur) {
            std::cout << cur->value << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

};

int main(void){

    stack myStack;

    // Push some elements into the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Print all values in the stack
    std::cout << "Stack values: ";
    myStack.printStack();




    return 0;
}