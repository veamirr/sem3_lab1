#pragma once
#include <iostream>
#include "Sequence.h"
#include "ArraySequence.h"

template <class T>
class Sort
{
public:
    void shakeSort(Sequence<T>* seq, bool (*cmp)(T, T));
    void insertSort(Sequence<T>* seq, bool (*cmp)(T, T));
    void SelectionSort(Sequence<T>* seq, bool (*cmp)(T, T));
};

template <class T>
void Sort<T>::shakeSort(Sequence<T>* seq, bool (*cmp)(T, T))
{
    int left = 0, right = seq->getLength() - 1;
    int flag = 1;
    T a, b;

    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)
        {
            a = seq->get(i);
            b = seq->get(i + 1);
            //if (a > b)
            if (cmp(a,b)==true)
            {
                T t = a;
                seq->insertAt(i, b);
                seq->insertAt(i + 1, t);
                flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            a = seq->get(i - 1);
            b = seq->get(i);
            //if (a > b)
            if (cmp(a,b)==true)
            {
                T t = b;
                seq->insertAt(i, a);
                seq->insertAt(i - 1, t);
                flag = 1;
            }
        }
        left++;
    }
}

template <class T>
void Sort<T>::insertSort(Sequence<T>* seq, bool (*cmp)(T, T))
{
    T key;
    int j;
    for (int i = 1; i < seq->getLength(); i++)
    {
        key = seq->get(i);
        j = i - 1;

        while (j >= 0 && cmp(seq->get(j),key)==true)
        {
            seq->insertAt(j + 1, seq->get(j));
            j = j - 1;
        }
        seq->insertAt(j + 1, key);
    }
}

template <class T>
void Sort<T>::SelectionSort(Sequence<T>* seq, bool (*cmp)(T, T))//не работает для списка так как insertAt работает со сдвигом
{
    T max, x;
    int maxnum;
    for (int i = seq->getLength(); i > 1; i--)
    {
        max = seq->getFirst();
        maxnum = 0;
        for (int j = 1; j < i; j++)
        {
            if (cmp(seq->get(j), max) == true)
            {
                max = seq->get(j);
                maxnum = j;
            }
        };
        seq->insertAt(maxnum, seq->get(i - 1));
        seq->insertAt(i - 1, max);
    }
}