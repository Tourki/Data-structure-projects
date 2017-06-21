//============================================================================
// Name        : A4.cpp
// Author      : Hossam Tourki
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

using namespace std;

int main(int argc,char*argv[]) {
	if(argc<5 || !atoi(argv[2])||(string)argv[4]!=":")
		{
			cout<<"Invalid Configuration";
			return 0;
		}
	unsigned int SeqNumBits=atoi(argv[1]);
	unsigned int WinSizeBits=atoi(argv[2]);
	unsigned int intialSeq=atoi(argv[3]);
/*check the input*/
	int i=1;
	while(i<argc)
		{
			unsigned int j=0;
			while((unsigned int )strlen(argv[i])>j)
				{

					if((i<5)&&((!(((argv[i][j]>='0'&&argv[i][j]<='9'))||((string)argv[i]==":"&&i==4)))||((intialSeq/((unsigned int)pow(2,SeqNumBits)))||(((unsigned int)pow(2,WinSizeBits))>((unsigned int)pow(2,SeqNumBits-1))))))
						{
							cout<<"Invalid Configuration";
							return 0;
						}

					if((!(argv[i][j]>='0'&&argv[i][j]<='9')||(unsigned int)atoi(argv[i])/((unsigned int)pow(2,SeqNumBits)))&& i>4)
						{
							cout<<"Invalid Packet";
							return 0;
						}
					j++;
				}
			i++;
		}


	//cout<<(intialSeq/((unsigned int)pow(2,SeqNumBits)))<<endl;


	/*end of check*/

	unsigned int  expected=intialSeq;
	unsigned int  MaxSeq=((unsigned int)pow(2,SeqNumBits))-1;
	unsigned int  WindowOffset=((unsigned int)pow(2,WinSizeBits))-1;
	unsigned int WindowNormalEnd=expected+WindowOffset<MaxSeq?expected+WindowOffset:MaxSeq;
	 int WindowWrappedEnd=expected+WindowOffset<MaxSeq?-1:expected+WindowOffset-1-MaxSeq;
	//cout <<expected<<endl<<MaxSeq<<endl<<WindowOffset<<endl<<WindowEnd<<endl;
	cout<<"R ";
	unsigned int Droped=0;
	Queue<unsigned int> wait,wrapped;
	i=5;
	while(i<argc)
		{	 if((unsigned int)atoi(argv[i])==expected)
				{
					cout<<(unsigned int)atoi(argv[i])<<" ";

					expected=(expected+1)%(MaxSeq+1);//if next expected is wrapped
					WindowNormalEnd=expected+WindowOffset<MaxSeq?expected+WindowOffset:MaxSeq;
					WindowWrappedEnd=expected+WindowOffset<MaxSeq?-1:expected+WindowOffset-1-MaxSeq;
					unsigned int buf;
					if(!wait.isEmpty())
					{
						while(wait.front(buf)&&buf==expected)
							{
									cout<<wait.dequeue()<<" ";
									expected=(expected+1)%(MaxSeq+1);//if next expected is wrapped
									WindowNormalEnd=expected+WindowOffset<MaxSeq?expected+WindowOffset:MaxSeq;
									WindowWrappedEnd=expected+WindowOffset<MaxSeq?-1:expected+WindowOffset-1-MaxSeq;

							}
					}
					if(!wrapped.isEmpty())
						{
							while(wrapped.front(buf)&&buf==expected)
								{
											cout<<wrapped.dequeue()<<" ";
											expected=(expected+1)%(MaxSeq+1);//if next expected is wrapped
											WindowNormalEnd=expected+WindowOffset<MaxSeq?expected+WindowOffset:MaxSeq;
											WindowWrappedEnd=expected+WindowOffset<MaxSeq?-1:expected+WindowOffset-1-MaxSeq;

								}
						}
				}
			else if((((unsigned int)atoi(argv[i])>=expected)&&((unsigned int)atoi(argv[i])<=WindowNormalEnd)))
				{
					Droped+=!wait.enqueue((unsigned int)atoi(argv[i]));//increase the dropped if repeated
				}
			else if((((int)atoi(argv[i])<=WindowWrappedEnd)))
				{
					Droped+=!wrapped.enqueue((unsigned int)atoi(argv[i]));//increase the dropped if repeated
				}
			else
				Droped++;
				i++;
		}
	cout<<"E "<<expected<<" ";
	cout<<"W ";
	while(!wait.isEmpty())
			cout<<wait.dequeue()<<" ";
	while(!wrapped.isEmpty())
			cout<<wrapped.dequeue()<<" ";
	cout<<"D# "<<Droped;
	return 0;
}
