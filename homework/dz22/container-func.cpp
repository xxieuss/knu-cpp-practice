#include "container.h"

void Container::push_back(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Container::~Container() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// task 2.c
Container::iterator Container::find_small_el(Container& c) {
    auto it = c.begin();
    auto end = c.end();

    if (it == end) return end;
    auto next1 = std::next(it);
    
    if (next1 == end) return end;
    auto next2 = std::next(next1);

    while (next2 != end) {
        if (*it < *next1 && *it < *next2) {
            return it;
        }
        ++it;
        ++next1;
        ++next2;
    }

    return end;
}

// task 4.b
void Container::insert_after(iterator pos, int val) {
    if (pos == end()) return;

    Node* current_node = pos.current;
    Node* new_node = new Node(val);

    new_node->next = current_node->next;
    current_node->next = new_node;

    if (current_node == tail) tail = new_node;
}