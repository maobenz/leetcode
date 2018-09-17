#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longestValidParentheses(string s) {
        int i;
        int stack[s.length()];
        int top=-1;
        int maxlength=0;
        int start=0;
        for(i=0;i<s.length();i++)
        {
        	if(s[i]=='(')
        	{
        		stack[++top]=i;
			}
			else
			{
				if(top==-1)
				start=i+1;
				else
				{
					top--;
					maxlength= top==-1 ? max(maxlength,i-start+1): max(maxlength,i-stack[top]);
				}
			}
		}
		return maxlength;
    }
int main()
{
	string s;
	s="(())";
	cout<<longestValidParentheses(s);
	return 0;
}
