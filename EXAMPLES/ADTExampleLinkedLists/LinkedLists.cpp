#include <iostream>

struct linked_list_node {
    int value;
    linked_list_node* next;

    linked_list_node(int x) : 
    value(x), 
    next(nullptr) {}
};

class LinkedList {
private:
    linked_list_node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the beginning
    void insertAtBeginning(int value) {
        linked_list_node* newNode = new linked_list_node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the end
    void insertAtEnd(int value) {
        linked_list_node* newNode = new linked_list_node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        linked_list_node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Function to delete a node with a given value
    void deleteNode(int value) {
        linked_list_node* current = head;
        linked_list_node* prev = nullptr;

        while (current != nullptr && current->value != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Node with value " << value << " not found." << std::endl;
            return;
        }

        if (prev == nullptr) {
            // Deleting the first node
            head = current->next;
        } else {
            // Deleting a node that is not the first
            prev->next = current->next;
        }

        delete current;
    }

    // Function to display the elements of the linked list
    void display() {
        linked_list_node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Test your LinkedList implementation here
    LinkedList myList;

    myList.insertAtBeginning(5);
    myList.insertAtEnd(10);
    myList.insertAtBeginning(2);
    myList.insertAtEnd(8);

    std::cout << "Original list: ";
    myList.display();

    myList.deleteNode(10);

    std::cout << "List after deleting node with value 10: ";
    myList.display();

    return 0;
}
