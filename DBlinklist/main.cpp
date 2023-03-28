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

void changer(DblLinkedList list);


int main()
{
    DblLinkedList list1, list2, modList1, modList2;
    vector<AVString> words;
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

}

void changer(DblLinkedList list)
{
    list.insert("ZIP");
    list.insert("ZAP");
}
/*
 "C:\Users\alexv\CS 132\DBlinklist\cmake-build-debug\DBlinklist.exe"
List1 count: 1245
List2 count: 1222
ModList1 count: 1245
ModList2 count: 1222

modList2 after removal: 1222
modList1 after removal: 1241
 Inside changer function: size of list1 is 1245
 Inside changer function: size of list1 is 1222

AVString created Word Count: 1973919
AVString current Word Count of list1: 4935

Process finished with exit code 0
*/