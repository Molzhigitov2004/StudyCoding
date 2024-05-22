#include <iostream>

class queue {
  ////////////////////////////
  struct ListNode {
    int value;
    ListNode *next;

    ListNode(int x) : value(x), next(nullptr) {}
  };
  ////////////////////////////
  size_t queue_size;
  ListNode *front;
  ListNode *back;

public:
  queue() : queue_size(0), front(nullptr), back(nullptr) {}

  void push(int x) {
    ListNode *new_node = new ListNode(x);

    if (back == nullptr) {
      front = back = new_node;
    } else {
      back->next = new_node;
      back = new_node;
    }

    queue_size++;
  }

  void pop() {
    if (!front) {
      throw std::out_of_range("Queue is empty");
    }

    ListNode *old_top = front;
    front = front->next;
    delete old_top;

    queue_size--;
  }

  ~queue() {
    ListNode *cur = front;
    while (cur) {
      ListNode *next = cur->next;
      delete (cur);
      cur = next;
    }
    front = nullptr;
    back = nullptr;
  }

  // exercise
  queue(const queue &stk) {
    if (stk.front == nullptr) {
      queue_size = 0;
      front = nullptr;
      back = nullptr;
      return;
    }

    queue_size = 0;
    front = nullptr;
    back = nullptr;

    ListNode *cur = stk.front;

    while (cur) {
      push(cur->value);
      cur = cur->next;
    }
  }

  // exercise
  queue(std::initializer_list<int> ilist) {
    queue_size = 0;
    front = nullptr;
    back = nullptr;

    const int *temp = ilist.begin();
    while (temp != ilist.end()) {
      push(*temp);
      ++temp;
      queue_size++;
    }
  }

  void printQueue() const {
    ListNode *cur = front;
    while (cur) {
      std::cout << cur->value << " ";
      cur = cur->next;
    }
    std::cout << std::endl;
  }
};

int main(void) {
  queue myQueue;
  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);

  myQueue.printQueue();

  myQueue.pop();
  myQueue.printQueue();

  queue hisQueue = {1, 2, 3, 4, 5};
  hisQueue.printQueue();

  queue herQueue(hisQueue);
  herQueue.printQueue();

  return 0;
}