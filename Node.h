#pragma once
//
// Created by 14035 on 2020/10/5.
//

#ifndef UNTITLED57_NODE_H
#define UNTITLED57_NODE_H
#include<iostream>
template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node(T item, Node<T>* link = NULL)
    {
        data = item;
        next = link;
    }
    Node()
    {
        next = NULL;
    }
};
#endif // UNTITLED57_NODE_H
