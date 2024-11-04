#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
template <typename T>
class Vector {
    T* array;
    int size;
    int capacity;
public:
    Vector();
    ~Vector();
    int getSize() const;
    int getCapacity() const;
    void push_back(T element);
    void pop_back();
    T at(int index);
    T& operator[](int index);
};
#include "Vector.tpp"




#endif //PR_1_VECTOR_H