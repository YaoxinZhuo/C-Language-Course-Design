#include"DiskH.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern  struct a disk[NUM];//extern�����ں���ǰ���Ա�ʾ�������ߺ����Ķ����ڱ���ļ���
extern  struct b rent[NUM];
//������д��ĳ��� 
#include<ctype.h>
int cmpname( const void *x ,const void *y)//�����������õ���, const�޶�һ�������������ı�,������̬����
{
	return  strcmp( (*(struct a *)x).name , (*(struct a *)y).name );// strcmp�Ƚ������ַ������ڷ�������С�ڷ��ظ���
}
int cmpheat( const void *x ,const void *y)//���ȶ������õ��� 
{
	return (*(struct a*)x).heat<(*(struct a*)y).heat?1:-1;
}
int cmpmark( const void *x ,const void *y)//�����������õ��� 
{
	return (*(struct a*)x).mark<(*(struct a*)y).mark?1:-1;
}
int checklegal(int n)//�������Ƿ�Ϸ������Ϸ���һֱ����������Ϸ�Ϊֹ 
{
    if(n>0&&n<8)
	{
		return 0;
    }  
    else
    {
    	system("cls");//���Ϸ��������ĻȻ�󷵻����˵� 
        printf("����������һ��1~6�����֣�\n");
    	return 1;
	}
}
int checkj(int n)
{
    if(n>0&&n<4)
        return 0;
    else
        printf("������һ��1~3�����֣�\n");
    return 1;
}
int checkchar(char ch)//����û����벻���� 
{
    if(ch == 'q'||ch == 'c')
        return 0;
    else
	{
		system("cls"); 
        printf("������c��������q�˳�\n");
    }
    return 1;
}
void makestd(char s[])//�Զ���makestd�������Ʊ�׼�� 
{
	int i,flag=1;
	
	for(i=0;s[i]!='\0';i++)
	{
		if(flag&&s[i]!='_')
		{
			s[i]=toupper(s[i]);//toupper�������ַ�ת��Ϊ��дӢ����ĸ 
			flag=0;
		}
		else s[i]=tolower(s[i]);//tolower �������ַ�ת����Сд��ĸ,����ĸ�ַ�����������
		if(s[i]=='_')
		flag=1;
	}
}
