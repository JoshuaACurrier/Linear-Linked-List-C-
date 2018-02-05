//
// Created by Josh Currier on 2/4/2018.
//

#include <cstring>
#include "List.h"

List::List():head(NULL)
{
    //nothing to do here
}


List::List(char *toName,int toData):head(NULL)
{
    bool flag;
    Node *toAdd = new Node(toName,toData);


    flag = recAddNew(toAdd,head);

    if(!flag)
    {
        std::cout << "Error adding a new node to the list" << std::endl;
    }
}


List::~List()
{
    if(head)
        recDelAll(head);
}


bool List::findName(char *findName)
{
    if(!findName)//if the name is null
        return false;

    return recFindName(findName,head);
}


bool List::findData(int findData)
{
    return recFindData(findData,head);
}


int List::countData(int findData)
{
    return recCountData(findData,head);
}


bool List::delName(char *removeName)
{
    if(!removeName)
        return false;

    return recDelName(removeName,head);
}


int List::delNameAll(char *removeName)
{
    if(!removeName)
        return false;

    return recDelNameAll(removeName,head);
}


bool List::delData(int removeData)
{
    return recDelData(removeData,head);
}


int List::delDataAll(int removeData)
{
    return recDelDataAll(removeData,head);
}


void List::displayAll()
{
    recDisplayAll(head,1);
}


int List::countList()
{
    return recCountList(head);
}


bool List::recAddNode(char *addName, int addData, Node *&current)
{
    Node *toAdd;
    bool flag = false;
    if(!current)
    {
        toAdd = new Node(addName,addData);
        current = toAdd;
        flag = true;

    }
    else
    {
        flag = recAddNode(addName,addData,current->next);
    }

    return flag;
}


int List::recCountData(int countData, Node *current)
{
    int count = 0;
    if(!current)
        return 0;

    count = recCountData(countData,current->next);

    if(countData == current->getData())
        count++;

    return count;


}


bool List::recAddNew(Node *toNode, Node *&current)
{
    bool flag = false;
    if(!current)
    {
        current = toNode;
        flag = true;
    } else
    {
        flag = recAddNew(toNode,current->next);
    }

    return flag;
}


bool List::recFindData(int findData, Node *current)
{
    bool flag = false;
    if(!current)
        return false;

    flag = recFindData(findData,current->next);

    if(!flag)
    {
        if(findData == current->getData())
            flag = true;
    }

    return flag;

}


bool List::recFindName(char *findName, Node *current)
{
    bool flag = false;
    if(!current)
        return false;

    flag = recFindName(findName,current->next);

    if(!flag)
        if(!strcmp(findName,current->getName()))
            flag = true;

    return flag;
}


int List::recCountList(Node *current)
{
    if(!current)
        return 0;

    return recCountList(current->next) + 1;
}


bool List::recDelName(char *delName, Node *&current)
{
    Node *temp;

    if(!current)
        return false;

    if(!strcmp(delName,current->getName()))
    {
        temp = current;
        current = current->next;
        delete temp;

        return true;
    }

    return recDelName(delName,current->next);

}


int List::recDelNameAll(char *delName, Node *&current)
{
    int count;
    Node *temp;

    if(!current)
        return 0;

    count = recDelNameAll(delName,current->next);

    if(!strcmp(delName,current->getName()))
    {
        temp = current;
        current = current->next;
        delete temp;
        count++;
    }

    return count;
}


bool List::recDelData(int delData, Node *&current)
{
    Node *temp;

    if(!current)
        return false;

    if(delData == current->getData())
    {
        temp = current;
        current = current->next;
        delete temp;

        return true;
    }

    return recDelData(delData,current->next);
}


int List::recDelDataAll(int delData, Node *&current)
{
    Node *temp;
    int count;

    if(!current)
        return 0;

    count = recDelDataAll(delData,current->next);

    if(delData == current->getData())
    {
        temp = current;
        current = current->next;

        delete temp;

        count++;
    }

    return count;

}


void List::recDisplayAll(Node *current, int position)
{
    if(!current)
        return;

    std::cout << position << "- Name: " << current->getName() << std::endl;
    std::cout << "Data: " << current->getData() << std::endl << std::endl;

    recDisplayAll(current->next,++position);
}


void List::recDelAll(Node *&toDel)
{
    Node *temp;
    if(!toDel)
        return;

    recDelAll(toDel->next);

    temp = toDel;
    toDel = NULL;
    delete temp;

}