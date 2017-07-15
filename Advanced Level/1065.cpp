/*1065. A+B and C (64bit) (20)

Given three integers A, B and C in [-2^63, 2^63], you are supposed to tell whether A+B > C.

Input Specification:

The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:

For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false" otherwise, where X is the case number (starting from 1).

Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false
*/
#include <stdio.h>
int main()
{
  long long A,B,C;
  int T,i=1;
  bool flag=0;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%lld%lld%lld",&A,&B,&C);
    long long ans=A+B;
    if(A>0&&B>0&&ans<0) flag=1;
    else if(A<0&&B<0&&ans>=0) flag=0;
    else if(ans>C) flag=1;
    else flag=0;
    if(flag==1) printf("Case #%d: true\n",i++);
    else printf("Case #%d: false\n",i++);
  }
  return 0;
}
