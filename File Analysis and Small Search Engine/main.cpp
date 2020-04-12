//============================================================================
// Name        : A2.cpp
// Author      : Hossam Tourki
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "inord_list.h"
using namespace std;
bool insertingData(const char * file,inord_list &words,unsigned int& i_wordCounter,unsigned int& i_charCounter);
string int_to_string(unsigned int& integer);
string to_lower(string target);
void frequentWord(inord_list& target);
void distWords(inord_list &target);
void countMyword(inord_list &target,const string &targetword);
void containing(inord_list &target,const string &targetword);
void search(inord_list &target,const string &pattern);
void starting(inord_list &target,const string &pattern);


int main(int argc,char*argv[])
{	inord_list words;
	unsigned int wordCounter,charCounter;
	insertingData(argv[1],words,wordCounter,charCounter);//insert the data to the list and get the char and word count


	ifstream commandfile(argv[2]);
			if(commandfile.fail())//check if the file is opened correctly
				{cout<<"File not found";}
			 string s_lineBuffer;
			while(!commandfile.eof())//while not the end of the file
			 {   getline(commandfile,s_lineBuffer);//fetch a line
				 stringstream ss(s_lineBuffer);//input this line in a stream
				 int arguments=0;
				 string s_argBuffer,s_argument1,s_argument2;
			  	  while(ss >> s_argBuffer )  //devide the line we took in the stream into words
			  	  	  {
			  		  	  arguments++;
			  		  	  if(arguments==1)
			  		  		s_argument1.assign(s_argBuffer);
			  		  	  if(arguments==2)
			  		  		s_argument2.assign(s_argBuffer);
			  	  	  }
			  	  if(s_argument1=="wordCount")
			  	  	  {	if(arguments!=1)
			  	  		  cout<<"Incorrect number of arguments\n";
			  	  	    else
			  	  	      cout<<wordCounter<<" words\n";
			  	  	  }
			  	  else if(s_argument1=="distWords")
			  	  	  {
			  		  	if(arguments!=1)
			  	  		  cout<<"Incorrect number of arguments\n";
			  	  	    else
			  	  	       distWords(words);
			  	  	  }
			  	else if(s_argument1=="charCount")
			  		  {
			  			if(arguments!=1)
			  	  		  cout<<"Incorrect number of arguments\n";
			  			else
				  	  	      cout<<charCounter<<" characters\n";
			  	  	  }
			  	else if(s_argument1=="frequentWord")
			  		  {
			  			if(arguments!=1)
			  	  		  cout<<"Incorrect number of arguments\n";
			  			else
			  				frequentWord(words);
			  		  }
			  	else if(s_argument1=="countWord")
			  		  {
			  			if(arguments!=2)
			  	  		  cout<<"Incorrect number of arguments\n";
			  			else
			  				countMyword(words,s_argument2);
			  		  }
			  	else if(s_argument1=="starting")
			  		  {
			  			if(arguments!=2)
			  	  		  cout<<"Incorrect number of arguments\n";
			  			else
			  				starting(words,s_argument2);
			  		  }
			  	else if(s_argument1=="containing")
			  		  {
			  			if(arguments!=2)
			  	  		  cout<<"Incorrect number of arguments\n";
			  			else
			  				containing(words,s_argument2);
			  		  }
			  	else if(s_argument1=="search")
			  		  {
			  			if(arguments!=2)
			  	  		  cout<<"Incorrect number of arguments\n";
			  			else
			  				search(words,s_argument2);
			  		  }
			  	else
			  		cout<<"Undefined command\n";

			 }
			commandfile.close();
















	/*	//frequentWord(words);
	//distWords(words);
	//countMyword(words,"the");
	//containing(words,"ex");
	starting(words,"th");
	string w,l;
	unsigned int x;
	words.first(w,x,l);
	fflush(stdout);
	cout<<w<<" : \n"<<"counter : "<<x<<endl<<"lines : "<<l<<endl;
		while(words.next(w,x,l))
			cout<<w<<" : \n"<<"counter : "<<x<<endl<<"lines : "<<l<<endl;

*/
	return 0;
}



bool insertingData(const char * file,inord_list &word,unsigned int &i_wordCounter,unsigned int &i_charCounter)
	{	ifstream Datafile(file);
		if(Datafile.fail())//check if the file is opened correctly
			{cout<<"File not found";return false;}

		/*getting the char count*/
		Datafile.seekg (0,Datafile.end);//take the cursor to the end of the file
		i_charCounter=Datafile.tellg();//tellg tells the char position as we at the end of the file it would give us the char counter
		Datafile.seekg (0,Datafile.beg);//take the cursor back to the beginning
		/******************************************************************/

		 string s_lineCounter,s_lineBuffer,s_wordBuffer;
		 unsigned int i_lineCounter=0;
		 i_wordCounter=0;

		while(!Datafile.eof())//while not the end of the file
		 {   getline(Datafile,s_lineBuffer);//fetch a line
			 stringstream ss(s_lineBuffer);//input this line in a stream
			 i_lineCounter++;//increase the line counter
		  	  while(ss >> s_wordBuffer )  //Divide the line we took in the stream into words
		  	  	  {		s_wordBuffer=to_lower(s_wordBuffer);
		  	  	  	  	 // if(s_wordBuffer!=string())
		  	  	  	  		  word.insert(s_wordBuffer,int_to_string(i_lineCounter));//insert the word into the list and read the line as a string
			  		  	  i_wordCounter++;//increase the word counter

			  	  }

		 }
		  Datafile.close();
		  return true;
	}
string int_to_string(unsigned int& integer)
	{
	 	 stringstream temp;//create a stream  to convert from int to string
	  	 temp<<integer;//put the integer in stream
	  	 return temp.str();//read the data again as a string
	}
string to_lower(string target)
	{
			string output;
			int i=0;
			while (target[i])//start from the first char of the argument to the last
				{	if((target[i]>='0'&&target[i]<='9')||(target[i]>='A'&&target[i]<='Z')||(target[i]>='a'&&target[i]<='z'))
					output+=tolower(target[i]);
					i++;
				}

			return output;
	}


void frequentWord(inord_list& target)
{	string forbidden[]={"a","an","the","in","on","of","and","is","are"};
	unsigned int max=target.max_repeated(),targetCounter;
	if(max!=0)
	{	string word;
		target.first(word,targetCounter);//get the word and the counter
		cout<<"Most frequent word is:";
		if(targetCounter==max && (!(word==forbidden[0] || word==forbidden[1] || word==forbidden[2] || word==forbidden[3] || word==forbidden[4] || word==forbidden[5] || word==forbidden[6] || word==forbidden[7] || word==forbidden[8])))
		cout<<" "<<word;//if the first word is the most frequent and not one of the forbidden
		while(target.next(word,targetCounter))
			{
				if(targetCounter==max && (!(word==forbidden[0] || word==forbidden[1] || word==forbidden[2] || word==forbidden[3] || word==forbidden[4] || word==forbidden[5] || word==forbidden[6] || word==forbidden[7] || word==forbidden[8])))
					cout<<" "<<word;
			}
	}
	cout<<" \n";
}
void distWords(inord_list &target)
{
	unsigned int counter=0,temp;
	target.first(temp);
	 counter++;//if the temp is one then it is a distword increase the counter by one
	 while(target.next(temp))
		 counter++;
	 cout<<counter<<" distinct words\n";
}
void countMyword(inord_list &target,const string &targetword)
{	string word;
	unsigned int c=0;
	target.first(word,c);
		if(!(word.compare(to_lower(targetword))))//match found
			{cout<<targetword<<" is repeated "<<c<<" times"<<endl;return;}
	while(target.next(word,c))
		{
				if(!(word.compare(to_lower(targetword))))//match found
					{cout<<targetword<<" is repeated "<<c<<" times"<<endl;return;}
		}
	cout<<targetword<<" is repeated "<<c<<" times"<<endl;return;//if the word wasn't found
}
void containing(inord_list &target,const string &pattern)
{
		string word;
		unsigned int c;
		target.first(word,c);
			if(word.find(to_lower(pattern))!=std::string::npos)//match found
				cout<<word<<": "<<c<<"\t";
		while(target.next(word,c))
			{
					if(word.find(to_lower(pattern))!=std::string::npos)//match found
						cout<<word<<": "<<c<<"\t";
			}
		cout<<"\n";
}
void search(inord_list &target,const string &pattern)
{
		string word,lines;
		target.first(word,lines);
			if(word.find(to_lower(pattern))!=std::string::npos)//match found
				cout<<word<<":\t"<<"lines "<<lines<<" \n";
		while(target.next(word,lines))
			{
					if(word.find(to_lower(pattern))!=std::string::npos)//match found
						cout<<word<<":\t"<<"lines "<<lines<<" \n";
			}
}
void starting(inord_list &target,const string &pattern)
{
		string word;
		unsigned int c;
		target.first(word,c);
			if(word.find(to_lower(pattern))==0)//find return the position of the found pattern so with starting we need the find to return posision zero
				cout<<word<<": "<<c<<"\t";
		while(target.next(word,c))
			{
					if(word.find(to_lower(pattern))==0)//match found
						cout<<word<<": "<<c<<"\t";
			}
		cout<<"\n";
}







