#pragma once

#ifndef NODE_H
#define NODE_H


template <typename T>
class Node {
public:
    T data;
    Node<T>* _pNext;

    Node(T a) {
        data = a;
        _pNext = NULL;
    }
};


#endif