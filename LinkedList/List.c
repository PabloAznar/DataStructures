#include "List.h"
#include <stdlib.h>
#include <stdio.h>

#define ZERO 0
#define ERROR -1

struct NodeRep
{
    int element;
    Node next;
    Node previous;
};

struct ListRep
{
    int size;
    Node frontNode;
    Node backNode;
};

Node createNode(int element)
{
    Node newNode = malloc(sizeof(struct NodeRep));
    newNode->element = element;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

List createList()
{
    List newList = malloc(sizeof(struct ListRep));
    newList->size = ZERO;
    newList->frontNode = createNode(ZERO);
    newList->backNode = createNode(ZERO);
    newList->frontNode->next = newList->backNode;
    newList->backNode->previous = newList->frontNode;
    return newList;
}

void deleteNode(Node node)
{
    free(node);
}

void deleteList(List list)
{
    while(list->frontNode->next != NULL)
    {
        Node takeOffNode = list->frontNode;
        list->frontNode = list->frontNode->next;
        deleteNode(takeOffNode);
    }
    deleteNode(list->frontNode);
    free(list);
}

void insertFirst(List list, int element)
{
    Node newNode = createNode(element);
    list->frontNode->next->previous = newNode;
    newNode->next = list->frontNode->next;
    list->frontNode->next = newNode;
    newNode->previous = list->frontNode;
    list->size++;
}

void insertLast(List list, int element)
{
    Node newNode = createNode(element);
    list->backNode->previous->next = newNode;
    newNode->previous = list->backNode->previous;
    newNode->next = list->backNode;
    list->backNode->previous = newNode;
    list->size++;
}

//Encapsulation of how a node is removed so remove methods 
//calls this function instead of doing the same operations
void removeNode(Node takeOffNode)
{
    takeOffNode->previous->next = takeOffNode->next;
    takeOffNode->next->previous = takeOffNode->previous;
    deleteNode(takeOffNode);
}
void removeIndex(List list, int index)
{
    if(index >= ZERO && index < list->size)
    {
        Node searchNode = list->frontNode->next;
        for(int currentNodeIndex = ZERO; currentNodeIndex < index; currentNodeIndex++)
            searchNode = searchNode->next;
        removeNode(searchNode);
        list->size--;
    }
}

void removeFirstMatch(List list, int element)
{
    Node searchNode = list->frontNode->next;
    for(int currentNodeIndex = ZERO; currentNodeIndex < list->size && searchNode->element != element; currentNodeIndex++)
        searchNode = searchNode->next;
    if(searchNode->element == element)
    {
        removeNode(searchNode);
        list->size--;
    }
}

void removeAllMatches(List list, int element)
{
    Node searchNode = list->frontNode->next;
    for(int currentNodeIndex = ZERO; currentNodeIndex < list->size; currentNodeIndex++)
    {
        if(searchNode->element == element)
        {
            Node takeOffNode = searchNode;
            searchNode = searchNode->next;
            removeNode(takeOffNode);
            list->size--;
        }
        else
            searchNode = searchNode->next;
    }
}

int getElement(List list,int index)
{
    if(index >= ZERO && index < list->size)
    {
        Node searchNode = list->frontNode->next;
        for(int currentNodeIndex = ZERO; currentNodeIndex < index; currentNodeIndex++)
            searchNode = searchNode->next;
        return searchNode->element;
    }
    return ERROR;
}

void displayFrontToBack(List list)
{
    Node currentNode = list->frontNode->next;
    for(int currentNodeIndex = ZERO;currentNodeIndex < list->size; currentNodeIndex++)
    {
        printf("%d\n", currentNode->element);
        currentNode = currentNode->next;
    }
}    

void displayBackToFront(List list)
{
    Node currentNode = list->backNode->previous;
    for(int currentNodeIndex = ZERO;currentNodeIndex < list->size; currentNodeIndex++)
    {
        printf("%d\n", currentNode->element);
        currentNode = currentNode->previous;
    }
}  

int getSize(List list)
{
    return list->size;
}
