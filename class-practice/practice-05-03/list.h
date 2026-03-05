#pragma once
#include <iostream>

struct Node{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

void addNodeAfter(Node* n, int data);
void printList(Node* head);
void deleteNode(Node* p);
void add6After7(Node* head);
void deleteDublicates(Node* head);
void destructor(Node* head);