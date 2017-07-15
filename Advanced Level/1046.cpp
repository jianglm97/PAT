/*1046. Shortest Distance (20)

The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

Input Specification:

Each input file contains one test case.
For each case, the first line contains an integer N (in [3, 10^5]), followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits.
All the numbers in a line are separated by a space.
The second line gives a positive integer M (<=10^4), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 107.

Output Specification:

For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7

#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  int M,N,d[100000],ans[10000],j=0;
  scanf("%d",&N);
  for(int i=1;i<=N;i++) scanf("%d",&d[i]);
  scanf("%d",&M);
  while(M--)
  {
    int l,r,left=0,right=0;
    scanf(" %d %d",&l,&r);
    if(l>r) swap(l,r);
    for(int i=l;i<r;i++) right+=d[i];
    for(int i=l-1;i>=1;i--) left+=d[i];
    for(int i=N;i>=r;i--) left+=d[i];
    ans[j++]=left>right?right:left;
  }
  for(int i=0;i<j;i++) printf("%d\n",ans[i]);
  return 0;
}   TIME LIMIT EXCEEDED
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=100005;
int dis[MAXN],A[MAXN];
int main()
{
  int sum=0,query,n,left,right;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&A[i]);
    sum+=A[i];
    dis[i]=sum;
  }
  scanf("%d",&query);
  for(int i=0;i<query;i++)
  {
    scanf("%d%d",&left,&right);
    if(left>right) swap(left,right);
    int temp=dis[right-1]-dis[left-1];
    printf("%d\n",min(temp,sum-temp));
  }
  return 0;
}

