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

    static unsigned int instancesAlive();

    ~DynArrayExtended();

    void append(double value);
    unsigned int size() const;
    double get(int index);

    DynArrayExtended& operator=(const DynArrayExtended &other);
    double& operator[](int index);
    DynArrayExtended operator+(const DynArrayExtended &other);
    DynArrayExtended& operator>>(unsigned int shift);
    DynArrayExtended& operator<<(unsigned int shift);
private:
    double* array;
    unsigned int realSize;
    unsigned int capacity;
    static unsigned int _instancesAlive;
};


#endif //HSE_CPP_COURSE_DYNARRAYEXTENDED_H
