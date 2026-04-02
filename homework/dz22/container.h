#pragma once
#include <iterator>

class Container {
private:
    struct Node {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;

public:
    void push_back(int val);

    class iterator {
        friend class Container;
    private:
        Node* current;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = int;
        using difference_type = std::ptrdiff_t;
        using pointer = int*;
        using reference = int&;

        iterator(Node* node) : current(node) {}

        reference operator*() const { return current->value; }
        
        iterator& operator++() {
            current = current->next; 
            return *this; 
        }
        
        bool operator!=(const iterator& other) const { return current != other.current; }
        bool operator==(const iterator& other) const { return current == other.current; }
    };

    class const_iterator; 

    iterator begin() noexcept { return iterator(head); }
    iterator end() noexcept { return iterator(nullptr); }

    // task 2.c
    iterator find_small_el(Container& c);

    // task 4.b
    void insert_after(iterator pos, int val);

    ~Container();
};