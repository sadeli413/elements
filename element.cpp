#include "element.h"
#include <string>
using std::string;
string lowercase(string); // prototype

// default constructor
Element::Element() {
    _num = 0;
    _sym = "";
    _name = "";
    _low = "";
}

// custom constructor
Element::Element(int num, string sym, string name) {
    _num = num;
    _sym = sym;
    _name = name;
    _low = lowercase(_sym);
}

int Element::compare(Element other, string type) {
    // compare by atomic number
    if (type == "num") {
        return _num - other.getNum();
    }
    // compare by symbol
    else if (type == "sym") {
        return _sym.compare(other.getSym());
    }
    // compare by name
    else if (type == "name") {
        return _name.compare(other.getName());
    }
    // throw an error for invalid type
    else {
        throw "invalid type";
    }
}

// return a lowercase word
string lowercase(string word) {
    string lower = "";
    for (int i = 0; i < word.length(); i++) {
        lower += tolower(word[i]);
    }
    return lower;
}

// getters

int Element::getNum() {
    return _num;
}

string Element::getSym() {
    return _sym;
}

string Element::getName() {
    return _name;
}

string Element::getLow() {
    return _low;
}

// setters

void Element::setNum(int num) {
    _num = num;
}

void Element::setSym(string sym) {
    _sym = sym;
}

void Element::setName(string name) {
    _name = name;
}