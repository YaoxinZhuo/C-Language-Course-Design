#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "DiskH.h"
extern  struct a disk[NUM];
extern  struct b rent[NUM];
//�����濪ʼд��ĳ��� 
void chazhao(int n)
{
    char name[50];		//��ʱ���������ӰƬ��
    int i,flag1,flag2;//i����Ԥ��ʹ�ã� 
    int top,bot;//���ڶ��ַ� 
    
    char ch;//���������switch�ж� 
		getchar();
	
    printf("�����������ѯ��Ƭ���ƣ�");
    gets(name);
    
    start:makestd(name);//start������goto�ĵ��ĵط� 
    qsort(disk,n,sizeof(disk[0]),cmpname);		//��ӰƬ����������,qsort�ǿ������� 
                                            /*qsort����ϸ˵������ ���� void qsort(void *base,int nelem,int width,int (*fcmp)(const void *,const void *));
                                            ������ 1 �����������׵�ַ
                                                   2 �����д�����Ԫ������
                                                   3 ��Ԫ�ص�ռ�ÿռ��С
                                                   4 ָ������ָ�룬����ȷ�������˳�� 
                                            */
    
    top = n;//������������������Ķ��ַ����� 
    bot = 0;
    while(top>=bot)			//�ö��ַ�����ӰƬ�����ǵ�ӰƬ���������ܽϴ�
    {
    	i = (top+bot)/2;
        if(strcmp(name,disk[i].name)==0)
        {
            if(disk[i].flag)
                printf("����Ҫ�ĵ�Ƭ����\n");
            else
                printf("��Ǹ����Ҫ�ĵ�Ƭ������\n");
            return ;
        }
        else if(strcmp(name,disk[i].name)<0)
        top = i-1;
        else bot = i+1;
    }
    printf("��Ǹ������û���ҵ�����Ҫ���ĵĵ�Ƭ\n");
}//һ��һ�������ѯ���Ǿ�ȷ�������� 



void show(int n)
{
	int i,count;
	char ch;

	do{
		system("cls"); 
		printf("������������ʾ��˳��\n");
		printf("(1)���ȶ�����\t(2)����������\n");
		printf("(3)����������\n");
		scanf("%d",&i);
	}while(checkj(i));	//checkj������������� //����Ƿ�Ϊ1-3������ʽһ�� (��ͷ�ļ��п����ҵ� )			
	switch(i)									//�������ķ�ʽ����
	{
		case 1:
			qsort(disk,n,sizeof(disk[0]),cmpheat);
			break;
		case 2:
			qsort(disk,n,sizeof(disk[0]),cmpmark);
			break;
		case 3:
			qsort(disk,n,sizeof(disk[0]),cmpname);
			break;
	}
	i=0;
	do{
		printf("����\t\t ��Ƭ��     ����      ������� �ȶ� ����\n");
		for(count=0;count<5&&i<n;i++,count++)
		{
			printf("%-15s %-8s ",disk[i].name,disk[i].nation);
			printf("  %-10s    ",disk[i].type);
			if(disk[i].flag)printf("�ɽ�  ");
			else printf("���ɽ�   ");
			printf("%-3d   %.1f",disk[i].heat,disk[i].mark);
			printf("\n");
		}					//һ�δ�ӡ�岿��Ӱ
		if(i<n)
		{
			printf("����c������ʾ������q���ز˵�\n");
			getchar();
			do{
				scanf(" %c",&ch);
			}while(checkchar(ch));
		}
	}while(ch == 'c'&&i<n);
}

