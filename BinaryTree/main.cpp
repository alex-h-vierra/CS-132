/*
 * @author Alex Vierra
 * This Program will show an organized printed out tree with inputs of
 * an unorganized inputs
 * This will show you how to insert, and print a binary tree in order
 * */
#include <iostream>
#include "TreeClass.h"

int main()
{
    Tree list;
    list.insert(5);
    list.insert(4);
    list.insert(1);
    list.insert(6);
    list.insert(0);
    list.insert(8);
    list.insert(7);
    list.insert(10);
    list.insert(2);
    list.insert(3);
    list.insert(9);
    list.insert(3);
    list.insert(6);
    list.insert(5);

    std::cout << list;
}

