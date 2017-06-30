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
 > 给出n个升序的整数和一个阈值c(1≤n≤10^5, 1≤c≤ 10^9) ，表示屏幕上依次出现整数，若整数与上一整数间隔超过c那么屏幕上的数将全部消失，求最终屏幕上有几个数。
 ### Solution
 >依次扫描整数，用一个变量表示当前屏幕有几个整数，按题意模拟即可。
 >时间复杂度O(n)。
 ***** 
 # 赛后补题
