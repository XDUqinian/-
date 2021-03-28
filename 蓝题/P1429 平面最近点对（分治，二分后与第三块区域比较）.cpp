/*
	1.将平面上所有点按横纵坐标排序
	2.取中位数点的横坐标m，将平面点分为P1和P2左右两个部分
	3.在P1和P2中分别寻找平面最近点对，比较得到最近距离为d
	4.在距离直线x=m小于d的所有点中，寻找有没有距离比d更小的点对，最后得到最小的距离 
	参见2013年上古题解：https://www.luogu.com.cn/problem/solution/P1429
*/ 
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1000001 ;
const int INF=2<<20;
int n;
int temp[maxn];
struct node
{
	double x;
	double y;
}s[maxn];
bool cmp(node a,node b)
{
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
bool cmps(int a,int b)
{
	return s[a].y<s[b].y;
}
double dlist(int i,int j)
{
	double x=(s[i].x-s[j].x)*(s[i].x-s[j].x);
	double y=(s[i].y-s[j].y)*(s[i].y-s[j].y);
	return sqrt(x+y);
}
double merge(int l,int r)
{
	double d=INF;
	if(l==r) return d;
	if(l+1==r) return dlist(l,r);
	int mid=(l+r)>>1;
	double d1=merge(l,mid);
	double d2=merge(mid+1,r);
	d=(d1<d2)?d1:d2;
	int k=0;
	for(int i=l;i<=r;i++)
	{
		if(fabs(s[i].x-s[mid].x)<d)
		{
			temp[k++]=i;
		}
	}
	sort(temp,temp+k,cmps);
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k&&s[temp[j]].y-s[temp[i]].y<d;j++)
		{
			double d3=dlist(temp[i],temp[j]);
			if(d3<d) d=d3;
		}
	}
	
	return d;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].x>>s[i].y;
	}
	sort(s,s+n,cmp);
	printf("%.4lf\n",merge(0,n-1));
	return 0;
}
