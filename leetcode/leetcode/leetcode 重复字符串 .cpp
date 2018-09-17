#include<iostream>
using namespace std;
int lengthOfLongestSubstring(string s) {
        int i,j;
        int start,end;
        start=end=0;
        int max=0;
        for(i=1;i<s.length();i++)
        {
        	for(j=start;j<i;j++)
        	{
        		if(s[j]==s[i])
        		{
        			if(max<i-start)
        			max=i-start;
        			start=j+1;
        			i--;
        			break;
				}
			}
		}
		if(s.length()-start>max)
		max=s.length()-start;
		return max;
    }
int main()
{
	string s;
	cin>>s; 
	cout<<lengthOfLongestSubstring(s);
	return 0;
 } 
