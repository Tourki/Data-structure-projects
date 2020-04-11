#include <string.h>
#include <stdio.h>
#include "inordered_LinkedList.h"

inordered_LinkedList::inordered_LinkedList()
{
	head = NULL;
	tail = NULL;
	current = NULL;
}
bool inordered_LinkedList::insert( ListElemType& item)
{
	Link addedNode = new Node;
	Link pred;
	if (addedNode == NULL) {
		return false; // allocation failed
	}
	else{
		// transform it to upper case then insert
		for(unsigned int j=0;j<item.length();j++)
		{
			if((item[j]>='a'&&item[0]<='z'))
			{
				item[j]=item[j]-32;
			}
		}
		(addedNode->element).assign(item);

		int x=item.compare(head->element);

		if (head == NULL||item <= head->element)
		{addedNode->next=head;
		head = addedNode;
		return true;
		}
		else
		{
			pred=head;
		//	int y=item.compare(pred->next->element);
			while(pred->next!=NULL&&pred->next->element < item)
				pred=pred->next;

		addedNode->next=pred->next;
		pred->next=addedNode;
		return true;
		}
	}
}




bool inordered_LinkedList::first(ListElemType& item)
{
	if (head == NULL) {
		// check if the list is empty
		return false;
	}
	else {
		current = head;
		item = current->element;
		return true;
	}
}

bool inordered_LinkedList::next(ListElemType& item)
{
	if (current == NULL || current->next == NULL) {
		// check if first has been called at least once
		// check if end of the list is reached
		return false;
	}
	else {
		current = current->next;
		item = current->element;
		return true;
	}
}
