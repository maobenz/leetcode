#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bubblesort(vector<int>& nums,int low,int high)
{
	int j,k,t;
	for(j=high;j>=low;j--)
	{
		for(k=low+1;k<=j;k++)
		{
			if(nums[k]<nums[k-1])
			{
				t=nums[k];
				nums[k]=nums[k-1];
				nums[k-1]=t;
			}
		}
	}
}
void nextPermutation(vector<int>& nums)
{
	int i,j,k;
	int max=999;
	int index,t;
	for(i=nums.size()-2;i>=0;i--)
	{
		if(nums[i]<nums[i+1])
		{
			for(j=i+1;j<nums.size();j++)
			{
				if(nums[j]>nums[i]&&nums[j]<max)
				{
					max=nums[j];
					index=j;
				}
			}
			t=nums[index];
			nums[index]=nums[i];
			nums[i]=t;
			bubblesort(nums,i+1,nums.size()-1);
			break;
		}
	}
	if(i==-1)
	{
		bubblesort(nums,0,nums.size()-1);
	}
}
int main()
{
	int a[5]={5,4,3,2,1};
	vector<int>nums;
	for(int i=0;i<5;i++)
	nums.push_back(a[i]);
	nextPermutation(nums);
	for(int i=0;i<nums.size();i++)
	cout<<nums[i];
	cout<<endl;
	return 0;
}
