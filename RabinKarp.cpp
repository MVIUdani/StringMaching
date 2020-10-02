#include<iostream>
#include <fstream>
#include <cstring>
#define d 256

using namespace std;

void search(char pattern[],string content,int q)
{
 int n,m,i,j;
 
 n=strlen(pattern);
 m=content.length();
 
 int hpat=0;//hash value of pattern
 int htxt=0;//hash value of text
 int h=1;
 
 for(i=0;i<n-1;i++)
 {
 	h=(h*d)%q;
 }
 for(i=0;i<n;i++)
 {
 	hpat=(d*hpat+pattern[i])%q;
 	htxt=(d*htxt+content[i])%q;
 }
 
 for(i=0;i<=m-n;i++)
 {
 	if(hpat==htxt)
 	{
 		for(j=0;j<n;j++)
 		{
 			if(content[i+j]!=pattern[j])
 			break;
		 }
		 if(j==n)
		 {
		 	cout<<"\nPattern found at :"<<i;
		 }
	 }
	 if(i<m-n)
	 {
	 	htxt=(d*(htxt-content[i]*h)+content[i+n])%q;
	 	if(htxt<0)
	 	htxt=(htxt+q);
	 }
 }
 
}

int main()
{
	cout<<"*****Rabin-Karp Algorithm*****\n";

	char pattern[6];
	
    ifstream file("pi.txt");
    string str; 
    string content;
    while (getline(file, str))
    {
    content += str;
    content.push_back('\n');
    }
  //  cout<<content;
    
    cout<<"\nEnter pattern that you want to search:";
	cin>>pattern;//Write pattern as 970410

	int q=101;
	
	search(pattern,content,q);
	
	return 0;
}
