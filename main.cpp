#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "AVString.h"

int wordCount = 0;

using namespace std;

int main()
{
    vector<AVString> words(100);// calls default constructor 100 times

    string fileName = "infile2.txt";
    ifstream fin(fileName.c_str());
    // READ
    if (fin.fail())
    {
        cout << "Couldn't open infile2.txt" << endl;
        system("pause");
        exit(1);
    }

    int wordCnt = 0;
    for (; words[wordCnt].read(fin); ++wordCnt)
    {       // empty loop
        // for verifying input
    }
    words.resize(wordCnt);            //shrink vector to size used
    // You need to write the rest

    // SORT
    bool notDone = true;
    while (notDone)
    {

        for (int i = 0; i < words[wordCnt].read(fin); i++)
        {
            for (int j = i + 1; i < words[wordCnt].; j++)
            {
                words[i].compareTo(words[j]);
            }
        }
        notDone = false;
    }


    // OUTPUT


}