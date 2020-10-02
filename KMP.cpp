#include<iostream>
#include <fstream>
#include <string>
#include <cstring>
#include<stdlib.h>

using namespace std;

int m,n,i,j;


void LPS(char *pattern,int n,int *lps)
{
int length=0;//length of previous LPS
int i=1;
lps[0]=0;//lps[0] is always 0

while(i<n)	//lps[i] for i=1 to n-1
{
	if(pattern[i]==pattern[length])
	{
	length++;
	lps[i]=length;
	i++;	
	}
	else   //length!=pattern[length]
	{
		if(length!=0)
		{
			length=lps[length-1];
		}
		else
		{
			lps[i]=0;
		    i++;
		}
	}
}
}

void kmp(char *pattern,char *content)
{
	m=strlen(content);//lenth of text
    n=strlen(pattern);//lenth of pattern
	
	int *lps=(int*)malloc(n*sizeof(int));
	int j=0;
	
	LPS(pattern,n,lps);
	
	int i=0;
	while(i<m)
	{
	if(pattern[j]==content[i])
	{
		j++;
		i++;
		}
		if(j==n)
		{
		    cout<<"\npattern found at "<<i-j;
			j=lps[j-1];
			
		}
		else if(pattern[j]!=content[i])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
			free(lps);
}	

int main()
{
    cout<<"*****Knuth-Morris-Pratt Algorithm*****\n";
    
	char pattern[6];

    ifstream file("pi.txt");
    string str; 
    string content;
    
    while (getline(file, str))
    {
    content += str;
    content.push_back('\n');
    }

	char* chstr=const_cast<char*>(content.c_str());
//	cout<<chstr;
	
	cout<<"\nEnter pattern that you want to search:";
	cin>>pattern;//Write pattern as 970410
	
	kmp(pattern,chstr);
	
	return 0;
}

