#include <iostream>
#include <fstream>
#include <string>
#include "table.h"
#include "element.h"
// using namespace::std;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::cerr;

Table::Table() {
    // Element elements[NUM_ELEMENTS];
    string numstr;
    string sym;
    string name;
    try {
        ifstream elementstxt("../src/elements.txt");
        for (int i = 0; i < NUM_ELEMENTS; i++) {
            getline(elementstxt, numstr, ' ');
            getline(elementstxt, sym, ' ');
            getline(elementstxt, name, ' ');
            Element insert(stoi(numstr), sym, name);
            _elements[i] = insert;
        }
        elementstxt.close();
    }
    catch (ifstream::failure e) {
        cerr << "Exception in opening/closing file" << endl;
    }
}

Element* Table::getElements() {
    return _elements;
}

// sort the table by type
void Table::sort(string type) {
    qsort(type, 0, NUM_ELEMENTS - 1);
}

// recursively quicksort the elements by num, sym, or name
void Table::qsort(string type, int low, int high) {
    if (high - low <= 0) {
        return;
    }

    // store important indexes
    int pivot = high;
    int compare = low;
    int store = low;

    Element tmp;
    while (compare < pivot) {
        if (_elements[compare].compare(_elements[pivot], type) < 0) {
            // swap store and compare
            tmp = _elements[store];
            _elements[store] = _elements[compare];
            _elements[compare] = tmp;
            store++;
        }
        compare++;
    }
    // swap store and pivot
    tmp = _elements[store];
    _elements[store] = _elements[pivot];
    _elements[pivot] = tmp;
    qsort(type, low, store - 1);
    qsort(type, store + 1, high);
}

// prototype for lowercase function
string lowercase(string);

// search for element by symbol
bool Table::search(string sym) {
    if (sym.length() < 1 || sym.length() > 2) {
        return false;
    }
    return bsearch(0, NUM_ELEMENTS - 1, lowercase(sym));
}

// recursive binary search to search an element by symbol
bool Table::bsearch(int low, int high, string sym) {
    if (high >= low) {
        int mid = (low + high) / 2;
        string lowersym = lowercase(_elements[mid].getSym());
        // if lower(symbol) == sym
        if (lowersym.compare(sym) == 0) {
            return true;
        }
        else if (lowersym.compare(sym) > 0) {
            return bsearch(low, mid - 1, sym);
        }
        else {
            return bsearch(mid + 1, high, sym);
        }
    }
    // sym isn't in
    return false;
}

string lowercase(string word) {
    string lower = "";
    for (int i = 0; i < word.length(); i++) {
        lower += tolower(word[i]);
    }
    return lower;
}