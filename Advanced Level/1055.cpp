/*1055. The World's Richest (25)

Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages.
That is, given the net worths of N people, you must find the M richest people in a given range of their ages.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=10^5) - the total number of people, and K (<=10^3) - the number of queries.
Then N lines follow, each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), and the net worth (integer in [-10^6, 10^6]) of a person.
Finally there are K lines of queries, each contains three positive integers: M (<= 100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.

Output Specification:

For each query, first print in a line "Case #X:" where X is the query number starting from 1. Then output the M richest people with their ages in the range [Amin, Amax]. Each person's information occupies a line, in the format

Name Age Net_Worth
The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages.
If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information.
In case no one is found, output "None".
Sample Input:
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
Sample Output:
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct rich
{
  char name[10];
  int age,net;
}r[100010];
bool cmp(rich a,rich b)
{
  if(a.net!=b.net) return a.net>b.net;
  else if(a.age!=b.age) return a.age<b.age;
  else return strcmp(a.name,b.name)<0;
}
int main()
{
  int N,K;
  scanf("%d%d",&N,&K);
  for(int i=0;i<N;i++) scanf("%s%d%d",r[i].name,&r[i].age,&r[i].net);
  sort(r,r+N,cmp);
  for(int i=0;i<K;i++)
  {
    int M,Amin,Amax,count=0;
    scanf("%d %d %d",&M,&Amin,&Amax);
    printf("Case #%d:\n",i+1);
    for(int j=0;j<N&&count<M;j++)
    {
      if(r[j].age<=Amax&&r[j].age>=Amin)
      {
        printf("%s %d %d\n",r[j].name,r[j].age,r[j].net);
        count++;
      }
    }
  if(count==0) printf("None\n");
  }
  return 0;
}
