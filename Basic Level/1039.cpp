/*1039. 到底买不买（20）

小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。

为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。

输入格式：

每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。

输出格式：

如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。

输入样例1：
ppRYYGrrYBR2258
YrR8RrY
输出样例1：
Yes 8
输入样例2：
ppRYYGrrYB225
YrR8RrY
输出样例2：
No 2
*/
#include <stdio.h>
#include <string.h>
int main()
{
  bool flag=0;
  int hashTable[130]={0};
  char str[1010];
  gets(str);
  int len=strlen(str);
  for(int i=0;i<len;i++) hashTable[str[i]]++;
  gets(str);
  len=strlen(str);
  for(int i=0;i<len;i++) hashTable[str[i]]--;
  int j=0;
  for(j=0;j<130;j++) if(hashTable[j]<0)
  {
    printf("No");
    break;
  }
  if(j==130)
  {
    printf("Yes");
    flag=1;
  }
  int sum=0;
  for(int i=0;i<130;i++)
  {
    if(hashTable[i]<0&&flag==0) sum-=hashTable[i];
    if(hashTable[i]>0&&flag==1) sum+=hashTable[i];
  }
  printf("% d",sum);
  return 0;
}
