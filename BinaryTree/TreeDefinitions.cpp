//
// Created by alexv on 3/28/2023.
//
#include <iostream>
#include "TreeClass.h"

bool Tree::insert(int newVal)
{
    Node *temp = new Node(newVal);
    Node *iterator;
    if (root == nullptr)
    {
        root = temp;
        count++;
        return true;
    }
    iterator = root;
    while (iterator != nullptr)
    {
        if (iterator->data == temp->data)
        {
            delete temp;
            return false;
        }
        else if (iterator->data > temp->data)
        {
            if (iterator->left == nullptr)
            {
                iterator->left = temp;
                count++;
                return true;
            }
            iterator = iterator->left;
        }
        else if (iterator->data < temp->data)
        {
            if (iterator->right == nullptr)
            {
                iterator->right = temp;
                count++;
                return true;
            }
            iterator = iterator->right;
        }
    }
    return true;
}
std::ostream &operator << (std::ostream& ostream1, const Tree& tree)
{
    tree.print(ostream1, tree.root);
    std::cout << std::endl << "Tree Count: " << tree.count << " ";
    return ostream1;
}
void Tree::print(std::ostream &ostream1, Node *currentNode) const
{
    if (currentNode->left != nullptr)
    {
        print(ostream1, currentNode->left);
    }
    std::cout << currentNode->data << " ";
    if (currentNode->right != nullptr)
    {
        print(ostream1, currentNode->right);
    }
}
