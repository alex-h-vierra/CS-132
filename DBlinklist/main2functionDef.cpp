/*
 * @author Alex Vierra
 * This main.cpp hold the function that preform the key to sorting
 * , reading and outputting the string
 * */
#include "Classes.h"
#include <iomanip>
#include <vector>
#include <iostream>
#include <cctype> //Included for .ispunc( );

using namespace std;

/*
 * preconditions: calculate new end, and new cap of the giving array
 * post-condition: set a new end, and new cap
 * */
AVString::AVString()
{
    currentCount++;
    createdCount++;
    cap = 20;
    end = 0;
    str = new char[cap];
    str[end] = '\0';
}

/*
 * Para:
 * preconditions: inputs new data, and creates new object char array
 * post-conditions: makes new object char array to
 * compared with object string
 * */

int AVString::currentCount = 0;
int AVString::createdCount = 0;

AVString::AVString(const char *cstr)
{
    currentCount++;
    createdCount++;
    for (end = 0; cstr[end] != '\0'; ++end);
//empty loop
    cap = capacity();
    str = new char[cap];
    for (int i = 0; i <= end; ++i)
    {
        str[i] = cstr[i];
    }
}

AVString::~AVString()
{
    currentCount--;
    delete[] str;
};

AVString::AVString(const AVString &argStr)
{
    currentCount++;
    createdCount++;
    end = argStr.end;
    cap = argStr.cap;
    str = new char[end];
    for (int i = 0; i <= end; i++)
    {
        str[i] = argStr.str[i];
    }
}


/*
 * preconditions: finds the end of an object string
 * post-conditions: sets end to a new object strings end
 */
int AVString::length()
{
    return end;
}

/*
 * preconditions: find the capacity of a string
 * post-conditions: sets cap to the capacity of the string*/
int AVString::capacity()
{
    return cap;
}

char AVString::operator[](int count)
{
    if (count >= 0 && count < end)
    {
        return str[count];
    }
    return '\0';
}

int AVString::compareTo(const AVString &argStr)
{
    int answer = 0;
    int temp = 0;
    int localSize = 0;
    if (this->end < argStr.end)
    {
        localSize = argStr.end;
    }                                                   //split this function
    else
    {
        localSize = this->end;
    }
    for (int i = 0; i < localSize; i++)
    {
        answer = toupper(argStr.str[i]) - toupper(str[i]);
        if (answer != 0)
        {
            return answer;
        }
    }
    return 0;
}

istream &operator>>(istream &istream1, AVString &argStr)
{
    char inputWord[100];
    DblLinkedList list;
    argStr.checkCap();
    if (istream1 >> inputWord)
    {
        if (ispunct(argStr.str[argStr.end - 1]))
        {
            argStr.str[argStr.end - 1] = '\0';
            argStr.end--;
        }
        for (argStr.end = 0; inputWord[argStr.end] != '\0'; ++argStr.end);
        argStr.checkCap();
        for (int i = 0; i <= argStr.end; i++)
        {
            argStr.str[i] = inputWord[i];
        }
    }
    return istream1;
}

bool AVString::operator==(const AVString &argStr)
{
    return (this->compareTo(argStr) == 0);
}

bool AVString::operator<(const AVString &argStr)
{
    return (this->compareTo(argStr) < 0);
}

bool AVString::operator>(const AVString &argStr)
{
    return (this->compareTo(argStr) > 0);
}

bool AVString::operator!=(const AVString &argStr)
{
    return (this->compareTo(argStr) != 0);
}


/*
 * param: object string from the array
 * precondition: checks to see if object is out of bounds
 * post-condition: return the out of bounds
 * to the end of the passed in object
 * */
AVString &AVString::operator=(const AVString &argStr)
{
    if (this != &argStr)
    {
        end = argStr.end;
        cap = argStr.cap;
        delete[] this->str;
        this->str = new char[cap];
        for (int i = 0; i <= end; ++i)
        {
            str[i] = argStr.str[i];
        }
    }
    return *this;
}

const char *AVString::c_str()
{
    return str;
}

AVString AVString::operator+(const AVString &argStr)
{
    AVString comboLvRv;
    comboLvRv.end = this->end + argStr.end;
    comboLvRv.checkCap();
    int i = 0;
    for (i = 0; i < this->end; i++)
    {
        comboLvRv.str[i] = this->str[i];
    }
    for (int j = 0; j <= argStr.end; j++)
    {
        comboLvRv.str[i++] = argStr.str[j];
    }
    return comboLvRv;
}

void AVString::checkCap()
{
    int previousCap = cap;
    while (end >= cap)
    {
        cap = cap + 20;
        //new memory
    }
    if (previousCap != cap)
    {
        delete[] str;
        str = new char[cap];
    }
}

ostream &operator<<(ostream &ostream1, AVString &argStr)
{
    for (int i = 0; i <= argStr.getCreatedCount(); i++)
    {
        ostream1 << argStr.c_str();
    }
    return ostream1;
}

int AVString::getCreatedCount()
{
    return createdCount;
}

int AVString::getCurrentCount()
{
    return currentCount;
}

DblLinkedList::DblLinkedList()
{
    head = nullptr;
    tail = nullptr;
    it = nullptr;
    count = 0;
}

DblLinkedList::DblLinkedList(const DblLinkedList &dLL)
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

DblLinkedList &DblLinkedList::operator=(const DblLinkedList &dll)
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

DblLinkedList::~DblLinkedList()
{
    delete[] it;
}

ostream &operator<<(ostream &ostream1, DblLinkedList &argStr)
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
        ostream1 << setw(3) << argStr.it->data.c_str() << " ";
        argStr.next();
        endLineCount++;
    }
    return ostream1;
}
/*
 * @Param: Cstring object
 * pre: Will insert the object if object is either smaller than the head or greater than the tail, but
 * will insert if it isn't a repeating word
 * post: Object has been inserted in a orderly fashion from less to greatest
 * Description: This function will insert the object if either its a new head, new tail, or a non repeating object
 * and return true if inserted or false if it is not
 * */
bool DblLinkedList::insert(const AVString &str) //TODO make a insert for alpha order
{
    Node *temp = new Node(str);
    Node *before;
    if (head == nullptr)
    {
        head = tail = temp;
        count++;
    }
    else if (head->data > str && head->data != str)
    {
        before = head;
        head->prev = temp;
        temp->next = head;
        head = temp;
        head->next = before;
        count++;
    }
    else if (tail->data < str && tail->data != str)
    {
        before = tail;
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        tail->prev = before;
        count++;
    }
    else
    {
        resetIterator();
        while (hasMore())
        {
            if (it->data == str)
            {
                delete temp;
                return false;
            }
            else if (it->data > str)
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
/*
 * resets it to head pointer
 * */
void DblLinkedList::resetIterator() const
{
    it = head;
}
/*
 * Checks to see if there is another node within the DLL
 * */
bool DblLinkedList::hasMore() const
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
AVString DblLinkedList::next() const
{
    AVString temp;
    if (it != nullptr)
    {
        temp = it->data;
        it = it->next;
    }
    return temp;
}
/*
 * @param: AVString object
 * pre: it will make the passed in object go through a checklist for it not to be removed
 * post: it will remove the node and sure the lines together after nodes been removed under the conditions
 * description: this function will remove the node if it is a repeating node */
bool DblLinkedList::remove(const AVString &argStr)
{
    resetIterator();
    while (it != nullptr)
    {
        if (it->data == argStr)
        {
            Node *temp = it;
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
            delete temp;
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
int DblLinkedList::getCount() const
{
    return count;
}
void DblLinkedList::testConnections()
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