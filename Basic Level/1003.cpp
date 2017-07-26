/*1003. 我要通过！(20)

“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
*/
#include <stdio.h>
#include <string.h>
int main()
{
  int n;
  char str[110];
  scanf("%d",&n);
  getchar();
  while(n--)
  {
    gets(str);
    int len=strlen(str);
    int pnum=0,ploc=-1,tnum=0,tloc=-1,other=0;
    for(int i=0;i<len;i++)
    {
      if(str[i]=='P')
      {
        pnum++;
        ploc=i;
      }
      else if(str[i]=='T')
      {
        tnum++;
        tloc=i;
      }
      else if(str[i]!='A') other++;
    }
    if(pnum!=1||tnum!=1||other!=0||tloc-ploc<=1)
    {
      printf("NO\n");
      continue;
    }
    int x=ploc,y=tloc-ploc-1,z=len-tloc-1;
    if(z-x*(y-1)==x) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
