#include "List.h"
#include <iostream>

#define ZERO 0

template <class T>
List<T>::List()
{
    this->frontNode = new Node;
    this->backNode = new Node;
    this->size = ZERO;
}

template <class T>
List<T>::~List()
{
    delete(frontNode);
    delete(backNode);
}


template <class T>
void List<T>::insert(T element)
{
    Node* currentNode = this->frontNode;
    for(int currentNodeIndex = ZERO; currentNodeIndex < this->size && currentNode->next->element < element; currentNodeIndex++)
        currentNode = currentNode->next;
    Node* newNode = new Node(element);
    newNode->next = currentNode->next;
    currentNode->next->previous = newNode;
    currentNode->next = newNode;
    newNode->previous = currentNode;
}

template <class T>
void List<T>::removeElement(T element)
{
    Node* currentNode = this->frontNode->next;
    for(int currentNodeIndex = ZERO; currentNodeIndex < this->size && currentNode->element != element; currentNodeIndex++)
        currentNode = currentNode->next;
    if(currentNode->element == element)
    {
        currentNode->previous->next = currentNode->next;
        currentNode->next->previous = currentNode->previous;
        delete(currentNode);
    }
}

template <class T>
void List<T>::removeIndex(int index)
{
    Node* currentNode = this->frontNode->next;
    if(index > ZERO && index <= this->size)
    {
        for(int currentNodeIndex = ZERO; currentNodeIndex < index; currentNodeIndex++)
            currentNode = currentNode->next;
                currentNode->previous->next = currentNode->next;
        currentNode->next->previous = currentNode->previous;
        delete(currentNode);
    }
}

template <class T>
void List<T>::displayFrontToBack()
{
    Node* currentNode = this->frontNode->next;
    for(int currentNodeIndex = ZERO; currentNodeIndex < this->size; currentNodeIndex++)
    {
        std::cout<< currentNode->element << std::endl;
        currentNode = currentNode->next;
    }
}

template <class T>
void List<T>::displayBackToFront()
{
    Node* currentNode = this->backNode->next;
    for(int currentNodeIndex = ZERO; currentNodeIndex < this->size; currentNodeIndex++)
    {
        std::cout<< currentNode->element << std::endl;
        currentNode = currentNode->previous;
    }
}

template <class T>
T List<T>::getElement(int index)
{
    
    Node* currentNode = this->frontNode->next;
    if(index > ZERO && index <= this->size)
    {
        for(int currentNodeIndex = ZERO; currentNodeIndex < index; currentNodeIndex++)
            currentNode = currentNode->next;
        return currentNode->element;
    }
    return NULL;
}

template <class T>
int List<T>::getSize()
{
    return this->size;
}

