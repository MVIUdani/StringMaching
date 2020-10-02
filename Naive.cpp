#include<iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() 
{ 
    cout<<"******Naive String Matching Algorithm*****\n";
    
    ifstream file("pi.txt");
    string str; 
    string content;
    while (getline(file, str))
    {
    content += str;
    content.push_back('\n');
    }
//    cout<<content;
    
	char pattern[6];
	int m,n,i,j;
	
    cout<<"\nEnter pattern that you want to search:";
	cin>>pattern;//Write pattern as 970410
	
	m=content.length();//lenth of text
	n=strlen(pattern);//lenth of pattern
  //  cout<<m;
  
	for(i=0;i<m-n+1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(content[i+j]!=pattern[j])
			break;
		}
			if(j==n)
			{
				cout<<"\npattern found at  "<<i;
			}
	}
}
