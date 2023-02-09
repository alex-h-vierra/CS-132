/*
 * @author Alex Vierra
 * This main.cpp hold the function that preform the key to sorting
 * , reading and outputting the string
 * */
#include "AVString.h"
#include <vector>

/*
 * preconditions: calculate new end, and new cap of the giving array
 * post-condition: set a new end, and new cap
 * */
AVString::AVString()
{
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
AVString::AVString(const char *cstr)
{
    for (end = 0; cstr[end] != '\0'; ++end);
//empty loop
    cap = capacity();
    str = new char[cap];
    for (int i = 0; i <= end; ++i)
    {
        str[i] = cstr[i];
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

char AVString::at(int index)
{
    if (index >= 0 && index < end)
    {
        return str[index];
    }
    else
    {
        return '\0';
    }
}

bool AVString::read(istream &inputStrm)
{
    AVString temp;
    char inputWord[100];
    if (inputStrm >> inputWord)
    {
        for (end = 0; inputWord[end] != '\0'; ++end);
        //empty loop
        temp.checkCap();
        for (int i = 0; i <= end; ++i)
        {
            str[i] = inputWord[i];
        }
        return true;
    }
    else
    {
        return false;
    }
}

void AVString::write(ostream &outputStrm)
{
    outputStrm << str;
}

/*
 * Bubble sort
 * Precondition: checks to get the smallest size
 * than checks if both the ASCII numbers equal 0
 * Post-condition: checks if the two object strings
 * are equal to 0, and calculates the size of the smallest
 * object
 * */
int AVString::compareTo(const AVString &argStr)
{
    int size = 0;
    int answer = 0;
    if (this->end > argStr.end)
    {
        size = argStr.end;
    }                                                   //split this function
    else
    {
        size = this->end;
    }
    for (int i = 0; i <= size; i++)
    {
        answer = str[i] - argStr.str[i];
        if (answer != 0)
        {
            return answer;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

            //TODO need to make overloading insertion and extraction functions
            //TODO and friend the insertion and extraction in the scope of the class


bool AVString::operator == (const AVString &argStr)
{
    return (this->compareTo(argStr) == 0);
}

bool AVString::operator < (const AVString &argStr)
{
    return (this->compareTo(argStr) < 0);
}

int AVString::operator > (const AVString &argStr)
{
    return (this->compareTo(argStr) > 0);
}

/*
 * param: object string from the array
 * precondition: checks to see if object is out of bounds
 * post-condition: return the out of bounds
 * to the end of the passed in object
 * */
void AVString::setEqualTo(const AVString &argStr)
{
    end = argStr.end;
    cap = argStr.cap; //TODO: needs to potentially grow
    for (int i = 0; i <= end; ++i)
    {
        str[i] = argStr.str[i];
    }
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
    for (int i = 0; i < this->end; i++)
    {
        comboLvRv.str[i] = this->str[i];
    }
    for (int i = this->end; i < comboLvRv.end; i++)
    {
        comboLvRv.str[i] = argStr.str[i];
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

