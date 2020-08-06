#include <iostream>
#include <string>
#include <fstream>
#include "table.h"
#include "element.h"
#include "array.h"
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::string;

#define NUM_ELEMENTS 118

// void combo(Array<string>, Array<string>&, int);
// void getCombinations(Array<string>, Array<string>&, string, int, int, int);
// void getCombinations(Array<string>, Array<string>&, Array<string>, int, int, int);
bool checkWord(string, Table);

int main() {
    // create array of elements sorted in alphabetical order by symbol
    Table table;
    table.sort("sym");
    Element *elements = table.getElements();
    try {
        string word;
        ifstream dictionary("../src/words_alpha.txt");
        // for word in dictionary
        // while (getline(dictionary, word)) {
        getline(dictionary, word);
        if (checkWord(word, table)) {
            cout << word << endl;
        }
        // }
    }
    catch(ifstream::failure e) {
        cerr << "Exception in opening/closing file" << endl;
    }
}

// word your checking, with start of the word 
// include num of chars you're checking
bool checkWord(string word, Table table)  {
    string substr;
    int start = 0; // starting point index 0
    bool single = true; // searching for single(true) vs searching for double(false)
    int i = 0; // index to loop through word
    int success = 0; // number of successful found chars
    while(i < word.length() -  1) {
        substr = "";
        substr += word[i];
        // if double, then make it so
        if (!single) {
            substr += word[i+1];
            i++;
        }
        bool found = table.search(substr);
        
        // if search fails
        if (found) {
            single = true;
            i++;
            success = i;
        }
        else {
            // don't search double if there are no more words left
            // if i is greater than success, then it's a failure
            if ((i >= word.length() - 1) || i > success) {
                return false;
            }
            // if check fails, then check double
            
            single = false;
            i = start;
            start++;
        }
    }
    return true;
}