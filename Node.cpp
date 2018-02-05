//
// Created by Josh Currier on 2/4/2018.
//

#include "Node.h"

Node::Node():name(nullptr),data(0),next(nullptr)
{
    //nothing to do here
}


Node::Node(char *toName):data(0),next(nullptr)
{
    addName(toName);
}


Node::Node(int todata):name(nullptr),data(todata),next(nullptr)
{
    //nothing to do here
}


Node::Node(char *toName, int toData):data(toData),next(nullptr)
{
    addName(toName);
}


Node::~Node()
{
    if(name)//check if the name object is not null
    {
        delete [](name);
    }

    name = nullptr;
}


char * Node::getName()
{
    return name;
}


int Node::getData()
{
    return data;
}

