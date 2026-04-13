#include "tree.h"

void Tree::_add(Node* root, int data){
    if (data < root->data){
        if (!(root->left)) root->left = new Node(data);
        else _add(root->left, data);
    }
    else if (data > root->data){
        if (!(root->right)) root->right = new Node(data);
        else _add(root->right, data);
    }
}

void Tree::add(int new_data){
    if (!root) root = new Node(new_data);
    else _add(root, new_data);
}

Tree::~Tree(){
    delete root;
}

Tree::Node::~Node(){
    delete left;
    delete right;
}

void Tree::Stack::push(Tree::Node* node){
    StackNode* new_node = new StackNode(node);
    new_node->next = top_node;
    top_node = new_node;
}

void Tree::Stack::pop(){
    if (top_node){
        StackNode* tmp = top_node;
        top_node = top_node->next;
        delete tmp;
    }
}

Tree::Node* Tree::Stack::top(){
    return top_node ? top_node->stack_node : nullptr;
}

bool Tree::Stack::empty() const{
    return top_node == nullptr;
}

Tree::Stack::~Stack(){
    while (!empty()){
        pop();
    }
}

void Tree::Iterator::push_left(Tree::Node* node){
    while (node != nullptr){
        stack.push(node);
        node = node->left;
    }
}

Tree::Iterator::Iterator(Tree::Node* root){
    push_left(root);
    current = stack.empty() ? nullptr : stack.top();
}

int Tree::Iterator::operator*(){
    return current->data;
}

Tree::Iterator& Tree::Iterator::operator++(){
    if (stack.empty()) return *this;
    Node* tmp = stack.top();
    stack.pop();
    push_left(tmp->right);
    current = stack.empty() ? nullptr : stack.top();
    return *this;
}

bool Tree::Iterator::operator!=(const Iterator& other) const{
    return current != other.current;
}

Tree::Iterator Tree::begin(){
    return Iterator(root);
}

Tree::Iterator Tree::end(){
    return Iterator(nullptr);
}