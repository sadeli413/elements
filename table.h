#ifndef TABLE_H
#define TABLE_H
#include "element.h"
#include "flag.h"
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
        // quicksort
        void sort(string);
        void qsort(string, int, int);
        // binary search
        int search(string);
        int bsearch(int, int, string);
};

#endif