// @author Thad Shinno
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
#include <cstring>
using std::cout;
using std::endl;

template <typename T>
class Array {
  private:
    int _size; // number of elements
    T *_list; // template pointer
    bool _beenMalloc; // has it been malloc?
  public:
    Array<T>();
    ~Array<T>();
    void add(T);
    void insert(int, T);
    T remove(int);
    T pop();
    T peek();
    T get(int);
    int size();
    void print();
};

// initialize array size as 0
template <typename T>
Array<T>::Array() {
  _size = 0;
  _beenMalloc = false;
}

// descructer
template <typename T>
Array<T>::~Array() {
  if (_beenMalloc)
    free(_list);
}

// increase the size of the array by one and put a val at the end
template <typename T>
void Array<T>::add(T val) {
  if (_size == 0) {
    _list = (T*) malloc(sizeof(T)); // allocate memory 
    memset(_list, 0, sizeof(T)); // initialize the new memory
    _list[0] = val; // put val at beginning
    _size++;
    _beenMalloc = true;
  }
  // reallocate pointer
  else {
    _size++;
    _list = (T*)realloc(_list, _size*sizeof(T)); // increase size
    memset(_list+(_size-1), 0, sizeof(T)); // initialize the new space
    _list[_size - 1] = val;  // put val at end
  }
}

// insert a val at an index
template <typename T>
void Array<T>::insert(int index, T val) {
  // check index validity
  if (index < 0 || index > _size) {
    throw "Invalid index";
  }

  // if inserted at the end of array, just add it
  if (index == _size) {
    add(val);
    return;
  }

  // increase size by one
  _size++;
  _list = (T*) realloc(_list, (_size)*sizeof(T));
  // shift values to the right to make a hole at index
  for (int i = _size - 1; i > index; i--) {
    _list[i] = _list[i-1];
  }
  // insert value
  _list[index] = val;
}

// remove an item at index
template <typename T>
T Array<T>::remove(int index) {
  // check index validity
  if (index < 0 || index >= _size) {
    throw "Invalid index";
  }
  
  // store the index value
  T store = _list[index];
  // shift over each element to overwrite the index value
  for (int i = index; i < _size - 1; i++) {
    _list[i] = _list[i+1];
  }
  // decrease the size
  _size--;
  _list = (T*)realloc(_list, _size*sizeof(T));
  
  return store;
}

// remove the last element of the array
template <typename T>
T Array<T>::pop() {
  // can't pop an empty array
  if (_size == 0) {
    throw "Can't pop an empty array";
  }
  return remove(_size - 1);
}

// return the last element of the array
template <typename T>
T Array<T>::peek() {
  if (_size == 0) {
    throw "Can't peek at an empty array";
  }
  return get(_size - 1);
}

// get an item at an index
template <typename T>
T Array<T>::get(int index) {
  if (index < 0 || index >= _size) {
    throw "Invalid index";
  }
  return _list[index];
}

// return number of stuff in the array
template <typename T>
int Array<T>::size() {
  return _size;
}

// print the array
template <typename T>
void Array<T>::print() {
  for (int i = 0; i < _size; i++) {
    cout << _list[i] << " ";
  }
  cout << endl;
}

#endif
