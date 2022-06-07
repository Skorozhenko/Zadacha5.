#ifndef ZADACHA5_BINARINTEGERTREE_H
#define ZADACHA5_BINARINTEGERTREE_H

#pragma once
#include "iostream"
#include "vector"
#include "climits"

using namespace std;

struct TreeElem { //элемент дерева
    int info;
    TreeElem* left;
    TreeElem* right;

    TreeElem(int info, TreeElem *left = nullptr, TreeElem *right = nullptr);
};

class BinarIntegerTree {
private:
    TreeElem* root;
    int size;

    void copyTree(TreeElem *root, TreeElem *copy);

    void deleteTree(TreeElem *root);

    void printTree(ostream &os, TreeElem *root, int counter);

    int getEvenCount(TreeElem *root);

    bool checkPositive(TreeElem *root);

    bool deleteAllLeafs(TreeElem *root);

    double getSum(TreeElem *root);

    bool findElem(TreeElem *root, int x, vector<int> &patn);

public:
    BinarIntegerTree();

    BinarIntegerTree(int);

    BinarIntegerTree(const BinarIntegerTree&);

    BinarIntegerTree(BinarIntegerTree&&);

    ~BinarIntegerTree();

    BinarIntegerTree &operator=(const BinarIntegerTree &copy);

    BinarIntegerTree &operator=(BinarIntegerTree &&copy);

    friend ostream &operator<<(ostream &os, BinarIntegerTree &obj);

    void addElem(int x, vector<int> path);

    int getEvenCount();

    bool checkPositive();

    void deleteAllLeafs();

    double getMiddle();

    vector<int> findElem(int x);
};


#endif //ZADACHA5_BINARINTEGERTREE_H
