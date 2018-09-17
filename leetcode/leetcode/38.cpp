#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int i,j;
	cin>>n;
	string s="11";
	if(n>2)
	{
	for(i=3;i<=n;i++)
	{
		for(j=0;j<s.length();j=j+2)
		{
			if(s[j]=='1'&&s[j+1]=='1')
			{
				s[j]='2';
				j-=2;
			}
			else if(s[j]=='1'&&s[j+1]=='2')
			s.replace(j,2,"1112");
			else if(s[j]=='2'&&s[j+1]=='1')
			s.replace(j,2,"1211");
			else if(s[j]=='2'&&s[j+1]=='2')
			s.replace(j,2,"1212");
			j+=2;
		}
	}
	cout<<s<<endl;
}
	else if(n==1)
	cout<<"1";
	else if(n==2)
	cout<<"11";
	return 0;
 } 
