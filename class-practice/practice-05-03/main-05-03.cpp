#include <iostream>
#include "list.h"
using namespace std;

int main(){
    Node* head = new Node{1};
    addNodeAfter(head, 4);
    printList(head);

    addNodeAfter(head->next, 7);
    printList(head);

    addNodeAfter(head->next->next, 10);
    printList(head);

    addNodeAfter(head->next, 6);
    printList(head);
    return 0;
}