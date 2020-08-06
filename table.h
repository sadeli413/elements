#ifndef TABLE_H
#define TABLE_H
#include "element.h"
#define NUM_ELEMENTS 118
class Table {
    private:
        Element _elements[NUM_ELEMENTS];

    public:
        Table();
        Element* getElements();
        // quicksort
        void sort(string);
        void qsort(string, int, int);
        // binary search
        bool search(string);
        bool bsearch(int, int, string);
};

#endif