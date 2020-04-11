/*
 * LinkedList.h
 *
 *  Created on: Mar 15, 2017
 *      Author: tourki
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include<iostream>
#include<string>
using namespace std;

#undef stringlinked //use string as the data type

#ifdef  stringlinked
typedef string ListDataType;
#else
typedef int ListDataType;
#endif

class LinkedList
{
private :
	struct node;
	typedef node* link; // typedef of the pointer to the structure node
	struct node	//node structure contian the data (element) and a pointer to the next node in the list
	{
		ListDataType element;
		link next;
	};
	link head,tail,current;
public :
	LinkedList();
	~LinkedList();
	bool insert(const ListDataType &e);
	bool first( ListDataType &e);
	bool next(	ListDataType &e);

};




#endif /* LINKEDLIST_H_ */
