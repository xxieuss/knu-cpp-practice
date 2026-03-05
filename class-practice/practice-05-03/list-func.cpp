#include <iostream>
#include "list.h"

void addNodeAfter(Node* n, int data){
    Node* p1 = new Node{data, n->next, n};
    n->next = p1;
    if (p1->next != nullptr) p1->next->prev=p1;
}

void printList(Node* head){
    Node* n_end;
    for (Node* node = head; node != nullptr; node = node->next){
        std::cout << "-> " << node->data << std::endl;
        n_end = node;
    }
    std::cout << std::endl;
    for(Node* node=n_end; node!=nullptr; node=node->prev){
        std::cout << node->data << "<-" << std::endl;
    }
    std::cout << std::endl;
}