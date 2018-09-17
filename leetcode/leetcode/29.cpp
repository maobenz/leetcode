#include<iostream>
#include <string>
using namespace std;
int divide(int dividend, int divisor) {
        int sum=0;
        int flag=0;
        if(dividend<0&&divisor>0||dividend>0&&divisor<0)
        {
            flag=1;
        }
        if(dividend<0)
        {
        	dividend=-dividend;
		}
            if(divisor<0)
                divisor=-divisor;
        while(dividend>0)
        {
            dividend-=divisor;
            sum++;
        }
        cout<<sum<<endl;
        if(dividend<0)
            sum-=1;
        cout<<sum<<endl;
        if(flag==1)
            return -sum;
        return sum;
    }
    int main()
	{
		int sum=divide(-2147483648,-1);
		cout<<sum<<endl;
	 } 
