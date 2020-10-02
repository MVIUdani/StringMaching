#include<iostream>
#include <fstream>
#include <cstring>
#include<limits>

#define d 256

using namespace std;

int max(int a,int b)
{
	return (a>b)? a:b;
}

void badChar(char *s,int size,int badC[d])
{
	int i;
	for(i=0;i<d;i++)
	{
		badC[i]= -1;
	}
	for(i=0;i<size;i++)
	{
		badC[(int)s[i]]=i;
	}
	
}

void search(char *text,char *pattern)
{
	int n,m;
	int badC[d];
	n=strlen(pattern);
	m=strlen(text);
	
	badChar(pattern,n,badC);
	
	int shift=0;
	
	while(shift<=(m-n))
	{
	int j=n-1;
	
	while(j>=0 && pattern[j]==text[shift+j])
	{
	j--;
    }
	
	if(j<0)
	{
		cout<<"\npattern found at  "<<shift;
		(shift=shift+(shift+n<m))?n-badC[text[shift+n]]:1;
	
	}
	else
	{
		shift=shift+max(1,j-badC[text[shift+j]]);
		}	
	}
}
	
int main()
{
	cout<<"*****Boyer Moore Algorithm*****\n";
	
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
	
	search(chstr,pattern);

	return 0;
	
}

