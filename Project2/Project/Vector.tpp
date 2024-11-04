#include "Vector.h"
template <typename T>
Vector<T>::Vector() {
    capacity = 10;
    array = new T[capacity];
    size = 0;
}
template <typename T>
Vector<T>::~Vector() {
    delete[] array;
}
template <typename T>
int Vector<T>::getSize() const{
    return size;
}
template <typename T>
int Vector<T>::getCapacity() const{
    return capacity;
}
template <typename T>
void Vector<T>::push_back(T element) {
    if (size >= capacity) {
        capacity *= 2;
        T* newArray = new T[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
    array[size] = element;
    size++;
}
template <typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        size--;
    }
}
template <typename T>
T Vector<T>::at(int index) {
    if (index >= 0 && index < size) {
        return array[index];
    }
    throw std::out_of_range("Індекс виходить за межі вектора");
}
template <typename T>
T& Vector<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        return array[index];
    }
    throw std::out_of_range("Індекс виходить за межі вектора");
}