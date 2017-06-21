//============================================================================
// Name        : A1.cpp
// Author      : Hossam Tourki
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cstdlib>

using namespace std;

int main(int argc , char *argv[])
{
	if(!strcmp(argv[1],"print"))//check if the command is print
		{
			if(argc < 3) // there is more than one word
				cout<<"Incorrect Number of Arguments";
			else
				{
				for(int i = 2; i < argc ; i++)
					{
						cout << argv[i]; //print arguments without spaces
						i==argc-1? :cout<<" ";
					}
				}
		}

	/*-----------------------------------------------------------------------------------------------------------*/

	else if (!strcmp(argv[1],"reverse")) //check if the command is reverse
		{
			if(argc < 3) // there is more than one word
				cout<<"Incorrect Number of Arguments";
			else
				{
					for(int i = argc-1 ; i > 1 ; i--)
						{
							cout << argv[i]; //print from the last word to the first
							i==2? :cout<<" ";
						}

				}
		}
	/*-----------------------------------------------------------------------------------------------------------*/

	else if (!strcmp(argv[1],"upper")) //check if the command is upper : change the characters into upper case
		{
			if(argc < 3) // there is more than one word
				cout<<"Incorrect Number of Arguments";
			else
			{
				for(int i =2 ; i < argc ; i++)// start from the first argument to the last
					{
						int j=0;
						while (argv[i][j])//start from the first char of the argument to the last
							{
							printf("%c",toupper(argv[i][j]));
							j++;
							}
						i==argc-1? :cout<<" "; //space between every word
					}
			}
		}
	/*-----------------------------------------------------------------------------------------------------------*/

	else if (!strcmp(argv[1],"shuffle")) //check if the command is shuffle a provided word
		{ // first check it is only one word
		 	 if(argc != 3) // there is more than one word
		 		 cout<<"Incorrect Number of Arguments";
		 	 else
		 	 {
		 		 	 int x=strlen(argv[2]); // length of the word
		 		 	 if (!(x%2))//number of char is even
		 		 	 	 {
		 		 		 	 for (int i = 0;argv[2][i];i+=2)//till you find no characters
		 		 	 		 cout<< argv[2][i+1] << argv[2][i];
		 		 	 	 }
		 		 	 else // number of char is odd
		 		 	 	 {
		 		 		 	 for (int i = 0; i < x-1;i+=2) // shuffle the even part without the last char
		 		 		 		 cout<< argv[2][i+1] << argv[2][i];
		 		 		 	 cout<< argv[2][x-1] ;// print the last char
		 		 	 	 }
		 	}

		}
	/*-----------------------------------------------------------------------------------------------------------*/

	else if (!strcmp(argv[1],"shuffleStatement")) //check if the command is shuffleStatment
		{
			if(argc < 3) // there is more than one word
				cout<<"Incorrect Number of Arguments";
			else
				{
	 		 	 if (!((argc-2)%2))//number of words is even
	 		 	 	 {
	 		 		 	 for (int i = 2;i < argc-1;i+=2)//shuffle every two words
	 		 		 	 {
	 		 		 		 cout<< argv[i+1] << " "<< argv[i];
	 		 		 		 i==argc-2? :cout<<" ";//if not the last pair don't put the space

	 		 		 	 }
	 		 	 	 }
	 		 	 else // number of words is odd
	 		 	 	 {
	 		 		 	 for (int i = 2 ; i < argc-2;i+=2) // shuffle the even part without the last word
	 		 		 		 cout<< argv[i+1] << " " << argv[i]<< " ";
	 		 		 	 cout<< argv[argc-1] ;// print the last word
	 		 	 	 }
				}
		}
	/*-----------------------------------------------------------------------------------------------------------*/

	else if (!strcmp(argv[1],"delete")) //check if the command is delete the middle argument
		{
			 if(argc < 4 || atoll((const char*)argv[2]) > argc-3) // there is only two arguments there is no middle to delete
				 cout<<"Incorrect Number of Arguments";
			 else
			 	{
				 /*check the fist argument*/
					for (int j=0;argv[2][j];j++)//check data of every argument
						{	if (!(((48 <= argv[2][j] && 57 >= argv[2][j]) || ((argv[2][0] == 43) && (argv[2][1]))) && (atoll((const char*)argv[2]) > 0 && atoll((const char*)argv[2]) <= argc-3 )))
								  /*check 0-9 if starts with + 0-9 will fail but 43 ascii of + and followed by # */   /*index larger than 0 and less than the number of arguments */
								{cout << "Incorrect Data Type"; return 0;}//if you find a char show error and get out
						}
					for (int i=3;i<argc;i++)
						{
							if((atoll((const char*)argv[2]))!=i-2)
									{
										cout << argv[i];
										i==argc-1? :cout<<" ";
									}
						}
			 	}
		}
	/*-----------------------------------------------------------------------------------------------------------*/

	else if (!strcmp(argv[1],"middle")) //check if the command is get the middle arrgument
		{
	 	 	 if(argc < 3) //there is only two arguments there is no middle to delete
	 	 		 cout<<"Incorrect Number of Arguments";
			 else
			 	{
				 	 if((argc-2)%2) //odd number of arguments
				 	 	{
				 		 	 for (int i=2;i <argc;i++)
				 	 			{
				 	 				if (i== ((argc-2)/2)+2)// the last +1 for the file name and the function name as the array start from 0
				 	 					cout << argv[i];
				 	 			}
				 	 	}
				 	 else //even number of arguments
				 	 	{
		 		 	 	 	 for (int i=2;i < argc;i++)
		 		 	 	 	 	 {
		 		 	 		 	 	 if (i == (((argc-2)/2)+1))
		 		 	 		 	 		 cout << argv[i];
		 		 	 		 	 	 if(i == (((argc-2)/2)+2))
										 cout << " " << argv[i];
		 		 	 	 	 	 }

				 	 	}
			 	}
		}
	/*-----------------------------------------------------------------------------------------------------------*/

	else if (!strcmp(argv[1],"add")) //check if the command is add
		{
			if(argc < 3) // there is only one number to add or less
				cout<<"Incorrect Number of Arguments";
			else
				{	long long int sum=0;
					for (int i=2 ; i < argc;i++) //check there is no characters
						{
							for (int j=0;argv[i][j];j++)//check data of every argument
								{	if (!((48 <= argv[i][j] && 57 >= argv[i][j]) || ((argv[i][0] == 43 || argv[i][0] == 45) && (argv[i][1])))) // ascii of 0-9 ,+#,-#
										{cout << "Incorrect Data Type"; return 0;}//if you find a char show error and get out
								}
							sum +=atoll((const char *)argv[i]); //add the number
						}
					cout << sum;
				}

		}
	/*-----------------------------------------------------------------------------------------------------------*/

	else if (!strcmp(argv[1],"random")) //check if the command is random
		{	if (argc != 6)//too few arguments
				cout << "Incorrect Number of Arguments";
			else
				{	for (int j=0;argv[2][j];j++)//check data of every argument
						{
							if (!((48 <= argv[2][j] && 57 >= argv[2][j]) || (argv[2][0] == 43 && (argv[2][1]))))
								{cout << "Incorrect Data Type"; return 0;}
						}
					for (int i=3 ; i < argc;i++)// check the arguments are numbers
						{
							for (int j=0;argv[i][j];j++)//check data of every argument
								{	if (!((48 <= argv[i][j] && 57 >= argv[i][j]) || ((argv[i][0] == 43 || argv[i][0] == 45) && (argv[i][1]))))
									{cout << "Incorrect Data Type"; return 0;}
									if (!((atoll((const char *)argv[2]) > 0) && (0 < ((atoll((const char *)argv[4])-atoll((const char *)argv[3]))))))
									{cout << "Incorrect Data Type"; return 0;}
								}
						}
					srand(atoll((const char * )argv[5])); // seed is the number  argument
					long long int random;
					for (int i = 0; i < atoll((const char *)argv[2]); i++)// sequence length is the #2 argument
						{ /* random = (rand % max -min+1) + min */
							random= ((long long int )rand() % (atoll((const char *)argv[4])-atoll((const char *)argv[3])+1)) + atoll((const char *)argv[3]);
							cout << random ;
							i==atoll((const char *)argv[2])-1? :cout<<" ";
						}
				}
		}
	/*-----------------------------------------------------------------------------------------------------------*/

	else
		cout << "Undefined Command" ;
	/*-----------------------------------------------------------------------------------------------------------*/





	return 0;
}
