/*1067. Sort with Swap(0,*) (25)

Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:

Each input file contains one test case, which gives a positive N (<=10^5) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.

Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
  int N,count=0,pos[100010];
  scanf("%d",&N);
  int left=N-1;
  for(int i=0;i<N;i++)
  {
    int temp;
    scanf("%d",&temp);
    pos[temp]=i;
    if(temp==i&&temp!=0) left--;
  }
  int idx=1;
  while(left>0)
  {
    if(pos[0]==0) while(idx<N)
    {
      if(pos[idx]!=idx)
      {
        swap(pos[0],pos[idx]);
        count++;
        break;
      }
      idx++;
    }
    while(pos[0]!=0)
    {
      swap(pos[0],pos[pos[0]]);
      count++;
      left--;
    }
  }
  printf("%d",count);
  return 0;
}

