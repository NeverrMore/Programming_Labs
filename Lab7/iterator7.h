#pragma once

template<typename T>
class CircularBuffer;

template<typename T>
struct iterator : std::iterator<std::random_access_iterator_tag, T> {
    using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
    T *obj;
    T *first;

    char *buffer;
    size_t capacity;

    explicit iterator(size_t capacity = 0, char *data = nullptr, T *obj = nullptr, T *first = nullptr)
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

    iterator(const iterator &other) : capacity(other.capacity), buffer(other.buffer), obj(other.obj),
                                      first(other.first) {};

    iterator &operator=(const iterator &other) {
        iterator(other).swap(*this);
        return *this;
    }

    ~iterator() = default;

    bool operator==(const iterator &other) const {
        return obj == other.obj;
    }

    bool operator!=(const iterator &other) const {
        return obj != other.obj;
    }

    T &operator*() const {
        return *obj;
    }

    iterator &operator++() {
        ++obj;
        if (obj == ((T *) buffer) + capacity) {
            obj = (T *) buffer;
        }
        return *this;
    }

    iterator &operator--() {
        --obj;
        if (obj < (T *) buffer) {
            obj = (T *) buffer + capacity - 1;
        }
        return *this;
    }

    difference_type operator-(const iterator &other) const {
        return obj - other.obj;
    }

    difference_type operator+(const iterator &other) const {
        return obj + other.obj;
    }

    iterator operator+(difference_type diff) const {
        return iterator(capacity, buffer, obj + diff, first);
    }

    iterator operator-(difference_type diff) const {
        return iterator(capacity, buffer, obj - diff, first);
    }

    friend iterator operator+(difference_type diff, const iterator &other) {
        return iterator(other.capacity, other.buffer, diff + other.obj, other.first);
    }

    T &operator[](difference_type diff) const {
        return *(obj + diff);
    }

    void swap(iterator &other) {
        std::swap(obj, other.obj);
        std::swap(buffer, other.buffer);
        std::swap(capacity, other.capacity);
        std::swap(first, other.first);
    }
};