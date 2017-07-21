/*1043. 输出PATest(20)

给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。

输入格式：

输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：

在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee
*/
#include <stdio.h>
#include <string.h>
int main()
{
  char str[10010];
  int hashTable[200]={0};
  gets(str);
  int len=strlen(str);
  for(int i=0;i<len;i++) if(str[i]=='P'||str[i]=='A'||str[i]=='T'||str[i]=='e'||str[i]=='s'||str[i]=='t') hashTable[str[i]]++;
  while(hashTable['P']||hashTable['A']||hashTable['T']||hashTable['e']||hashTable['s']||hashTable['t'])
  {
    if(hashTable['P'])
    {
      printf("P");
      hashTable['P']--;
    }
    if(hashTable['A'])
    {
      printf("A");
      hashTable['A']--;
    }
    if(hashTable['T'])
    {
      printf("T");
      hashTable['T']--;
    }
    if(hashTable['e'])
    {
      printf("e");
      hashTable['e']--;
    }
    if(hashTable['s'])
    {
      printf("s");
      hashTable['s']--;
    }
    if(hashTable['t'])
    {
      printf("t");
      hashTable['t']--;
    }
  }
  return 0;
}
