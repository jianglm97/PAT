/*1029. Median (25)

Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15.
The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input

Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence.
Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output

For each test case you should output the median of the two given sequences in a line.

Sample Input
4 11 12 13 14
5 9 10 15 16 17
Sample Output
13
*/
#include <stdio.h>
long long a1[1000100],a2[1000100],a[2000200];
int main()
{
  int N1,N2;
  scanf("%d",&N1);
  for(int i=0;i<N1;i++) scanf("%lld",&a1[i]);
  scanf("%d",&N2);
  for(int i=0;i<N2;i++) scanf("%lld",&a2[i]);
  int i=0,j=0,index=0;
  while(i<N1&&j<N2)
  {
    if(a1[i]<=a2[j]) a[index++]=a1[i++];
    else a[index++]=a2[j++];
  }
  while(i<N1) a[index++]=a1[i++];
  while(j<N2) a[index++]=a2[j++];
  printf("%lld",a[(index-1)/2]);
  return 0;
}
