//
// Created by alexv on 3/28/2023.
//

#ifndef BINARYTREE_TREECLASS_H
#define BINARYTREE_TREECLASS_H

#include <fstream>

class Tree{
public:
    class Node{
    public:
        Node() : left(nullptr), right(nullptr), data(0) {}
        explicit Node(int val) : left(nullptr), right(nullptr), data(val){}
        int data;
        Node *left, *right;
    };
    Tree() : count (0), root(nullptr) {}
    bool insert(int newVal);
    friend std::ostream& operator << (std::ostream& ostream1, const Tree& tree);
private:
    void print(std::ostream& ostream1, Node* currentNode) const;
    Node* root;
    int count;
};
#endif //BINARYTREE_TREECLASS_H
