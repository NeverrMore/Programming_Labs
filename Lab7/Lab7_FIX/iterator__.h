#pragma once
#include "CircleBuffer_.h"

template<typename T>
class CircularBuffer;

template<typename T>
struct iterator : std::iterator<std::random_access_iterator_tag, T> {
    using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
    T *obj;
    T *first;

    char *buffer;
    size_t capacity;

    explicit iterator(size_t capacity = 0, char *data = nullptr, T *obj = nullptr, T *first = nullptr);

    iterator(const iterator &other);;

    iterator &operator=(const iterator &other);

    ~iterator() = default;

    bool operator==(const iterator &other) const;

    bool operator!=(const iterator &other) const;

    T &operator*() const;

    iterator &operator++();

    iterator &operator--();

    difference_type operator-(const iterator &other) const;

    difference_type operator+(const iterator &other) const;

    iterator operator+(difference_type diff) const;

    iterator operator-(difference_type diff) const;

    friend iterator operator+(difference_type diff, const iterator &other) {
        return iterator(other.capacity, other.buffer, diff + other.obj, other.first);
    }

    T &operator[](difference_type diff) const;

    void swap(iterator &other);
};

#include "iterator__.hpp"







