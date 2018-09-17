#include<iostream>
#include <string>
using namespace std;
void myAtoi(string str)
{
	int flag=0;
	int t1,t2,t3;
	int i,j;
	string str1;
	t1=0; 
	for(i=0;i<str.length();i++)
	{
		if(flag==0&&(str[i]=='+'))
		{
			t1=1;
			flag=1;
		}
		else if(flag==0&&str[i]=='-')
		{
			t1=0;
			flag=1;
		}
		else if(flag==0&&(str[i]>57||str[i]<48))
		else if(str[i]>=48&&str[i]<=57)
		{
			str1+=str[i];
			flag=1;
		}
		else if(flag==1&&(str[i]>57||str[i]<48))
		break;
	} 
	for(i=0;i<str1.length();i++)
	{
		if(str1[i]>57||str1[i]<48)
		break;
		else {
			
			
		}
	}
	cout<<str1<<endl;
}
int main()
{
	string str;
	str="   123";
	myAtoi(str);
}
