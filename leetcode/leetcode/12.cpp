#include<iostream>
using namespace std;
string ToRoman(int num,string&str) {
        	if(num>=1000)
        	{
        		str+='M';
        		return intToRoman(num-1000,str);
			}
			else if(num>=900)
        	{
        		str+="CM";
        		return intToRoman(num-900,str);
			}
        	else if(num>=500)
        	{
        		str+='D';
        		return intToRoman(num-500,str);
			}
			else if(num>=400)
        	{
        		str+="CD";
        		return intToRoman(num-400,str);
			}
        	else if(num>=100)
        	{
        		str+='C';
        		return intToRoman(num-100,str);
			}
			else if(num>=90)
        	{
        		str+="XC";
        		return intToRoman(num-90,str);
			}
        	else if(num>=50)
        	{
        		str+='L';
        		return intToRoman(num-50,str);
			}
			else if(num>=40)
        	{
        		str+="XL";
        		return intToRoman(num-40,str);
			}
        	else if(num>=10)
        	{
        		str+='X';
        		return intToRoman(num-10,str);
			}
			else if(num>=9)
        	{
        		str+="IX";
        		return intToRoman(num-9,str);
			}
        	else if(num>=5)
        	{
        		str+='V';
        		return intToRoman(num-5,str);
			}
			else if(num>=4)
        	{
        		str+="IV";
        		return intToRoman(num-4,str);
			}
        	else if(num>=1)
        	{
        		str+='I';
        		return intToRoman(num-1,str);
			}
        	else return str;  
    }
int main()
{
	string str;
	str=intToRoman(1994,str);
	cout<<str;
}
