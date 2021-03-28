/*
	read():返回解压后的字符串 
*/ 
#include<iostream>
using namespace std;
string read()
{
	int d;
	string s="";
	string s1;
	char ch;
	while(cin>>ch)
	{
		if(ch==']') return s;
		else if(ch=='[')
		{
			cin>>d;
			s1=read();
			while(d--) s+=s1;
		}
		else s+=ch;
	}
	return s;
}
int main()
{
	cout<<read()<<endl;
	return 0;
}
