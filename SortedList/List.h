#ifndef LIST_H
#define LIST_H

#include <iostream>

#define ZERO 0

template <class T>
class List
{
    private:
            class Node;
            int size;
            Node *frontNode;
            Node *backNode;
    public:
        List();
        ~List();
        void insert(T element);
        void removeElement(T element);
        void removeIndex(int index);
        void displayFrontToBack();
        void displayBackToFront();
        T getElement(int index);
        int getSize();
};    
    

template <class T>
class List<T>::Node
{
    public:
        Node* next;
        Node* previous;
        T element;
        Node(T element)
        {
            this->next = nullptr;
            this->previous = nullptr;
            this->element = element;
        }
        ~Node()
        {
            delete(next);
            delete(previous);
        }
};

template <class T>
List<T>::List()
{
    this->frontNode = new Node(ZERO);
    this->backNode = new Node(ZERO);
    this->frontNode->next = this->backNode;
    this->backNode->previous = this->frontNode;
    this->size = ZERO;
}

template <class T>
List<T>::~List()
{
    while(frontNode->next != nullptr)
    {
        Node* takeOffNode = frontNode;
        frontNode = frontNode->next;
        takeOffNode->next=nullptr;
        takeOffNode->previous=nullptr;
        delete(takeOffNode);
    }
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
    this->size++;
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
        currentNode->previous = nullptr;
        currentNode->next = nullptr;
        delete(currentNode);
        this->size--;
    }
}

template <class T>
void List<T>::removeIndex(int index)
{
    Node* currentNode = this->frontNode->next;
    if(index >= ZERO && index < this->size)
    {
        for(int currentNodeIndex = ZERO; currentNodeIndex < index; currentNodeIndex++)
            currentNode = currentNode->next;
                currentNode->previous->next = currentNode->next;
        currentNode->next->previous = currentNode->previous;
        currentNode->previous = nullptr;
        currentNode->next = nullptr;
        delete(currentNode);
        this->size--;
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

#endif
