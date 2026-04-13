#include <iostream>
#include "tree.h"
using namespace std;

bool isBST(Tree& tree){
    Tree::Iterator it = tree.begin();
    Tree::Iterator end = tree.end();
    if (!(it != end)) return true;
    int prev = *it;
    ++it;
    while (it != end){
        int current = *it;
        if (current <= prev) return false;
        prev = current;
        ++it;
    }
    return true;
}

int main(){
    Tree tree;
    tree.add(10);
    tree.add(5);
    tree.add(3);
    tree.add(8);
    tree.add(1);
    tree.add(4);
    tree.add(18);
    tree.add(13);
    tree.add(15);
    tree.add(16);

    cout << "in-order: ";
    for (Tree::Iterator it = tree.begin(); it != tree.end(); ++it){
        cout << *it << " -> ";
    }
    cout << endl;

    if (isBST(tree)) cout << "This tree is BST" << endl;
    else cout << "This tree is not BST" << endl;
    return 0;
}