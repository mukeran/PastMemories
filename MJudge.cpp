#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<conio.h>
#include<unistd.h>
#define _ver_ printf("��ӭʹ�� MJudge\n\n");
#define _help_ help();
FILE *fauto;
char s[100000],find1[100000],find2[100000],s1[100000],c[100000],comp[100000],comp1[100000],cmd[100000];
void help()
{
	printf("*****Linux�汾*****\n\n");
	printf("��������ʹ�ñ�����֮ǰ��װ��g++��\n");
	printf("�����뽫��׼��������ļ�*.in��*.out���ڱ�Ŀ¼�µ�data�ļ���\n");
	printf("�����뽫�ļ�����Ϊ(string)number������\n");
	printf("��������stringΪ���ļ��������ж��壬��number�����1,2,3...��ʽ����\n");
	printf("������������ȡ���е�(string)number�ļ�\n");
	printf("�����벻Ҫʹ���ļ�������������ں���汾֧���ļ����������\n");
}
void tozero(char *s)
{
	memset(s,0,sizeof s);
}
void normalmode()
{
	printf("\n~~~~�����������ļ������ļ���(string)��");
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
			printf("��������ļ�����\n�ļ��ĸ�ʽ��·���Ƿ��ڵ�ǰĿ¼��data�ļ����У����������룺");
			continue;
		}
		fprintf(fauto,"inoutfile:%s\n",s);
		break;
	}
	printf("\n~~~~�뽫����ĳ�����ڵ�ǰĿ¼�£�Ȼ�����������ƣ�");
	while(1)
	{
		fflush(stdin);
		tozero(s1);
		tozero(find1);
		scanf("%s",s1);
		sprintf(find1,"%s.cpp",s1);
		if(fopen(find1,"r")==NULL)
		{
			printf("û���ҵ�����\n���������룺");
			continue;
		}
		fprintf(fauto,"cppfile:%s",s1);
		tozero(c);
		sprintf(c,".\\bin\\bin\\g++ -o .\\temp\\judge.exe %s",find1);
		freopen("MJudge_�������;���.txt","w",stderr);
		system(c);
		fclose(stderr);
		if(fopen(".\\temp\\judge.exe","r")==NULL)
		{
			printf("���������鿴MJudge_�������;���.txt����Ϣ���ĳ���");
			printf("�밴������˳�...");
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
		printf("�Զ������ļ������ã���������ļ�����\n�ļ��ĸ�ʽ��·���Ƿ��ڵ�ǰĿ¼��data�ļ����С�");
		printf("�밴������˳�...");
		getch();
		exit(-1);
	}
	tozero(find1);
	sprintf(find1,"%s.cpp",s1);
	if(fopen(find1,"r")==NULL)
	{
		printf("�Զ������ļ������ã�û���ҵ�����\n");
		printf("�밴������˳�...");
		getch();
		exit(-1);
	}
	tozero(c);
	sprintf(c,".\\bin\\bin\\g++ -o .\\temp\\judge.exe %s",find1);
	freopen("MJudge_�������;���.txt","w",stderr);
	system(c);
	fclose(stderr);
	if(fopen(".\\temp\\judge.exe","r")==NULL)
	{
		printf("�Զ������ļ������ã����������鿴MJudge_�������;���.txt����Ϣ���ĳ���");
		printf("�밴������˳�...");
		getch();
		exit(-1);
	}
}
void complier()
{
	fflush(stdin);
	printf("\n~~~~׼���������밴�������ʼ����...");
	getch();
	printf("\n\n");
	int i=1,_true=0;
	FILE* fp;
	fp=fopen("MJudge_������.txt","w+");
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
			fprintf(fp,"\n\n��ȷ[%d/%d]",_true,i-1);
			fclose(fp);
			fflush(stdin);
			fclose(stderr);
			printf("\n�����������ȷ[%d/%d]���������MJudge_������.txt�У�\n",_true,i-1);
			printf("�밴������˳�...");
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
			printf("��%d�����Ե���ȷ ʱ�䣺%0.2lfs\n",i,(double)(end-start)/CLOCKS_PER_SEC);
			fprintf(fp,"%d:�� ʱ�䣺%0.2lfs\n",i,(double)(end-start)/CLOCKS_PER_SEC);
			_true++;
		}
		else
		{
			printf("��%d�����Ե���� ʱ�䣺%0.2fs\n",i,(double)(end-start)/CLOCKS_PER_SEC);
			fprintf(fp,"%d:�� ʱ�䣺%0.2fs\n",i,(double)(end-start)/CLOCKS_PER_SEC);
			fprintf(fp,"��׼�����\n********\n");
			char f;
			while(fscanf(fcomp1,"%c",&f)!=EOF)
				fprintf(fp,"%c",f);
			fprintf(fp,"\n********\n���������\n********\n");
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
	fauto=fopen("MJudge_�Զ������ļ�.txt","r");
	if(fauto==NULL)
	{
		fauto=fopen("MJudge_�Զ������ļ�.txt","w+");
		normalmode();
	}
	else
	{
		printf("\n~~~~�����Զ������ļ����Ƿ����[y/n]:");
		while(1)
		{
			char inp=getch();
			printf("\n");
			if(inp=='Y'||inp=='y')
				datmode();
			else if(inp=='N'||inp=='n')
			{
				fclose(fauto);
				fauto=fopen("MJudge_�Զ������ļ�.txt","w+");
				normalmode();
			}
			else
			{
				printf("�����������������[y/n]��");
				continue;
			}
			break;
		}
	}
	complier();
}
