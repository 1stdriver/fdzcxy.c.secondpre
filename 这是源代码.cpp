zheshi#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MEMBNUM 1000
#define BOOKNUM 1000
void major();//主菜单
void member();//用户选项
void book();//书籍选项
void datainput(char bookfile[20],char memberfile[20],char notreturnbookfile[20]);//从文件bookfile,memberfile,notreturnbookfile中分别读入图书信息，会员信息，未还图书信息
void dataquit(char bookfile[20],char memberfile[20],char notreturnbookfile[20]);//询问用户此次是否存入硬盘，退出程序
void datacontinue();//询问是否再次选择,y则fl2为1，n则fl2为0
void memberfun();//用户管理
void bookfun();//书籍管理
void notreturnbookfun();//未还图书函数
void addnewmember();//添加新用户
void memberinformation();//用户信息
void addnewbook();//添加新书籍
void issuebook();//借书
void delbook();//删除书籍
void searchbook();//查询书籍
void returnbook();//归还书籍
void librarian();
void gly();
int b,m,n;//b为图书册数量，m为用户人数，n为未还图书数量
int fl1=0,fl2=0;//两个标志变量
struct member//成员结构体
{
    int mid;//mid为已注册的用户数量
    char mname[10],madd[10];//成员的姓名、账号
}mem[MEMBNUM];//成员信息

struct book//书籍结构体
{
    int no;//书的编号
    char bname[20],author[20],isbn[20];//书的名称、作者、isbn码
    int x;//被借走的书x为0
}bk[BOOKNUM];//书籍信息

struct notreturnbook//未还图书结构体
{
    struct book nb;//图书信息
    struct member nm;//借书用户信息
}nrb[BOOKNUM];//未还图书信息
int main()
{
    char bookfile[]={"book"},memberfile[20]={"member"},notreturnbookfile[20]={"notreturnbook"};//给三个文件夹分别起名：书籍文件夹，用户文件夹，未还书文件夹
    int num;
    datainput(bookfile,memberfile,notreturnbookfile);
    while(!fl1)//当fl1为0时，循环封面
    {
        major();
        scanf("%d",&num);
        switch(num)
        {
            case 1 :
                memberfun();//用户管理
                break;
            case 2 :
                bookfun();//书籍管理
                break;
            case 3 :
            	librarian();//管理员模式 
            	break;
            case 4 :
                dataquit(bookfile,memberfile,notreturnbookfile);//数据保存磁盘并退出
                break;
            default:
                printf("选择错误，按任意键返回菜单！");
                getchar();
        }
    }
}
void datainput(char bookfile[20],char memberfile[20],char notreturnbookfile[20])//从文件bookfile,memberfile,notreturnbookfile中分别读入图书信息，会员信息，未还图书信息
{
    int i=0;
    FILE *fp;
    fp=fopen(bookfile,"a");
    if((fp=fopen(bookfile,"r"))==NULL)//如果指针为空的
    {
        printf("不能打开文件%s!",bookfile);
        exit(0);
    }
    while(!feof(fp))//当指针不为空时 
    {
        fread(&bk[i],sizeof(struct book),1,fp);//指针不为空时，持续读入书籍信息，一次读入一个书籍信息结构体
        i++;//每读入一个，i从0开始就加1
    }
    b=i-1;//用b来记录读入的书籍结构体个数
    fclose(fp);//关掉文件
    i=0;
    fp=fopen(memberfile,"a");
    if((fp=fopen(memberfile,"r"))==NULL)//如果指针为空的
    {
        printf("不能打开文件!%s",memberfile);
        exit(0);
    }
    while(!feof(fp))
    {
        fread(&mem[i],sizeof(struct member),1,fp);//指针不为空时，持续读入成员信息，一次读入一个成员信息结构体
        i++;
    }
    m=i-1;//用m来记录读入的成员结构体个数
    fclose(fp);

    i=0;
    fp=fopen(notreturnbookfile,"a");
    if((fp=fopen(notreturnbookfile,"r"))==NULL)//如果指针为空的
    {
        printf("不能打开文件!%s",notreturnbookfile);
        exit(0);
    }
    while(!feof(fp))
    {
        fread(&nrb[i],sizeof(struct notreturnbook),1,fp);//指针不为空时，持续读入未还书籍信息，一次读入一个未还书籍信息结构体
        i++;
    }
    n=i-1;//用n来记录读入的未还书籍结构体个数
    fclose(fp);
}

void major()
{
    system("cls");
    printf("*----------欢迎来到至诚学院图书管理系统----------*\n");
    printf("\n1-用户管理\n");
    printf("2-图书管理\n");
    printf("3-管理员登录\n");
    printf("4-退出\n\n\n");
    printf("\n\n请输入选项:\n");
}

void member()
{
    system("cls");
    printf("用户\n\n");
    printf("\n\n1-注册用户\n");
    printf("2-用户信息\n");
    printf("3-返回\n\n");
    printf("\n\n请输入选项:\n");
}

void book()
{
    system("cls");
    printf("图书\n\n");
    printf("\n\n1-借书\n");
    printf("2-还书\n");
    printf("3-查书\n");
    printf("4-返回\n");
    printf("\n\n请输入选项:\n");
}


void gly()
{
	system("cls");
	printf("\n\n1-添加新书籍\n");
	printf("2-查找用户\n");
	printf("3-查询书籍\n");
	printf("4-删除书籍\n");
	printf("5-未还书籍\n");
	printf("6-返回\n");
	printf("\n\n请输入选项:\n");
}
void memberfun()
{
    int num;
    fl2=0;
    while(!fl2)
    {
        member();//调用用户选项函数
        scanf("%d",&num);//让用户输入数字进行选择
        switch(num)
        {
            case 1:
                addnewmember();//调用增加新用户函数
                break;
            case 2:
                memberinformation();//调用用户信息函数
                break;
            case 3:
                fl2=1;//返回上一级
                break;
            default:
                printf("选择错误，按任意键返回菜单！");
                getchar();
        }
    }
}

void bookfun()
{
    int num;
    fl2=0;
    while(!fl2)//当fl2为0，进入循环
    {
        book();//调用书籍选项函数
        scanf("%d",&num);
        switch(num)//让用户输入数字进行选择
        {
            case 1:
                issuebook();//借书
                break;
            case 2:
                returnbook();//还书
                break;
            case 3:
                searchbook();//查询书籍
                break;
            case 4:
                fl2=1;//返回上一级
                break;
            default :
                printf("选择错误，按任意键返回菜单！");
                getchar();
        }
    }
}

void notreturnbookfun()
{
    char ch;
    int i;
    fl2=0;
    system("cls");//清屏
    printf("图书名称\n图书编号\n用户名称\n用户编号\n");//输入被借图书和借书用户的信息
    for(i=0;i<n;i++)
    {
        printf("%s \n %d \n\n %s \n\n %d \n\n",nrb[i].nb.bname,nrb[i].nb.no,nrb[i].nm.mname,nrb[i].nm.mid);
    }
    ch=getchar();
    printf("\n\n\n按'b'键返回上级菜单\n");
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
    while(fl2)//当fl2不为0时
    {
        printf("\n\n请输入新用户姓名:\n");
        scanf("%s",mem[m].mname);
        printf("\n请输入新用户的账号\n");
        scanf("%s",mem[m].madd);
        strcpy(just,mem[m].madd);//利用字符串just来记录刚刚创建的新用户的账号
        int i;
        for(i=0;i<m;i++)
        {
            if(strcmp(just,mem[i].madd)==0)//将just和之前的所有账号进行比较，看是否相同，如果相同...
            {
                same=1;
            }
        }
        if(same==1)
        {
            printf("\n注册失败,此账号已被注册!\n");//当same为1时，代表刚刚注册的账号已被注册过了
        }
        else if (same==0)
        {
            mem[m].mid=m+1;
            m++;//用户序号+1
            printf("\n注册成功，您的用户编号为%d\n\n",m);
        }
        ch=getchar();
        datacontinue();//y  fl2为1，x   fl2为0
    }
}

void memberinformation()
{
    char ch;
    int num,i;
    fl2=1;
    while(fl2)//当fl2不为0时
    {
        printf("请输入要查询的用户编号:\n");
        scanf("%d",&num);
        if(num>m||num==0)//如果输入的序号大于现有的序号量或输入的数为0
        {
            printf("该用户尚未存在!\n");
        }
        else
        {
            printf("用户名称:%s\t账号:%s\n", mem[num - 1].mname, mem[num - 1].madd);//输出被查找的用户信息（名称和账号）
            for (i = 0; i < n; i++)
            {
                if (nrb[i].nm.mid == num)//查看该用户是否有未归还书籍
                    printf("应还图书:&s\n", nrb[i].nb.bname);

            }
        }
        ch=getchar();
        datacontinue();//y  fl2为1，x   fl2为0
    }
}

void addnewbook()
{
    char ch;
    fl2=1;
    while(fl2)
    {
        printf("\n\n请输入新书的名称:\n");
        scanf("%s",bk[b].bname);
        printf("\n请输入新书的ISBN编号:\n");
        scanf("%s",bk[b].isbn);
        printf("\n请输入新书的作者:\n");
        scanf("%s",bk[b].author);
        printf("\n成功增添新书籍!\n");
        bk[b].no=b+1;
        printf("此书的编号为%d\n",bk[b].no);
        bk[b].x=1;//表示此书未被借走
        b++;//b加1来记录下一个新书的信息
        ch=getchar();
        datacontinue();//y  fl2为1，x   fl2为0
    }
}

void issuebook()//借书
{
    char ch,name[20];
    int num,i,z=0,y=0;
    fl2=1;
    while(fl2)//如果fl2不为0，进入借书循环
    {
        printf("\n请输入要借的书的名称:\n");
        scanf("%s",name);
        printf("\n请输入借书人的用户编号:\n");
        scanf("%d",&num);
        z=0;
        for(i=0;i<m;i++)
        {
            if(mem[i].mid==num)//检查是否有这个用户
            {
                nrb[n].nm=mem[i];//记录再尚未还书的结构体中
                z=1;//标志变量
            }
        }
        if(z==0)//如果z是0，就没有用户
        {
            printf("没有此用户!\n");
            ch=getchar();
            datacontinue();//y  fl2为1，x   fl2为0
            continue;
        }

        z=0;y=0;
        for(i=0;i<b;i++)
        {
            if(!strcmp(bk[i].bname,name)&&bk[i].x==1)//如果书库的书和被借的书名称一样该书已经被成功借走
            {
                nrb[n].nb=bk[i];//将被借的书的信息录入未还的书的结构体中
                z=1;//z=1代表借书成功
                bk[i].x=0;//被借走的书的x被赋值为0
                n++;//未还的书数量加1
                printf("\n成功借书!\n");
                printf("此书的编号为%d\n",bk[i].no);
            }
            else if(!strcmp(bk[i].bname,name)&&bk[i].x!=1)//如果被借的书和书库的书名称对不上并且书库里的那本书已被借走
            {
                printf("此书已借出!\n");
                ch=getchar();
                datacontinue();//y  fl2为1，n  fl2为0
                y=1;
                break;
            }
        }
        if(y==1)//书已经被借走时
            continue;//当书已经被借走时，进行下一次的借书循环
        if(z==0)//如果借书失败
        {
            printf("没有此书!\n");
            ch=getchar();
            datacontinue();//y  fl2为1；n  fl2为0
            continue;
        }
        ch=getchar();
        datacontinue();//y  fl2为1，n   fl2为0
    }
}

void returnbook()
{
    int num, i, temp = -1;
    char ch;
    fl2 = 1;
    while (fl2)//当fl2不为0时，进行还书循环
    {
        printf("请输入归还书的编号:\n");
        scanf("%d", &num);
        for (i = 0; i < n; i++)
        {
            if (nrb[i].nb.no == num) //遍历所有被借走的书的编号，看是否能对的上正在被归还的书
            {
                printf("归还图书的名称:%s\n", nrb[i].nb.bname);
                printf("读者姓名:%s\n", nrb[i].nm.mname);
                printf("还书成功!\n");
                temp = i;//temp赋值为此时被归还的书的编号
            }
        }

        if (temp != -1)//如果成功还书了
        {
            for (i = temp; i < n - 1; i++)
            {
                nrb[i] = nrb[i + 1];//=在被借走的书结构体中，通过后一个覆盖前一个将其归还的书删除掉
            }
            n--;//被借走没还的书减少一个
            for (i = 0; i < b; i++) //遍历所有图书的信息
            {
                if (bk[i].no == num) //如果某个书的编号和归还书的编号相等
                {
                    bk[i].x = 1;//这本书的x就赋值为1
                }
            }
        }
        else//如果没有成功归还
        {
            printf("这本书并未接触或图书库中没有此书!\n");
        }
        ch = getchar();
        datacontinue();//y  fl2为1，x   fl2为0
    }
}

void searchbook()//查询书籍
{
    int sq=0;
    int sw=0;
	int se=0;
    int n1,n2;
    int i;
    char ch;
    char boname[20];//要查询的书籍名称
    fl2=1;
    while(fl2)//当fl2不为0时，进行还书循环
    {
        printf("请输入您要查询的书籍名称:\n");
        scanf("%s",boname);
        for(i=0;i<b;i++)//遍历所有书籍
        {
            if(strcmp(bk[i].bname,boname) == 0 && bk[i].x == 0)//如果查到这本书并且这本书已经被借走了
            {
               sq=1;//sq为1代表查到这本书并且这本书已经被借走了
               n1=i;
            }
            else if(strcmp(bk[i].bname,boname) == 0 && bk[i].x == 1)//如果查到这本书并且没被借走
            {
                sw=1;//sw为1代表查到这本书并且没被借走
                n2=i;
            }
            else if(strcmp(bk[i].bname,boname)!=0)//如果查不到这本书 
            {
                se=1;//se为1代表图书换内没有这本书
            }
        }
        if(sq==1)
        {
            printf("书籍名称:%s\n书籍编号:%d\n",bk[n1].bname,bk[n1].no);
            printf("此书已借走\n");
        }
        if(sw==1)
        {
            printf("书籍名称:\n书籍编号:\n");
            printf("%s\n%d\n",bk[n2].bname,bk[n2].no);
            printf("此书尚存馆内\n");
        }
        if(se==1)
        {
            printf("馆内尚无此书或被删除!\n");
        }
        if(b==0)
        {
        	printf("图书馆内还没有书籍!\n");
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
    	printf("图书馆内还没有书籍!\n");
	}
	else
	{
	    printf("请输入您要删除的书籍编号:\n");
    scanf("%d",&num);
    for(i=num;i<=b;i++)
    {
        bk[i]=bk[i+1];//将后一个书籍结构体的信息覆盖掉前一个书籍结构体的信息
    }

    b--;
    printf("删除成功!\n");
	}//删除完书籍之后，书籍总数减少1,也就是把最后一个重复的书籍结构体删掉
    ch=getchar();
    datacontinue();
}

void dataquit(char bookfile[20],char memberfile[20],char notreturnbookfile[20])
{
    int i;
    FILE *fp;
    char ch;
    ch=getchar();
    printf("是否将这次使用记录保存到库中?(y/n)\n");
    ch=getchar();
    if(ch=='Y'||ch=='y')
    {
        if((fp=fopen(bookfile,"w"))==NULL)
        {
            printf("不能打开文件%s!\n",bookfile);
            exit(0);
        }
        for(i=0;i<b;i++)
            fwrite(&bk[i],sizeof(struct book),1,fp);
        fclose(fp);
        if((fp=fopen(memberfile,"w"))==NULL)
        {
            printf("不能打开文件%s!\n",memberfile);
            exit(0);
        }
        for(i=0;i<m;i++)
            fwrite(&mem[i],sizeof(struct member),1,fp);
        fclose(fp);
        if((fp=fopen(notreturnbookfile,"w"))==NULL)
        {
            printf("不能打开文件%s!\n",notreturnbookfile);
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
	printf("*=========管理员系统=========*");
	char admin[10]={"gly"},password[10]={"gly"},admin1[10],password1[10];
	printf("\n\n请输入账号:\n");
	scanf("%s",admin1);
	if(strcmp(admin,admin1)==0)
	{
		printf("\n请输入密码:\n");
		scanf("%s",password1);
		if (strcmp(password,password1)==0)
			    {
				printf("登录成功\n");
				}
		else printf("登录失败\n");
	}
	else printf("账号错误");
	while(fl2==0)//当fl2为0时,进行循环 
	{
	gly();//管理员菜单 
	scanf("%d",&num);
	switch(num)//让用户输入数字进行选择
	        {
	            case 1 :
	                addnewbook();//添加新书
	                break;
	            case 2 :
	                memberinformation();//调用用户信息
	                break;
	            case 3 :
	                searchbook();//查询书籍
	                break;
	            case 4 :
	                delbook();//删除书籍 
	                break;
	            case 5 :
	            	notreturnbookfun();//所有未还的书籍 
	            	break;
	            case 6 :
	                fl2=1;//返回上一级
	                break;
	            default :
	                printf("选择错误，按任意键返回菜单！");
	                getchar();
	        }
	    }
}


void datacontinue()
{
    char ch;
    printf("是否再次进行该行为?(y/n)\n");
    ch=getchar();
    if(ch=='Y'||ch=='y')
        fl2=1;
    else
        fl2=0;
}

