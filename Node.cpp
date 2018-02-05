//
// Created by Josh Currier on 2/4/2018.
//

#include "Node.h"

Node::Node():name(NULL),data(0),next(NULL)
{
    //nothing to do here
}


Node::Node(char *toName):data(0),next(NULL)
{
    addName(toName);
}


Node::Node(int todata):name(NULL),data(todata),next(NULL)
{
    //nothing to do here
}


Node::Node(char *toName, int toData):data(toData),next(NULL)
{
    addName(toName);
}


Node::~Node()
{
    if(name)//check if the name object is not null
    {
        delete [](name);
    }
}


char * Node::getName()
{
    return name;
}


int Node::getData()
{
    return data;
}


Node * Node::getNext()
{
    return next;
}