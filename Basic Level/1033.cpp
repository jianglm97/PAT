/*1033. 旧键盘打字(20)

旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：

输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过10^5个字符的串。
可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：

在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
  bool hashTable[100010]={0},flag=0;
  char broken[100],str[100010];
  gets(broken);
  for(int i=0;i<strlen(broken);i++) if(broken[i]>='A'&&broken[i]<='Z') broken[i]+=32;
  gets(str);
  int len=strlen(str);
  fill(hashTable,hashTable+len,1);
  for(int i=0;i<strlen(broken);i++)
  {
    if(broken[i]=='+') for(int j=0;j<len;j++) if(str[j]>='A'&&str[j]<='Z') hashTable[j]=0;
    for(int j=0;j<len;j++) if(str[j]==broken[i]||str[j]+32==broken[i]) hashTable[j]=0;
  }
  for(int i=0;i<len;i++) if(hashTable[i]==1) printf("%c",str[i]);
  return 0;
}
