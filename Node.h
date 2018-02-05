//
// Created by jtike on 2/4/2018.
//

#ifndef LLL_NODE_H
#define LLL_NODE_H

#include <iostream>


class Node {
public:
    Node();
    explicit Node(char *);
    explicit Node(int );
    Node(char *, int);
    ~Node();
    char * getName();
    int getData();
    Node *next;

private:
    char *name;
    int data;
};


#endif //LLL_NODE_H
