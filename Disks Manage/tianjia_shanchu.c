#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "DiskH.h" 
extern  struct a disk[NUM];
extern  struct b rent[NUM];
//������д��ĳ��� 
void add(int n)			//nΪ��¼�����е�ӰƬ��
{
	getchar();
   
    printf("�������Ƭ���֣�����֮������_�� (������20�ַ�)��");
    gets(disk[n].name);
    
    makestd(disk[n].name);
    printf("�������Ƭ���أ�");
    gets(disk[n].nation);
    
    printf("�������Ƭ���ͣ�");
    gets(disk[n].type);
    
	disk[n].heat = 0;	//��ʼ�����Ĵ���
    disk[n].flag = 1;	//��ʼ���������
    disk[n].mark = 0;	//��ʼ���û�����
    
    printf("�µĵ�Ƭ�Ѿ�����ɹ�!\n"); 
    
}
int delet(int n)			////nΪ��¼�����е�ӰƬ��
{
    char name[100];
    int k,top,bot,i;

    puts("������Ҫɾ����ӰƬ���֣�");
    getchar();
		gets(name);
		makestd(name);
    qsort(disk,n,sizeof(disk[0]),cmpname);		//��ӰƬ�����ֽ�������
    top = n;
    bot = 0;
	while(top>=bot)	//�ö��ַ�����ӰƬ
	{
        i = (top+bot)/2;
        if(strcmp(name,disk[i].name)==0) 		//�ҵ��󣬽����ں����������ǰ��һ����λ
        {
			for(k=i;k<n-1;k++)
		    {
			    strcpy(disk[k].name,disk[k+1].name);
			    strcpy(disk[k].nation,disk[k+1].nation);
			    strcpy(disk[k].type,disk[k+1].type);
			    disk[k].flag = disk[k+1].flag;
			    disk[k].heat = disk[k+1].heat;
			    disk[k].mark = disk[k+1].mark;
		    }
		    printf("ɾ���ɹ���\n");
		    return 1;
		}
        else if(strcmp(name,disk[i].name)<0)
        top = i-1;
        else bot = i+1;            
    }
	printf("�޴�ӰƬ\n");
    return 0;
}

