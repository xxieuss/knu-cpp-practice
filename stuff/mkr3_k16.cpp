#include <iostream>
#include <string>
using namespace std;

// task 3.1
class Car {
private:
    int total_probig;
    int km_after_oil_change;
    bool engine_block;
public:
    Car(); 
    void change_oil();
    bool drive(int km); 
    operator bool() const;
    void print() const;
};

Car::Car() {
    total_probig = 0;
    km_after_oil_change = 0;
    engine_block = false;
}

void Car::change_oil() {
    if (engine_block) {
        cout << "Engine is already blocked" << endl;
        return;
    }
    km_after_oil_change = 0;
    cout << "Oil has changed" << endl;
}

bool Car::drive(int km) {
    if (engine_block) {
        cout << "Engine is BLOCKED dolboeb" << endl;
        return false;
    }
    total_probig += km;
    km_after_oil_change += km;
    if (km_after_oil_change > 1000) {
        engine_block = true;
        cout << "Not enough oil. Engine is blocked" << endl;
        return false;
    }
    cout << "Car drived " << km << "km" << endl;
    return true;
}

Car::operator bool() const {
    return !engine_block;
}

void Car::print() const {
    cout << "Total probig: " << total_probig << "km" << endl;
    if (engine_block) cout << "Engine is blocked" << endl;
    else {
        cout << "Engine is not blocked" << endl;
        cout << "How much km with oil left: " << 1000 - km_after_oil_change << "km" << endl;
    }
}

// task 3.2
struct Tree {
    int data;
    Tree* right = nullptr;
    Tree* left = nullptr;
};

Tree* find_node_father(Tree* root, Tree* target) {
    if (root == nullptr || root == target) return nullptr;
    if (root->left == target || root->right == target) return root;
    
    Tree* find_left = find_node_father(root->left, target);
    if (find_left != nullptr) return find_left;
    
    return find_node_father(root->right, target);
}

// task 3.3
struct LList {
    int data;
    LList* next = nullptr;
};

void del_all_second(LList*& head) {
    if (head == nullptr || head->next == head) return;
    LList* current = head;
    
    while (current->next != current) { 
        LList* tmp = current->next;
        current->next = tmp->next;
        if (tmp == head) head = current->next;
        delete tmp;
        current = current->next;
    }
}