/*1017. A除以B (20)

本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/
#include <stdio.h>
#include <string.h>
struct bign
{
  int d[1010];
  int len;
  bign()
  {
    memset(d,0,sizeof(d));
    len=0;
  }
};
bign change(char str[])
{
  bign a;
  a.len=strlen(str);
  for(int i=0;i<a.len;i++) a.d[i]=str[a.len-i-1]-'0';
  return a;
}
bign divide(bign a,int b,int &r)
{
  bign c;
  c.len=a.len;
  for(int i=a.len-1;i>=0;i--)
  {
    r=r*10+a.d[i];
    if(r<b) c.d[i]=0;
    else
    {
      c.d[i]=r/b;
      r=r%b;
    }
  }
  while(c.len-1>=1&&c.d[c.len-1]==0) c.len--;
  return c;
}
void print(bign a)
{
  for(int i=a.len-1;i>=0;i--) printf("%d",a.d[i]);
}
int main()
{
  int b,r=0;
  char str[1010];
  scanf("%s%d",str,&b);
  bign a=change(str);
  print(divide(a,b,r));
  printf(" %d",r);
  return 0;
}
