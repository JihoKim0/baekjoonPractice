/*
2021-07-26
���� 2798�� Ǯ��
���� : N���� ī�忡 ���� �ִ� ���ڰ� �־����� ��, M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ���� ����Ͻÿ�.
�ۼ��� : JihoKim0
*/
#include <stdio.h>

int choice(int answer, int temp, int m)	//���� ã�� �Լ�
{
	if (temp > m)	//temp�� m �ʰ���
		return answer;	//���� answer ��ȯ
	else if (temp > answer)	//temp�� m�� ���� �ʰ� answer���� ũ�ٸ�
		return temp;	//temp ��ȯ
	else
		return answer;
}

int main(void)
{
	int n, m, i, j, k;	//n�� ī�尳��, m�� �ִ밪
	int card[100] = { NULL };	//ī�� ������ 3~100��
	int answer = 0, temp = 0;	//answer�� ã�ƾ� �ϴ� ��, temp�� �ӽ� �� ����

	//ī�尳���� �ִ밪�� �Է¹ް� ī�尳����ŭ ī���� ���� �Է¹���
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &card[i]);

	//3���� ī�带 ���� �� �ִ� ��� ����� �� ��������
	for (i = 0; i < (n - 2); i++) {
		for (j = i + 1; j < (n - 1); j++) {
			for (k = j + 1; k < n; k++) {
				temp = card[i] + card[j] + card[k];	//�ӽú����� �ش� �� ����
				answer = choice(answer, temp, m);	//���� ã�� �Լ��� ���� answer�� �Ҵ�
			}
		}
	}
	printf("%d", answer);	//�� ���

	return 0;
}