#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
    std::vector<T> stck;
};


template <typename T>
Stack<T>::Stack()
{

}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
bool Stack<T>::empty() const
{
    return stck.size() == 0;
}

template <typename T>
size_t Stack<T>::size() const
{
    return stck.size();
}

template <typename T>
void Stack<T>::push(const T& item)
{
    stck.push_back(item);
}

template <typename T>
void Stack<T>::pop()
{
    if (stck.empty())
    {
        throw std::underflow_error("Empty");
    }else{
        stck.pop_back();
    }
}

template <typename T>
const T& Stack<T>::top() const
{
    if (stck.empty())
    {
        throw std::underflow_error("Empty");
    }else{
        return stck.back();
    }
}


#endif