#include <iostream>
#include "container.h"
using namespace std;

int main() {
    Container c;
    c.push_back(10);
    c.push_back(5);
    c.push_back(8);
    c.push_back(9);
    c.push_back(3);

    auto result = c.find_small_el(c);

    if (result != c.end()) {
        cout << "found element: " << *result << endl;
        cout << "inserting 99 after the found element." << endl;
        c.insert_after(result, 99);
        
    } else {
        cout << "element not found" << endl;
    }

    cout << "list contents: ";
    for (auto it = c.begin(); it != c.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}