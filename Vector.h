#ifndef MYVECTORAPP_VECTOR_H
#define MYVECTORAPP_VECTOR_H

#include <iostream>

using namespace std;

template <class T>
class Vector {
private:
    T* arr;
    int capacity;
    int size;

    void realloc();
public:
    Vector(int capacity = 10);
    Vector(Vector& obj);

    ~Vector();

    T get(int index);
    void set(int index, T& value);

    void push_back(T& value);
    void pop_back();

    Vector<T>& operator=(const Vector& obj);
    T& operator[](int index);

    int getSize();
};


#endif //MYVECTORAPP_VECTOR_H
