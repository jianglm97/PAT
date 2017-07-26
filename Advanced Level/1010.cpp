/*1010. Radix (25)

Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35.
The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL Map[256];
LL INF=(1LL<<63)-1;
char N1[20],N2[20],temp[20];
int tag,radix;
void init()
{
  for(char c='0';c<='9';c++) Map[c]=c-'0';
  for(char c='a';c<='z';c++) Map[c]=c-'a'+10;
}
LL to10(char a[],LL radix,LL t)
{
  LL ans=0;
  int len=strlen(a);
  for(int i=0;i<len;i++)
  {
    ans=ans*radix+Map[a[i]];
    if(ans<0||ans>t) return -1;
  }
  return ans;
}
int cmp(char N2[],LL radix,LL t)
{
  int len=strlen(N2);
  LL num=to10(N2,radix,t);
  if(num<0) return 1;
  if(t>num) return -1;
  else if(t==num) return 0;
  else return 1;
}
LL binSearch(char N2[],LL left,LL right,LL t)
{
  LL mid;
  while(left<=right)
  {
    mid=(left+right)/2;
    int flag=cmp(N2,mid,t);
    if(flag==0) return mid;
    else if(flag==-1) left=mid+1;
    else right=mid-1;
  }
  return -1;
}
int digitMax(char N2[])
{
  int ans=-1,len=strlen(N2);
  for(int i=0;i<len;i++) if(Map[N2[i]]>ans) ans=Map[N2[i]];
  return ans+1;
}
int main()
{
  init();
  scanf("%s %s %d %d",N1,N2,&tag,&radix);
  if(tag==2)
  {
    strcpy(temp,N1);
    strcpy(N1,N2);
    strcpy(N2,temp);
  }
  LL t=to10(N1,radix,INF);
  LL low=digitMax(N2);
  LL high=max(low,t)+1;
  LL ans=binSearch(N2,low,high,t);
  if(ans==-1) printf("Impossible");
  else printf("%lld",ans);
  return 0;
}
