//
// Created by yawkar on 03.10.22.
//

#ifndef HSE_CPP_COURSE_MYSTACK_H
#define HSE_CPP_COURSE_MYSTACK_H
class MyStack {
public:
    MyStack(); // the same as MyStack(1)
    explicit MyStack(unsigned int initialCapacity);

    ~MyStack();

    void push(int value);
    int pop();
    unsigned int size();
    int peek();
private:
    int* array;
    unsigned int realSize;
    unsigned int capacity;
};
#endif //HSE_CPP_COURSE_MYSTACK_H
