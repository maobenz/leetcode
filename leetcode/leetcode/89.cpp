#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
void changevector(vector<int>&a,vector<vector<int> >&b)
{
	int i,j;
	int sum;
	for(i=0;i<b.size();i++)
	{
		sum=0;
		for(j=b[i].size()-1;j>=0;j--)
		{
			if(b[i][j]==1)
			{
				sum+=pow(2,b[i].size()-j-1);
			}
		}
		a.push_back(sum);
	}
}
void solvegrayCode(int n,vector<vector<int> >&b)
{
	int i,j,k;
	int sum=pow(2,n);
	for(i=sum/2;i<sum;i++)
	{
		b.push_back(b[sum-i-1]);
		b[i].push_back(1);
	}
	for(i=0;i<sum/2;i++)
	{
		b[i].push_back(0);
	}
}
vector<int> grayCode(int n) 
{
	int i,j,k;
	vector<int> a;
	vector<vector<int> > b(2);
	if(n==0)
	{
		a.push_back(0);
		return a;
	}
	else
	{
		b[0].push_back(0);
		b[1].push_back(1);
		for(i=2;i<=n;i++)
		{
			solvegrayCode(i,b);
			changevector(a,b);
			for(j=0;j<a.size();j++)
			cout<<a[j]<<" ";
			
		}
	}
}
int main()
{
	vector<int> a;
	a=grayCode(3);
	return 0;
}
