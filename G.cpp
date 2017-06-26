#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
struct data {
	int next,num;
}edge[10001];
void add(int u,int v) {
	edge[++tot].next=head[u];
	edge[tot].num=v;
	head[u]=tot;
}
void Tarjan(int x,int fa) {
	bool judge=0;
	dfn[x]=low[x]=deep;
	for (int i=head[x];i!=-1;i=edge[i].next) {
		int kx=edge[i].num;
		if (kx==fa) continue;
		if (dfn[kx]) {
			judge=1;
			low[x]=min(low[x],dfn[kx]);
			continue;
		}
		deep++;
		Tarjan(kx,x);
		deep--;
		low[x]=min(low[x],low[kx]);
	}
	int num=0;
	for (int i=head[x];i!=-1;i=edge[i].next) d[++num]=edge[i].num;
	for (int opt1=0;opt1<3;opt1++) {
		for (int i=1;i<=num;i++) {
			for (int j=1;j<=n;j++) g[i][j]=-INF;
			if (low[d[i]]>dfn[x]) {
				for (int opt=0;opt<3;opt++) 
				  if (opt+opt1!=3)
				  	  for (int j=1;j<=n;j++) g[i]=max(g[i][j],f[d[i]][j][opt][0]);
				continue;
			}
			if (low[d[i]]==dfn[x])
				for (int h1=0;h1<3;h1++) {
					if (h1+opt1==3) continue;
					for (int h2=0;h2<3;h2++) 
					  if (h2+opt1!=3) 
					    for (int j=1;j<=n;j++) g[i]=max(g[i][j],f[d[i]][j][h1][h2]);
				}
		}
		for (int opt2=0;opt2<3;opt2++) {
			if (judge&&opt2+opt1==3) {
				for (int i=1;i<=n;i++) f[x][i][opt1][opt2]=-INF;
				continue;
			}
			if (dfn[x]==low[x]&&opt2>0) break;
			for (int i=1;i<=num;i++) 
			  	if (low[d[i]]<dfn[x]) {
			  		g[i]=-INF;
			  		for (int h1=0;h1<3;h1++)
			  		  if (h1+opt1!=3) g[i]=max(g[i],f[d[i]][h1][opt2]);
			  	}
			
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for (int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	deep=1;
	Tarjan(1,0);
	return 0;
}
