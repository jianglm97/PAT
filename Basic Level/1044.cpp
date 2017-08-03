/*1044. 火星数字(20)

火星人是以13进制计数的：

地球人的0被火星人称为tret。
地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;
string unit[15]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string ten[15]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
string num_str[170];
map<string,int> str_num;
void init()
{
  for(int i=0;i<13;i++)
  {
    num_str[i]=unit[i];
    str_num[unit[i]]=i;
    num_str[i*13]=ten[i];
    str_num[ten[i]]=i*13;
  }
  for(int i=1;i<13;i++) for(int j=1;j<13;j++)
  {
    string str=ten[i]+" "+unit[j];
    num_str[i*13+j]=str;
    str_num[str]=i*13+j;
  }
}
int main()
{
  init();
  int N;
  scanf("%d",&N);
  getchar();
  while(N--)
  {
    string str;
    getline(cin,str);
    if(str[0]>='0'&&str[0]<='9')
    {
      int num=0;
      for(int i=0;i<str.length();i++) num=num*10+str[i]-'0';
      cout<<num_str[num]<<endl;
    }
    else cout<<str_num[str]<<endl;
  }
  return 0;
}
