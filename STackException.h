#pragma once
#include <string>
#include <exception>

class StackException : public std::exception {};

class StackOverflow : public StackException
{
    const char* what() const throw() override
    {
        return "Stack oveflow!\n";
    }
};

class EmptyStack : public StackException
{
    const char* what() const throw() override {
        return "Stack is empty!\n";
    }
};