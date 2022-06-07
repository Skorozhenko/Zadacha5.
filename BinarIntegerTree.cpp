#include "BinarIntegerTree.h"

using namespace std;

TreeElem::TreeElem(int i, TreeElem *l, TreeElem *r) : info(i), left(l), right(r) {
}

BinarIntegerTree::BinarIntegerTree() : root(nullptr), size(0) {
}

BinarIntegerTree::BinarIntegerTree(int x) : root(new TreeElem(x)), size(1) {
}

// копирование
BinarIntegerTree::BinarIntegerTree(const BinarIntegerTree &copy) {
    if (!copy.root) {
        return;
    }
    size = copy.size;
    TreeElem* copyroot = copy.root;
    copyTree(root, copyroot);
}

// перемещение
BinarIntegerTree::BinarIntegerTree(BinarIntegerTree &&copy) : root(copy.root), size(copy.size) {
    copy.root = nullptr;
    copy.size = 0;
}

BinarIntegerTree::~BinarIntegerTree() {
    deleteTree(root);
    root = nullptr;
}

BinarIntegerTree &BinarIntegerTree::operator=(const BinarIntegerTree &obj) {
    if (this == &obj) { return *this; }
    this->deleteTree(root);
    root = new TreeElem(obj.root->info);
    copyTree(root, obj.root);
    return *this;
}

BinarIntegerTree &BinarIntegerTree::operator=(BinarIntegerTree &&obj) {
    swap(root, obj.root);
    size = obj.size;
    return *this;
}

ostream &operator<<(ostream &os, BinarIntegerTree &obj) {
    obj.printTree(os, obj.root, 0);
    return os;
}



// копирование дерева
void BinarIntegerTree::copyTree(TreeElem *root, TreeElem *copy) {
    if (!copy) {
        return ;
    }
    root = new TreeElem(copy->info);
    copyTree(root->left, copy->left);
    copyTree(root->right, copy->right);
}

// очистка дерева
void BinarIntegerTree::deleteTree(TreeElem *root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
}

// обход дерева
void BinarIntegerTree::printTree(ostream &os, TreeElem *root, int counter) {
    if (!root) return;
    for (int i = 0; i < counter; i++) {
        os << "\t";
    }
    os << root->info << endl;
    printTree(os, root->left, counter + 1);
    printTree(os, root->right, counter + 1);
}


//вставка элемента в дерево. Метод получает на вход число x, которое нужно
// вставить, и последовательность из 0 и 1, кодирующую путь в дереве:
// 0 – переход к левому потоку текущего узла, 1 – к правому. Если путь ведет
// в уже существующий узел, то число в нем заменяется на x. Если путь проходит
// через лист дерева и заканчивается на уровень ниже, то в это место добавляется
// новый узел как потомок листа. В остальных случаях — ошибка.
void BinarIntegerTree::addElem(int x, vector<int> path) {
    TreeElem *current = root;
    if (!root && path.size() > 0) {
        throw exception();
    }
    if (!root && path.size() == 0) {
        root = new TreeElem(x);
        return;
    }
    if (path.size() == 0) {
        root->info = x;
        return;
    }
    for (int i = 0; i < (path.size() - 1); i++) {
        if (path[i] == 0) {
            current = current->left;
        }
        if (path[i] == 1) {
            current = current->right;
        }
        if (path[i] != 1 && path[i] != 0) {
            throw exception();
        }
    }
    if (!current || (path.back() != 1 && path.back() != 0)) {
        throw exception();
    }
    if (path.back() == 0) {
        if (!current->left) {
            current->left = new TreeElem(x);
            size++;
        } else {
            current->left->info = x;
        }
    }
    if (path.back() == 1) {
        if (!current->right) {
            current->right = new TreeElem(x);
            size++;
        } else {
            current->right->info = x;
        }
    }
}

//количество четных
int BinarIntegerTree::getEvenCount(TreeElem *root) {
    if (!root) { return 0; }
    if (root->info % 2 == 0) {
        return (1 + getEvenCount(root->left) + getEvenCount(root->right));
    }
    return (getEvenCount(root->left) + getEvenCount(root->right));
}

//положительные числа
bool BinarIntegerTree::checkPositive(TreeElem *root) {
    if (!root) { return true; }
    if (root->info <= 0) { return false; }
    if (!checkPositive(root->left)) {
        return false;
    }
    if (!checkPositive(root->right)) {
        return false;
    }
    return true;
}

//удаление листьев
bool BinarIntegerTree::deleteAllLeafs(TreeElem *root) {
    if (!root) { return false; }
    if (!root->left && !root->right) {
        delete root;
        return true;
    } else {
        if (deleteAllLeafs(root->left)) {
            root->left = nullptr;
        }
        if (deleteAllLeafs(root->right)) {
            root->right = nullptr;
        }
    }
    return false;
}

//среднее арифметическое
double BinarIntegerTree::getSum(TreeElem *root) {
    if (!root) { return 0; }
    return (root->info + getSum(root->left) + getSum(root->right));
}

bool BinarIntegerTree::findElem(TreeElem *root, int x, vector<int> &path) {
    if (!root) { return false; }
    if (root->info == x) {
        return true;
    }
    path.push_back(0); //добавляем 0 в конец, идем влево
    if (findElem(root->left, x, path)) { return true; }
    path.pop_back(); //удаляем последний элемент
    path.push_back(1); //идем вправо
    if (findElem(root->right, x, path)) { return true; }
    path.pop_back();
    return false;
}

vector<int> BinarIntegerTree::findElem(int x) {
    vector<int> path = {};
    if (!findElem(root, x, path)) {
        throw exception();
    }
    return path;
}

int BinarIntegerTree::getEvenCount() {
    return getEvenCount(root);
}

bool BinarIntegerTree::checkPositive() {
    return checkPositive(root);
}

void BinarIntegerTree::deleteAllLeafs() {
    deleteAllLeafs(root);
}

double BinarIntegerTree::getMiddle() {
    return getSum(root) / size;
}





