#include <iostream>
#include <string>
using namespace std;

// task 4.1
class Ship {
private:
    struct Deck {
        int x, y;
        bool hit;
    };
    Deck* decks;
    int hit_counter;
    bool is_valid;
public:
    Ship(int x1, int y1, int x2, int y2, int x3, int y3);
    ~Ship();
    bool set(int index, int x, int y);
    bool fire(int x, int y);
    operator bool() const;
    operator string() const;
};

bool Ship::set(int index, int x, int y) {
    if (x >= 1 && x <= 10 && y >= 1 && y <= 10) {
        decks[index] = {x, y, false};
        return true;
    }
    return false;
}

Ship::Ship(int x1, int y1, int x2, int y2, int x3, int y3) {
    decks = new Deck[3];
    hit_counter = 0;
    
    bool d1 = set(0, x1, y1);
    bool d2 = set(1, x2, y2);
    bool d3 = set(2, x3, y3);
    
    is_valid = d1 && d2 && d3;
    
    if (!is_valid) {
        cout << "Error: ship coordinates are out of the 10x10 board" << endl;
    }
}

Ship::~Ship() {
    delete[] decks;
}

bool Ship::fire(int x, int y) {
    if (!is_valid) return false;
    for (int i = 0; i < 3; i++) {
        if (decks[i].x == x && decks[i].y == y) {
            if (!decks[i].hit) {
                decks[i].hit = true;
                hit_counter++;
                return true;
            }
            return false;
        }
    }
    return false;
}

Ship::operator bool() const {
    return hit_counter < 3 && is_valid;
}

Ship::operator string() const {
    if (!is_valid) return "Ship is placed incorrectly";
    if (hit_counter == 0) return "Ship is okidoki";
    if (hit_counter == 3) return "Ship is plakiplaki";
    return "Ship is damaged " + to_string(hit_counter) + " times";
}

void battle() {
    Ship s(1, 2, 3, 4, 5, 6);
    int x, y;
    while(s) {
        cin >> x >> y;
        if (s.fire(x, y)) cout << "good job!" << endl;
        else cout << "shit happens" << endl;
        cout << "ship status: " << string(s) << endl;
    }
    cout << "ship is dead :(" << endl;
}

// task 4.2
struct Node {
    int data;
    Node* right = nullptr;
    Node* left = nullptr;
};

void del_right_node(Node*& root) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        delete root;
        root = nullptr;
        return;
    }
    if (root->right != nullptr) del_right_node(root->right);
    else if (root->left != nullptr) del_right_node(root->left);
}

// task 4.3
struct CNode {
    int data;
    CNode* next = nullptr;
    CNode(int val) : data(val) {}
};

int del_k_node(int n, int k) {
    if (n <= 0 || k <= 0) return 0;
    CNode* head = new CNode(1);
    CNode* prev = head;
    for (int i = 2; i <= n; i++) {
        CNode* node = new CNode(i);
        prev->next = node;
        prev = node;
    }
    prev->next = head;

    CNode* current = head;
    CNode* prev_node = prev;
    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            prev_node = current;
            current = current->next;
        }
        prev_node->next = current->next;
        CNode* tmp = current;
        current = current->next;
        delete tmp;
    }
    int answer = current->data;
    delete current;
    return answer;
}