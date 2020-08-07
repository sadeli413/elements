#ifndef FLAG_H
#define FLAG_H

#include "element.h"

class Flag {
    private:
        Element _element;
        int _index; // the index in the word the flag was found at
        bool _single; // is the element a single char or double char?
    public:
        Flag();
        Flag(Element, int);
        // get
        Element getElement();
        int getIndex(); 
        bool single();
        // set
        void setElement(Element);
        void setIndex(int);
};

#endif