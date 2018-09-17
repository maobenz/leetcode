#include<iostream>
#include <string>
#include<vector.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i,j;
        i=j=0;
        int flag=0;
        while(1)
        {
        	matrix[i][j]=0;
            if(flag==0)
            {
                if(j<matrix[i].resize()&&matrix[i][j+1]!=0)
                j++;
                else if(j==matrix[i].resize())
                {
                	flag=1;
                	i++;
				}
            }
            else if(flag==1)
            {
            	if(i<matrix.resize()&&matrix[i+1][j]!=0)
            	i++;
				else
				{
					flag=2;
					j--;
				}
			}
			else if(flag==2)
			{
				if(matrix[i][j-1]!=0&&j>=0)
				j--;
				else
				{
					flag=3;
					i--;
				}
			}
			else if(flag==3)
			{
				if(matrix[i-1][j]!=0&&i>=0)
				{
					i--;
				}
				else 
				{
					flag=1;
					j++;
				}
			}
        }
}
int main()
{
	return 0;
 } 
