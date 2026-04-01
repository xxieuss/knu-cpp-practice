#include <iostream>
#include <utility>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};
struct LList{
    int data;
    LList* next = nullptr;
};

// Вставка вузла node після вузла after
void add_node_after(Node* n, int new_data){
    if (n == nullptr) return;
    n1 = new Node*;
    n1->data = new_data;
    n1->prev = n;
    n1->next = n->next;
    if (n->next != nullptr) n->next->prev = n1;
    n->next = n1;
}
void add_node_after(LList* n, int new_data){
    if (n == nullptr) return;
    n1 = new LList*;
    n1->data = new_data;
    n1->next = n->next;
    n->next = n1;
}

// Вилучення вузла, що розташований після вузла after
LList* remove_after_next(LList* after){
    if (after == nullptr || after->next == nullptr) return nullptr;
    LList* delete_node = after->next;
    LList* after_next = delete_node->next;
    after->next = after_next;
    delete delete_node;
    return after_next;
}
// Вилучення вузла remove (відомо, що він не є головою списку)
Node* remove_node(Node* remove){
    if (remove == nullptr) return nullptr;
    Node* remove_prev = remove->prev;
    Node* remove_next = remove->next;
    remove_prev->next = remove_next;
    if (remove_next != nullptr) remove_next->prev = remove_prev;
    delete remove;
    return remove_next;
}

// Обмін двох сусідніх елементів послідовності
Node* swap_adj_el(Node* head, Node* node){
    if (head == nullptr || node == nullptr || node->next == nullptr) return head;

    Node* a = node;
    Node* b = node->next;
    Node* prev_a = a->prev;
    Node* next_b = b->next;

    if (prev_a == nullptr) head = b;
    else prev_a->next = b;

    if (next_b != nullptr) next_b->prev = a;

    b->prev = prev_a;
    b->next = a;
    a->prev = b;
    a->next = next_b;
    
    return head;
}
// Обмін місцями двох елементів node1 та node2
Node* swap_el(Node* head, Node* node1, Node* node2) {
    if (head == nullptr || node1 == nullptr || node2 == nullptr || node1 == node2) return head;

    if (node2->next == node1) swap(node1, node2);

    if (node1->next == node2) {
        Node* prev_n1 = node1->prev;
        Node* next_n2 = node2->next;

        if (prev_n1 == nullptr) head = node2;
        else prev_n1->next = node2;

        if (next_n2 != nullptr) next_n2->prev = node1;

        node2->prev = prev_n1;
        node2->next = node1;
        node1->prev = node2;
        node1->next = next_n2;
        
        return head;
    }

    Node* prev_n1 = node1->prev;
    Node* next_n1 = node1->next;
    Node* prev_n2 = node2->prev;
    Node* next_n2 = node2->next;

    if (prev_n1 == nullptr) head = node2;
    else prev_n1->next = node2;
    
    if (prev_n2 == nullptr) head = node1;
    else prev_n2->next = node1;

    if (next_n1 != nullptr) next_n1->prev = node2;
    if (next_n2 != nullptr) next_n2->prev = node1;

    node2->prev = prev_n1;
    node2->next = next_n1;
    node1->prev = prev_n2;
    node1->next = next_n2;

    return head;
}

// Бульбашкове сортування
Node* bubble_sort(Node* head){
    if (head == nullptr || head->next == nullptr) return head;
    bool swapped;
    Node* last_sorted = nullptr;
    do{
        swapped = false;
        Node* current = head;
        while (current != nullptr && current->next != last_sorted){
            if (current->data > current->next->data){
                Node* a = current;
                Node* b = current->next;
                Node* prev_a = a->prev;
                Node* next_b = b->next;

                if (prev_a == nullptr) head = b;
                else prev_a->next = b;

                if (next_b != nullptr) next_b->prev = a;

                b->prev = prev_a;
                b->next = a;
                a->prev = b;
                a->next = next_b;

                swapped = true;
            } else current = current->next;
        }
        last_sorted = current;
    } while (swapped);
    return head;
}

// Сортування злиттям
LList* merge(LList* left, LList* right){ // злиття відсортованих списків (правого та лівого)
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    LList dummy; // фіктивна голова
    LList* tail = &dummy; // хвіст нового злитого списку
    dummy.next = nullptr;

    while (left != nullptr && right != nullptr){
        if (left->data <= right->data){
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    if (left != nullptr) tail->next = left;
    else tail->next = right;

    return dummy.next;
}
LList* get_mid(LList* head){ // пошук середини початкового списку
    if (head == nullptr || head->next == nullptr) return head;

    LList* slow = head; // зупиниться в кінці першої половини списку
    LList* fast = head->next;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
LList* merge_sort(LList* head){ // головна сортуюча функція
    if (head == nullptr || head->next == nullptr) return head;

    LList* middle = get_mid(head);
    LList* next_middle = middle->next;
    middle->next = nullptr; // розриваємо список наполовину

    LList* left_sorted = merge_sort(head);
    LList* right_sorted = merge_sort(next_middle);

    return merge(left_sorted, right_sorted);
}

// Реалізувати клас DLList, що реалізує циклічний двобічно звʼязний список з фіктивною
// головою і підтримує операції вставки/вилучення даних з обох кінців списку.
// Розглянути випадки, коли список зберігає:
// -- рядки
// -- дійсні числа
// Реалізувати копіювання та переміщення.
// Реалізувати стек та чергу як обгортки цього списку.
class DLList{
private:
    struct Node{
        bool is_string;
        string str_data;
        double num_data;

        Node* prev;
        Node* next;
    };
    Node* dummy; // фіктивна голова
public:
    DLList();
    ~DLList();
    // копіювання
    DLList(const DLList& other);
    DLList& operator=(const DLList& other);
    // переміщення
    DLList(DLList&& other) noexcept;
    DLList& operator=(DLList&& other) noexcept;
    // операції вставки
    void push_front(const string& value);
    void push_back(const string& value);
    void push_front(double value);
    void push_back(double value);
    // операції вилучення
    void pop_front();
    void pop_back();
    // метод для обгорток
    bool empty() const;
    // метод, що вилучає перше входження заданого елемента в послідовність
    void remove(const string& value);
    void remove(double value);
};
// реалізація обгорток
class Stack{
private:
    DLList list;
public:
    void push(double value){ list.push_front(value); }
    void push(const string& value){ list.push_front(value); }
    void pop(){ list.pop_front(); }
    bool empty() const {return list.empty(); }
};
class Queue{
private:
    DLList list;
public:
    void push(double value){ list.push_back(value); }
    void push(const string& value){ list.push_back(value); }
    void pop(){ list.pop_front(); }
    bool empty() const {return list.empty(); }
};
// реалізація методів класу
DLList::DLList(){
    dummy = new Node;
    dummy->is_string = false;
    dummy->num_data = 0.0;
    dummy->next = dummy;
    dummy->prev = dummy;
}
DLList::~DLList(){
    Node* current = dummy->next;
    while (current != dummy){
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
    delete dummy;
}
DLList::DLList(const DLList& other){
    dummy = new Node;
    dummy->is_string = false;
    dummy->num_data = 0.0;
    dummy->next = dummy;
    dummy->prev = dummy;

    Node* current = other.dummy->next;
    while (current != other.dummy){
        if (current->is_string) push_back(current->str_data);
        else push_back(current->num_data);
        current = current->next;
    }
}
DLList& DLList::operator=(const DLList& other){
    if (this == &other) return *this;

    Node* current = dummy->next;
    while (current != dummy){
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
    dummy->next = dummy;
    dummy->prev = dummy;
    
    current = other.dummy->next;
    while (current != other.dummy){
        if (current->is_string) push_back(current->str_data);
        else push_back(current->num_data);
        current = current->next;
    }

    return *this;
}
DLList::DLList(DLList&& other) noexcept{
    dummy = new Node;
    dummy->is_string = false;
    dummy->num_data = 0.0;
    dummy->next = dummy;
    dummy->prev = dummy;

    swap(this->dummy, other.dummy);
}
DLList& DLList::operator=(DLList&& other) noexcept{
    if (this == &other) return *this;
    swap(this->dummy, other.dummy);
    return *this;
}
void DLList::push_front(const string& value){
    Node* n = new Node;
    n->is_string = true;
    n->str_data = value;
    Node* old_head = dummy->next;
    n->prev = dummy;
    n->next = old_head;
    dummy->next = n;
    old_head->prev = n;
}
void DLList::push_back(const string& value){
    Node* n = new Node;
    n->is_string = true;
    n->str_data = value;
    Node* old_tail = dummy->prev;
    n->prev = old_tail;
    n->next = dummy;
    dummy->prev = n;
    old_tail->next = n;
}
void DLList::push_front(double value){
    Node* n = new Node;
    n->is_string = false;
    n->num_data = value;
    Node* old_head = dummy->next;
    n->prev = dummy;
    n->next = old_head;
    dummy->next = n;
    old_head->prev = n;
}
void DLList::push_back(double value){
    Node* n = new Node;
    n->is_string = false;
    n->num_data = value;
    Node* old_tail = dummy->prev;
    n->prev = old_tail;
    n->next = dummy;
    dummy->prev = n;
    old_tail->next = n;
}
bool DLList::empty() const{
    return dummy->next == dummy;
}
void DLList::pop_front(){
    if (empty()) return;
    Node* tmp = dummy->next;
    dummy->next = tmp->next;
    tmp->next->prev = dummy;
    delete tmp;
}
void DLList::pop_back(){
    if (empty()) return;
    Node* tmp = dummy->prev;
    dummy->prev = tmp->prev;
    tmp->prev->next = dummy;
    delete tmp;
}

void DLList::remove(const string& value){
    Node* current = dummy->next;
    while (current != dummy){
        if (current->is_string && current->str_data == value){
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return;
        }
        current = current->next;
    }
}
void DLList::remove(double value){
    Node* current = dummy->next;
    while (current != dummy){
        if (!current->is_string && current->num_data == value){
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return;
        }
        current = current->next;
    }
}

int main(){
    return 0;
}