//
// Created by yawkar on 04.11.22.
//

#ifndef HSE_CPP_COURSE_6_1_TEMPLATEDDYNARRAYPRIMITIVE_H
#define HSE_CPP_COURSE_6_1_TEMPLATEDDYNARRAYPRIMITIVE_H

namespace task6 {

    template<class T>
    class TemplatedDynArrayPrimitive {
    public:
        explicit TemplatedDynArrayPrimitive(unsigned int initialCapacity);

        TemplatedDynArrayPrimitive(); // the same as DynArray(1)
        TemplatedDynArrayPrimitive(const TemplatedDynArrayPrimitive<T> &other);

        static unsigned int instancesAlive();

        ~TemplatedDynArrayPrimitive();

        void append(const T &value);

        unsigned int size() const;

        T get(unsigned int index);

        TemplatedDynArrayPrimitive &operator=(const TemplatedDynArrayPrimitive<T> &other);

        T &operator[](unsigned int index);

        TemplatedDynArrayPrimitive operator+(const TemplatedDynArrayPrimitive<T> &other);

        TemplatedDynArrayPrimitive &operator>>(unsigned int shift);

        TemplatedDynArrayPrimitive &operator<<(unsigned int shift);

    private:
        static unsigned int _instancesAlive;

        T *_array;
        unsigned int _capacity;
        unsigned int _size;
    };
}

template<class T>
unsigned int task6::TemplatedDynArrayPrimitive<T>::_instancesAlive = 0;

template<class T>
task6::TemplatedDynArrayPrimitive<T>::TemplatedDynArrayPrimitive(unsigned int initialCapacity) {
    ++_instancesAlive;
    _array = new T[initialCapacity];
    _capacity = initialCapacity;
    _size = 0;
}

template<class T>
task6::TemplatedDynArrayPrimitive<T>::TemplatedDynArrayPrimitive() {
    ++_instancesAlive;
    _array = new T[1];
    _capacity = 1;
    _size = 0;
}

template<class T>
task6::TemplatedDynArrayPrimitive<T>::~TemplatedDynArrayPrimitive() {
    --_instancesAlive;
    delete[] _array;
}

template<class T>
task6::TemplatedDynArrayPrimitive<T>::TemplatedDynArrayPrimitive(const task6::TemplatedDynArrayPrimitive<T> &other) {
    ++_instancesAlive;
    _size = other._size;
    _capacity = other._capacity;
    _array = new T[_capacity];
    for (int i = 0; i < other._size; ++i) {
        _array[i] = other._array[i];
    }
}

template<class T>
unsigned int task6::TemplatedDynArrayPrimitive<T>::instancesAlive() {
    return _instancesAlive;
}

template<class T>
void task6::TemplatedDynArrayPrimitive<T>::append(const T& value) {
    if (_size == _capacity) {
        auto* copy = new T[_capacity * 2];
        for (unsigned int i = 0; i < _size; ++i) {
            copy[i] = _array[i];
        }
        _capacity *= 2;
        delete[] _array;
        _array = copy;
    }
    _array[_size++] = value;
}

template<class T>
unsigned int task6::TemplatedDynArrayPrimitive<T>::size() const {
    return _size;
}

template<class T>
T task6::TemplatedDynArrayPrimitive<T>::get(unsigned int index) {
    return _array[index];
}

template<class T>
task6::TemplatedDynArrayPrimitive<T> &task6::TemplatedDynArrayPrimitive<T>::operator=(const task6::TemplatedDynArrayPrimitive<T> &other) {
    if (this == &other) {
        return *this;
    }
    delete[] _array;
    _size = other._size;
    _capacity = other._capacity;
    _array = new T[_capacity];
    for (int i = 0; i < other._size; ++i) {
        _array[i] = other._array[i];
    }
    return *this;
}

template<class T>
T &task6::TemplatedDynArrayPrimitive<T>::operator[](unsigned int index) {
    return _array[index];
}

template<class T>
task6::TemplatedDynArrayPrimitive<T> task6::TemplatedDynArrayPrimitive<T>::operator+(const task6::TemplatedDynArrayPrimitive<T> &other) {
    TemplatedDynArrayPrimitive<T> concat(_size + other._size);
    for (int i = 0; i < _size; ++i) {
        concat.append(_array[i]);
    }
    for (int i = 0; i < other._size; ++i) {
        concat.append(other._array[i]);
    }
    return concat;
}

template<class T>
task6::TemplatedDynArrayPrimitive<T> &task6::TemplatedDynArrayPrimitive<T>::operator>>(unsigned int shift) {
    shift %= _size;
    if (shift == 0) {
        return *this;
    }
    auto* head = new T[_size - shift];
    for (int i = 0; i < _size - shift; ++i) {
        head[i] = _array[i];
    }
    for (int i = 0; i < shift; ++i) {
        _array[i] = _array[_size - shift + i];
    }
    for (int i = 0; i < _size - shift; ++i) {
        _array[shift + i] = head[i];
    }
    return *this;
}

template<class T>
task6::TemplatedDynArrayPrimitive<T> &task6::TemplatedDynArrayPrimitive<T>::operator<<(unsigned int shift) {
    shift %= _size;
    if (shift == 0) {
        return *this;
    }
    auto* head = new double[shift];
    for (int i = 0; i < shift; ++i) {
        head[i] = _array[i];
    }
    for (int i = 0; i < _size - shift; ++i) {
        _array[i] = _array[shift + i];
    }
    for (int i = _size - shift; i < _size; ++i) {
        _array[i] = head[i - (_size - shift)];
    }
    return *this;
}

#endif //HSE_CPP_COURSE_6_1_TEMPLATEDDYNARRAYPRIMITIVE_H