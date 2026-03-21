#include "node.h"
#include <iostream>

// add node funcs
void add_node_after(Node* n, int new_data){
    if (n == nullptr) return;
    Node* n1 = new Node;
    n1->data = new_data;
    n1->prev = n;
    n1->next = n->next;
    if (n->next != nullptr) {
        n->next->prev = n1;
    }
    n->next = n1;
}
void add_node_after(SListNode* n, int new_data){
    if (n == nullptr) return;
    SListNode* n1 = new SListNode;
    n1->data = new_data;
    n1->next = n->next;
    n->next = n1;
}

// print list funcs
void print_list(Node* head){
    Node* tail = nullptr;
    for (Node* current = head; current != nullptr; current = current->next){
        std::cout << current->data << " ";
        tail = current;
    }
    std::cout << std::endl;
}
void print_list(SListNode* head){
    for (SListNode* current = head; current != nullptr; current = current->next){
        std::cout << current->data << " ";
    }
    std::cout << std::endl;
}

// del node funcs
Node* delete_node(Node *n) {
    if (n == nullptr)
        return nullptr;
    Node *n1 = n->next;
    if (n->next) n->next->prev = n->prev;
    if (n->prev) n->prev->next = n->next;
    delete n;
    return n1;
}
SListNode* delete_node(SListNode *n) {
    if (n == nullptr)
        return nullptr;
    SListNode *n1 = n->next;
    delete n;
    return n1;
}

// destructor funcs
void destructor(Node* head){
    Node* tmp = nullptr;
    if (!head) return;
    while (head){
        head = delete_node(head);
    }
}
void destructor(SListNode* head){
    if (!head) return;
    while (head){
        head = delete_node(head);
    }
}

// task 5
Node* swap_adj_el(Node* head, Node* n){
    if (head == nullptr || n == nullptr || n->next == nullptr) return head;

    Node* a = n;
    Node* b = n->next;
    Node* prev_a = a->prev;
    Node* next_b = b->next;

    if (prev_a != nullptr) prev_a->next = b;
    else head = b;

    if (next_b != nullptr) next_b->prev = a;

    b->prev = prev_a;
    b->next = a;
    a->prev = b;
    a->next = next_b;

    return head;
}
Node* swap_el(Node* head, Node* n1, Node* n2){
    if (n1 == nullptr || n2 == nullptr || n1 == n2) return head;
    if (n1->next == n2) return swap_adj_el(head, n1);
    else if (n2->next == n1) return swap_adj_el(head, n2);

    Node* prev_n1 = n1->prev;
    Node* next_n1 = n1->next;
    Node* prev_n2 = n2->prev;
    Node* next_n2 = n2->next;

    if (prev_n1 != nullptr) prev_n1->next = n2;
    else head = n2;
    if (next_n1 != nullptr) next_n1->prev = n2;

    if (prev_n2 != nullptr) prev_n2->next = n1;
    else head = n1;
    if (next_n2 != nullptr) next_n2->prev = n1;

    n1->prev = prev_n2;
    n1->next = next_n2;
    n2->prev = prev_n1;
    n2->next = next_n1;

    return head;
}

// task 7
SListNode* delete_all_3(SListNode* head){
    while (head && head->data == 3){
        SListNode* curr_head = head;
        head = head->next;
        delete curr_head;
    }
    SListNode* current = head;
    while (current != nullptr && current->next != nullptr){
        if (current->next->data == 3){
            SListNode* tmp = current->next;
            current->next = tmp->next;
            delete tmp;
        } else current = current->next;
    }
    return head;
}

// task 8
Node* bubble_sort(Node* head){
    if (head == nullptr || head->next == nullptr) return head;
    bool swapped;
    Node* last_sorted = nullptr;
    do{
        swapped = false;
        Node* current = head;
        while (current->next && current->next != last_sorted){
            if (current->data > current->next->data){
                head = swap_adj_el(head, current);
                swapped = true;
            } else current = current->next;
        }
        last_sorted = current;
    } while (swapped);
    return head;
}

// task 11.a
void push(SListNode*& head, int new_data){
    SListNode* n1 = new SListNode;
    n1->data = new_data;
    SListNode* old_head = head;
    n1->next = head;
    head = n1;
}
void pop(SListNode*& head){
    if (head == nullptr) return;
    SListNode* current_head = head;
    head = head->next;
    delete current_head;
}
// task 11.b
void enqueue(SListNode*& head, SListNode*& tail, int new_data){
    SListNode* n1 = new SListNode;
    n1->data = new_data;
    n1->next = nullptr;
    if (tail == nullptr){
        head = n1;
        tail = n1;
    } else {
        tail->next = n1;
        tail = n1;
    }
}
void dequeue(SListNode*& head, SListNode*& tail){
    pop(head);
    if (head == nullptr) tail = nullptr;
}