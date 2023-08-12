#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MEMBNUM 1000
#define BOOKNUM 1000
void major();//���˵�
void member();//�û�ѡ��
void book();//�鼮ѡ��
void datainput(char bookfile[20],char memberfile[20],char notreturnbookfile[20]);//���ļ�bookfile,memberfile,notreturnbookfile�зֱ����ͼ����Ϣ����Ա��Ϣ��δ��ͼ����Ϣ
void dataquit(char bookfile[20],char memberfile[20],char notreturnbookfile[20]);//ѯ���û��˴��Ƿ����Ӳ�̣��˳�����
void datacontinue();//ѯ���Ƿ��ٴ�ѡ��,y��fl2Ϊ1��n��fl2Ϊ0
void memberfun();//�û�����
void bookfun();//�鼮����
void notreturnbookfun();//δ��ͼ�麯��
void addnewmember();//������û�
void memberinformation();//�û���Ϣ
void addnewbook();//������鼮
void issuebook();//����
void delbook();//ɾ���鼮
void searchbook();//��ѯ�鼮
void returnbook();//�黹�鼮
void librarian();
void gly();
int b,m,n;//bΪͼ���������mΪ�û�������nΪδ��ͼ������
int fl1=0,fl2=0;//������־����
struct member//��Ա�ṹ��
{
    int mid;//midΪ��ע����û�����
    char mname[10],madd[10];//��Ա���������˺�
}mem[MEMBNUM];//��Ա��Ϣ

struct book//�鼮�ṹ��
{
    int no;//��ı��
    char bname[20],author[20],isbn[20];//������ơ����ߡ�isbn��
    int x;//�����ߵ���xΪ0
}bk[BOOKNUM];//�鼮��Ϣ

struct notreturnbook//δ��ͼ��ṹ��
{
    struct book nb;//ͼ����Ϣ
    struct member nm;//�����û���Ϣ
}nrb[BOOKNUM];//δ��ͼ����Ϣ
int main()
{
    char bookfile[]={"book"},memberfile[20]={"member"},notreturnbookfile[20]={"notreturnbook"};//�������ļ��зֱ��������鼮�ļ��У��û��ļ��У�δ�����ļ���
    int num;
    datainput(bookfile,memberfile,notreturnbookfile);
    while(!fl1)//��fl1Ϊ0ʱ��ѭ������
    {
        major();
        scanf("%d",&num);
        switch(num)
        {
            case 1 :
                memberfun();//�û�����
                break;
            case 2 :
                bookfun();//�鼮����
                break;
            case 3 :
            	librarian();//����Աģʽ 
            	break;
            case 4 :
                dataquit(bookfile,memberfile,notreturnbookfile);//���ݱ�����̲��˳�
                break;
            default:
                printf("ѡ����󣬰���������ز˵���");
                getchar();
        }
    }
}
void datainput(char bookfile[20],char memberfile[20],char notreturnbookfile[20])//���ļ�bookfile,memberfile,notreturnbookfile�зֱ����ͼ����Ϣ����Ա��Ϣ��δ��ͼ����Ϣ
{
    int i=0;
    FILE *fp;
    fp=fopen(bookfile,"a");
    if((fp=fopen(bookfile,"r"))==NULL)//���ָ��Ϊ�յ�
    {
        printf("���ܴ��ļ�%s!",bookfile);
        exit(0);
    }
    while(!feof(fp))//��ָ�벻Ϊ��ʱ 
    {
        fread(&bk[i],sizeof(struct book),1,fp);//ָ�벻Ϊ��ʱ�����������鼮��Ϣ��һ�ζ���һ���鼮��Ϣ�ṹ��
        i++;//ÿ����һ����i��0��ʼ�ͼ�1
    }
    b=i-1;//��b����¼������鼮�ṹ�����
    fclose(fp);//�ص��ļ�
    i=0;
    fp=fopen(memberfile,"a");
    if((fp=fopen(memberfile,"r"))==NULL)//���ָ��Ϊ�յ�
    {
        printf("���ܴ��ļ�!%s",memberfile);
        exit(0);
    }
    while(!feof(fp))
    {
        fread(&mem[i],sizeof(struct member),1,fp);//ָ�벻Ϊ��ʱ�����������Ա��Ϣ��һ�ζ���һ����Ա��Ϣ�ṹ��
        i++;
    }
    m=i-1;//��m����¼����ĳ�Ա�ṹ�����
    fclose(fp);

    i=0;
    fp=fopen(notreturnbookfile,"a");
    if((fp=fopen(notreturnbookfile,"r"))==NULL)//���ָ��Ϊ�յ�
    {
        printf("���ܴ��ļ�!%s",notreturnbookfile);
        exit(0);
    }
    while(!feof(fp))
    {
        fread(&nrb[i],sizeof(struct notreturnbook),1,fp);//ָ�벻Ϊ��ʱ����������δ���鼮��Ϣ��һ�ζ���һ��δ���鼮��Ϣ�ṹ��
        i++;
    }
    n=i-1;//��n����¼�����δ���鼮�ṹ�����
    fclose(fp);
}

void major()
{
    system("cls");
    printf("*----------��ӭ��������ѧԺͼ�����ϵͳ----------*\n");
    printf("\n1-�û�����\n");
    printf("2-ͼ�����\n");
    printf("3-����Ա��¼\n");
    printf("4-�˳�\n\n\n");
    printf("\n\n������ѡ��:\n");
}

void member()
{
    system("cls");
    printf("�û�\n\n");
    printf("\n\n1-ע���û�\n");
    printf("2-�û���Ϣ\n");
    printf("3-����\n\n");
    printf("\n\n������ѡ��:\n");
}

void book()
{
    system("cls");
    printf("ͼ��\n\n");
    printf("\n\n1-����\n");
    printf("2-����\n");
    printf("3-����\n");
    printf("4-����\n");
    printf("\n\n������ѡ��:\n");
}


void gly()
{
	system("cls");
	printf("\n\n1-������鼮\n");
	printf("2-�����û�\n");
	printf("3-��ѯ�鼮\n");
	printf("4-ɾ���鼮\n");
	printf("5-δ���鼮\n");
	printf("6-����\n");
	printf("\n\n������ѡ��:\n");
}
void memberfun()
{
    int num;
    fl2=0;
    while(!fl2)
    {
        member();//�����û�ѡ���
        scanf("%d",&num);//���û��������ֽ���ѡ��
        switch(num)
        {
            case 1:
                addnewmember();//�����������û�����
                break;
            case 2:
                memberinformation();//�����û���Ϣ����
                break;
            case 3:
                fl2=1;//������һ��
                break;
            default:
                printf("ѡ����󣬰���������ز˵���");
                getchar();
        }
    }
}

void bookfun()
{
    int num;
    fl2=0;
    while(!fl2)//��fl2Ϊ0������ѭ��
    {
        book();//�����鼮ѡ���
        scanf("%d",&num);
        switch(num)//���û��������ֽ���ѡ��
        {
            case 1:
                issuebook();//����
                break;
            case 2:
                returnbook();//����
                break;
            case 3:
                searchbook();//��ѯ�鼮
                break;
            case 4:
                fl2=1;//������һ��
                break;
            default :
                printf("ѡ����󣬰���������ز˵���");
                getchar();
        }
    }
}

void notreturnbookfun()
{
    char ch;
    int i;
    fl2=0;
    system("cls");//����
    printf("ͼ������\nͼ����\n�û�����\n�û����\n");//���뱻��ͼ��ͽ����û�����Ϣ
    for(i=0;i<n;i++)
    {
        printf("%s \n %d \n\n %s \n\n %d \n\n",nrb[i].nb.bname,nrb[i].nb.no,nrb[i].nm.mname,nrb[i].nm.mid);
    }
    ch=getchar();
    printf("\n\n\n��'b'�������ϼ��˵�\n");
    while(!fl2)
    {
        ch=getchar();
        if(ch=='b'||ch=='B')
            fl2=1;
    }
}

void addnewmember()
{
    char ch;
    int same=0;
    fl2=1;
    char just[20];
    while(fl2)//��fl2��Ϊ0ʱ
    {
        printf("\n\n���������û�����:\n");
        scanf("%s",mem[m].mname);
        printf("\n���������û����˺�\n");
        scanf("%s",mem[m].madd);
        strcpy(just,mem[m].madd);//�����ַ���just����¼�ոմ��������û����˺�
        int i;
        for(i=0;i<m;i++)
        {
            if(strcmp(just,mem[i].madd)==0)//��just��֮ǰ�������˺Ž��бȽϣ����Ƿ���ͬ�������ͬ...
            {
                same=1;
            }
        }
        if(same==1)
        {
            printf("\nע��ʧ��,���˺��ѱ�ע��!\n");//��sameΪ1ʱ������ո�ע����˺��ѱ�ע�����
        }
        else if (same==0)
        {
            mem[m].mid=m+1;
            m++;//�û����+1
            printf("\nע��ɹ��������û����Ϊ%d\n\n",m);
        }
        ch=getchar();
        datacontinue();//y  fl2Ϊ1��x   fl2Ϊ0
    }
}

void memberinformation()
{
    char ch;
    int num,i;
    fl2=1;
    while(fl2)//��fl2��Ϊ0ʱ
    {
        printf("������Ҫ��ѯ���û����:\n");
        scanf("%d",&num);
        if(num>m||num==0)//����������Ŵ������е���������������Ϊ0
        {
            printf("���û���δ����!\n");
        }
        else
        {
            printf("�û�����:%s\t�˺�:%s\n", mem[num - 1].mname, mem[num - 1].madd);//��������ҵ��û���Ϣ�����ƺ��˺ţ�
            for (i = 0; i < n; i++)
            {
                if (nrb[i].nm.mid == num)//�鿴���û��Ƿ���δ�黹�鼮
                    printf("Ӧ��ͼ��:&s\n", nrb[i].nb.bname);

            }
        }
        ch=getchar();
        datacontinue();//y  fl2Ϊ1��x   fl2Ϊ0
    }
}

void addnewbook()
{
    char ch;
    fl2=1;
    while(fl2)
    {
        printf("\n\n���������������:\n");
        scanf("%s",bk[b].bname);
        printf("\n�����������ISBN���:\n");
        scanf("%s",bk[b].isbn);
        printf("\n���������������:\n");
        scanf("%s",bk[b].author);
        printf("\n�ɹ��������鼮!\n");
        bk[b].no=b+1;
        printf("����ı��Ϊ%d\n",bk[b].no);
        bk[b].x=1;//��ʾ����δ������
        b++;//b��1����¼��һ���������Ϣ
        ch=getchar();
        datacontinue();//y  fl2Ϊ1��x   fl2Ϊ0
    }
}

void issuebook()//����
{
    char ch,name[20];
    int num,i,z=0,y=0;
    fl2=1;
    while(fl2)//���fl2��Ϊ0���������ѭ��
    {
        printf("\n������Ҫ����������:\n");
        scanf("%s",name);
        printf("\n����������˵��û����:\n");
        scanf("%d",&num);
        z=0;
        for(i=0;i<m;i++)
        {
            if(mem[i].mid==num)//����Ƿ�������û�
            {
                nrb[n].nm=mem[i];//��¼����δ����Ľṹ����
                z=1;//��־����
            }
        }
        if(z==0)//���z��0����û���û�
        {
            printf("û�д��û�!\n");
            ch=getchar();
            datacontinue();//y  fl2Ϊ1��x   fl2Ϊ0
            continue;
        }

        z=0;y=0;
        for(i=0;i<b;i++)
        {
            if(!strcmp(bk[i].bname,name)&&bk[i].x==1)//���������ͱ����������һ�������Ѿ����ɹ�����
            {
                nrb[n].nb=bk[i];//������������Ϣ¼��δ������Ľṹ����
                z=1;//z=1�������ɹ�
                bk[i].x=0;//�����ߵ����x����ֵΪ0
                n++;//δ������������1
                printf("\n�ɹ�����!\n");
                printf("����ı��Ϊ%d\n",bk[i].no);
            }
            else if(!strcmp(bk[i].bname,name)&&bk[i].x!=1)//��������������������ƶԲ��ϲ����������Ǳ����ѱ�����
            {
                printf("�����ѽ��!\n");
                ch=getchar();
                datacontinue();//y  fl2Ϊ1��n  fl2Ϊ0
                y=1;
                break;
            }
        }
        if(y==1)//���Ѿ�������ʱ
            continue;//�����Ѿ�������ʱ��������һ�εĽ���ѭ��
        if(z==0)//�������ʧ��
        {
            printf("û�д���!\n");
            ch=getchar();
            datacontinue();//y  fl2Ϊ1��n  fl2Ϊ0
            continue;
        }
        ch=getchar();
        datacontinue();//y  fl2Ϊ1��n   fl2Ϊ0
    }
}

void returnbook()
{
    int num, i, temp = -1;
    char ch;
    fl2 = 1;
    while (fl2)//��fl2��Ϊ0ʱ�����л���ѭ��
    {
        printf("������黹��ı��:\n");
        scanf("%d", &num);
        for (i = 0; i < n; i++)
        {
            if (nrb[i].nb.no == num) //�������б����ߵ���ı�ţ����Ƿ��ܶԵ������ڱ��黹����
            {
                printf("�黹ͼ�������:%s\n", nrb[i].nb.bname);
                printf("��������:%s\n", nrb[i].nm.mname);
                printf("����ɹ�!\n");
                temp = i;//temp��ֵΪ��ʱ���黹����ı��
            }
        }

        if (temp != -1)//����ɹ�������
        {
            for (i = temp; i < n - 1; i++)
            {
                nrb[i] = nrb[i + 1];//=�ڱ����ߵ���ṹ���У�ͨ����һ������ǰһ������黹����ɾ����
            }
            n--;//������û���������һ��
            for (i = 0; i < b; i++) //��������ͼ�����Ϣ
            {
                if (bk[i].no == num) //���ĳ����ı�ź͹黹��ı�����
                {
                    bk[i].x = 1;//�Ȿ���x�͸�ֵΪ1
                }
            }
        }
        else//���û�гɹ��黹
        {
            printf("�Ȿ�鲢δ�Ӵ���ͼ�����û�д���!\n");
        }
        ch = getchar();
        datacontinue();//y  fl2Ϊ1��x   fl2Ϊ0
    }
}

void searchbook()//��ѯ�鼮
{
    int sq=0;
    int sw=0;
	int se=0;
    int n1,n2;
    int i;
    char ch;
    char boname[20];//Ҫ��ѯ���鼮����
    fl2=1;
    while(fl2)//��fl2��Ϊ0ʱ�����л���ѭ��
    {
        printf("��������Ҫ��ѯ���鼮����:\n");
        scanf("%s",boname);
        for(i=0;i<b;i++)//���������鼮
        {
            if(strcmp(bk[i].bname,boname) == 0 && bk[i].x == 0)//����鵽�Ȿ�鲢���Ȿ���Ѿ���������
            {
               sq=1;//sqΪ1����鵽�Ȿ�鲢���Ȿ���Ѿ���������
               n1=i;
            }
            else if(strcmp(bk[i].bname,boname) == 0 && bk[i].x == 1)//����鵽�Ȿ�鲢��û������
            {
                sw=1;//swΪ1����鵽�Ȿ�鲢��û������
                n2=i;
            }
            else if(strcmp(bk[i].bname,boname)!=0)//����鲻���Ȿ�� 
            {
                se=1;//seΪ1����ͼ�黻��û���Ȿ��
            }
        }
        if(sq==1)
        {
            printf("�鼮����:%s\n�鼮���:%d\n",bk[n1].bname,bk[n1].no);
            printf("�����ѽ���\n");
        }
        if(sw==1)
        {
            printf("�鼮����:\n�鼮���:\n");
            printf("%s\n%d\n",bk[n2].bname,bk[n2].no);
            printf("�����д����\n");
        }
        if(se==1)
        {
            printf("�������޴����ɾ��!\n");
        }
        if(b==0)
        {
        	printf("ͼ����ڻ�û���鼮!\n");
		}
        ch=getchar();
        datacontinue();
    }
}


void delbook()
{
    char ch;
    int num;
    int i;
    if(b==0)
    {
    	printf("ͼ����ڻ�û���鼮!\n");
	}
	else
	{
	    printf("��������Ҫɾ�����鼮���:\n");
    scanf("%d",&num);
    for(i=num;i<=b;i++)
    {
        bk[i]=bk[i+1];//����һ���鼮�ṹ�����Ϣ���ǵ�ǰһ���鼮�ṹ�����Ϣ
    }

    b--;
    printf("ɾ���ɹ�!\n");
	}//ɾ�����鼮֮���鼮��������1,Ҳ���ǰ����һ���ظ����鼮�ṹ��ɾ��
    ch=getchar();
    datacontinue();
}

void dataquit(char bookfile[20],char memberfile[20],char notreturnbookfile[20])
{
    int i;
    FILE *fp;
    char ch;
    ch=getchar();
    printf("�Ƿ����ʹ�ü�¼���浽����?(y/n)\n");
    ch=getchar();
    if(ch=='Y'||ch=='y')
    {
        if((fp=fopen(bookfile,"w"))==NULL)
        {
            printf("���ܴ��ļ�%s!\n",bookfile);
            exit(0);
        }
        for(i=0;i<b;i++)
            fwrite(&bk[i],sizeof(struct book),1,fp);
        fclose(fp);
        if((fp=fopen(memberfile,"w"))==NULL)
        {
            printf("���ܴ��ļ�%s!\n",memberfile);
            exit(0);
        }
        for(i=0;i<m;i++)
            fwrite(&mem[i],sizeof(struct member),1,fp);
        fclose(fp);
        if((fp=fopen(notreturnbookfile,"w"))==NULL)
        {
            printf("���ܴ��ļ�%s!\n",notreturnbookfile);
            exit(0);
        }
        for(i=0;i<n;i++)
            fwrite(&nrb[i],sizeof(struct notreturnbook),1,fp);
        fclose(fp);
    }
    fl1=1;
}


void librarian()
{
	fl2=0;
	int num;
	printf("*=========����Աϵͳ=========*");
	char admin[10]={"gly"},password[10]={"gly"},admin1[10],password1[10];
	printf("\n\n�������˺�:\n");
	scanf("%s",admin1);
	if(strcmp(admin,admin1)==0)
	{
		printf("\n����������:\n");
		scanf("%s",password1);
		if (strcmp(password,password1)==0)
			    {
				printf("��¼�ɹ�\n");
				}
		else printf("��¼ʧ��\n");
	}
	else printf("�˺Ŵ���");
	while(fl2==0)//��fl2Ϊ0ʱ,����ѭ�� 
	{
	gly();//����Ա�˵� 
	scanf("%d",&num);
	switch(num)//���û��������ֽ���ѡ��
	        {
	            case 1 :
	                addnewbook();//�������
	                break;
	            case 2 :
	                memberinformation();//�����û���Ϣ
	                break;
	            case 3 :
	                searchbook();//��ѯ�鼮
	                break;
	            case 4 :
	                delbook();//ɾ���鼮 
	                break;
	            case 5 :
	            	notreturnbookfun();//����δ�����鼮 
	            	break;
	            case 6 :
	                fl2=1;//������һ��
	                break;
	            default :
	                printf("ѡ����󣬰���������ز˵���");
	                getchar();
	        }
	    }
}


void datacontinue()
{
    char ch;
    printf("�Ƿ��ٴν��и���Ϊ?(y/n)\n");
    ch=getchar();
    if(ch=='Y'||ch=='y')
        fl2=1;
    else
        fl2=0;
}

