#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ifsame(vector<int>a,vector<vector<int> >b)
{
	int flag;
	for(int i=0;i<b.size();i++)
	{
		flag=0;
		for(int j=0;j<b[i].size();j++)
		{
			if(b[i][j]!=a[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		return false;
	}
	return true;
}
void track(int i,vector<int>&a,vector<vector<int> >&b)
{
	int t;
	if(i==a.size())
	{
		if(ifsame(a,b))
		b.push_back(a);
	}
	else
	{
		for(int j=i;j<a.size();j++)
		{
			if(i==j||a[j]!=a[i])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
				track(i+1,a,b);
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
}
int main()
{
	int s[4]={2,2,1,1};
	vector<int>a;
	for(int i=0;i<4;i++)
	{
		a.push_back(s[i]); 
	}
	vector<vector<int> >b;
	track(0,a,b);
	for(int i=0;i<b.size();i++)
	{
		for(int j=0;j<b[i].size();j++)
		cout<<b[i][j]<<" ";
		cout<<endl;
	}
	return 0;
 } 
