/*
 * LinkedList.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: tourki
 */

/*This function take the List element and create a new node it and lik it with the list
 *
 */
#include"LinkedList.h"

LinkedList::LinkedList()
{
	head=NULL;
	tail=NULL;
	current=NULL;
}
LinkedList::~LinkedList()
{	link target=head;
	link next;
	while(target!=NULL)
		{	next=target->next;
			delete target;
			target=next;
		}
}
/*This function is used to insert a new element to the list
 * arguments: e -> a reference to a constant data
 * return type : bool to indicate the success of the insert
 */
bool LinkedList::insert(const ListDataType &e)
{	link NewNode=new node;//locating a new block in the heap
	if(NewNode==NULL) //asking if the allocation is a success
		return false;
	else
		{
			#ifdef  stringlinked //if the list type is string use the assign function to assign the string
			(NewNode->element).assign(e);
			#else
			NewNode->element=e;	//inserting the data element to the node
			#endif
			NewNode->next=NULL;//clearing the pointer of this new block
			if(head==NULL)//if the head pointer is empty then this is the first element
				{
					head=NewNode;//this node is the head
					tail=NewNode;//and the tail at the same time as only one element of the list
				}
			else
				{
					tail->next=NewNode;//not the first element then link the old tail to the new node
					tail=NewNode;//make the new node the current tail
				}
			return true;
		}
}
/*This function is used to read the first element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */
bool LinkedList::first( ListDataType &e)
{	current=head;//as it is the first read it would be equal to the head
	if(current==NULL)
		return false;
	else
		{
			e=current->element;//get the data of the current node which is the head
	    	return true;
		}
}

/*This function is used to read the next element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */

bool LinkedList::next(	ListDataType &e)
{	if (current==NULL || current==tail)
		return false;
	else
		{
		 	current=current->next;//increasing the current pointer to point to the next node
			e=current->element;//get the data of the current node
			return true;
		}
}
