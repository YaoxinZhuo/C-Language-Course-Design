#include<stdio.h>
int main()
{
	int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int year,day,month;
	
	int days=0;
	int i;
	
	printf("�������꣬�£��գ���ʽ������2008 5 15��\n");
	scanf("%d %d %d",&year,&month,&day);

	if((year%4==0)&&(year%100!=0)||(year%400==0)) 
	{
		d[2]=29;
	} 
	
	for(i=1;i<month;i++)
	{
		days += d[i];
	}
	
	days += day;
	printf("�����Ǹ�����Ȼ��ĵ�%d��\n",days);
	return 0;
}
