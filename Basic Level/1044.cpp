/*1044. ��������(20)

����������13���Ƽ����ģ�

�����˵�0�������˳�Ϊtret��
����������1��12�Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
�����˽���λ�Ժ��12����λ���ֱַ��Ϊ��tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou��
��������˵����֡�29������ɻ����ľ��ǡ�hel mar�����������ġ�elo nov����Ӧ�������֡�115����Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣

�����ʽ��

�����һ�и���һ��������N��<100�������N�У�ÿ�и���һ��[0, 169)�����ڵ����� ���� �����ǵ����ģ������ǻ����ġ�

�����ʽ��

��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�

����������
4
29
5
elo nov
tam
���������
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
