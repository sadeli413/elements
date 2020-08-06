// @author Thad Shinno
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

// array list has a size and a template pointer.
template <typename T>
class Array {
  private:
    int _size;
    T *_list;
  public:
    Array<T>();
    void add(T);
    void insert(int, T);
    void remove(int);
    void replace(int, T);
    T get(int);
    int size();
    void print();
};

// initialize array size as 0
template <typename T>
Array<T>::Array() {
  _size = 0;
}

// increase the size of the array by one and put a val at the end
template <typename T>
void Array<T>::add(T val) {
  if (_size == 0) {
    _list = (T*) malloc(sizeof(T));
    _list = new T;
    _list[0] = val; // put val at beginning
    _size++;
  }
  // reallocate pointer
  else {
    _size++;
    _list = (T*) realloc(_list, _size*sizeof(T)); // increase size
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
void Array<T>::remove(int index) {
  // check index validity
  if (index < 0 || index >= _size) {
    throw "Invalid index";
  }
  
  // create tmp array and copy
  T tmp[_size - 1];
  for (int i = 0; i < index; i++) {
    tmp[i] = _list[i];
  }
  // skip index
  for (int i = index + 1; i < _size; i++) {
    tmp[i-1] = _list[i];
  }
  
  // delete the list and malloc it to appropriate size
  _size--;
  delete[]_list;
  _list = (T*) malloc(_size*sizeof(T));
  for (int i = 0; i < _size; i++) {
    _list[i] = tmp[i];
  }
}

template <typename T>
void Array<T>::replace(int index, T val) {
  if (index < 0 || index > _size) {
    throw "Invalid index";
  }
  else if (index == _size) {
    add(val);
  }
  else if (index < _size) {
    _list[index] = val;
  }
  // else if (index > _size) {
  //   _size = index + 1;
  //   _list = (T*)realloc(_list, (_size)*(sizeof(T)));
  //   _list[index] = val;
  // }
}

// get an item at an index
template <typename T>
T Array<T>::get(int index) {
  if (index < 0 || index >= _size) {
    throw "Invalid index";
  }
  return _list[index];
}

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
