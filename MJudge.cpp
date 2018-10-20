#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<conio.h>
#include<unistd.h>
#define _ver_ printf("欢迎使用 MJudge\n\n");
#define _help_ help();
FILE *fauto;
char s[100000],find1[100000],find2[100000],s1[100000],c[100000],comp[100000],comp1[100000],cmd[100000];
void help()
{
	printf("*****Linux版本*****\n\n");
	printf("——请在使用本程序之前安装好g++！\n");
	printf("——请将标准输入输出文件*.in和*.out放在本目录下的data文件夹\n");
	printf("——请将文件名改为(string)number的名字\n");
	printf("——其中string为主文件名可自行定义，而number请根据1,2,3...格式输入\n");
	printf("——本程序会读取所有的(string)number文件\n");
	printf("——请不要使用文件输入输出，将在后面版本支持文件输入输出！\n");
}
void tozero(char *s)
{
	memset(s,0,sizeof s);
}
void normalmode()
{
	printf("\n~~~~请首先输入文件的主文件名(string)：");
	while(1)
	{
		fflush(stdin);
		tozero(s);
		tozero(find1);
		tozero(find2);
		scanf("%s",s);
		sprintf(find1,".\\data\\%s1.in",s);
		sprintf(find2,".\\data\\%s1.out",s);
		if(fopen(find1,"r")==NULL||fopen(find2,"r")==NULL)
		{
			printf("输入输出文件错误\n文件的格式和路径是否在当前目录的data文件夹中，请重新输入：");
			continue;
		}
		fprintf(fauto,"inoutfile:%s\n",s);
		break;
	}
	printf("\n~~~~请将评测的程序放在当前目录下，然后请输入名称：");
	while(1)
	{
		fflush(stdin);
		tozero(s1);
		tozero(find1);
		scanf("%s",s1);
		sprintf(find1,"%s.cpp",s1);
		if(fopen(find1,"r")==NULL)
		{
			printf("没有找到程序！\n请重新输入：");
			continue;
		}
		fprintf(fauto,"cppfile:%s",s1);
		tozero(c);
		sprintf(c,".\\bin\\bin\\g++ -o .\\temp\\judge.exe %s",find1);
		freopen("MJudge_编译错误和警告.txt","w",stderr);
		system(c);
		fclose(stderr);
		if(fopen(".\\temp\\judge.exe","r")==NULL)
		{
			printf("编译错误！请查看MJudge_编译错误和警告.txt的信息更改程序！");
			printf("请按任意键退出...");
			getch();
			exit(-1);
		}
		break;
	}
}
void datmode()
{
	tozero(s);
	tozero(s1);
	tozero(find1);
	tozero(find2);
	fscanf(fauto,"inoutfile:%s\ncppfile:%s",s,s1);
	sprintf(find1,".\\data\\%s1.in",s);
	sprintf(find2,".\\data\\%s1.out",s);
	if(fopen(find1,"r")==NULL||fopen(find2,"r")==NULL)
	{
		printf("自动配置文件中设置：输入输出文件错误\n文件的格式和路径是否在当前目录的data文件夹中。");
		printf("请按任意键退出...");
		getch();
		exit(-1);
	}
	tozero(find1);
	sprintf(find1,"%s.cpp",s1);
	if(fopen(find1,"r")==NULL)
	{
		printf("自动配置文件中设置：没有找到程序\n");
		printf("请按任意键退出...");
		getch();
		exit(-1);
	}
	tozero(c);
	sprintf(c,".\\bin\\bin\\g++ -o .\\temp\\judge.exe %s",find1);
	freopen("MJudge_编译错误和警告.txt","w",stderr);
	system(c);
	fclose(stderr);
	if(fopen(".\\temp\\judge.exe","r")==NULL)
	{
		printf("自动配置文件中设置：编译错误！请查看MJudge_编译错误和警告.txt的信息更改程序！");
		printf("请按任意键退出...");
		getch();
		exit(-1);
	}
}
void complier()
{
	fflush(stdin);
	printf("\n~~~~准备就绪，请按任意键开始评测...");
	getch();
	printf("\n\n");
	int i=1,_true=0;
	FILE* fp;
	fp=fopen("MJudge_评测结果.txt","w+");
	while(1)
	{
		memset(comp,0,sizeof comp);
		memset(comp1,0,sizeof comp1);
		sprintf(comp,".\\data\\%s%d.in",s,i);
		sprintf(comp1,".\\data\\%s%d.out",s,i);
		FILE *fcomp,*fcomp1;
		fcomp=fopen(comp,"r");
		fcomp1=fopen(comp1,"r");
		if(fcomp==NULL||fcomp1==NULL)
		{
			fclose(fauto);
			remove(".\\temp\\judge.exe");
			rmdir("temp");
			fprintf(fp,"\n\n正确[%d/%d]",_true,i-1);
			fclose(fp);
			fflush(stdin);
			fclose(stderr);
			printf("\n评测结束！正确[%d/%d]！结果存在MJudge_评测结果.txt中！\n",_true,i-1);
			printf("请按任意键退出...");
			getch();
			exit(0);
		}
		memset(cmd,0,sizeof cmd);
		sprintf(cmd,".\\temp\\judge.exe < %s > .\\temp\\output.out",comp);
		clock_t start,end;
		start=clock();
		system(cmd);
		end=clock();
		char *diff;
		diff=new char[100000];
		sprintf(diff,"diff %s .\\temp\\output.out > nul",comp1);
		int result=system(diff);
		delete diff;
		if(result==0)
		{
			printf("第%d个测试点正确 时间：%0.2lfs\n",i,(double)(end-start)/CLOCKS_PER_SEC);
			fprintf(fp,"%d:√ 时间：%0.2lfs\n",i,(double)(end-start)/CLOCKS_PER_SEC);
			_true++;
		}
		else
		{
			printf("第%d个测试点错误 时间：%0.2fs\n",i,(double)(end-start)/CLOCKS_PER_SEC);
			fprintf(fp,"%d:× 时间：%0.2fs\n",i,(double)(end-start)/CLOCKS_PER_SEC);
			fprintf(fp,"标准输出：\n********\n");
			char f;
			while(fscanf(fcomp1,"%c",&f)!=EOF)
				fprintf(fp,"%c",f);
			fprintf(fp,"\n********\n程序输出：\n********\n");
			FILE *ff=fopen(".\\temp\\output.out","r");
			while(fscanf(ff,"%c",&f)!=EOF)
				fprintf(fp,"%c",f);
			fclose(ff);
			fprintf(fp,"\n********\n");
		}
		fclose(fcomp);
		fclose(fcomp1);
		remove(".\\temp\\output.out");
		i++;
	}
}
int main()
{
	mkdir("temp");
	remove(".\\temp\\judge.exe");
	_ver_
	_help_
	fauto=fopen("MJudge_自动配置文件.txt","r");
	if(fauto==NULL)
	{
		fauto=fopen("MJudge_自动配置文件.txt","w+");
		normalmode();
	}
	else
	{
		printf("\n~~~~发现自动配置文件，是否加载[y/n]:");
		while(1)
		{
			char inp=getch();
			printf("\n");
			if(inp=='Y'||inp=='y')
				datmode();
			else if(inp=='N'||inp=='n')
			{
				fclose(fauto);
				fauto=fopen("MJudge_自动配置文件.txt","w+");
				normalmode();
			}
			else
			{
				printf("输入错误，请重新输入[y/n]：");
				continue;
			}
			break;
		}
	}
	complier();
}
