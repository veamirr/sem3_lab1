#pragma once

#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"

template <class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* items;
    int count = 0;
    int capacity = 0;

public:
    ArraySequence()
    {
        this->items = new DynamicArray<T>(this->capacity);
    }

    ArraySequence(int size):Sequence<T>()
    {
        this->capacity = size;
        this->count = 0;
        this->items = new DynamicArray<T>(this->capacity);
    }

    ArraySequence(T* items, int count)
    {
        if (count < 0) {
            throw ArrayException("IndexOutOfRange");
        }
        this->items = new DynamicArray<T>(items, count);
    }

    int getLength() const override
    {
        return this->items->getSize();
    }

    T getFirst() const override
    {
        if (count < 1)
            throw ArrayException("IndexOutOfRange");
        return this->items->get(0);
    }

    T getLast() const override
    {
        if (count < 1)
            throw ArrayException("IndexOutOfRange");
        return this->items->get(count - 1);
    }

    T get(const int i) const override
    {
        if ((i < 0) || (i > count))
            throw ArrayException("IndexOutOfRange");
        return this->items->get(i);
    }

    void append(T value) override
    {
        if (this->count == this->capacity)
        {
            this->capacity = 2 * this->capacity;
            this->items->resize(this->capacity);
        }
        for (int i = (this->count - 1); i >= 0; i--) {
            items[i + 1] = items[i];
        }
        items->set(0, value);
        this->count = this->count + 1;
    }

    void prepend(T value) override
    {
        if (this->count == this->capacity) 
        {
            this->capacity = 2 * this->capacity;
            this->items->resize(this->capacity);
        }
        this->items->set(this->count, value);
        this->count = this->count + 1;
    }

    void insertAt(const int index, T value) override
    {
        if ((index > count) || (index < 0))
            throw ArrayException("IndexOutOfRange");
        else if (index == count && capacity == count)
        {
            this->capacity = 2 * this->capacity;
            this->items->resize(this->capacity);
            this->items->set(index, value);
            this->count++;
        }
        else if (index == count && capacity != count)
        {
            this->items->set(index, value);
            this->count++;
        }
        else if (index < count)
            this->items->set(index, value);
        //this->items->set(index, value);
    } 

};
#endif