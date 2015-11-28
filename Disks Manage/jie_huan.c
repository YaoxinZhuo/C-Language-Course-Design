#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "DiskH.h"
extern  struct a disk[NUM];
extern  struct b rent[NUM];
//������д��ĳ��� 
int jie(int n,int k)		//nΪ��¼�����е�ӰƬ��
//kΪ��¼�н�����Ϣ����Ŀ
{
    int i,j,m;
    int bot,top;

	getchar();
    printf("��������Ҫ���ĵ�ӰƬ����\n");
    scanf("%d",&m);
    
    getchar();
    
    for(j=0;j<m;j++)
    {
        printf("�������Ա����");
        gets(rent[k].memname);
        printf("������ӰƬ���ƣ���_�ָ�ÿ�����ʣ���");
        gets(rent[k].disname);
        makestd(rent[k].disname);
        printf("�������������ڣ�\n");
        printf("(����2015-11-28)\n");
        scanf("%d-%d-%d",&rent[k].botime[0],&rent[k].botime[1],&rent[k].botime[2]);
        getchar();
        
        bot = 0;
        top = n;
        qsort(disk,n,sizeof(disk[0]),cmpname);		//��ӰƬ����������
        
        while(top>=bot)		//���ֲ���ӰƬ
        {
        	i = (top+bot)/2;
            if(strcmp(rent[k].disname,disk[i].name)==0)		//�ҵ�ӰƬ��ı��ǲ�����
            {
                disk[i].flag = 0;
                disk[i].heat++;
                break;
            }
        	else if(strcmp(rent[k].disname,disk[i].name)<0)
	        top = i-1;
	        else bot = i +1;
    	}
    	k++;
    }
    printf("�ɹ�����!\n");
    return k; 
}

void guihuan(int n,int k)		//nΪ��¼�����е�ӰƬ��
//kΪ��¼�н�����Ϣ����Ŀ
{
    int i,j,m,sum=0,day;
    char mname[20],dname[20];		//��ʱ��������Ļ�Ա����ӰƬ�� 
    double mark;
    int top,bot;

	getchar();
    printf("�������Ա��:");
    gets(mname);
    printf("����������黹ӰƬ������:");
    scanf("%d",&m);
    getchar();
    for(j=0;j<m;j++)
    {
        printf("������ӰƬ���ƣ���_�ָ�ÿ�����ʣ�:");
        gets(dname);
        top = n;
        bot = 0;
        qsort(disk,n,sizeof(disk[0]),cmpname);		//��ӰƬ����������
        while(top>=bot)
        {
        	i = (top+bot)/2;
            if(strcmp(dname,disk[i].name)==0)	//�ҵ�ӰƬ���ı�������
            {
                disk[i].flag = 1;
                break;
            }
        	else if(strcmp(dname,disk[i].name)<0)
 			top = i-1;
        	else bot = i+1;
        }		
        printf("��������������(0-10):");
        scanf("%lf",&mark);
		while(mark<0||mark>10)
		{
			printf("����0-10�������֣�");
			printf("�������������֣�0-10��:");
			scanf("%lf",&mark);
		}
        disk[i].mark = (disk[i].mark*disk[i].heat+mark)/(disk[i].heat+1);		//����ƽ������ 
        qsort(rent,k,sizeof(rent[0]),cmpname);		//��ӰƬ����������
        bot=0;
        top=k;
        while(top>=bot)		//�ҵ���ӰƬ��rent�е��±� 
        {
        	i = (top+bot)/2;
            if(strcmp(dname,rent[i].disname)==0)
            break;
            else if(strcmp(dname,rent[i].disname)<0)
        	top = i-1;
        	else bot = i+1;
        }			
        printf("�������������ڣ�\n");
        printf("(����2015-11-28)\n");
        scanf("%d-%d-%d",&rent[i].retime[0],&rent[i].retime[1],&rent[i].retime[2]);
        day = countday(i);		
        sum=day;//ͳ��Ӧ�����ÿ��һԪ
		if(sum>60)
		{
			sum=(sum-60)*3+60;//���������������Ժ�ÿ����Ԫ
		}
    }
    printf("�˴���Ҫ֧��%dԪ",sum);
}


int countday(int i)			//iΪӰƬ��rent�ж�Ӧ���±�
{
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int totalday=0;
    int by,bm,bd;		//��Ӧ����ʱ���������
int ry,rm,rd;		//��Ӧ�黹ʱ���������

    by = rent[i].botime[0];
    bm = rent[i].botime[1];
    bd = rent[i].botime[2];
    ry = rent[i].retime[0];
    rm = rent[i].retime[1];
    rd = rent[i].retime[2];

    if(by<ry)		//���ĵ�ʱ������һ������
    {
		totalday+=(365-dayth(by,bm,bd));
	    by++;		//�Ƚ��������һ�������ȫ����
	    while(by<ry)
	    {
	        totalday += 365+leap(by);
 	       by++;
    	}			//�㵽�黹�ĵ����һ��
    	totalday+=dayth(ry,rm,rd);		// �㵽�黹����
	}
	else	 totalday = dayth(ry,rm,rd) - dayth(by,bm,bd); 	//����ʱ��δ���һ������
    return totalday;
}

int dayth(int y,int m,int d)		//
{
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i,day=0;

    month[1]+=leap(y);
    for(i=0;i<m-1;i++)
    	day+=month[i];
    day+=d;
    return day;
}
int leap(int year)
{
    if((year%4==0&&year%100!=0)||year%400==0)
    {
    	return 1;
	}
	else
	{
		return 0;
	}
}
