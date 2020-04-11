/*
 * inord_list.cpp
 *
 *  Created on: Mar 18, 2017
 *      Author: tourki
 */

/*
 * LinkedList.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: tourki
 */

/*This function take the List element and create a new node it and lik it with the list
 *
 */
#include "inord_list(sameWordsWithCounters).h"
inord_list::inord_list()
	{
		head=NULL;
		current=NULL;
	}
inord_list::~inord_list()
	{
		link target=head;
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
bool inord_list::insert(const inord_ListDataType &e)
{	link NewNode=new node;//locating a new block in the heap
	if(NewNode==NULL) //asking if the allocation is a success
		return false;
	else
		{
			#ifdef  stringinordLinked //if the list type is string use the assign function to assign the string

			(NewNode->element).assign(e);//add the data of the new element
			 NewNode->counter=1;
			if(head==NULL)//first insert
				{
					head=NewNode;
					NewNode->next=NULL;
				}
			else
				{
					link pre=NULL,target=head;//setting loop arrows
					while(target!=NULL)//as this is not the last target
						{	if(pre==NULL)
								{
									if((NewNode->element).compare(target->element)==0)//they are the same word
										{
											(target->counter)++;//increase repating counter by one
											return true;
										}
									else if((NewNode->element).compare(target->element)<0)//the new is higher
										{
											link temp=head;
											head=NewNode;
											NewNode->next=temp;
											return true;
										}
									else
										{
											pre=target;
											target=target->next;
										}
								}
							else
								{
									if((NewNode->element).compare(target->element)==0)//they are the same word
										{
											(target->counter)++;//increase repating counter by one
											return true;
										}
									else if((NewNode->element).compare(target->element)<0)//the new is higher
										{
											pre->next=NewNode;
											NewNode->next=target;
											return true;
										}
									else
										{
											pre=target;
											target=target->next;
										}
								}

						}
				}



			#else
			NewNode->element=e;	//inserting the data element to the node
			#endif

			return true;
		}


}
/*This function is used to read the first element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */
bool inord_list::first( inord_ListDataType &e,unsigned int &c)
{	current=head;//as it is the first read it would be equal to the head
	if(current==NULL)
		return false;
	else
		{
			e=current->element;//get the data of the current node which is the head
			c=current->counter;
	    	return true;
		}
}

/*This function is used to read the next element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */

bool inord_list::next(	inord_ListDataType &e,unsigned int &c)
{	if (current==NULL || current->next==NULL)
		return false;
	else
		{
		 	current=current->next;//increasing the current pointer to point to the next node
			e=current->element;//get the data of the current node
			c=current->counter;
			return true;
		}
}

