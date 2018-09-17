#include<iostream>
#include <string>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int begin,end;
    begin=0;
    end=nums.size()-1;
    while(begin<=end)
    {
        int mid=(begin+end)/2;
        if(nums[mid]==target)
            return mid;
        if(nums[mid]>=nums[begin])
        {
            if(target>=nums[begin]&&target<=nums[mid])
            {
                end=mid-1;
            }
            else begin=mid+1;
        }
        else 
        {
            if(target>=nums[mid]&&target<=nums[end])
            {
                begin=mid+1;
            }
            else end=mid-1;
        }
    }
    return -1;
}
int main()
{
	int i;
	int a[7]={4,5,6,7,0,1,2};
	vector<int> v;
	for(i=0;i<7;i++)
	v.push_back(a[i]);
	cout<<search(v,3)<<endl;
	return 0;
}
