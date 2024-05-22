#ifndef QUEUE_H_
#define QUEUE_H_

#include <ostream>

class queue {

    int *values;

    size_t queue_size;
    size_t array_capacity;
    size_t front_pos;
    size_t back_pos;
    
public:

    queue(); //Creates an empty queue

    queue(const queue& q); //Copy constructor

    queue(std::initializer_list<int> ilist); //Initializer list

    queue& operator=(const queue& q); //Copy assignment

    void push(int val); //Inserts value to the back of the queue

    int peek() const; //Returns value of frontmost item of the queue
                      //Throws an exception if queue is empty

    void pop(); //Removes the frontmost item from the queue
                //Throws an exception if queue is empty

    void clear(); //Removes everything from the queue

    size_t size() const; //Returns the number of items in the queue

    bool empty() const; //Returns whether or not the queue is currently empty

    void print(std::ostream& out) const; //Print out contents of the queue

    ~queue(); //Destructor
};

#endif