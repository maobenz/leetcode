#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
string multiply(string num1, string num2) 
{
    int i,j;
    int sum;
    long long n1,n2,n3;
    n1=n2=0;
    string s;
    for(i=num1.length()-1;i>=0;i--)
    {
        n1+=(num1[i]-48)*pow(10,num1.length()-i-1);
    }
    for(i=num2.length()-1;i>=0;i--)
    {
        n2+=(num2[i]-48)*pow(10,num2.length()-i-1);
    }
    n3=n1*n2;
    cout<<n3<<endl;
    i=0;
    if(n3==0)
    return "0";
    cout<<n1<<" "<<n2<<endl;
    while(n3>0)
    {
        sum=n3%10;
        s+=sum+48;
        n3=(n3-sum)/10;
        i++;
    }
    cout<<s<<endl;
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
	int i,j;
	cout<<multiply("123456789",
"987654321"); 
	return 0;
}
