/*
 * @author Alex Vierra
 * Section OL1
 * P2 string Bubble Sort 1/25/2023
 * This program will sort in a bubble sort data structure and output
 * word from least to great in ASCII format. The input is put in file
 * "infile2.txt" and output is the sorted form in
 * "outFilePrint.txt" of your input
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "AVString.h"

using namespace std;

int main()
{
    vector<AVString> words(100);// calls default constructor 100 times
    string fileName = "infile2.txt";
    ifstream fin(fileName);
    // READ fail to see if file is there
    if (fin.fail())
    {
        cout << "Couldn't open infile2.txt" << endl;
        //        system("pause");
        exit(1);
    }
    int wordCnt = 0;
    AVString tempString;
    while (fin >> tempString)
    {

    }
    for (; words[wordCnt].read(fin); ++wordCnt)
    {
        words.push_back(words[wordCnt]);
    }

        words.resize(wordCnt);
       //shrink vector to size used



    // sorts through the string array, and put less to greater words in order
    bool notDone = true;
    AVString longString;
    int stringPlacement = 0;
    while (stringPlacement != words.size())
    {
        for (int i = 0; i < 5; i++)
        {
            longString;
            stringPlacement++;
        }
    }
    while (notDone)
    {
        notDone = false;
        //loops through array checking if it returns a negative numbers to sort
        for (int i = 0; i < words.size() - 1; ++i)
        {
            if (words[i] > words[i + 1])
            {
                //switches the values of what's in words[i + 1] to words[i]
                AVString tempString;
                tempString.setEqualTo(words[i]);
                words[i].setEqualTo(words[i + 1]);
                words[i + 1].setEqualTo(tempString);
                notDone = true;
            }
            else if (words[i] < words[i + 1])
            {
                notDone = true;
            }
            else if (words[i] == words[i + 1])
            {
                notDone = true;
            }
        }
    }
    ofstream outFile("outFilePrint.txt");
    //prints to the file of "outFilePrint.txt"
    int fileCount = 0;
    while (fileCount < words.size())
    {
        for (int i = 0; i < 6; i++)
        {
            outFile << setw(13) << words[fileCount].c_str();
            fileCount++;
            if (fileCount == words.size() / 2)
            {
                outFile << endl << endl << setw(13)
                        << ".....This is the middle of the paper....."
                        << endl << endl;
            }
        }
        outFile << endl << endl;
    }
    //this couts the order in which the bubble sort organized it in
    int count = 0;
    while (count < words.size())
    {
        //prints a newline every six elements
        for (int i = 0; i < 6; i++)
        {
            cout << setw(13) << words[count].c_str();
            count++;
        }
        cout << endl << endl;
    }
}