#pragma once

struct Node{
    int data;
    Node* prev = nullptr;
    Node* next = nullptr;
};

void add_node_after(Node* n, int data);
void print_list(Node* head);
Node* delete_node(Node *n);
void destructor(Node* head);

struct SListNode{
    int data;
    SListNode* next;
};

void add_node_after(SListNode* n, int new_data);
void print_list(SListNode* head);
SListNode* delete_node(SListNode *n);
void destructor(SListNode* head);

// task 5
Node* swap_adj_el(Node* head, Node* n);
Node* swap_el(Node* head, Node* n1, Node* n2);

// task 7
SListNode* delete_all_3(SListNode* head);

//task 8
Node* bubble_sort(Node* head);

// task 11.a
void push(SListNode*& head, int new_data);
void pop(SListNode*& head);
// task 11.b
void enqueue(SListNode*& head, SListNode*& tail, int new_data);
void dequeue(SListNode*& head, SListNode*& tail);