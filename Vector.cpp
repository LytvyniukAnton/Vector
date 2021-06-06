#include "Vector.h"

template<class T>
void Vector<T>::realloc() {
    int new_capacity = capacity * 2;
    T* buffer = new T[new_capacity];

    for(int i=0;i<capacity;i++)
    {
        buffer[i] = arr[i];
    }

    delete[] arr;
    arr = buffer;

    capacity = new_capacity;
}

template<class T>
Vector<T>::Vector(int capacity) {
    this->capacity = capacity;
    size = 0;

    arr = new T[capacity];
}

template<class T>
Vector<T>::Vector(Vector &obj) {
    capacity = obj.capacity;
    size = obj.size;
    arr = new T[capacity];

    for(int i=0;i<size;i++)
        arr[i] = obj.arr[i];
}

template<class T>
Vector<T>::~Vector() {
    delete[] arr;
}

template<class T>
T Vector<T>::get(int index) {
    if(index >= 0 && index < size)
        return arr[index];
    return nullptr;
}

template<class T>
void Vector<T>::set(int index, T &value) {
    if(index >= 0 && index < size)
        arr[index] = value;
}

template<class T>
void Vector<T>::push_back(T &value) {
    if(size == capacity)
        realloc();

    arr[size++] = value;
}

template<class T>
void Vector<T>::pop_back() {
    if(size > 0)
        size--;
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector &obj) {
    if(this== &obj)
        return *this;

    delete[] arr;

    capacity = obj.capacity;
    size = obj.size;
    arr = new T[capacity];

    for(int i=0;i<size;i++)
        arr[i] = obj.arr[i];

    return *this;
}

template<class T>
T &Vector<T>::operator[](int index) {
    if(index >= 0 && index < size)
        return arr[index];
    throw invalid_argument("invalid index");
}

template<class T>
int Vector<T>::getSize() {
    return size;
}







