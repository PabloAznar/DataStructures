#ifndef LIST_H
#define LIST_H

typedef struct NodeRep* Node;
typedef struct ListRep* List;

Node createNode(int element);

List createList();

void deleteNode(Node node);

void deleteList(List list);

void insertFirst(List list, int element);

void insertLast(List list, int element);

void removeIndex(List list, int index);

void removeFirstMatch(List list, int element);

void removeAllMatches(List list, int element);

int getElement(List list, int index);

void displayFrontToBack(List list);

void displayBackToFront(List list);

int getSize(List list);

#endif
