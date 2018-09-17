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
void sumfoursum(vector<int>&nums,int target,int order,int&num,vector<int>&sums,vector<vector<int> >&v)
{
	int i;
	if(target==0&&sums.size()==4)
	{
		if(ifsame(sums,v)||num==0)
		{
			v.resize(num+1);
			for(int i=0;i<sums.size();i++)
			{
				v[num].push_back(sums[i]);
			}
		num++;
		}
	}
	else
	for(i=order;i<nums.size();i++)
	{
		if(sums.size()<4)
		{
			sums.push_back(nums[i]);
			sumfoursum(nums,target-nums[i],i+1,num,sums,v);
			sums.pop_back();
		}
	}
}
int main()
{
	vector<vector<int> > v;
	int a[100]= {-463,-428,-392,-386,-348,-312,-280,-248,-247,-244,-224,-216,-198,-195,-195,-189,-175,-173,-167,-155,-111,-96,-36,-28,-3,10,15,22,25,44,44,49,50,68,84,88,104,107,111,116,171,208,233,304,309,313,318,323,330,331,331,358,364,365,388,396,403,425,449};
	int num=0;
	vector<int> nums,sums;
	for(int i=0;i<100;i++)
	nums.push_back(a[i]);
	sort(nums.begin(),nums.end());
	sumfoursum(nums,2110,0,num,sums,v); 
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<v[i].size();j++)
	     cout<<v[i][j]<<" ";
	     cout<<endl;
	}
	return 0;
}
