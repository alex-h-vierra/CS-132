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
    delete str;
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

int AVString::getCreatedCount()
{
    return createdCount;
}

int AVString::getCurrentCount()
{
    return currentCount;
}

ostream &operator<<(ostream &ostream1, AVString &argStr)
{
    for (int i = 0; i <= argStr.getCreatedCount(); i++)
    {
        ostream1 << argStr.c_str();
    }
    return ostream1;
}