 # 比赛记录
 ## [contest14] [Codeforces Round #372(Div.2)]
 
 [比赛链接](http://codeforces.com/contest/716)
 
 ## A
 ### Description
 > 给出n个升序的整数和一个阈值c(1≤n≤10^5, 1≤c≤ 10^9) ，表示屏幕上依次出现整数，若整数与上一整数间隔超过c那么屏幕上的数将全部消失，求最终屏幕上有几个数。
 ### Solution
 >依次扫描整数，用一个变量表示当前屏幕有几个整数，按题意模拟即可。
 
 >时间复杂度O(n)。
 ```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main() {
	int n,c;
	scanf("%d%d",&n,&c);
	int nowx=0,nowtot=0;
	for (int i=1;i<=n;i++) {
		int x;
		scanf("%d",&x);
		if (x-nowx>c) nowtot=0;
		nowtot++;
		nowx=x;
	}
	printf("%d\n",nowtot);
	return 0;
}
 ```
## B
### Description
 > 给出一个只含有英文大写字母及"?"的字符串s (1≤|s|≤5\*10^4),求能否用大写字母填充该字符串中的"?"使得该字符串拥有一个长度为26的子串，这个子串出现每个英文大写字母各一次，若能输出填充后的串，否则输出-1。
 ### Solution
 >枚举该串的长度为26的子串，分别判断是否能符合要求，若能符合要求则可将子串外的"?"字符任意填充输出，若不能找到输出-1。
 
 >时间复杂度依写的方法而定，O(|s|) 或 O(26\*|s|)，为方便起见下面的程序采用后者复杂度。
 
  ```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[100001];
int vis[100];
int main() {
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i<=len-26;i++) {
		memset(vis,0,sizeof(vis));
		for (int j=i;j<i+26;j++) if (s[j]!='?') vis[s[j]-65]++;
		bool judge=1;
		for (int j=0;j<26;j++) if (vis[j]>1) {
			judge=0;
			break;
		}
		if (judge) {
			for (int j=0;j<i;j++) if (s[j]=='?') s[j]='A';
			int nowi=0;
			for (int j=i;j<i+26;j++) if (s[j]=='?') {
				while (vis[nowi]) nowi++;
				s[j]=nowi+65;
				nowi++;
			}
			for (int j=i+26;j<len;j++) if (s[j]=='?') s[j]='A';
			printf("%s",s);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
 ```
## C
### Description
 > 你现在有一个数x和一个等级k，开始时x=2，k=1每次你能进行两个操作之一：
 
 操作1：将x加上k；
 
 操作2：若x为完全平方数且x的算术平方根对(k+1)取模的值为0，你可以将k变为k+1，x变为x的算术平方根。
 > 现在要求你进行n次操作2,(1≤n≤10^5),请你输出每次操作2之前需要操作多少次操作1，输出的数不能超过10^18。
 
 ### Solution
 > 由于要进行操作2时，x为完全平方数且x的算术平方根对(k+1)取模的值为0，因此x必须为(k+1)^2的倍数，而上一次操作2结束时x为k的倍数，因此我们可以令x变为k^2\*(k+1)^2，因此第i次加的次数应为[k^2\*(k+1)^2-k\*(k-1)]/k=k\*(k+1)^2-k+1，可以知道不会超过10^18。
 ***** 
 # 赛后补题
