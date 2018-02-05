//
// Created by Josh Currier on 2/4/2018.
//

#ifndef LLL_LIST_H
#define LLL_LIST_H

#include "Node.h"

class List {
public:
    List();
    List(char *,int);
    ~List();
    bool addNode(char *,int);
    bool findName(char *);//if the name exists in the linear linked list this will return true
    bool findData(int);//if the data exists in the linear linked list this will return true
    int countData(int);//returns the number of times the data appears into the LLL
    bool delName(char *);//deletes the first instance of the name, returns false if no value is found
    int delNameAll(char *);//deletes all instances that match the name, returns the number deleted
    bool delData(int);//deletes the first instance of matching data, returns false if no value is found
    int delDataAll(int);//deletes all instances that match the data, returns the number deleted
    void displayAll();
    int countList();//returns the number of elements in the Linear Linked List



private:
    Node *head;
    bool recAddNode(char *,int,Node *&);//adds a new node to the end of the LLL
    int recCountData(int,Node *);
    bool recFindName(char *,Node *);
    bool recFindData(int ,Node *);
    bool recAddNew(Node *,Node *&);//adds a new node to the end of the LLL
    int recCountList(Node *);
    bool recDelName(char *,Node *&);
    int recDelNameAll(char *,Node *&);
    bool recDelData(int,Node *&);
    int recDelDataAll(int,Node *&);
    void recDisplayAll(Node *,int);
    void recDelAll(Node *&);//deletes all of the nodes in the linear linked list
};


#endif //LLL_LIST_H
