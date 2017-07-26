/*1008. Elevator (20)

The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order.
It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:

For each test case, print the total time on a single line.

Sample Input:
3 2 3 1
Sample Output:
41
*/
#include <stdio.h>
int main()
{
  int N,a[110],sum=0;
  scanf("%d",&N);
  a[0]=0;
  for(int i=1;i<=N;i++) scanf("%d",&a[i]);
  for(int i=1;i<=N;i++)
  {
    if(a[i]>a[i-1]) sum+=6*(a[i]-a[i-1])+5;
    else if(a[i]<a[i-1]) sum+=4*(a[i-1]-a[i])+5;
    else sum+=5;
  }
  printf("%d",sum);
  return 0;
}
