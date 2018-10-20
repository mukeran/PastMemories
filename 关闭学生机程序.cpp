#include<windows.h>
int main()
{
	system("title 学生机程序关闭工具，适用于e-Learning Class v2.0 SR BY MUKERAN BETA1");
	system("echo off");
	system("echo 学生机程序关闭工具，适用于e-Learning Class v2.0 SR BY MUKERAN BETA1");
	system("taskkill /f /im student3.exe");
	system("echo 操作已完成，请注意返回信息，请按任意键退出...");
	system("pause >nul");
}
