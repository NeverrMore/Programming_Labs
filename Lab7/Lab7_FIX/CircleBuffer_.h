#pragma once
#include <iostream>
#include <algorithm>
#include "iterator__.h"

template<typename T>
class CircularBuffer {
    char *buffer;
    size_t capacity, size;
    iterator<T> first, last;

public:
    CircularBuffer(const CircularBuffer<T> &other, int cap = -1);

    explicit CircularBuffer(size_t capacity = 0);

    CircularBuffer<T> &operator=(const CircularBuffer<T> &other);

    ~CircularBuffer();

    iterator<T> begin();;

    iterator<T> end();;

    bool empty() const;

    size_t getSize() const;

    T &GetLast();

    T &GetFirst();

    void addLast(T value);

    void addFirst(T value);

    void add(iterator<T> it, T value);

    void removeLast();

    void removeFirst();

    void remove(iterator<T> it);

    void changeCapacity(size_t newCapacity);

    T &operator[](int index);

    void swap(CircularBuffer &other);

    void checkSize();

    friend std::ostream &operator<<(std::ostream &s, CircularBuffer<T> &a) {

        int i = 0;
        for (iterator<T> it = a.begin(); i < a.size; ++it, ++i) {
            s << *it << " ";
        }
        s << "]" << std::endl;
        return s;
    }

    friend std::istream &operator>>(std::istream &s, CircularBuffer<T> &a);

    friend class iterator<T>;
};

#include "CircleBuffer.hpp"