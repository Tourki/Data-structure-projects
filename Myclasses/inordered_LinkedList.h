#ifndef INORDERED_LINKEDLIST_H_
#define INORDERED_LINKEDLIST_H_
#include <iostream>
using namespace std;

typedef string ListElemType;

class inordered_LinkedList {
public:
    inordered_LinkedList();
    bool insert( ListElemType& item);
    bool first(ListElemType& item);
    bool next(ListElemType& item);


private:
    struct Node; // Forward declaration of structure
    typedef Node* Link;
    struct Node {
        ListElemType element;
        Link next;
    };
    Link head;
    Link tail;
    Link current;
};




#endif /* INORDERED_LINKEDLIST_H_ */
