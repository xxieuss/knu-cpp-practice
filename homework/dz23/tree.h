#pragma once

class Tree{
private:
    struct Node{
        int data;
        Node* right;
        Node* left;
        Node(int val) : data(val), right(nullptr), left(nullptr) {}
        ~Node();
    };

    struct StackNode{
        Node* stack_node;
        StackNode* next;
        StackNode(Node* node) : stack_node(node), next(nullptr) {}
    };
    class Stack{
    private:
        StackNode* top_node = nullptr;
    public:
        void push(Node* node);
        void pop();
        Node* top();
        bool empty() const;
        ~Stack();
    };

    Node* root = nullptr;
    void _add(Node* root, int data);
public:
    void add(int new_data);
    ~Tree();
    class Iterator{
    private:
        Stack stack;
        Node* current;
        void push_left(Node* node);
    public:
        Iterator(Node* root);
        int operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
    };
    Iterator begin();
    Iterator end();
};