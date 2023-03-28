/*
 * Double cstring Linked List
 * @Author Alex Vierra
 * Section B
 * Description:
 * This program will make a node for every Cstring
 * depending on if it's not a repeating Word and print the count of created words,
 * and how many words it tried to create */

#include <iostream>
#include "Classes.h"
#include <vector>
#include <fstream>

template<typename T>
void changer(DblLinkedList<T> list);


int main()
{
    DblLinkedList<AVString> list1, list2, modList1, modList2;
    ifstream fin1("infile1.txt");
    ifstream fin2("infile2.txt");
    ofstream outFile1("modList1.txt");
    ofstream outFile2("modList2.txt");
    if (fin1.fail() || fin2.fail())
    {
        std::cout << "File Not Opened";
    }
    AVString temp;
    while (fin1 >> temp)
    {
        list1.insert(temp);
    }
    while (fin2 >> temp)
    {
        list2.insert(temp);
    }
    modList1 = list1;
    modList2 = list2;

    cout << "List1 count: " << list1.getCount() << endl;
    cout << "List2 count: " << list2.getCount() << endl;
    cout << "ModList1 count: " << modList1.getCount() << endl;
    cout << "ModList2 count: " << modList2.getCount() << endl << endl;

    list1.resetIterator();
    while(list1.hasMore())
    {
        modList2.remove(list1.next());
    }
    cout << "modList2 after removal: " << modList2.getCount() << endl;
    list2.resetIterator();
    while(list2.hasMore())
    {
        modList1.remove(list2.next());
    }
    cout << "modList1 after removal: " << modList1.getCount() << endl;

    changer(list1);
    cout << " Inside changer function: size of list1 is " << list1.getCount() << endl;
    changer(list2);
    cout << " Inside changer function: size of list1 is " << list2.getCount() << endl
         << endl;

    cout << "AVString created Word Count: " << temp.getCreatedCount() << endl;
    cout << "AVString current Word Count of list1: " << temp.getCurrentCount() << endl;

    outFile1 << modList1;
    outFile2 << modList2;

    DblLinkedList<int> intList;
    for (int i = 20; i > 0; i -= 2)
        intList.insert(i);

    for (int i = 25; i > 0; i -= 5)
        intList.insert(i);

    cout << "intlist: " << intList << "  size:" << intList.getCount() << endl << endl;

    DblLinkedList<double> dblList;
    for (double i = 10.9; i > 0; i -= .57)
        dblList.insert(i);

    for (double i = 24.8; i > 5; i -= .64)
        dblList.insert(i);

    cout << "dblList: " << dblList << "  size:" << dblList.getCount() << endl << endl;
}

template<typename T>
void changer(DblLinkedList<T> list)
{
    list.insert("ZIP");
    list.insert("ZAP");
}
/*
 * "C:\Users\alexv\CS 132\DBlinklist - Copy\cmake-build-debug\DBlinklist.exe"
List1 count: 742
List2 count: 701
ModList1 count: 742
ModList2 count: 701

modList2 after removal: 700
modList1 after removal: 739
 Inside changer function: size of list1 is 744
 Inside changer function: size of list1 is 703

AVString created Word Count: 7423
AVString current Word Count of list1: 2887
intlist:   2   4   5   6   8  10  12  14  15  16
 18  20  25   size:13

dblList: 0.07 0.64 1.21 1.78 2.35 2.92 3.49 4.06 4.63 5.2
5.6 5.77 6.24 6.34 6.88 6.91 7.48 7.52 8.05 8.16
8.62 8.8 9.19 9.44 9.76 10.08 10.33 10.72 10.9 11.36
 12 12.64 13.28 13.92 14.56 15.2 15.84 16.48 17.12 17.76
18.4 19.04 19.68 20.32 20.96 21.6 22.24 22.88 23.52 24.16
24.8   size:51

*/