#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int quick(vector<int>&a,int low,int high)
{
	int i,t;
	int p=low;
	int q=high;
	if(a[low]<=0)
	{
		for(i=low+1;i<=high;i++)
		if(a[i]>0)
		{
			t=a[low];
			a[low]=a[i];
			a[i]=t;
		}
	}
	t=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>t)
		high--;
		a[low]=a[high];
		while(low<high&&a[low]<t)
		low++;
		a[high]=a[low];
	}
	a[low]=t;
	for(i=p;i<=q;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return low;
}
void quicksort(vector<int>&nums,int low,int high,int sum)
{
	int partition;
	if(low<high)
	{
		partition=quick(nums,low,high);
		cout<<partition<<"kk"<<endl;
		if(low>0)
		{
			if(partition-low<nums[partition]-nums[low])
			{
				if(partition-low==0)
				cout<<"mm"<<endl;
				else
				quicksort(nums,low,partition-1,sum);
			}
			else if(high-partition<nums[high]-nums[partition])
			{
				if(high==partition)
				cout<<"nn"<<endl;
				else 
				quicksort(nums,partition+1,high,0);
			}	
		}
		else if(low==0)
		{
			if(partition-low-sum<nums[partition]-1)
			{
				if(partition-low==0)
				cout<<"mm"<<endl;
				else
				quicksort(nums,low,partition-1,sum);
			}
			else if(high-partition<nums[high]-nums[partition])
			{
				if(high==partition)
				cout<<"nn"<<endl;
				else 
				quicksort(nums,partition+1,high,0);
			}	
		}
	}
}
int firstMissingPositive(vector<int>& nums) 
{
	int i=0;
	int sum=0;
	for(i=0;i<nums.size();i++)
	{
		if(nums[i]<0)
		sum++;
	}
 	quicksort(nums,0,nums.size()-1,sum);
 	return 0;
}
int main()
{
	int a[4]={3,4,-1,1};
	vector<int> c;
	for(int i=0;i<4;i++)
	c.push_back(a[i]);
	cout<<firstMissingPositive(c); 
	return 0;
}
