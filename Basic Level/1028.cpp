/*1028. 人口普查(20)

某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：

输入在第一行给出正整数N，取值在(0, 10^5]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：

在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。//19971014 19980615

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John
*/
#include <stdio.h>
struct people
{
  char name[5];
  int y,m,d;
}temp,max,min;
int main()
{
  int N,count=0;
  scanf("%d",&N);
  max.y=1814;
  max.m=9;
  max.d=6;
  min.y=2014;
  min.m=9;
  min.d=6;
  for(int i=0;i<N;i++)
  {
    scanf("%s%d/%d/%d",temp.name,&temp.y,&temp.m,&temp.d);
    if(temp.y<1814) continue;
    if(temp.y==1814&&temp.m<9) continue;
    if(temp.y==1814&&temp.m==9&&temp.d<6) continue;
    if(temp.y>2014) continue;
    if(temp.y==2014&&temp.m>9) continue;
    if(temp.y==2014&&temp.m==9&&temp.d>6) continue;
    count++;
    if(temp.y>max.y) max=temp;
    if(temp.y==max.y&&temp.m>max.m) max=temp;
    if(temp.y==max.y&&temp.m==max.m&&temp.d>max.d) max=temp;
    if(temp.y<min.y) min=temp;
    if(temp.y==min.y&&temp.m<min.m) min=temp;
    if(temp.y==min.y&&temp.m==min.m&&temp.d<min.d) min=temp;
  }
  if(count==0) printf("0");
  else printf("%d %s %s",count,min.name,max.name);
  return 0;
}
