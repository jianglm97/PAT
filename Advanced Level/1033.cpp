/*1033. To Fill or Not to Fill (25)

With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time.
Different gas station may give different price. You are asked to carefully design the cheapest route to go.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city;
Davg (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations.
Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning.
If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.

Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct station
{
  double price,dest;
}stat[505];
bool cmp(station a,station b)
{
  return a.dest<b.dest;
}
int main()
{
  int N;
  double Cmax,D,Davg;
  scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
  for(int i=0;i<N;i++) scanf("%lf%lf",&stat[i].price,&stat[i].dest);
  stat[N].price=0;
  stat[N].dest=D;
  sort(stat,stat+N+1,cmp);
  if(stat[0].dest!=0)
  {
    printf("The maximum travel distance = 0.00");
    return 0;
  }
  int now=0;
  double Dmax=Cmax*Davg,nowTank=0,ans=0;
  while(now<N)
  {
    int idx=-1;
    double priceMin=1000000000;
    for(int i=now+1;i<=N&&stat[i].dest-stat[now].dest<=Dmax;i++) if(stat[i].price<priceMin)
    {
      priceMin=stat[i].price;
      idx=i;
      if(priceMin<stat[now].price) break;
    }
    if(idx==-1) break;
    double need=(stat[idx].dest-stat[now].dest)/Davg;
    if(priceMin<stat[now].price)
    {
      if(nowTank<need)
      {
        ans+=(need-nowTank)*stat[now].price;
        nowTank=0;
      }
      else nowTank-=need;
    }
    else
    {
      ans+=(Cmax-nowTank)*stat[now].price;
      nowTank=Cmax-need;
    }
    now=idx;
  }
  if(now==N) printf("%.2f",ans);
  else printf("The maximum travel distance = %.2f",stat[now].dest+Dmax);
  return 0;
}
