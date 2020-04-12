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
#include"inord_list.h"

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
		head=NULL;
		current=NULL;
	}

/*This function is used to insert a new element to the list
 * arguments: e -> a reference to a constant data
 * return type : bool to indicate the success of the insert
 */
bool inord_list::insert(const inord_ListDataType &e,const string &line)
{	link NewNode=new node;//locating a new block in the heap
	NewNode->next=NULL;
	if(NewNode==NULL) //asking if the allocation is a success
		return false;
	else
		{
			#ifdef  stringinordLinked //if the list type is string use the assign function to assign the string

			(NewNode->element).assign(e);//add the data of the new element
			 NewNode->counter=1;//first time to get this node
			(NewNode->lines).assign((line));
			if(head==NULL)//first insert
				{
					head=NewNode;
					NewNode->next=NULL;
					return true;
				}
			else
				{
					link pre=NULL,target=head;//setting loop arrows
					while(target!=NULL)//as this is not the last target
						{

									if((NewNode->element).compare(target->element)==0)//they are the same word
										{
											(target->counter)++;//increase repating counter by one
											(target->lines).append(" ");
											(target->lines).append(line);
											delete NewNode;//no need for this node as it is a repeated one
											return true;
										}
									else if((NewNode->element).compare(target->element)<0)//the new is higher
										{
											if(pre==NULL) //if i am at the head
												{
													link temp=head;
													head=NewNode;
													NewNode->next=temp;
													return true;
												}
											else
												{
													pre->next=NewNode;
													NewNode->next=target;
													return true;
												}
											}
									else if(target->next !=NULL) //if this is not  the last element
										  {
											 pre=target;
											 target=target->next;
										  }
									else			//if this is the last node then add at the end
										{
											target->next=NewNode;
											target=NewNode->next;
											return true;
										}



						}
				}



			#else
			NewNode->element=e;	//inserting the data element to the node
			#endif

			return false;
		}


}
/*This function is used to read the first element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */
bool inord_list::first( inord_ListDataType &e,unsigned int &c,string &l)
{	current=head;//as it is the first read it would be equal to the head
	if(current==NULL)
		return false;
	else
		{
			e=current->element;//get the data of the current node which is the head
			c=current->counter;
			l.assign(current->lines);
	    	return true;
		}
}

/*This function is used to read the next element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */

bool inord_list::next(	inord_ListDataType &e,unsigned int &c,string &l)
{	if (current==NULL || current->next==NULL)
		return false;
	else
		{
		 	current=current->next;//increasing the current pointer to point to the next node
			e=current->element;//get the data of the current node
			c=current->counter;
			l.assign(current->lines);
			return true;
		}
}
/*This function is used to read the first element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */
bool inord_list::first( unsigned int &c)
{	current=head;//as it is the first read it would be equal to the head
	if(current==NULL)
		return false;
	else
		{
			c=current->counter;
	    	return true;
		}
}

/*This function is used to read the next element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */

bool inord_list::next(unsigned int &c)
{	if (current==NULL || current->next==NULL)
		return false;
	else
		{
		 	current=current->next;//increasing the current pointer to point to the next node
			c=current->counter;
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
/*This function is used to read the first element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */
bool inord_list::first( inord_ListDataType &e,string &l)
{	current=head;//as it is the first read it would be equal to the head
	if(current==NULL)
		return false;
	else
		{
			e=current->element;//get the data of the current node which is the head
			l.assign(current->lines);
	    	return true;
		}
}

/*This function is used to read the next element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */

bool inord_list::next(	inord_ListDataType &e,string &l)
{	if (current==NULL || current->next==NULL)
		return false;
	else
		{
		 	current=current->next;//increasing the current pointer to point to the next node
			e=current->element;//get the data of the current node
			l.assign(current->lines);
			return true;
		}
}
/*This function is used to read the first element in the list
 * arguments: e -> reference to the variable in which the data will be returned
 * return type : bool to indicate the success of the reading
 */
/*this function take a reference to the list and return the max number of
*
*/
unsigned int inord_list::max_repeated()
{	string forbidden[]={"a","an","the","in","on","of","and","is","are"};
	link currnettemp=current;//bush the current pointer
	unsigned int max=0,currnetWordCounter;
	string word;
	first(word,currnetWordCounter);
	checker: if(word==forbidden[0] || word==forbidden[1] || word==forbidden[2] || word==forbidden[3] || word==forbidden[4] || word==forbidden[5] || word==forbidden[6] || word==forbidden[7] || word==forbidden[8]  ) //if the word is one of the forbidden
					{	if(next(word,currnetWordCounter))//use the next word if avaliable to get the first max
							goto checker;
						else
							return max;//no next any more
					}
			 else
				 max=currnetWordCounter;
		while(next(word,currnetWordCounter))
			{
				if(!(word==forbidden[0] || word==forbidden[1] || word==forbidden[2] || word==forbidden[3] || word==forbidden[4] || word==forbidden[5] || word==forbidden[6] || word==forbidden[7] || word==forbidden[8] )) //if the word is one of the forbidden
					 max=(currnetWordCounter>max)?currnetWordCounter:max; //if the counter is higher then it is the new max

			}
		current=currnettemp;
		return max;
}
