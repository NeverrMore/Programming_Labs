#include "CircleBuffer_.h"

template<typename T>
CircularBuffer<T>::CircularBuffer(const CircularBuffer<T> &other, int cap) : capacity((cap == -1) ? other.capacity : cap), size(0)
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

template<typename T>
CircularBuffer<T>::CircularBuffer(size_t capacity) : capacity(capacity), size(0) {
    buffer = new char[capacity * sizeof(T)];
    T *ptr = (T *) buffer;
    for (size_t i = 0; i < capacity; ++i) {
        new(ptr + i) T();
    }
    first = iterator<T>(capacity, buffer, (T *) buffer, first.obj);
    last = iterator<T>(capacity, buffer, (T *) buffer - 1, first.obj);
}

template<typename T>
CircularBuffer<T> &CircularBuffer<T>::operator=(const CircularBuffer<T> &other) {
    if (this != &other) {
        CircularBuffer(other).swap(*this);
    }
    return *this;
}

template<typename T>
CircularBuffer<T>::~CircularBuffer() {
    for (iterator<T> it = iterator<T>(capacity, buffer, (T *) buffer, first.obj);
         it != iterator<T>(capacity, buffer, (T *) buffer + capacity, first.obj); ++it) {
        if ((it.obj) != nullptr) {
            it.obj->~T();
        }
    }
    delete[] buffer;
}

template<typename T>
iterator<T> CircularBuffer<T>::begin() {
    return first;
}

template<typename T>
iterator<T> CircularBuffer<T>::end() {
    return last + 1;
}

template<typename T>
bool CircularBuffer<T>::empty() const {
    return size == 0;
}

template<typename T>
size_t CircularBuffer<T>::getSize() const {
    return size;
}

template<typename T>
T &CircularBuffer<T>::GetLast() {
    checkSize();
    return *(last);
}

template<typename T>
T &CircularBuffer<T>::GetFirst() {
    checkSize();
    return *first;
}

template<typename T>
void CircularBuffer<T>::addLast(T value) {
    ++last;
    *last = value;
    ++size;
    if (size > capacity) {
        ++first;
        --size;
    }
}

template<typename T>
void CircularBuffer<T>::addFirst(T value) {
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

template<typename T>
void CircularBuffer<T>::add(iterator<T> it, T value) {
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

template<typename T>
void CircularBuffer<T>::removeLast() {
    checkSize();
    --last;
    --size;
}

template<typename T>
void CircularBuffer<T>::removeFirst() {
    checkSize();
    ++first;
    --size;
}

template<typename T>
void CircularBuffer<T>::remove(iterator<T> it) {
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

template<typename T>
void CircularBuffer<T>::changeCapacity(size_t newCapacity) {
    CircularBuffer(*this, newCapacity).swap(*this);
}

template<typename T>
T &CircularBuffer<T>::operator[](int index) {
    iterator<T> cur = first + index;
    return *cur;
}

template<typename T>
void CircularBuffer<T>::swap(CircularBuffer &other) {
    std::swap(buffer, other.buffer);
    std::swap(capacity, other.capacity);
    std::swap(size, other.size);
    std::swap(first, other.first);
    std::swap(last, other.last);
}

template<typename T>
void CircularBuffer<T>::checkSize() {
    if (empty()) {
        throw std::runtime_error("is empty!");
    }
}

template<typename T>
std::istream &operator>>(std::istream &s, CircularBuffer<T> &a) {
    T newData;
    while (s >> newData) {
        a.addLast(&newData);
    }
    return s;
}


