#include <iostream>
#include <fstream>
#include <string>
#include "table.h"
#include "array.h"
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::cerr;

Table::Table() {
    // temporary string holders
    string numstr;
    string sym;
    string name;
    try {
        /*
         * fill elements and symbol with elements
         * THIS IS HARD CODED to be run in a bin folder, refering to ../src
         */
        ifstream elementstxt("../src/elements.txt");
        for (int i = 0; i < NUM_ELEMENTS; i++) {
            // get three words at a time
            getline(elementstxt, numstr, ' ');
            getline(elementstxt, sym, ' ');
            getline(elementstxt, name, ' ');
            // make the element then put it into _elements and symbols
            Element insert(stoi(numstr), sym, name);
            _elements[i] = insert;
            _symbols[i] = insert;
        }
        elementstxt.close();
        // sort _symbols
        sort("sym");
    }
    catch (ifstream::failure e) {
        cerr << "Exception in opening/closing file" << endl;
    }
}

Element* Table::getElements() {
    return _elements;
}

// check if a word can be spelled with periodic table words
bool Table::checkWord(string word) {
    Array<Flag> flags; // array of successful periodic table substrings
    int i = 0; // index of word
    string substr; // substring of a word to check if it matches a periodic table symbol
    int found; // if the substring matches a periodic table symbol
    bool single = true; // if the substring length should be one (true) or two (false)
    while (i < word.length() - 1) {
        // check single
        substr = "";
        substr += word[i];
        
        // check a double if it doesn't go over the word length
        if (!single && i + 1 < word.length() - 1) {
            substr += word[i+1];
        }
        // if single or proper double
        if (single || (!single && i + 1 < word.length() - 1)) { 
            found = search(substr);
        }
        // otherwise, then I can't check double that goes over word length
        else {
            found = -1;
        }
        
        // if a word has been found
        if (found >= 0) {
            Flag flag(_symbols[found], i);
            flags.add(flag);
            i = single ? i + 1 : i + 2;
            single = true;
        }
        else {
            // if single failed then check double
            if (!single) {
                // go back to last single
                while (flags.size() > 0 && !flags.peek().single()) {
                    flags.pop();
                }
                // if there are no successful substrings, then it fails
                if (flags.size() == 0) {
                    return false;
                }
                i = flags.pop().getIndex(); // set i to the last single found
            }
            single = false; // check double
        }
    }
    return true;
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
        if (_symbols[compare].compare(_symbols[pivot], type) < 0) {
            // swap store and compare
            tmp = _symbols[store];
            _symbols[store] = _symbols[compare];
            _symbols[compare] = tmp;
            store++;
        }
        compare++;
    }
    // swap store and pivot
    tmp = _symbols[store];
    _symbols[store] = _symbols[pivot];
    _symbols[pivot] = tmp;
    // quicksort the other halves
    qsort(type, low, store - 1);
    qsort(type, store + 1, high);
}

// search for element by lowercase symbol
int Table::search(string sym) {
    if (sym.length() < 1 || sym.length() > 2) {
        return -1;
    }
    return bsearch(0, NUM_ELEMENTS - 1, sym);
}

// recursive binary search to search an element by symbol (is lowercase already)
// returns index of _symbols it was found at
int Table::bsearch(int low, int high, string sym) {
    if (high >= low) {
        int mid = (low + high) / 2;
        string lowersym = _symbols[mid].getLow();
        // success
        if (lowersym.compare(sym) == 0) {
            return mid;
        }
        // search left half
        else if (lowersym.compare(sym) > 0) {
            return bsearch(low, mid - 1, sym);
        }
        // search right half
        else {
            return bsearch(mid + 1, high, sym);
        }
    }
    // sym isn't in
    return -1;
}