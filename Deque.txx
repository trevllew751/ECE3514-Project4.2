#include "Deque.hpp"
#include <algorithm>
#include <iterator>

template<typename T>
Deque<T>::Deque() : frontIndex(0), rearIndex(0), size(0), capacity(INITIAL_CAPACITY) {
    items = new T[INITIAL_CAPACITY + 1];
}

template<typename T>
Deque<T>::Deque(const Deque<T> &other) {
    frontIndex = other.frontIndex;
    rearIndex = other.rearIndex;
    size = other.size;
    capacity = other.capacity;
    items = new T[capacity];
    std::copy(other.items, other.items + other.capacity, items);
}

template<typename T>
Deque<T>::~Deque() {
    delete[] items;
}

template<typename T>
Deque<T> &Deque<T>::operator=(Deque<T> rhs) {
    if (this != &rhs) {
        Deque<T> temp(rhs);
        swap(*this, rhs);
        frontIndex = rhs.frontIndex;
        rearIndex = rhs.rearIndex;
        size = rhs.size;
        capacity = rhs.capacity;
    }
    return *this;
}

template<typename T>
bool Deque<T>::isEmpty() const noexcept {
    return size == 0;
}

template<typename T>
void Deque<T>::pushFront(const T &item) {
    if (size == capacity) {
        resize();
    }
    if (isEmpty()) {
        frontIndex = 0;
        rearIndex = 0;
    } else if (frontIndex == 0) {
        frontIndex = capacity - 1;
    } else {
        frontIndex--;
    }
    items[frontIndex] = item;
    size++;
}

template<typename T>
void Deque<T>::popFront() {
    if (isEmpty()) {
        throw std::runtime_error("Error: Empty Deque");
    }
    if (frontIndex == rearIndex) {
        frontIndex = 0;
        rearIndex = 0;
    } else {
        if (frontIndex == capacity - 1) {
            frontIndex = 0;
        } else {
            frontIndex++;
        }
    }
    size--;
}

template<typename T>
T Deque<T>::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Error: Empty deque");
    }
    return items[frontIndex];
}

template<typename T>
void Deque<T>::pushBack(const T &item) {
    if (size == capacity) {
        resize();
    }
    if (isEmpty()) {
        frontIndex = 0;
        rearIndex = 0;
    } else if (rearIndex == capacity - 1) {
        rearIndex = 0;
    } else {
        rearIndex++;
    }
    items[rearIndex] = item;
    size++;
}

template<typename T>
void Deque<T>::popBack() {
    if (isEmpty()) {
        throw std::runtime_error("Error: Empty Deque");
    }
    if (frontIndex == rearIndex) {
        frontIndex = 0;
        rearIndex = 0;
    } else if (rearIndex == 0) {
        rearIndex = capacity - 1;
    } else {
        rearIndex--;
    }
    size--;
}

template<typename T>
T Deque<T>::back() const {
    if (isEmpty()) {
        throw std::runtime_error("Error: Empty deque");
    }
    return items[rearIndex];
}

template<typename T>
void Deque<T>::resize() {
    T *temp = new T[capacity * 2 + 1];
    int i = frontIndex;
    int j = 0;
    while (j < capacity) {
        temp[j] = items[i];
        j++;
        i = (i + 1) % capacity;
    }
    delete[] items;
    items = nullptr;
    frontIndex = 0;
    rearIndex = capacity - 1;
    capacity *= 2;
    items = temp;
}

template<typename T>
void Deque<T>::swap(Deque &lhs, Deque &rhs) {
    T *temp = lhs.items;
    lhs.items = rhs.items;
    rhs.items = temp;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const Deque<U> &d) {
    for (int i = 0; i < d.size; i++) {
        os << d.items[i] << "\n";
    }
    return os;
}
