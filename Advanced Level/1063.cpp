/*1063. Set Similarity (25)

Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the number of distinct common numbers shared by the two sets, and Nt is the total number of distinct numbers in the two sets.
Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=10^4) and followed by M integers in the range [0, 10^9].
After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%
*/
#include <stdio.h>
#include <set>
using namespace std;
set<int> st[60];
void compare(int a, int b)
{
  int total=st[b].size(),same=0;
  for(set<int>::iterator it=st[a].begin();it!=st[a].end();it++)
  {
    if(st[b].find(*it)!=st[b].end()) same++;
    else total++;
  }
  printf("%.1f%%\n",same*100.0/total);
}
int main()
{
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++)
  {
    int M;
    scanf("%d",&M);
    for(int j=0;j<M;j++)
    {
      int temp;
      scanf("%d",&temp);
      st[i].insert(temp);
    }
  }
  int K;
  scanf("%d",&K);
  for(int i=0;i<K;i++)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    compare(a,b);
  }
  return 0;
}
