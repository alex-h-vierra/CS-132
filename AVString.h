//
// Created by alexv on 1/19/2023.
//

#ifndef P2_MYSTRING_V1_AVSTRING_H
#define P2_MYSTRING_V1_AVSTRING_H

#include <istream>

using namespace std;

class AVString
{    // You NEED to change the name of the class to reflect your
    // name
    //   for example Nancy Programmer would use the name NPString
public:
    AVString(); // default constructor

    AVString(const char *cstr); // cstring constructor

    int length() ;

    int capacity() ;

    char at(int index);

    bool read(istream &inputStrm);

    void write(ostream &outputStrm);

    int compareTo( const AVString& argStr);
    

    void setEqualTo(const AVString &argStr);

    const char *c_str();

private:
    char *str;
    int end;
    int cap;
};

#endif //P2_MYSTRING_V1_AVSTRING_H
