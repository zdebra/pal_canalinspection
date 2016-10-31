//
// Created by mangowebak on 31/10/2016.
//

#ifndef PAL_CANALSINSPECTION_STACK_H
#define PAL_CANALSINSPECTION_STACK_H


class Stack {
private:
    int size;
    int* data;
    int index;
    ~Stack();

public:
    Stack(int size);
    void push(int value);
    int pop();
    bool contains(int value);

};


#endif //PAL_CANALSINSPECTION_STACK_H
