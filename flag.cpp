#include "flag.h"

// default constructor
Flag::Flag() {
    _element = Element(0, "", "");
    _index = -1;
}

// custom constructor
Flag::Flag(Element element, int index) {
    _element = element;
    _index = index;
    _single = element.getSym().length() == 1;
}

// getter

Element Flag::getElement() {
    return _element;
}

int Flag::getIndex() {
    return _index;
}

bool Flag::single() {
    return _single;
}

// setter

void Flag::setElement(Element element) {
    _element = element;
}

void Flag::setIndex(int index) {
    _index = index;
}