#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int reverse(int x) {
	int flag=0;
	if(x<0)
	flag=1;
    char c[100];
    itoa(x,c,10);
    strrev(c);
    x=atoi(c);
    if(flag==1)
    return -x;
    return x;
    }
int main()
{
	int x=-120;
	x=reverse(x);
	cout<<x<<endl;
	return 0;
}
