#pragma once

class Tree {
    struct Node {
        int data;
        Node* left;
        Node* right;
        ~Node();
    };
    Node* _root = nullptr;
    void _add(Node* root, int data);
    Node* _findEl(int findData);
    bool _is_in_tree(Node* root, int data);
    int _count_leaves(Node* root); //task 4
    int _size = 0; // task 7
public:
    void add(int newData);
    bool is_in_tree(int data);
    int count_leaves(); //task 4
    // task 7
    int size();
    bool empty();
    ~Tree();
};