#define	ROAD "C:\\Users\\Zhuo\\Desktop\\11_28_����\\disks.txt"
#define LEN 20
#define NUM 100
//main
void list(void);//list��ʾѡ�������Ϣ 
int choice(int i);//����������ж� 
int read(int i);//���ļ�,�����������д���ṹ������disk�� 
void write(int i);//��������н��д�ص��ļ��� 
//���Һ���ʾ
void chazhao(int n);//Ѱ��Ӱ�� 
void show(int n);
//help�������ļ�
int cmpname( const void *a ,const void *b);//����������Ƚ� 
int cmpheat( const void *a ,const void *b);//���ȶ�����Ƚ� 
int cmpmark( const void *a ,const void *b);//����������Ƚ� 
int checklegal(int n);//�ж������Ƿ�Ϸ� 
int checkj(int n);//����Ƿ�Ϊ1-3������ʽһ�� 
int checkchar(char ch);
void makestd(char s[]);//�Զ���makestd�������Ʊ�׼�� 
//���ĺ͹黹
int jie(int n,int k);//���Ƭ�ĺ��� 
void guihuan(int n,int k);//����Ƭ 
int countday(int i);//�������� 
int leap(int year);//�������� 
int dayth(int y,int m,int d);//����ڼ��� 
//���ɾ�� 
void add(int n);//����µĵ�Ƭ 
int delet(int n);//ɾ����Ƭ 

struct a //�ṹ��a��Ӱ��������Ϣ 
{
    char name[LEN];//ӰƬ������
    char nation[LEN];//��Ƭ�Ĺ���
    char type[LEN];//ӰƬ������
    
    int flag;//�Ƿ�ɽ���ĵı�־��1Ϊ�ɽ裬0Ϊ���ɽ�
    int heat;//ӰƬ���ȶȣ������Ĵ���
    
	double mark;//�û����ⲿӰƬ������
};
struct b 
{
    char memname[LEN];//ӰƬ������
    char disname[LEN];//��Ա������
    
	int botime[3];//�����ʱ��
    int retime[3];//�黹��ʱ��
    int money;//�˴ε����
};
