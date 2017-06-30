 # 比赛记录[contest13] [Codeforces Round #221 (Div.1&2)]
 
 [比赛链接1(div1)](http://codeforces.com/contest/375)
 
 [比赛链接2(div2)](http://codeforces.com/contest/376)
 
 ## div2 A
 ### Problem description
 > 以字符串形式给出一个杠杆的形态(支点位置，重物位置及重物质量)，求杠杆是平衡，左倾还是右倾。(字符串长度3≤|s|≤10^6)。
 ### Solution
 >由杠杆平衡条件可以得到,设sum=∑(xi-k)wi，xi为第i个重物的位置，wi为第i个重物的质量，若sum<0杠杆左倾，sum>0杠杆右倾，sum=0杠杆平衡；注意使用64位整数；
 
 >时间复杂度O(|s|)。
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
 
 
 
 ## div2 B
 ### Problem description
 > 给出n个人,m条债务关系，(1≤n≤100;0 ≤m≤ 10^4)，试重新安排债务，使得债务总量之和最小。
 ### Solution
 >稍作思考可知，我们可以O(m)计算出每一个人的债权数和债务数，若一个人债权数大于债务数，则可以将其债务转接到欠他债的人处，若一个人债权数小于债务数，则可以将其债权交给欠债的人，这样对答案贡献为abs(xi-yi)/2，(xi为其债权数，yi为其债务数),一方面每个人至少造成这么多代价，另一方面这个方案是可达到的，因此∑abs(xi-yi)/2即为符合要求的答案；
 下面程序实现可能和上文稍有不同。
 
 >时间复杂度O(n+m)。
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
 ## div1 A
 ### Problem description
 > 给出一个大整数a，a的位数len在4和10^6之间，一定含有1,6,8,9，不含前导0，试给出一种重新排列整数中数字的方法，得到一个新数，使得新数不含前导0且能被7整除，不能组成输出0。
 ### Solution
>这题隐含一个比较隐藏的性质：仅通过排列1，6，8，9，可以得到模7为0~6中的所有数：1869%7=0，1896%7=6，1986%7=5，8691%7=4，6891%7=3，1689%7=2，6189%7=1；因此我们可以先把所有0放到最后，分别扣除一个1,6,8,9后乱排，最后用1,6,8,9来调整大整数对7的模数，从而保证每一个输入都能组成一个模7为0的数字串。

 >时间复杂度O(len)。
 ```cpp
 #include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[1000000];
int vis[100];
string s0;
int mod() {
	int len=s0.length();
	int ans=0;
	for (int i=0;i<len;i++) ans=(ans*10+s0[i]-48)%7;
	return ans;
}
int main() {
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i<len;i++) vis[s[i]-48]++;
	vis[1]--;
	vis[6]--;
	vis[8]--;
	vis[9]--;
	s0="";
	for (int i=1;i<=9;i++) for (int j=1;j<=vis[i];j++) s0+=i+48;
	cout<<s0;
	s0=s0+"0000";
	int ans=mod();
	if (ans==0) printf("1869");
	  else if (ans==1) printf("1896");
	  else if (ans==2) printf("1986");
	  else if (ans==3) printf("8691");
	  else if (ans==4) printf("6891");
	  else if (ans==5) printf("1689");
	  else if (ans==6) printf("6189");
	for (int i=1;i<=vis[0];i++) printf("0");
	return 0;
}
 ```
 ***** 
 # 赛后补题
