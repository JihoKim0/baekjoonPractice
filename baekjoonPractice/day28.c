/*
2021-08-11
hackerrank day 28 c��� Ǯ��
���� : �̸��� �̸��� ������ ��� �����ͺ��̽��� �Է¹ް� �̸������� ���� �� ����ϱ�.
	��, gmail �̸��ϸ� �Է¹޴´�.
�Է� : ���̺��� �� �� �� N, ���� �ٿ��� �̸��� �̸��� ID ���ڿ��� ������ �ΰ� �Է�
	(2 <= N <= 30) (�̸��� ���̴� 20�� ����, �̸��� ���̴� 50�� ����)
��� : gmail ������ �ִ� ����ڵ��� �̸��� ���ĺ������� ���� �� �̸� ���
�ۼ��� : JihoKim0
*/


#include <stdio.h>
#include <string.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))	//������ ���� ��ũ��
typedef struct {	//�����ͺ��̽� ����
	char name[20];
	char email[50];
}gmail;

void bubble_sort(gmail *list, int n)	//�������� ���
{
	int i, j;
	gmail temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strcmp(list[j].name, list[j+1].name) > 0)	//����ü�迭�� �� �̸� ������ ���Ͽ� ����
				SWAP(list[j], list[j + 1], temp);
		}
	}
}

int main()
{
	int n, i;
	gmail gmail[30];	//����� ����ü �迭
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s", gmail[i].name, gmail[i].email);	//�̸��� �����ͺ��̽� �Է¹ޱ�
		if (strstr(gmail[i].email, "@gmail.com") == 0) {	//gmail ������ �ƴ϶��
			i--; n--;	//i�� n�� ���ҽ��� �Է��� �ǵ�����
		}
	}

	bubble_sort(gmail, n);	//��������
	for (i = 0; i < n; i++)
		printf("%s\n", gmail[i].name);

	return 0;
}