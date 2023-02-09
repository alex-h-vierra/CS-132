/*
 * @author Alex Vierra
 * This interface is the holder to function members,
 * and member data
 * */

#ifndef P2_MYSTRING_V1_AVSTRING_H
#define P2_MYSTRING_V1_AVSTRING_H

#include <istream>

using namespace std;

class AVString
{
public:
    AVString(); // default constructor

    AVString(const char *cstr); // cstring constructor

    int length();

    int capacity();

    char at(int index);

    bool read(istream &inputStrm); //parameter is input stream name;

    void write(ostream &outputStrm); //parameter is the output stream name

    void setEqualTo(const AVString &argStr); // parameter is the object string

    const char *c_str(); //helps print string array

    AVString operator +(const AVString &lV);

    void checkCap();

    bool operator == (const AVString &argStr);

    int operator > (const AVString &argStr);

    bool operator < (const AVString &argStr);

private:


    // went out of bounds
    // that checks if bubble sort
    // you want to compare
    int compareTo(const AVString &argStr); //parameter is the object string
    char *str; //data of the new string that's created
    int end; //holds the end of string that's passed in
    int cap; //calculate the length of string
};



#endif //P2_MYSTRING_V1_AVSTRING_H