#ifndef TABLE_H
#define TABLE_H


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "element.h"
#include "array.h"
#include "flag.h"
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::cerr;
using std::setw;
using std::right;
using std::left;

#define NUM_ELEMENTS 118
class Table {
    private:
        Element _elements[NUM_ELEMENTS];
        Element _symbols[NUM_ELEMENTS]; // elements, but sorted by symbol
    public:
        Table();
        Element* getElements();
        // check if a word fits elements
        bool checkWord(string word);
        // print the elements that fit
        void printWord(Array<Flag>&, int);
        // quicksort
        void sort(string);
        void qsort(string, int, int);
        // binary search
        int search(string);
        int bsearch(int, int, string);
        
};

#endif