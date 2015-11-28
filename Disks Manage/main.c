/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "DiskH.h"

struct a disk[NUM];
struct b rent[NUM];

int main()
{
    int i=0;
    char ch;

    printf("           C���Գ�����ƿγ���ơ���Ӱ����Ϣ����ϵͳ\n");
    printf("           ׿ң�� ¬��٩ ������ ׯӱ ���ƺ� ���ϴ���\n");
	printf("                   ����س���ʼ���г���:\n");
	getchar();
	 
	i = read(i);
	if(i==-2)
	{
		return 0;
	}
	
	i = choice(i);
    
	printf("�������!\n");
    
    write(i);//�������ǰ�����ж����ٰ�˳��д���ļ� 
    return 0;
}

void list(void)
{
	system("cls");
    printf("**********************************************************\n");
    printf("                  ��ѡ����Ҫʹ�õĹ���(����1~6)\n");
    printf("                  (1)��ѯ����Ӱ��\n");
	printf("                  (2)�����µ�Ӱ��\n");
	printf("                  (3)  ����Ӱ��  \n");
	printf("                  (4)  �黹Ӱ��  \n");
	printf("                  (5)�������Ӱ��\n");
	printf("                  (6)ɾ��һ��Ӱ��\n");
	printf("                  (7)  �˳�����\n"); 
    printf("**********************************************************\n");
}

int choice(int i)
{
	int m,k=0;
	char ch;

	do//���û�û������q�˳���ʱ�� 
    {
    	
        do
        {
            list();
            scanf("%d",&m);
        }
        while(checklegal(m));			//������
        
        switch(m)				//����ѡ��
        {
        case 1:
        	chazhao(i);
            break;
        case 2:
            add(i++);
            break;
        case 3:
            k=jie(i,k);
            break;
        case 4:
            guihuan(i,k);
            break;
		case 5:
			show(i);
			break;
		case 6:
			i-=delet(i);
		case 7:
			return 0;
        }
        
        printf("�������ʹ�ñ�����������c����������q�˳�:\n");
        do
        {
            scanf(" %c",&ch);
        }
        while(checkchar(ch));		//������
    }
    while(ch != 'q');
    return i;
}

int read(int i)
{
	int n;
	FILE *fp;
	fp =fopen(ROAD,"r");
	
	if(fp==NULL)
	{
		puts("�ļ���ʧ�ܣ���ȷ���ļ�·����");
		return -2;//����򲻿��ͷ��ظ�-2�ɣ����������� 
	}
	
	while(!feof(fp))
	{
			n = fscanf(fp,"%s %s %s %d %d %lf",disk[i].name,disk[i].nation,disk[i].type,&disk[i].flag,&disk[i].heat,&disk[i].mark);
			if(n<0)//�������ʧ�����򷵻�-1������������break
			{ 
				break;
			}
			i++;
	}
	qsort(disk,i,sizeof(disk[0]),cmpname);		//��ӰƬ��������
	fclose(fp);
	return i;
}

void write(int i)
{
    int k=0;
    FILE *fp;

    fp =fopen(ROAD,"w");
    qsort(disk,i,sizeof(disk[0]),cmpname);			//��ӰƬ��������
	while(k<i)
	{
			fprintf(fp,"%-20s%-8s",disk[k].name,disk[k].nation);
			fprintf(fp,"%-10s%-2d",disk[k].type,disk[k].flag);
			fprintf(fp,"%-4d%.1lf\n",disk[k].heat,disk[k].mark);
			k++;
	}
	fclose(fp);
}

