/*1077. Kuchiguse (20)

The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality.
Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:

Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".

Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai
*/
#include <stdio.h>
#include <string.h>
void reverse(char str[],int len)
{
  for(int i=0;i<len/2;i++)
  {
    char temp=str[i];
    str[i]=str[len-1-i];
    str[len-1-i]=temp;
  }
}
int main()
{
  bool flag=1;
  char str[110][280];
  int N,len[110];
  scanf("%d",&N);
  getchar();//吸收'\n'
  for(int i=0;i<N;i++)
  {
    gets(str[i]);
    len[i]=strlen(str[i]);
    reverse(str[i],len[i]);
  }
  int lenmin=300;
  for(int i=0;i<N;i++) if(len[i]<lenmin) lenmin=len[i];
  for(int i=1;i<N;i++) if(str[i][0]!=str[0][0])
  {
    flag=0;
    break;
  }
  int j;
  if(flag==1)
  {
    for(j=1;j<=lenmin;j++)
    {
      for(int i=0;i<N;i++) if(str[i][j]!=str[0][j])
      {
        flag=0;
        break;
      }
      if(flag==0)
      {
        flag=1;
        break;
      }
    }
  }
  if(j==lenmin+1) j--;    //整个字符串都是的情况
  if(flag==1) for(j--;j>=0;j--) printf("%c",str[0][j]);
  else printf("nai");
  return 0;
}
