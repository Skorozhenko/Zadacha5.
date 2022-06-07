#include <iostream>
#include "BinarIntegerTree.h"
using namespace std;

int main() {
    BinarIntegerTree tree;
    vector<int> v = {};
    tree.addElem(10, {});
    tree.addElem(21, {1});
    tree.addElem(7, {0});
    tree.addElem(4, {0, 0});
    tree.addElem(9, {0, 1});
    tree.addElem(2, {0, 0, 0});
    tree.addElem(16, {1, 0});
    tree.addElem(19, {1, 0, 1});
    cout << tree << std::endl;
    cout << "even elements count - " << tree.getEvenCount() << endl;
    cout << "all elements positive? - " << (tree.checkPositive() ? "Yes" : "No") << endl;
    cout << "middle arithmetic - " << tree.getMiddle() << endl;
    v = tree.findElem(16);
    cout << "find elem(16) path: " << v[0] << " " << v[1] << endl;

    tree.addElem(-1, {0, 0, 0});
    tree.addElem(45, {});
    cout << tree << endl;
    cout << "even elements count - " << tree.getEvenCount() << endl;
    cout << "all elements positive? - " << (tree.checkPositive() ? "Yes" : "No") << endl;
    cout << "middle arithmetic - " << tree.getMiddle() << endl;

    tree.deleteAllLeafs();
    cout << tree << endl;
    cout << "even elements count - " << tree.getEvenCount() << endl;
    cout << "all elements positive? - " << (tree.checkPositive() ? "Yes" : "No") << endl;
    cout << "middle arithmetic - " << tree.getMiddle() << endl;
    return 0;
}

