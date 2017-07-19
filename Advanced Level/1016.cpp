/*1016. Phone Bills (25)

A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made.
When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone.
Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:

Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (<= 1000), followed by N lines of records.
Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".

For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record.
Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input.
You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample.
Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order.
Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char line[5][15]={"off-line","on-line"};
int cost[30];
struct list
{
  char name[25];
  int mon,day,hr,min;
  bool stat;
}call[1010];
bool cmp(list a,list b)
{
  if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
  else if(a.mon!=b.mon) return a.mon<b.mon;
  else if(a.day!=b.day) return a.day<b.day;
  else if(a.hr!=b.hr) return a.hr<b.hr;
  else return a.min<b.min;
}
double amount(list a,list b)
{
  double sum=0;
  while(a.day<b.day||a.hr<b.hr||a.min<b.min)
  {
    sum+=cost[a.hr];
    a.min++;
    if(a.min>=60)
    {
      a.hr++;
      a.min=0;
    }
    if(a.hr>=24)
    {
      a.day++;
      a.hr=0;
    }
  }
  return 1.0*sum/100;
}
int main()
{
  int N;
  for(int i=0;i<24;i++) scanf("%d",&cost[i]);
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    char temp[15];
    scanf("%s %d:%d:%d:%d %s",call[i].name,&call[i].mon,&call[i].day,&call[i].hr,&call[i].min,temp);
    if(strcmp(temp,line[0])==0) call[i].stat=false;
    if(strcmp(temp,line[1])==0) call[i].stat=true;
  }
  sort(call,call+N,cmp);
  double total=0;
  bool flag=1;
  for(int i=1;i<N;i++)
  {
    if(strcmp(call[i].name,call[i-1].name)==0&&call[i].stat==0&&call[i-1].stat==1)
    {
      if(flag==1)
      {
        printf("%s %02d\n",call[i].name,call[i].mon);
        flag=0;
      }
      printf("%02d:%02d:%02d %02d:%02d:%02d ",call[i-1].day,call[i-1].hr,call[i-1].min,call[i].day,call[i].hr,call[i].min);
      int sub=call[i].day*24*60+call[i].hr*60+call[i].min-call[i-1].day*24*60-call[i-1].hr*60-call[i-1].min;
      double sum=amount(call[i-1],call[i]);
      printf("%d $%.2f\n",sub,sum);
      total+=sum;
    }
    if(strcmp(call[i].name,call[i+1].name)!=0&&total!=0)
    {
      printf("Total amount: $%.2f\n",total);
      total=0;
      flag=1;
    }
  }
  return 0;
}
