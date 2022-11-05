//
// Created by yawkar on 05.11.22.
//

#ifndef HSE_CPP_COURSE_6_3_TEMPLATEDDYNQUEUE_H
#define HSE_CPP_COURSE_6_3_TEMPLATEDDYNQUEUE_H
#include <vector>

namespace task6 {

    template<class T>
    class TemplatedDynQueue {
    public:
        TemplatedDynQueue() = default;
        TemplatedDynQueue(const TemplatedDynQueue<T> &other);
        explicit TemplatedDynQueue(unsigned int initialCapacity);

        void offer(const T &value);
        T poll();
        unsigned int size();
    private:
        std::vector<T> in;
        std::vector<T> out;
    };

}

template<class T>
task6::TemplatedDynQueue<T>::TemplatedDynQueue(unsigned int initialCapacity) {
    in.reserve(initialCapacity);
    out.reserve(initialCapacity);
}

template<class T>
task6::TemplatedDynQueue<T>::TemplatedDynQueue(const task6::TemplatedDynQueue<T> &other) {
    in.clear();
    in = other.in;
    out.clear();
    out = other.out;
}

template<class T>
unsigned int task6::TemplatedDynQueue<T>::size() {
    return in.size() + out.size();
}

template<class T>
void task6::TemplatedDynQueue<T>::offer(const T &value) {
    in.push_back(value);
}

template<class T>
T task6::TemplatedDynQueue<T>::poll() {
    if (size() == 0) {
        throw "Queue is empty";
    }
    if (out.empty()) {
        while (!in.empty()) {
            out.push_back(in.back());
            in.pop_back();
        }
    }
    T result = out.back();
    out.pop_back();
    return result;
}

#endif //HSE_CPP_COURSE_6_3_TEMPLATEDDYNQUEUE_H
