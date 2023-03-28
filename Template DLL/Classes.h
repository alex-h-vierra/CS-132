//
// Created by alexv on 2/21/2023.
//
#ifndef DBLINKLIST_CLASSES_H
#define DBLINKLIST_CLASSES_H

#include <istream>
#include <iomanip>
#include <iostream>

using namespace std;

class AVString
{
public:
    AVString(); // default constructor
    AVString(const char *cstr); // cstring constructor
    AVString(const AVString &argStr);
    ~AVString();
    int length();
    int capacity();
    AVString &operator=(const AVString &argStr); // parameter is the object string
    const char *c_str(); //helps print string array
    AVString operator+(const AVString &lV);
    void checkCap();
    char operator[](int count);
    bool operator==(const AVString &argStr);
    bool operator>(const AVString &argStr);
    bool operator<(const AVString &argStr);
    bool operator!=(const AVString &argStr);
    friend istream &operator>>(istream &istream1, AVString &argStr);
    friend ostream &operator<<(ostream &ostream1, AVString &argStr);
    static int getCreatedCount();
    static int getCurrentCount();
private:
    // went out of bounds
    // that checks if bubble sort
    // you want to compare
    int compareTo(const AVString &argStr); //parameter is the object string
    char *str; //data of the new string that's created
    int end; //holds the end of string that's passed in
    int cap; //calculate the length of string
    static int currentCount;
    static int createdCount;
};


template<typename T>
class Node
{   // fully defined here due to its simplicity
public:
    Node()
    {
        next = prev = nullptr;
    }

    Node(const T &object)
    {
        data = object;
        next = prev = nullptr;
    }

    T data;
    Node *next;
    Node *prev;
};

template<typename T>
class DblLinkedList
{
public:
    DblLinkedList();
    DblLinkedList(const DblLinkedList<T> &dLL);
    DblLinkedList &operator=(const DblLinkedList<T> &dll);
    ~DblLinkedList();

    friend ostream &operator<<(ostream &ostream1, DblLinkedList<T> &argStr)
    {
        int endLineCount = 0;
        argStr.resetIterator();
        while (argStr.hasMore())
        {
            if (endLineCount == 10)
            {
                ostream1 << endl;
                endLineCount = 0;
            }
            ostream1 << setw(3) << argStr.it->data << " ";
            argStr.next();
            endLineCount++;
        }
        return ostream1;
    }

    void resetIterator() const;
    bool hasMore() const;
    T &next() const;
    void testConnections();
    bool remove(const T &argStr);
    int getCount() const;
    bool insert(const T &str);
private:
    Node<T> *head, *tail;
    mutable Node<T> *it;    // mutable says that it can change in a const member function
    int count;
};

template<typename T>
DblLinkedList<T>::DblLinkedList()
{
    head = nullptr;
    tail = nullptr;
    it = nullptr;
    count = 0;
}

template<typename T>
DblLinkedList<T>::DblLinkedList(const DblLinkedList<T> &dLL)
{
    head = tail = it = nullptr;
    resetIterator();
    count = getCount();
    while (it != nullptr)
    {
        it->data = dLL.it->data;
        dLL.next();
    }
}

template<typename T>
DblLinkedList<T> &DblLinkedList<T>::operator=(const DblLinkedList<T> &dll)
{
    dll.resetIterator();
    if (dll.it != nullptr)
    {
        dll.resetIterator();
        while (dll.it != nullptr)
        {
            insert(dll.next());
        }
    }
    return *this;
}

template<typename T>
DblLinkedList<T>::~DblLinkedList()
{
    delete[] it;
}

/*
 * resets it to head pointer
 * */

template<typename T>
void DblLinkedList<T>::resetIterator() const
{
    it = head;
}

/*
 * Checks to see if there is another node within the DLL
 * */
template<typename T>
bool DblLinkedList<T>::hasMore() const
{
    if (head != nullptr)
    {
        if (it != nullptr)
        {
            return true;
        }
        return false;
    }
    return false;
}


/*
 * Description: points it to the next data within the DLL
 * */
template<typename T>
T &DblLinkedList<T>::next() const
{
    T &temp = it->data;
    it = it->next;
    return temp;
}

template<typename T>
void DblLinkedList<T>::testConnections()
{
    // write test for connections:  loop through the list testing each node
    it = head;
    if (head == nullptr)
    {
        cout << "Empty list";
    }
    if (head == tail)
    {
        cout << "One Node";
    }
    resetIterator();
    while (it != nullptr)
    {
        if (it != it->next->prev)
        {
            system("pause");
            cout << "Problem at Node: " << it->data.c_str() << " ";
        }
        else
        {
            cout << it->data.c_str();
            next();
        }
    }
    cout << "TEST CONNECTIONS Passed\n";
}

/*
 * @param: AVString object
 * pre: it will make the passed in object go through a checklist for it not to be removed
 * post: it will remove the node and sure the lines together after nodes been removed under the conditions
 * description: this function will remove the node if it is a repeating node */
template<typename T>
bool DblLinkedList<T>::remove(const T &argStr)
{
    resetIterator();
    while (it != nullptr)
    {
        if (it->data == argStr)
        {
//            DblLinkedList<T> *temp = it;
            if (it == head)
            {
                head = head->next;
                head->prev = nullptr;
            }
            else if (it == tail)
            {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else
            {
                it->prev->next = it->next;
                it->next->prev = it->prev;
            }
            delete it;
            count--;
            return true;
        }
        return false;
    }
    cout << "not found";
    return false;
}

/*
 * Description: gets count of how many nodes there are
 * */
template<typename T>
int DblLinkedList<T>::getCount() const
{
    return count;
}

/*
 * @Param: Cstring object
 * pre: Will insert the object if object is either smaller than the head or greater than the tail, but
 * will insert if it isn't a repeating word
 * post: Object has been inserted in a orderly fashion from less to greatest
 * Description: This function will insert the object if either its a new head, new tail, or a non repeating object
 * and return true if inserted or false if it is not
 * */

template<typename T>
bool DblLinkedList<T>::insert(const T &objectData)
{
    Node<T> *temp = new Node<T>(objectData);
    Node<T> *before;
    if (head == nullptr)
    {
        head = tail = temp;
        count++;
        return true;
    }
    else if (head->data > objectData && head->data != objectData)
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
        count++;
        return true;
    }
    else if (tail->data < objectData && tail->data != objectData)
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        count++;
        return true;
    }
    else
    {
        resetIterator();
        while (hasMore())
        {
            if (it->data == objectData)
            {
                delete temp;
                return false;
            }
            else if (it->data > objectData)
            {
                before = it->prev;
                it->prev = temp;
                temp->next = it;
                before->next = temp;
                temp->prev = before;
                count++;
                return true;
            }
            next();
        }
    }
    return true;
}

#endif //DBLINKLIST_CLASSES_H
