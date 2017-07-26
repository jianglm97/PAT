/*1085. Perfect Sequence (25)

Given a sequence of positive integers and another positive integer p. The sequence is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (<= 105) is the number of integers in the sequence, and p (<= 109) is the parameter.
In the second line there are N positive integers, each is no greater than 109.

Output Specification:

For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:
8
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  int N,p,a[100010];
  scanf("%d%d",&N,&p);
  for(int i=0;i<N;i++) scanf("%d",&a[i]);
  sort(a,a+N);
  int i=0,j=0,len=0;
  while(i<N&&j<N)
  {
    while(j<N&&a[j]<=(long long)a[i]*p)
    {
      len=max(len,j-i+1);
      j++;
    }
  i++;
  }
  printf("%d",len);
  return 0;
}
