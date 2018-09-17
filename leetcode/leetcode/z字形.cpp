#include<iostream>
#include <string>
using namespace std;
void convert(string s, int numRows)
{
	char a[numRows][1000];
	string s1,s2;
	int i,j;
	for(i=0;i<numRows;i++)
	for(j=0;j<1000;j++)
	a[i][j]='\0';
	for(i=0;i<s.length();i++)
	{
		if(i%(2*numRows-2)<numRows)
		{
			a[i%(2*numRows-2)][i/(2*numRows-2)*(numRows-1)]=s[i];
		}
		else
		{
			a[numRows-1-(i%(2*numRows-2)-numRows+1)][i/(2*numRows-2)*(numRows-1)+i%(2*numRows-2)-numRows+1]=s[i];
		}
	}
	for(i=0;i<numRows;i++)
	for(j=0;j<1000;j++)
	if(a[i][j]!='\0')
	{
		s1+=a[i][j];
	}
	cout<<s1;
} 
int main()
{
	string s;
	s="A";
	convert(s,4);
	return 0;
}
