#pragma once

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>

class ArrayException
{
private:
    std::string m_error;

public:
    ArrayException(std::string error)
        : m_error(error)
    {
    }

    const char* getError() { return m_error.c_str(); }
};

template <class T>
class DynamicArray
{
private:
    T* items;
    int size=0;
    int capacity = 0;

public:
    DynamicArray(T* items, int count)
    {
        this->capacity = count;
        this->items = new T[this->capacity];

        for (int i = 0; i < count; i++) {
            this->items[i] = items[i];
            this->size++;
        }
    }

    DynamicArray(int capacity)
    {
        if (capacity < 0) {
            throw ArrayException("IndexOutOfRange");
        }
        this->capacity = capacity;
        this->items = new T[this->capacity];
    }

    int getSize()
    {
        return this->size;
    }

    T get(const int index) const
    {
        if (index < 0 || index >= this->capacity)
            throw ArrayException("IndexOutOfRange");
        return this->items[index];
    }

    void set(const int index, const T value)
    {
        if (index < 0 || index >= this->capacity)
            throw ArrayException("IndexOutOfRange");
        if (index >= this->size)
        {
            this->items[index] = value;
            this->size = this->size + 1;
        }
        else this->items[index] = value;
    }

    void resize(int newSize)
    {
        if (newSize < 0) {
            throw ArrayException("IndexOutOfRange");
        }

        T* items2 = new T[newSize];

        int count = 0;

        if (newSize > this->size) {
            count = this->size;
        }        
        else {
            count = newSize;
        }

        for (int i = 0; i < count; i++) {
            items2[i] = items[i];
        }

        this->capacity = newSize;
        this->items = items2;
        this->size = count;

    }
    
};

#endif
