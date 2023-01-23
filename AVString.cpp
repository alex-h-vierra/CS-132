#include <fstream>
#include "AVString.h"

AVString::AVString()
{
    cap = 20;
    end = 0;
    str = new char[cap];
    str[end] = '\0';
}

AVString::AVString(const char *cstr)
{
    for (end = 0; cstr[end] != '\0'; ++end);
//empty loop
    cap = 20; //TODO: needs to potentially grow
    str = new char[cap];
    for (int i = 0; i <= end; ++i)
    {
        str[i] = cstr[i];
    }
}

int AVString::length()
{
    return end;
}

int AVString::capacity()
{
    if (str[end])
    {
        return cap + 20;
    }
    else
    {
        return cap;
    }
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
    char inputWord[100];
    if (inputStrm >> inputWord)
    {
        for (end = 0; inputWord[end] != '\0'; ++end);
        {//empty loop
            cap = end; //TODO: needs to
            for (int i = 0; i <= end; ++i)
            {
                str[i] = inputWord[i];
            }
            return true;
        }
    }
    else
        return false;
}

void AVString::write(ostream &outputStrm)
{
    outputStrm << str;
}

int AVString::compareTo(const AVString &argStr)
{
    char tempInputString[100];
    if (at(argStr.str[end]) > at(tempInputString[end]))
    {
        return at(argStr.str[end]);
    }
    if (at(argStr.str[end]) < at(tempInputString[end]))
    {

    }
    if (at(argStr.str[end]) == at(tempInputString[end]))
    {
        setEqualTo(argStr);
        return 0;
    }
}


void AVString::setEqualTo(const AVString &argStr)
{
    end = argStr.end;
    cap = capacity(); //TODO: needs to potentially grow
    for (int i = 0; i <= end; ++i)
    {
        str[i] = argStr.str[i];
    }
}

const char *AVString::c_str()
{
    return str;
}