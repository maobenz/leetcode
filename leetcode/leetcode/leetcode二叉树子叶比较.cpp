#include<iostream>
#include <string>
using namespace std;
void Priorder(TreeNode*t,int*a,int&k)
{
	if(t)
	{
		if(t->left==NULL&&t->right==NULL)
		{
			a[k]=t->value;
			k++;
		}
		Priorder(t->left,a);
		Priorder(t->right,a);
	}
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    int i,j,k;
    int a[100],b[100];
    TreeNode*p,*q;
    p=root1;
    q=root2;
    i=j=0;
    Priorder(p,a,i);
    Priorder(q,b,j);
    for(k=0;k<i;k++)
    {
    	if(a[i]!=b[i])
    	break;
	}
	if(k!=i)
	return false;
	else return true;    
}
int main()
{
	return 0;
 } 
