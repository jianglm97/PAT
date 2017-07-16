/*1036. Boys vs Girls (25)

This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information.
Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100.
It is guaranteed that all the grades are distinct.

Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade.
The third line gives the difference gradeF-gradeM. If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.

Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:
Mary EE990830
Joe Math990112
6
Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA
*/
#include <stdio.h>
struct student
{
  char name[11],gend,id[11];
  int grad;
}stu[1000];
int main()
{
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++) scanf("%s %c %s %d",stu[i].name,&stu[i].gend,stu[i].id,&stu[i].grad);
  int max=-1,cmax=0,bmax;
  for(int i=0;i<N;i++) if(stu[i].grad>max&&stu[i].gend=='F')
  {
    max=stu[i].grad;
    bmax=i;
    cmax++;
  }
  int min=101,cmin=0,bmin;
  for(int i=0;i<N;i++) if(stu[i].grad<min&&stu[i].gend=='M')
  {
    min=stu[i].grad;
    bmin=i;
    cmin++;
  }
  if(cmax==0) printf("Absent\n");
  else printf("%s %s\n",stu[bmax].name,stu[bmax].id);
  if(cmin==0) printf("Absent\n");
  else printf("%s %s\n",stu[bmin].name,stu[bmin].id);
  if(cmax==0||cmin==0) printf("NA");
  else printf("%d",max-min);
  return 0;
}
