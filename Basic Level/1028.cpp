/*1028. �˿��ղ�(20)

ĳ��������˿��ղ飬�õ���ȫ���������ա�������д�������ҳ��������곤����������ˡ�

����ȷ��ÿ����������ڶ��ǺϷ��ģ�����һ���Ǻ���ġ���������֪����û�г���200������ˣ���������2014��9��6�գ����Գ���200������պ�δ���������ն��ǲ�����ģ�Ӧ�ñ����˵���

�����ʽ��

�����ڵ�һ�и���������N��ȡֵ��(0, 10^5]�����N�У�ÿ�и���1���˵��������ɲ�����5��Ӣ����ĸ��ɵ��ַ��������Լ�����yyyy/mm/dd��������/��/�գ���ʽ���������ա���Ŀ��֤���곤�����������û�в��С�

�����ʽ��

��һ����˳�������Ч���յĸ��������곤�˺��������˵�����������Կո�ָ���//19971014 19980615

����������
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
���������
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
