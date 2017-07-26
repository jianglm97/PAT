/*1101. Quick Sort (25)

There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot.
Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?

For example, given N = 5 and the numbers 1, 3, 2, 4, and 5. We have:

1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
and for the similar reason, 4 and 5 could also be the pivot.
Hence in total there are 3 pivot candidates.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<= 105). Then the next line contains N distinct positive integers no larger than 109. The numbers in a line are separated by spaces.

Output Specification:

For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:
5
1 3 2 4 5
Sample Output:
3
1 4 5
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
  int N,a[100010],leftMax[100010],rightMin[100010],ans[100010],count=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++) scanf("%d",&a[i]);
  leftMax[0]=0;
  for(int i=1;i<N;i++) leftMax[i]=max(a[i-1],leftMax[i-1]);
  rightMin[N-1]=0x7fffffff;
  for(int i=N-2;i>=0;i--) rightMin[i]=min(a[i+1],rightMin[i+1]);
  for(int i=0;i<N;i++) if(leftMax[i]<a[i]&&rightMin[i]>a[i]) ans[count++]=a[i];
  sort(ans,ans+count);
  printf("%d\n",count);
  for(int i=0;i<count;i++)
  {
    printf("%d",ans[i]);
    if(i!=count-1) printf(" ");
  }
  printf("\n");
  return 0;
}
