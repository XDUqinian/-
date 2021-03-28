/*
	用双端队列的广度优先搜索，保证了搜索完小反转再搜索大反转； 
*/
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct node
{
	int x,y,g,s;//坐标，重力状态，反转数 
}now,top;
deque<node> q;
char map[1005][1005];
bool vis[1005][1005][5];//标记 
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		scanf("%s",map[i]);//char型二维数组的输入方法 
		for(int j=0;j<=n;j++)
		{
			if(map[i][j]=='C')
			{
				now.x=i;
				now.y=j;
				now.g=1;
				now.s=0;
			}
		}
	}
	
	q.push_back(now);
	while(!q.empty())
	{
		top=q.front();
		q.pop_front();
		if(map[top.x][top.y]=='D')
		{
			cout<<top.s<<endl;
			return 0;
		}
		if(top.x+top.g<0||top.x+top.g>=m||top.y<0||top.y>=n) continue;
		vis[top.x][top.y][top.g+1]=1;
		if(map[top.x+top.g][top.y]=='#')
		{
			now.x=top.x;
			now.y=top.y+1;
			now.g=top.g;
			now.s=top.s;
			if(!vis[now.x][now.y][now.g+1]&&map[now.x][now.y]!='#')
			{
				vis[now.x][now.y][now.g+1]=1;
				q.push_front(now);
			}
			now.x=top.x;
			now.y=top.y-1;
			now.g=top.g;
			now.s=top.s;
			if(!vis[now.x][now.y][now.g+1]&&map[now.x][now.y]!='#')
			{
				vis[now.x][now.y][now.g+1]=1;
				q.push_front(now);
			}
			now.x=top.x;
			now.y=top.y;
			now.g=-top.g;
			now.s=top.s+1;
			if(!vis[now.x][now.y][now.g+1]&&map[now.x][now.y]!='#')
			{
				vis[now.x][now.y][now.g+1]=1;
				q.push_back(now);
			}
		}
		else
		{
			now.x=top.x+top.g;
			now.y=top.y;
			now.g=top.g;
			now.s=top.s;
			q.push_front(now);
		}
	}
	cout<<"-1"<<endl;
	return 0;
}

