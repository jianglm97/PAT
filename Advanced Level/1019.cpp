/*1019. General Palindromic Number (20)

A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system.
Consider a number N > 0 in base b >= 2, where it is written in standard notation with k+1 digits ai as the sum of (aibi) for i from 0 to k. Here, as usual, 0 <= ai < b for all i and ak is non-zero.
Then N is palindromic if and only if ai = ak-i for all i. Zero is written 0 in any base and is also palindromic by definition.

Given any non-negative decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.

Input Specification:

Each input file contains one test case. Each case consists of two non-negative numbers N and b, where 0 <= N <= 10^9 is the decimal number and 2 <= b <= 10^9 is the base. The numbers are separated by a space.

Output Specification:

For each test case, first print in one line "Yes" if N is a palindromic number in base b, or "No" if not. Then in the next line, print N as the number in base b in the form "ak ak-1 ... a0".
Notice that there must be no extra space at the end of output.

Sample Input 1:
27 2
Sample Output 1:
Yes
1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:
No
4 4 1
*/
#include <stdio.h>
int main()
{
  int N,b,a[100],num=0;
  scanf("%d%d",&N,&b);
  do
  {
    a[num++]=N%b;
    N/=b;
  }
  while(N!=0);
  int j;
  for(j=0;j<num/2;j++) if(a[j]!=a[num-1-j]) break;
  if(j==num/2) printf("Yes\n");
  else printf("No\n");
  for(int i=num-1;i>=0;i--)
  {
    printf("%d",a[i]);
    if(i!=0) printf(" ");
  }
  return 0;
}
