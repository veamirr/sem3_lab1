#pragma once

#ifndef SEQUENCE_H//если переменная не определена, то cout в силе; если дебаг определен то ничего не выводится.
#define SEQUENCE_H

template <class T>
class Sequence
{
public:
    virtual int getLength() const = 0;//virtual нужна для наследования функций (т.е. для полморфизма)
    virtual T getFirst() const = 0;//получить первый элемент в списке
    virtual T getLast() const = 0;
    virtual T get(const int i) const = 0;//получить элемент по индексу


    virtual void append(T value) = 0;//добавляет элемент в начало
    virtual void prepend(T value) = 0;//добавляет элемент в конец
    virtual void insertAt(const int index, T value) = 0;//вставляет элемент в заданную позцию

};

#endif