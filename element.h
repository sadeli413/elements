#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
using std::string;

class Element {
    private:
        int _num;
        string _sym;
        string _name;
    
    public:
        // constructors
        Element();
        Element(int, string, string);
        // get
        int getNum();
        string getSym();
        string getName();
        // set
        void setNum(int);
        void setSym(string);
        void setName(string);
        // compare
        int compare(Element, string);
};

#endif