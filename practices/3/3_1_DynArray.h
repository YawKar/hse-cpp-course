//
// Created by yawkar on 03.10.22.
//

#ifndef HSE_CPP_COURSE_3_1_DYNARRAY_H
#define HSE_CPP_COURSE_3_1_DYNARRAY_H
class DynArray {
public:
    explicit DynArray(unsigned int initialCapacity);
    DynArray(); // the same as DynArray(1)

    ~DynArray();

    void append(double value);
    unsigned int size();
    double get(int index);
private:
    double* array;
    unsigned int realSize;
    unsigned int capacity;
};
#endif //HSE_CPP_COURSE_3_1_DYNARRAY_H
