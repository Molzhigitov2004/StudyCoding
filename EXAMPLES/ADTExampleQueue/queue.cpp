#include "queue.h"
#include <stdexcept>
#include <iostream>

queue::queue():
    values(new int[5]),
    queue_size(0),
    array_capacity(5),
    front_pos(0),
    back_pos(-1)
{

}

queue::queue(const queue& q):
    values(new int[q.array_capacity]),
    queue_size(q.queue_size),
    array_capacity(q.array_capacity),
    front_pos(0),
    back_pos(q.queue_size - 1)
{
    for(size_t i = 0, j = q.front_pos; i < q.queue_size; i++, j = (j+1)%q.array_capacity){
        values[i] = q.values[j];
    }
}

queue::queue(std::initializer_list<int> ilist):
    values(new int[ilist.size()]),
    queue_size(ilist.size()),
    array_capacity(2*ilist.size()),
    front_pos(0),
    back_pos(ilist.size()-1)
{
        size_t i = 0;
        for(int val : ilist){
            values[i] = val;
            ++i;
        }
}

queue& queue::operator=(const queue& q){
    if (this == &q) {
        return *this;
    }
    delete[] values;
    values = new int[q.array_capacity];
    array_capacity = q.array_capacity;
    queue_size = q.queue_size;
    front_pos = 0;
    back_pos = q.queue_size - 1;
    for(size_t i = 0, j = q.front_pos; i < q.queue_size; i++, j = (j+1)%q.array_capacity){
        values[i] = q.values[j];
    }
    return *this;
}

void queue::push(int val){
    if(queue_size == array_capacity){
        int *new_values = new int[2*array_capacity];
        for(size_t i = 0, j = front_pos; i < queue_size; i++, j = (j+1)%array_capacity){
            new_values[i] = values[i];
        }
        front_pos = 0;
        back_pos = queue_size-1;
        delete[] values;
        values = new_values;
        array_capacity = 2 * array_capacity;
    }
    back_pos = (back_pos + 1) % array_capacity;
    values[back_pos] = val;
    queue_size++;
}

int queue::peek() const{
    if (queue_size == 0) {
        throw std::out_of_range("Cannot peek an empty queue.");
    }
    return values[front_pos];
}

void queue::pop(){
    if (queue_size == 0) {
        throw std::out_of_range("Cannot pop an empty queue.");
    }
    queue_size--;
    front_pos = (front_pos + 1) % array_capacity;
}

void queue::clear(){
    queue_size = 0;
    front_pos = 0;
    back_pos = -1;
}

size_t queue::size() const{
    return queue_size;
}

bool queue::empty() const{
    return(queue_size==0);
}

void queue::print(std::ostream& out) const{
    if(queue_size == 0){
        out << "Queue is empty.";
        return;
    }
    out << "[";
    for(size_t i = front_pos; i != back_pos; i = (i+1)%array_capacity){
        if(i > 0){
            out <<",";
        }
        out << values[i];
    }
    out << "]";
}

queue::~queue(){
    delete[] values;
}