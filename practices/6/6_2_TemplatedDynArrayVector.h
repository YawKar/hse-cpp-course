//
// Created by yawkar on 04.11.22.
//

#ifndef HSE_CPP_COURSE_6_2_TEMPLATEDDYNARRAYVECTOR_H
#define HSE_CPP_COURSE_6_2_TEMPLATEDDYNARRAYVECTOR_H
#include <vector>
#include <algorithm>

namespace task6 {

    template<class T>
    class TemplatedDynArrayVector {
    public:
        explicit TemplatedDynArrayVector(unsigned int initialCapacity);

        TemplatedDynArrayVector();

        TemplatedDynArrayVector(const TemplatedDynArrayVector<T> &other);

        static unsigned int instancesAlive();

        ~TemplatedDynArrayVector();

        void append(const T &value);

        unsigned int size() const;

        T get(unsigned int index);

        TemplatedDynArrayVector &operator=(const TemplatedDynArrayVector<T> &other);

        T &operator[](unsigned int index);

        TemplatedDynArrayVector operator+(const TemplatedDynArrayVector<T> &other);

        TemplatedDynArrayVector &operator>>(unsigned int shift);

        TemplatedDynArrayVector &operator<<(unsigned int shift);

    private:
        static unsigned int _instancesAlive;

        std::vector<T> _array;
    };
}

template<class T>
unsigned int task6::TemplatedDynArrayVector<T>::_instancesAlive = 0;

template<class T>
task6::TemplatedDynArrayVector<T>::TemplatedDynArrayVector(unsigned int initialCapacity) {
    ++_instancesAlive;
    _array.reserve(initialCapacity);
}

template<class T>
task6::TemplatedDynArrayVector<T>::TemplatedDynArrayVector() {
    ++_instancesAlive;
    _array.reserve(1);
}

template<class T>
task6::TemplatedDynArrayVector<T>::TemplatedDynArrayVector(const TemplatedDynArrayVector<T> &other) {
    ++_instancesAlive;
    _array.clear();
    _array = other._array;
}

template<class T>
unsigned int task6::TemplatedDynArrayVector<T>::instancesAlive() {
    return _instancesAlive;
}

template<class T>
task6::TemplatedDynArrayVector<T>::~TemplatedDynArrayVector() {
    --_instancesAlive;
    _array.clear();
}

template<class T>
void task6::TemplatedDynArrayVector<T>::append(const T &value) {
    _array.push_back(value);
}

template<class T>
unsigned int task6::TemplatedDynArrayVector<T>::size() const {
    return _array.size();
}

template<class T>
T task6::TemplatedDynArrayVector<T>::get(unsigned int index) {
    return _array.at(index);
}

template<class T>
task6::TemplatedDynArrayVector<T> &task6::TemplatedDynArrayVector<T>::operator=(const TemplatedDynArrayVector<T> &other) {
    if (this == &other) {
        return *this;
    }
    _array.clear();
    _array = other._array;
    return *this;
}

template<class T>
T &task6::TemplatedDynArrayVector<T>::operator[](unsigned int index) {
    return _array[index];
}

template<class T>
task6::TemplatedDynArrayVector<T> task6::TemplatedDynArrayVector<T>::operator+(const task6::TemplatedDynArrayVector<T> &other) {
    task6::TemplatedDynArrayVector<T> concat(this);
    for (int i = 0; i < other._array.size(); ++i) {
        concat.append(other._array[i]);
    }
    return concat;
}

template<class T>
task6::TemplatedDynArrayVector<T> &task6::TemplatedDynArrayVector<T>::operator>>(unsigned int shift) {
    shift %= _array.size();
    if (shift == 0) {
        return *this;
    }
    shift = _array.size() - shift;
    std::rotate(_array.begin(), _array.begin() + shift, _array.end());
}

template<class T>
task6::TemplatedDynArrayVector<T> &task6::TemplatedDynArrayVector<T>::operator<<(unsigned int shift) {
    shift %= _array.size();
    if (shift == 0) {
        return *this;
    }
    std::rotate(_array.begin(), _array.begin() + shift, _array.end());
}

#endif //HSE_CPP_COURSE_6_2_TEMPLATEDDYNARRAYVECTOR_H
