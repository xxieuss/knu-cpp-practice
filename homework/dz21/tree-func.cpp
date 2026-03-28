#include "tree.h"

// updated in task 7
void Tree::add(int data) {
    if (!_root){
         _root = new Node{data, nullptr, nullptr};
         _size++;
    }
    else _add(_root, data);
}
void Tree::_add(Node* root, int data) {
    if (data < root->data) {
        if (!(root->left)){
            root->left = new Node{data, nullptr, nullptr};
            _size++;
        }
        else _add(root->left, data);
    }
    else if (data > root->data) {
        if (!(root->right)){
            root->right = new Node{data, nullptr, nullptr};
            _size++;
        }
        else _add(root->right, data);
    }
}

bool Tree::_is_in_tree(Node* root, int data) {
    if (root -> data > data) {
        if (!(root -> left)) return 0;
        else return _is_in_tree(root->left, data);
    }
    if (root -> data < data) {
        if (!(root -> right)) return 0;
        else return _is_in_tree(root->right, data);
    }
    return 1;
}
bool Tree::is_in_tree(int data) {
    if (!(_root)) return 0;
    else return _is_in_tree(_root, data);
}

Tree::~Tree() {
    delete _root;
}

Tree::Node::~Node() {
    delete left;
    delete right;
}

// task 4
int Tree::_count_leaves(Node* root){
    if (root == nullptr) return 0;
    if (root->right == nullptr && root->left == nullptr) return 1;
    return _count_leaves(root->left) + _count_leaves(root->right);
}
int Tree::count_leaves(){
    if (_root == nullptr) return 0;
    return _count_leaves(_root);
}

// task 7
int Tree::size(){
    return _size;
}
bool Tree::empty(){
    return _size == 0;
}