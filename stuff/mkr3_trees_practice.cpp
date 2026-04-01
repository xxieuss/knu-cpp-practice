#include <iostream>
using namespace std;

class Tree{
private:
    struct Node{
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* root = nullptr;
    void _add_node(Node* root, int new_data);
    bool _is_in_tree(Node* root, int data);
    void _destructor(Node* root);
    Node* _clone_tree(Node* other_root, Node* root); // копіювання
public:
    ~Tree();
    void add_node(int new_data);
    bool is_in_tree(int data);
    // копіювання
    Tree(const Tree& other);
    Tree& operator=(const Tree& other);
    // переміщення
    Tree(Tree&& other) noexcept;
    Tree& operator=(Tree&& other) noexcept;
};

void Tree::_add_node(Node* root, int new_data){
    if (new_data < root->data){
        if (root->left == nullptr){
            root->left = new Node;
            root->left->data = new_data;
        } else _add_node(root->left, new_data);
    }
    else if (new_data > root->data){
        if (root->right == nullptr){
            root->right = new Node;
            root->right->data = new_data;
        } else _add_node(root->right, new_data);
    }
}
void Tree::add_node(int new_data){
    if (root == nullptr){
        root = new Node;
        root->data = new_data;
    } else _add_node(new_node, new_data);
}

bool Tree::_is_in_tree(Node* root, int data){
    if (root->data > data){
        if (root->left == nullptr) return 0;
        return _is_in_tree(root->left, data);
    }
    if (root->data < data){
        if (root->right == nullptr) return 0;
        return _is_in_tree(root->right, data);
    }
    return 1;
}
bool Tree::is_in_tree(int data){
    if (root == nullptr) return 0;
    return _is_in_tree(root, data);
}

void Tree::_destructor(Node* root){
    if (root == nullptr) return;
    _destructor(root->left);
    _destructor(root->right);
    delete root;
}
Tree::~Tree(){
    _destructor(root);
}

Tree::Node* Tree::_clone_tree(Node* root){
    if (root == nullptr) return nullptr;
    Node* new_node = new Node;
    new_node->data = root->data;
    new_node->left = _clone_tree(root->left);
    new_node->right = _clone_tree(root->right);
    return new_node;
}
Tree::Tree(const Tree& other){
    root = _clone_tree(other.root);
}
Tree& Tree::operator=(const Tree& other){
    if (this == &other) return *this;
    _destructor(this->root);
    root = _clone_tree(other.root);
    return *this;
}

Tree::Tree(Tree&& other) noexcept{
    swap(this->root, other.root);
}
Tree& Tree::operator=(Tree&& other) noexcept{
    if (this == &other) return *this;
    swap(this->root, other.root);
    return *this;
}
int main(){
    return 0;
}