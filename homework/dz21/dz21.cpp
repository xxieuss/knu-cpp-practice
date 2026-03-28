#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    Tree tree;
    cout << "is tree empty at start? " << (tree.empty() ? "Yes" : "No") << endl; // task 7
    cout << "initial size: " << tree.size() << endl; // task 7
    cout << tree.is_in_tree(5) << endl;
    cout << "leaves in empty tree: " << tree.count_leaves() << endl; // task 4

    tree.add(5);
    tree.add(3);
    tree.add(10);
    tree.add(7);
    tree.add(13);

    cout << "5: " << tree.is_in_tree(5) << endl;
    cout << "3: " << tree.is_in_tree(3) << endl;
    cout << "1: " << tree.is_in_tree(1) << endl;
    cout << "4: " << tree.is_in_tree(4) << endl;
    cout << "7: " << tree.is_in_tree(7) << endl;
    cout << "10: " << tree.is_in_tree(10) << endl;

    // task 4
    cout << "total leaves: " << tree.count_leaves() << endl;

    tree.add(1);
    tree.add(4);
    cout << "new total leaves: " << tree.count_leaves() << endl;

    // task 7
    cout << "is tree empty now? " << (tree.empty() ? "Yes" : "No") << endl;
    cout << "final size: " << tree.size() << endl;
    tree.add(5);
    cout << "size after adding duplicate 5: " << tree.size() << endl;
}