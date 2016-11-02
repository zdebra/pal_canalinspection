#include "Stack.h"

Stack::Stack(int size) {
    this->size = size;
    this->data = new int[size];
    this->index = 0;
}

void Stack::push(int value) {
    if(index > size) {
        throw -1;
    }
    this->data[index] = value;
    index++;

}

int Stack::pop() {
    if(index == 0) {
        return -1;
    }
    index--;
    return data[index];
}

bool Stack::contains(int value) {
    for(int i=0;i<index;i++) {
        if(data[i]==value) {
            return true;
        }
    }
    return false;
}

Stack::~Stack() {
    delete[] this->data;
}