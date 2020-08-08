#include <iostream>
#include <string>
#include <fstream>
#include "table.h"
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::string;

int main() {
    // create array of elements sorted in alphabetical order by symbol
    Table table;
    try {
        string word;
        // THIS IS HARD CODED to be run in a bin folder, refering to ../src
        ifstream dictionary("../src/alpha.txt");
        // for word in dictionary
        while (getline(dictionary, word)) {
            // check if the word can be spelled from periodic table
            table.checkWord(word);
        }
    }
    catch(ifstream::failure e) {
        cerr << "Exception in opening/closing file" << endl;
    }
}