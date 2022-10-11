//
// Created by yawkar on 11.10.22.
//

#ifndef HSE_CPP_COURSE_DYNARRAYEXTENDED_H
#define HSE_CPP_COURSE_DYNARRAYEXTENDED_H


class DynArrayExtended {
public:
    explicit DynArrayExtended(unsigned int initialCapacity);
    DynArrayExtended(); // the same as DynArray(1)
    DynArrayExtended(const DynArrayExtended &other);

    ~DynArrayExtended();

    void append(double value);
    unsigned int size();
    double get(int index);

    DynArrayExtended& operator=(const DynArrayExtended &other);
private:
    double* array;
    unsigned int realSize;
    unsigned int capacity;
};


#endif //HSE_CPP_COURSE_DYNARRAYEXTENDED_H
