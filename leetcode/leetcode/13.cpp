#include<iostream>
using namespace std;
string longestPalindrome(string s) {
	int i,j,k;
	int max=0;
	int flag,sum,len;
	string str,str1;
	str1="";
	if(s.length()>=2)
	for(i=0;i<s.length();i++)
	{
		for(j=i;j<s.length();j++)
		{
			flag=0;
			len=0;
			str="";
			if((i+j)%2==0)
			sum=1;
			else sum=0;
			for(k=(i+j)/2-sum;k>=i;k--)
			{
				if(s[k]!=s[j-k+i])
				{
					flag=1;
					break;
				 } 
				 else 
				 {
				 	len++;
				 }
			}
			if(!flag&&max<len)
			{
				for(k=i;k<=j;k++)
				str+=s[k];
				max=len;
				str1=str;
			 } 
		}
	}
	else return s;
    if(max==0)
    {
        str1+=s[0];
        return str1;
    }
	return str1; 
}

int main()
{
    string str,s;
	s="ccc"; 
	str=longestPalindrome(s);
	cout<<str<<endl;
	return 0;
}
