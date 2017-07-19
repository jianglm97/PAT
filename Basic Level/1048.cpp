/*1048. 数字加密(20)

本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：
对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：

输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118
*/
#include <stdio.h>
#include <string.h>
int main()
{
  char a[110],b[110],ans[110]={0},m[15]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
  int count=0,i,j;
  scanf("%s%s",a,b);
  int lena=strlen(a);
  int lenb=strlen(b);
  for(i=lena-1,j=lenb-1;i>=0&&j>=0;i--,j--)
  {
    if((count+1)%2==1)
    {
      int r=(b[j]-'0'+a[i]-'0')%13;
      ans[count++]=m[r];
    }
    else
    {
      int sub=b[j]-a[i];
      if(sub<0) sub+=10;
      ans[count++]=sub+'0';
    }
  }
  if(lena>lenb) for(i;i>=0;i--)
  {
    if((count+1)%2==1)
    {
      int r=(a[i]-'0')%13;
      ans[count++]=m[r];
    }
    else
    {
      if(a[i]=='0') ans[count++]='0';
      else ans[count++]='0'-a[i]+10+'0';   //CAUTION HERE
    }
  }
  if(lena<lenb) for(j;j>=0;j--) ans[count++]=b[j];
  int k;
  for(k=count-1;k>=0;k--) if(ans[k]!='0') break;
  if(k==-1) printf("0");
  for(k;k>=0;k--) printf("%c",ans[k]);
  return 0;
}

