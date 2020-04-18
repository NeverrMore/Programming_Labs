#pragma once
#include <iostream>
#include <vector>
#include "STackException.h"

template<class Type, int MaxSize>
class Stack
{
private:
std::vector<Type> stack_;
int size_;
public:
    Stack(){
        size_ = 0;
        stack_ = std::vector<Type>(MaxSize);
    }

    void Push(const Type &value){
        if(size_ == MaxSize) {
            throw StackOverflow();
        }
        stack_[size_] = value;
        size_++;
    }

    Type Pop(){
        if (size_ == 0){
            throw EmptyStack();
        }
        size_--;
        stack_[size_] = (Type)NULL;
    }
};