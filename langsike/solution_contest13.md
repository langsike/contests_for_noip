 # 比赛记录(contest13 Codeforces Round #221 (Div.1&2)
 
 [比赛链接1(div1)](http://codeforces.com/contest/375)
 
 [比赛链接2(div2)](http://codeforces.com/contest/376)
 
 ## div2 A
 ### Problem description
 > 以字符串形式给出一个杠杆的形态(支点位置，重物位置及重物质量)，求杠杆是平衡，左倾还是右倾。(字符串长度3≤|s|≤10^6)。
 ### Solution
 由杠杆平衡条件可以得到,设sum=∑(xi-k)wi，xi为第i个重物的位置，wi为第i个重物的质量，若sum<0杠杆左倾，sum>0杠杆右倾，sum=0杠杆平衡；注意使用64位整数；
 
 时间复杂度O(|s|)。
 ```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[2000002];
int main() {
	scanf("%s",s);
	int len=strlen(s);
	int k;
	for (int i=0;i<len;i++) 
	  if (s[i]=='^') k=i;
	long long sum=0;
	for (int i=0;i<len;i++)
		if (s[i]>='0'&&s[i]<='9') sum+=(i-k)*(s[i]-48);
	if (sum>0) printf("right\n");
	  else if (sum<0) printf("left\n");
	    else printf("balance\n");
	return 0;
}
 ```
 
 
 
 ## div1 B
 ### Problem description
 > 给出n个人,m条债务关系，(1≤n≤100;0 ≤m≤ 10^4)，试重新安排债务，使得债务总量之和最小。
 ### Solution
 稍作思考可知，我们可以O(m)计算出每一个人的债权数和债务数，若一个人债权数大于债务数，则可以将其债务转接到欠他债的人处，若一个人债权数小于债务数，则可以将其债权交给欠债的人，这样对答案贡献为abs(xi-yi)/2，(xi为其债权数，yi为其债务数),一方面每个人至少造成这么多代价，另一方面这个方案是可达到的，因此∑abs(xi-yi)/2即为符合要求的答案；
 下面程序实现可能和上文稍有不同。
 
 时间复杂度O(n+m)。
 ```cpp
 #include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int f[10001];
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		f[v]+=w;
		f[u]-=w;
	}
	int sum=0;
	for (int i=1;i<=n;i++) if (f[i]>0) sum+=f[i];
	printf("%d\n",sum);
	return 0;
}
 ```
 ***** 
  ## div2 A
 ### Problem description
 > 给出n个人,m条债务关系，(1≤n≤100;0 ≤m≤ 10^4)，试重新安排债务，使得债务总量之和最小。
 ### Solution
 稍作思考可知，我们可以O(m)计算出每一个人的债权数和债务数，若一个人债权数大于债务数，则可以将其债务转接到欠他债的人处，若一个人债权数小于债务数，则可以将其债权交给欠债的人，这样对答案贡献为abs(xi-yi)/2，(xi为其债权数，yi为其债务数),一方面每个人至少造成这么多代价，另一方面这个方案是可达到的，因此∑abs(xi-yi)/2即为符合要求的答案；
 下面程序实现可能和上文稍有不同。
 
 时间复杂度O(n+m)。
 ```cpp
 #include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int f[10001];
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		f[v]+=w;
		f[u]-=w;
	}
	int sum=0;
	for (int i=1;i<=n;i++) if (f[i]>0) sum+=f[i];
	printf("%d\n",sum);
	return 0;
}
 ```
 ***** 
 # 赛后补题
 
 ## B
 ### Problem description
 > 输出我要补题
 ### Solution
 仔细分析一下，这个题可以用一个printf语句解决
 ```cpp
 #include <bits/stdc++.h>
 using namespace std;
 int main () {
     printf("I want buti\n");
 }
 ```
