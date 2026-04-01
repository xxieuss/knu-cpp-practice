#include <iostream>
#include <string>
using namespace std;

// task 1.1
class Quadcopter{
private:
    struct Rotor{
        int work_percent;
        bool destroyed;
    };
    Rotor* rotor;
    int destroyed_rotor_counter;
public:
    Quadcopter();
    ~Quadcopter();
    void take_damage(int rotor_index, int damage);
    operator bool() const;
    operator string() const;
};

Quadcopter::Quadcopter(){
    rotor = new Rotor[4];
    int destroyed_rotor_counter = 0;
    for (int i = 0; i < 4; i++) {
        rotor[i].work_percent = 100;
        rotor[i].destroyed = false;
    }
}

Quadcopter::~Quadcopter(){
    delete[] rotor;
}

void Quadcopter::take_damage(int rotor_index, int damage){
    if (rotor_index < 0 || rotor_index > 3) {
        cout << "Invalid rotor index" << endl;
        return;
    }
    if (!rotor[rotor_index].destroyed){
        rotor[rotor_index].work_percent -= damage;
        if (rotor[rotor_index].work_percent <= 0){
            rotor[rotor_index].work_percent = 0;
            rotor[rotor_index].destroyed = true;
            destroyed_rotor_counter++;
            cout << "Rotor " << rotor_index << " is destroyed" << endl;
        }
        return;
    }
    cout << "Rotor has already been destroyed" << endl;
}

Quadcopter::operator bool() const{
    return destroyed_rotor_counter <= 1;
}

Quadcopter::operator string() const{
    if (*this){
        return "Rotor 0: " + to_string(rotor[0].work_percent) + "%, " +
               "Rotor 1: " + to_string(rotor[1].work_percent) + "%, " +
               "Rotor 2: " + to_string(rotor[2].work_percent) + "%, " +
               "Rotor 3: " + to_string(rotor[3].work_percent) + "%";
    }
    return "Quadcopter is destroyed";
}

void quadcopter_simulation(){
    Quadcopter quadcopter;
    while (quadcopter){
        int rotor_index, damage;
        cout << "Enter rotor's index and amount of damage: ";
        cin >> rotor_index >> damage;
        quadcopter.take_damage(int rotor_index, int damage);
        cout << string(quadcopter) << endl;
    }
}

// task 1.2
struct Tree{
    int data;
    Tree* right;
    Tree* left;
};
void del_all_leaves(Tree*& root){
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr){
        delete root;
        root = nullptr
        return;
    }
    del_all_leaves(root->left);
    del_all_leaves(root->right);
}

// task 1.3
struct SLList{
    int data;
    SLList* next = nullptr;
};
void move_head_to_tail(){
    if (head == nullptr || head->next == nullptr) return;
    SLList* old_head = head;
    head = head->next;
    SLList* current = head;
    while (current->next != nullptr){
        current = current->next;
    }
    current->next = old_head;
    old_head->next = nullptr;
}