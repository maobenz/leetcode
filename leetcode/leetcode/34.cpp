#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> search(vector<int>& nums, int target,int low ,int high)
{
	if(low<=high)
  	{
  		int middle=(low+high)/2;
  		if(nums[middle]<target)
  		return search(nums,target,middle+1,high);
  		else if(nums[middle]>target)
		return search(nums,target,low,middle-1);
		else
		{
			vector<int> a;
			int b,c;
			b=c=middle;
			if(i>low) 
			while(1)
			{
				if(nums[i]<target)
				{
					a.push_back(i+1);
					break;
				}
				else if(nums[i]==target&&i==low)
				{
					a.push_back(i);
					break;
				}
				i--;
			}
			else a.push_back(i);
			i=middle;
			if(i<high)
			while(1)
			{
				if(nums[i]>target)
				{
					a.push_back(i-1);
					break;
				}
				else if(i==high)
				{
					a.push_back(i);
					break;
				}
				i++;
			}
			else a.push_back(i);
			return a;
		}
	}
	else 
	{
		vector<int>a;
  		a.push_back(-1);
  		a.push_back(-1);
  		return a;
  	}
}

vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int>a;
  	if(nums.empty()||nums[0]>target||nums[nums.size()-1]<target)
  	{
  		a.push_back(-1);
  		a.push_back(-1);
  		return a;
  	}
  	return search(nums,target,0,nums.size()-1);
}

int main()
{
	int a[6]={5,7,7,8,8,10};
	int target=8;
	vector<int >nums;
	vector<int >b;
	for(int i=0;i<6;i++)
	nums.push_back(a[i]);
	b=searchRange(nums,target);
	for(int i=0;i<b.size();i++)
	cout<<b[i];
	return 0;
 } 
 
 
