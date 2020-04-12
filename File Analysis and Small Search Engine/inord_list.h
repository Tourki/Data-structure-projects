/*
 * inord_list.h
 *
 *  Created on: Mar 18, 2017
 *      Author: tourki
 */

#ifndef INORD_LIST_H_
#define INORD_LIST_H_
#include<iostream>
#include<string>
using namespace std;

#define stringinordLinked //use string as the data type

#ifdef  stringinordLinked
typedef string inord_ListDataType;
#else
typedef int inord_ListDataType;
#endif

class inord_list
{
private :
	struct node;
	typedef node* link; // typedef of the pointer to the structure node
	struct node	//node structure contian the data (element) and a pointer to the next node in the list
	{
		inord_ListDataType element;
		unsigned int counter;
		string lines;
		link next;
	};
	link head,current;
public :
	inord_list();
	~inord_list();
	bool insert(const inord_ListDataType &e,const string &line );
	bool first( inord_ListDataType &e,unsigned int &c, string &l);
	bool next(	inord_ListDataType &e,unsigned int &c, string &l);
	bool first( inord_ListDataType &e,unsigned int &c);
	bool next(	inord_ListDataType &e,unsigned int &c);
	bool first( inord_ListDataType &e,string &l);
	bool next(	inord_ListDataType &e,string &l);
	bool first( unsigned int &c);
	bool next( unsigned int &c);

	unsigned int max_repeated();

};






#endif /* INORD_LIST_H_ */
