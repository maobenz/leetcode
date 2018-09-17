#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void trackback(string&b,vector<string>&a,int n,int i,int remain)
{
	int j;
	if(i==n)
	{
		for(j=1;j<=remain;j++)
		b.insert(i+n-remain,")");
		a.push_back(b);
		b.erase(i+n-remain,remain);
	}
	else 
	{
		for(j=0;j<=i-n+remain;j++)
		{
			for(int k=1;k<=j;k++)
			b.insert(i+n-remain,")");
			trackback(b,a,n,i+1,remain-j);
			b.erase(i+n-remain,j);
		}
	}
}
vector<string> generateParenthesis(int n) 
{
	vector<string> a;
	string b;
	for(int i=0;i<n;i++)
	b.insert(0,"(");
	trackback(b,a,n,1,n);
	return a;
}
int main()
{
	int n;
	cin>>n;
	vector<string> c;
	c=generateParenthesis(n);
	for(int i=0;i<c.size();i++)
	cout<<c[i]<<endl;
	return 0;
}
