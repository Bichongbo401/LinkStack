#pragma once
//
// Created by 14035 on 2020/10/5.
//
#ifndef UNTITLED57_LINKSTACK_H
#define UNTITLED57_LINKSTACK_H
#include "Node.h"
template <class type>
class LinkStack
{
protected:
    Node<type>* top;
    int count;

public:
    LinkStack();
    virtual ~LinkStack();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse(void (*visit)(const type& e)) const;
    bool push(const type& e);
    bool Top(type& e) const;
    bool Pop(type& e);

};
template <class type>
LinkStack<type>::LinkStack()
{
    top = NULL;
    count = 0;
}
template <class type>
LinkStack<type>::~LinkStack()
{
    Clear();
}
template <class type>
int LinkStack<type>::Length() const
{
    return count;
}
template <class type>
bool LinkStack<type>::Empty() const
{
    return top == NULL;
}
template <class type>
void LinkStack<type>::Clear()
{
    type tmp;
    while (!Empty())
    {
        Pop(tmp);
    }
}
template <class type>
void LinkStack<type>::Traverse(void (*visit)(const type&)) const
{
    Node<type>* tmpPtr;
    LinkStack<type>tmps;
    for (tmpPtr = top; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {
        tmps.push(tmpPtr->data);
    }
    for (tmpPtr = tmps.top; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {
        (*visit)(tmpPtr->data);
    }
}
template <class type>
bool LinkStack<type>::push(const type& e)
{
    Node<type>* newTop = new Node<type>(e, top);
    if (newTop == NULL)
    {
        return false;
    }
    else
    {
        top = newTop;
        count++;
        return true;
    }
}
template <class type>
bool LinkStack<type>::Top(type& e) const
{
    if (Empty())
    {
        return false;
    }
    else
    {
        e = top->data;
        return true;
    }
}
template <class type>
bool LinkStack<type>::Pop(type& e)
{
    if (Empty())
    {
        return false;
    }
    else
    {
        Node<type>* oldTop = top;
        e = oldTop->data;
        top = oldTop->next;
        count--;
        delete oldTop;
        return true;
    }
}

#endif // UNTITLED57_LINKSTACK_H
