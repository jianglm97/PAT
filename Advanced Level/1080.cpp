/*1080. Graduate Admission (30)

It is said that in 2013, there were about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.

Each applicant will have to provide two grades: the national entrance exam grade GE, and the interview grade GI. The final grade of an applicant is (GE + GI) / 2. The admission rules are:

The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.
If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade GE. If still tied, their ranks must be the same.
Each applicant may have K choices and the admission will be done according to his/her choices: if according to the rank list, it is one's turn to be admitted;
and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order.
If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.
If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded.
Input Specification:

Each input file contains one test case. Each case starts with a line containing three positive integers: N (<=40,000), the total number of applicants;
M (<=100), the total number of graduate schools; and K (<=5), the number of choices an applicant may have.

In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.

Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant's GE and GI, respectively. The next K integers represent the preferred schools.
For the sake of simplicity, we assume that the schools are numbered from 0 to M-1, and the applicants are numbered from 0 to N-1.

Output Specification:

For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants' numbers that school admits.
The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.

Sample Input:
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
Sample Output:
0 10
3
5 6 7
2 8

1 4
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct student
{
  int id;
  int GE,GI,sum;
  int rank;
  int pref[6];
}stu[40040];
struct school
{
  int quota,last,now;
  int id[40040];
}sch[110];
bool cmp(student a,student b)
{
  if(a.sum!=b.sum) return a.sum>b.sum;
  else return a.GE>b.GE;
}
bool cmpID(int a,int b)
{
  return stu[a].id<stu[b].id;
}
int main()
{
  int N,M,K;
  scanf("%d%d%d",&N,&M,&K);
  for(int i=0;i<M;i++)
  {
    scanf("%d",&sch[i].quota);
    sch[i].now=0;
    sch[i].last=-1;
  }
  for(int i=0;i<N;i++)
  {
    stu[i].id=i;
    scanf("%d%d",&stu[i].GE,&stu[i].GI);
    stu[i].sum=stu[i].GE+stu[i].GI;
    for(int j=0;j<K;j++) scanf("%d",&stu[i].pref[j]);
  }
  sort(stu,stu+N,cmp);
  for(int i=0;i<N;i++)
  {
    if(i>0&&stu[i].sum==stu[i-1].sum&&stu[i].GE==stu[i-1].GE) stu[i].rank=stu[i-1].rank;
    else stu[i].rank=i;
  }
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<K;j++)
    {
      if((sch[stu[i].pref[j]].now<sch[stu[i].pref[j]].quota)||(sch[stu[i].pref[j]].now>=sch[stu[i].pref[j]].quota&&stu[i].rank==stu[sch[stu[i].pref[j]].last].rank))
      {
        sch[stu[i].pref[j]].id[sch[stu[i].pref[j]].now]=i;
        sch[stu[i].pref[j]].last=i;
        sch[stu[i].pref[j]].now++;
        break;
      }
    }
  }
  for(int i=0;i<M;i++)
  {
    sort(sch[i].id,sch[i].id+sch[i].now,cmpID);
    for(int j=0;j<sch[i].now;j++)
    {
      printf("%d",stu[sch[i].id[j]].id);
      if(j!=sch[i].now-1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
