//============================================================================
// Name        : A3.cpp
// Author      : Hossam Tourki
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <iomanip>      // std::setprecision
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "stack.h"
typedef  double NumberDataType ;
NumberDataType  string_to_Number(const string &buffer);
void calculate();
Stack<char> operatorStack;
Stack<NumberDataType> numbersStack;
int main(int argc,char*argv[]) {
	int i=0,brackets=0;
	if(argc>2)
		{
			cout<<"Invalid Expression";
			return 0;
		}
	else if(argc==1)
		{
			printf("%.2lf",NumberDataType(0));
			return 0;
		}
	else
	{
	while(int (strlen(argv[1])) > i)
		{
			if((argv[1][i]>='0'&&argv[1][i]<='9')||((!(argv[1][i-1]>='0'&&argv[1][i-1]<='9')&& argv[1][i-1]!=')')&&(argv[1][i]=='+'||argv[1][i]=='-')&&(argv[1][i+1]>='0'&&argv[1][i+1]<='9')))
				{	// number is  anything but numbers (+or-) , 0to9
					// if the input is a number or a sign of a number append on a string later to be converted into integer value
					string numString ="";//empty string to append to
					numString+=argv[1][i];//add the first figure alone in case it was a sign
					i++;//to the next figure
					while((argv[1][i]>='0'&&argv[1][i]<='9'))
						{
						//while it is numbers keep appending to the same number
						numString+=argv[1][i];
						i++;
						}
					numbersStack.push(string_to_Number(numString));//the number is finished
				}
			else if((argv[1][i]=='x'||argv[1][i]=='+'||argv[1][i]=='-'||argv[1][i]=='/') && ((argv[1][i-1]>='0'&&argv[1][i-1]<='9')||argv[1][i-1]==')')&&((argv[1][i+1]>='0'&&argv[1][i+1]<='9')||argv[1][i+1]=='('||argv[1][i+1]=='+'||argv[1][i+1]=='-'))
				{	// 0to9 or )  operator 0to9 or ( or + or -
					if((numbersStack.Counter-(operatorStack.Counter-brackets))!=1)
						{
							cout<<"Invalid Expression";
							return 0;
						}
					else
						{
							char poped=0,coming=argv[1][i];
							operatorStack.top(poped);
							if((coming<=poped || poped=='/') && poped !='(')
								calculate();
							else
								{
									operatorStack.push(argv[1][i]);
									i++;
								}
						}
				}
			else if(argv[1][i]=='(')
				{
					operatorStack.push(argv[1][i]);
					brackets++;
					i++;
				}
			else if(argv[1][i]==')')
				{	if(brackets!=0)
						{
							char oper;
							operatorStack.top(oper);
							while(oper!='('&&brackets!=0)
								{
									calculate();
									operatorStack.top(oper);
								}
							operatorStack.pop(oper);
							brackets--;
							i++;

						}
					else
						{
							cout<<"Invalid Expression";
							return 0;
						}

				}
			else
				{
					cout<<"Invalid Expression";
					return 0;
				}
		}
	}



	if((numbersStack.Counter-operatorStack.Counter)!=1)
		{
			cout<<"Invalid Expression";
			return 0;
		}
	else
		{
			while(!operatorStack.isEmpty())
				calculate();
			NumberDataType output=0;
			numbersStack.pop(output);
			if(numbersStack.isEmpty())
				printf("%.2lf",output);
			else
				cout<<"Invalid Expression";

		}

	return 0;
}



NumberDataType  string_to_Number(const string &buffer){
		 NumberDataType number;
	 	 stringstream temp;
	  	 temp<<buffer;
	  	 temp>>number;
	  	 return number;
	}

void calculate(){
	NumberDataType op1,op2;
	numbersStack.pop(op2);
	numbersStack.pop(op1);
	char operator1;
	operatorStack.pop(operator1);
			if(operator1=='+')
				numbersStack.push((op1+op2));
			else if(operator1=='-')
				numbersStack.push((op1-op2));
			else if(operator1=='x')
				numbersStack.push((op1*op2));
			else if(operator1=='/'){
				if(op2==0){
					cout<<"Invalid Expression";
					exit(1);
				}
				else
					numbersStack.push((op1/op2));
			}
			else{
				numbersStack.push(op1);
				numbersStack.push(op2);
				operatorStack.push(operator1);
			}


}
