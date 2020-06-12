#include "iterator__.h"

template<typename T>
iterator<T>::iterator(size_t capacity, char *data, T *obj, T *first)
        : capacity(capacity), buffer(data), obj(obj), first(first) {
    if (buffer != nullptr) {
        if (obj >= ((T *) buffer) + capacity) {
            this->obj = (T *) buffer + ((obj - (T *) buffer) % capacity);
        }
        if (obj < (T *) buffer) {
            this->obj = (T *) buffer + capacity - (((T *) buffer - obj) % capacity);
        }
    }
}

template<typename T>
iterator<T>::iterator(const iterator &other) : capacity(other.capacity), buffer(other.buffer), obj(other.obj),
                                               first(other.first) {}

template<typename T>
iterator<T> &iterator<T>::operator=(const iterator &other) {
    iterator(other).swap(*this);
    return *this;
}

template<typename T>
bool iterator<T>::operator==(const iterator &other) const {
    return obj == other.obj;
}

template<typename T>
bool iterator<T>::operator!=(const iterator &other) const {
    return obj != other.obj;
}

template<typename T>
T &iterator<T>::operator*() const {
    return *obj;
}

template<typename T>
iterator<T> &iterator<T>::operator++() {
    ++obj;
    if (obj == ((T *) buffer) + capacity) {
        obj = (T *) buffer;
    }
    return *this;
}

template<typename T>
iterator<T> &iterator<T>::operator--() {
    --obj;
    if (obj < (T *) buffer) {
        obj = (T *) buffer + capacity - 1;
    }
    return *this;
}

template<typename T>
iterator<T> iterator<T>::operator+(iterator::difference_type diff) const {
    return iterator(capacity, buffer, obj + diff, first);
}

template<typename T>
iterator<T> iterator<T>::operator-(iterator::difference_type diff) const {
    return iterator(capacity, buffer, obj - diff, first);
}

template<typename T>
void iterator<T>::swap(iterator &other) {
    std::swap(obj, other.obj);
    std::swap(buffer, other.buffer);
    std::swap(capacity, other.capacity);
    std::swap(first, other.first);
}

template<typename T>
typename iterator<T>::difference_type iterator<T>::operator-(const iterator &other) const {
    return obj - other.obj;
}

template<typename T>
T &iterator<T>::operator[](iterator::difference_type diff) const {
    return *(obj + diff);
}

template<typename T>
typename iterator<T>::difference_type iterator<T>::operator+(const iterator &other) const {
    return obj + other.obj;
}


