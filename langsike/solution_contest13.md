 # 比赛记录
 
 [比赛链接1(div1)](http://codeforces.com/contest/375)
 
 [比赛链接2(div2)](http://codeforces.com/contest/376)
 ## div2 A
 ### Problem description
 > 以字符串形式给出一个杠杆的形态(支点位置，重物位置及重物质量)，求杠杆是平衡，左倾还是右倾。(字符串长度3≤|s|≤1000000)。
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
  ## div2 B
 ### Problem description
 > 以字符串形式给出一个杠杆的形态(支点位置，重物位置及重物质量)，求杠杆是平衡，左倾还是右倾。(字符串长度3≤|s|≤1000000)。
 ### Solution
 由杠杆平衡条件可以得到,设sum=∑(xi-k)wi，xi为第i个重物的位置，wi为第i个重物的质量，若sum<0杠杆左倾，sum>0杠杆右倾，sum=0杠杆平衡；注意使用64位整数；
 
 时间复杂度O(|s|)。
 ```cpp
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
