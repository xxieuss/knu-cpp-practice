#include <iostream>
#include "node.h"
using namespace std;

Node* get_node_at(Node* head, int index) {
    Node* current = head;
    for (int i = 1; i < index && current != nullptr; i++) {
        current = current->next;
    }
    return current;
}

int main(){
    Node* head = new Node;
    head->data = 1;
    head->prev = nullptr;
    head->next = nullptr;

    add_node_after(head, 5);
    add_node_after(head, 4);
    add_node_after(head, 3);
    add_node_after(head, 2);

    cout << "Initial list:" << endl;
    print_list(head);
    cout << endl;

    // task 5
    cout << "Swap 2-nd and 3-d el:" << endl;
    Node* n1 = get_node_at(head, 2);
    Node* n2 = get_node_at(head, 3);
    head = swap_el(head, n1, n2);
    print_list(head);
    cout << endl;

    cout << "Swap 2-nd and 4-th el:" << endl;
    n1 = get_node_at(head, 2);
    n2 = get_node_at(head, 4);
    head = swap_el(head, n1, n2);
    print_list(head);
    cout << endl;

    cout << "Swap 1-st and last el:" << endl;
    n1 = get_node_at(head, 1);
    n2 = get_node_at(head, 5);
    head = swap_el(head, n1, n2);
    print_list(head);
    cout << endl;

    cout << "Swap el with itself:" << endl;
    n1 = get_node_at(head, 2);
    head = swap_el(head, n1, n1);
    print_list(head);
    cout << endl;

    // task 7
    SListNode* head1 = new SListNode;
    head1->data = 3;
    head1->next = nullptr;

    add_node_after(head1, 3);
    add_node_after(head1, 2);
    add_node_after(head1, 3);
    add_node_after(head1, 1);
    add_node_after(head1, 3);
    cout << "Initial list1:" << endl;
    print_list(head1);

    cout << "Deleted all 3s in list1: ";
    head1 = delete_all_3(head1);
    print_list(head1);
    cout << endl;
    destructor(head1);
    
    SListNode* head2 = new SListNode;
    head2->data = 3;
    head2->next = nullptr;
    add_node_after(head2, 3);
    add_node_after(head2, 3);
    cout << "Initial list2:" << endl;
    print_list(head2);

    cout << "Deleted all 3s in list2: ";
    head2 = delete_all_3(head2);
    print_list(head2);
    cout << endl;
    destructor(head2);

    SListNode* head3 = new SListNode;
    head3->data = 1;
    head3->next = nullptr;
    add_node_after(head3, 4);
    add_node_after(head3, 2);
    cout << "Initial list3:" << endl;
    print_list(head3);

    cout << "Deleted all 3s in list3: ";
    head3 = delete_all_3(head3);
    print_list(head3);
    cout << endl;
    destructor(head3);

    // task 8
    cout << "Initial list:" << endl;
    print_list(head);
    cout << "After bubble sorting:" << endl;
    head = bubble_sort(head);
    print_list(head);
    cout << endl;
    destructor(head);

    // task 11.a
    SListNode* stack_head = nullptr;
    push(stack_head, 10);
    push(stack_head, 20);
    push(stack_head, 30);
    cout << "Stack list after pushing 10, 20, 30:" << endl;
    print_list(stack_head);
    cout << endl;

    cout << "Stack after popping:" << endl;
    pop(stack_head);
    print_list(stack_head);
    cout << endl;

    while (stack_head != nullptr) {
        pop(stack_head);
    }

    // task 11.b
    SListNode* queue_head = nullptr;
    SListNode* queue_tail = nullptr;
    enqueue(queue_head, queue_tail, 1);
    enqueue(queue_head, queue_tail, 2);
    enqueue(queue_head, queue_tail, 3);
    cout << "Queue after pushing 1, 2, 3:" << endl;
    print_list(queue_head);
    cout << endl;

    cout << "Queue after popping:" << endl;
    dequeue(queue_head, queue_tail);
    print_list(queue_head);

    while (queue_head != nullptr) {
        dequeue(queue_head, queue_tail);
    }
    return 0;
}