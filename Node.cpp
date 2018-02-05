//
// Created by Josh Currier on 2/4/2018.
//

#include <cstring>
#include "Node.h"

Node::Node():name(nullptr),data(0),next(nullptr)
{
    //nothing to do here
}


Node::Node(char *toName):data(0),next(nullptr)
{
    addName(toName);
}


Node::Node(int toData):name(nullptr),data(toData),next(nullptr)
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


void Node::addName(char *toName)
{
    if(!toName)
        return;
    name = new char[strlen(toName)+1];
    strcpy(name,toName);
}

