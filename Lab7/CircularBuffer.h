#pragma once
#include <iostream>
#include <algorithm>
#include "iterator7.h"

template<typename T>
class CircularBuffer {
    char *buffer;
    size_t capacity, size;
    iterator<T> first, last;

public:
    CircularBuffer(const CircularBuffer<T> &other, int cap = -1) : capacity((cap == -1) ? other.capacity : cap), size(0)
        {
        buffer = new char[capacity * sizeof(T)];
        T *ptr = (T *) buffer;
        for (size_t i = 0; i < capacity; ++i) {
            new(ptr + i) T();
        }

        first = iterator<T>(capacity, buffer, (T *) buffer, first.obj);
        last = iterator<T>(capacity, buffer, (T *) buffer - 1, first.obj);

        int i = 0;
        for (iterator<T> it = other.first; i < other.size; ++it, ++i) {
            addLast(*it);
        }
    }

    explicit CircularBuffer(size_t capacity = 0) : capacity(capacity), size(0) {
        buffer = new char[capacity * sizeof(T)];
        T *ptr = (T *) buffer;
        for (size_t i = 0; i < capacity; ++i) {
            new(ptr + i) T();
        }
        first = iterator<T>(capacity, buffer, (T *) buffer, first.obj);
        last = iterator<T>(capacity, buffer, (T *) buffer - 1, first.obj);
    }

    CircularBuffer<T> &operator=(const CircularBuffer<T> &other) {
        if (this != &other) {
            CircularBuffer(other).swap(*this);
        }
        return *this;
    }

    ~CircularBuffer() {
        for (iterator<T> it = iterator<T>(capacity, buffer, (T *) buffer, first.obj);
             it != iterator<T>(capacity, buffer, (T *) buffer + capacity, first.obj); ++it) {
            if ((it.obj) != nullptr) {
                it.obj->~T();
            }
        }
        delete[] buffer;
    }

    iterator<T> begin() {
        return first;
    };

    iterator<T> end() {
        return last + 1;
    };

    bool empty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    T &GetLast() {
        checkSize();
        return *(last);
    }

    T &GetFirst() {
        checkSize();
        return *first;
    }

    void addLast(T value) {
        ++last;
        *last = value;
        ++size;
        if (size > capacity) {
            ++first;
            --size;
        }
    }

    void addFirst(T value) {
        if (size == 0) {
            addLast(value);
        } else {
            --first;
            *first = value;
            ++size;
            if (size > capacity) {
                --last;
                --size;
            }
        }
    }

    void add(iterator<T> it, T value) {
        if (it == begin()) {
            addFirst(value);
        } else if (it == end()) {
            addLast(value);
        } else {
            for (iterator<T> cur = last + 1; cur != it; --cur) {
                if (cur.obj > (T *) buffer) {
                    *cur = *(cur - 1);
                } else {
                    *cur = *((T *) buffer + capacity - 1);
                }
            }
            *it = value;
            ++last;
            ++size;
            if (size > capacity) {
                ++first;
                --size;
            }
        }
    }

    void removeLast() {
        checkSize();
        --last;
        --size;
    }

    void removeFirst() {
        checkSize();
        ++first;
        --size;
    }

    void remove(iterator<T> it) {
        checkSize();
        if (it == begin()) {
            removeFirst();
        } else if (it == end()) {
            removeLast();
        } else {
            for (iterator<T> cur = it; cur != last; ++cur) {
                if (cur.obj == (T *) buffer + capacity - 1) {
                    *cur = *((T *) buffer);
                } else {
                    *cur = *(cur + 1);
                }
            }
            --last;
            --size;
        }
    }

    void changeCapacity(size_t newCapacity) {
        CircularBuffer(*this, newCapacity).swap(*this);
    }

    T &operator[](int index) {
        iterator<T> cur = first + index;
        return *cur;
    }

    void swap(CircularBuffer &other) {
        std::swap(buffer, other.buffer);
        std::swap(capacity, other.capacity);
        std::swap(size, other.size);
        std::swap(first, other.first);
        std::swap(last, other.last);
    }

    void checkSize() {
        if (empty()) {
            throw std::runtime_error("is empty!");
        }
    }

    friend std::ostream &operator<<(std::ostream &s, CircularBuffer<T> &a) {
        s << "circular buffer size: " << a.capacity << " elements " << a.size << " \n[";
        int i = 0;
        for (iterator<T> it = a.begin(); i < a.size; ++it, ++i) {
            s << *it << " ";
        }
        s << "]" << std::endl;
        return s;
    }

    friend std::istream &operator>>(std::istream &s, CircularBuffer<T> &a) {
        T newData;
        while (s >> newData) {
            a.addLast(&newData);
        }
        return s;
    }

    friend class iterator<T>;
};