/*1025. PAT Ranking (25)

Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test.
Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations.
Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee.
All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct student
{
  char id[15];
  int score;
  int f_r,l_r,loc;
}stu[30030];
bool cmp(student a,student b)
{
  if(a.score!=b.score) return a.score>b.score;
  else return strcmp(a.id,b.id)<0;
}
int main()
{
  int N,K,sum=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%d",&K);
    for(int j=0;j<K;j++)
    {
      scanf("%s%d",stu[sum+j].id,&stu[sum+j].score);
      stu[sum+j].loc=i+1;
    }
    sort(stu+sum,stu+sum+K,cmp);
    stu[sum].l_r=1;
    for(int j=1;j<K;j++)
    {
      if(stu[sum+j].score==stu[sum+j-1].score) stu[sum+j].l_r=stu[sum+j-1].l_r;
      else stu[sum+j].l_r=j+1;
    }
    sum+=K;
  }
  sort(stu,stu+sum,cmp);
  stu[0].f_r=1;
  for(int i=1;i<sum;i++)
  {
    if(stu[i].score==stu[i-1].score) stu[i].f_r=stu[i-1].f_r;
    else stu[i].f_r=i+1;
  }
  printf("%d\n",sum);
  for(int i=0;i<sum;i++) printf("%s %d %d %d\n",stu[i].id,stu[i].f_r,stu[i].loc,stu[i].l_r);
  return 0;
}
