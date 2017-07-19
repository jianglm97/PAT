/*1062. Talent and Virtue (25)

About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue must be a "sage��ʥ�ˣ�";
being less excellent but with one's virtue outweighs talent can be called a "nobleman�����ӣ�"; being good in neither is a "fool man�����ˣ�"; yet a fool man is better than a "small man��С�ˣ�" who prefers talent than virtue.

Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.

Input Specification:

Each input file contains one test case. Each case first gives 3 positive integers in a line: N (<=105), the total number of people to be ranked; L (>=60), the lower bound of the qualified grades -- that is,
only the ones whose grades of talent and virtue are both not below this line will be ranked; and H (<100), the higher line of qualification
-- that is, those with both grades not below this line are considered as the "sages", and will be ranked in non-increasing order according to their total grades.
Those with talent grades below H but virtue grades not are cosidered as the "noblemen", and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages".
Those with both grades below H, but with virtue not lower than talent are considered as the "fool men". They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the L line are ranked after the "fool men".

Then N lines follow, each gives the information of a person in the format:

ID_Number Virtue_Grade Talent_Grade
where ID_Number is an 8-digit number, and both grades are integers in [0, 100]. All the numbers are separated by a space.
Output Specification:

The first line of output must give M (<=N), the total number of people that are actually ranked. Then M lines follow, each gives the information of a person in the same format as the input, according to the ranking rules.
If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. If there is still a tie, then output in increasing order of their ID's.

Sample Input:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
Sample Output:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct student
{
  char id[10];
  int  de,cai,sum,cls;
}stu[100010];
bool cmp(student a,student b)
{
  if(a.cls!=b.cls) return a.cls<b.cls;
  else if(a.sum!=b.sum) return a.sum>b.sum;
  else if(a.de!=b.de) return a.de>b.de;
  else return strcmp(a.id,b.id)<0;
}
int main()
{
  int N,L,H;
  scanf("%d%d%d",&N,&L,&H);
  int count=N;
  for(int i=0;i<N;i++)
  {
    scanf("%s%d%d",stu[i].id,&stu[i].de,&stu[i].cai);
    stu[i].sum=stu[i].de+stu[i].cai;
    if(stu[i].de<L || stu[i].cai<L)
    {
      stu[i].cls=5;
      count--;
    }
    else if(stu[i].de>=H && stu[i].cai>=H) stu[i].cls=1;
    else if(stu[i].de>=H && stu[i].cai<H) stu[i].cls=2;
    else if(stu[i].de<H && stu[i].cai<H && stu[i].de>=stu[i].cai) stu[i].cls=3;

    else stu[i].cls=4;
  }
  sort(stu,stu+N,cmp);
  printf("%d\n",count);
  for(int i=0;i<count;i++) printf("%s %d %d\n",stu[i].id,stu[i].de,stu[i].cai);
  return 0;
}