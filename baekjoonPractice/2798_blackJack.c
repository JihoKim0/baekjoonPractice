/*
2021-07-26
백준 2798번 풀이
문제 : N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하시오.
작성자 : JihoKim0
*/
#include <stdio.h>

int choice(int answer, int temp, int m)	//답을 찾는 함수
{
	if (temp > m)	//temp가 m 초과시
		return answer;	//기존 answer 반환
	else if (temp > answer)	//temp가 m을 넘지 않고 answer보다 크다면
		return temp;	//temp 반환
	else
		return answer;
}

int main(void)
{
	int n, m, i, j, k;	//n은 카드개수, m은 최대값
	int card[100] = { NULL };	//카드 개수는 3~100개
	int answer = 0, temp = 0;	//answer은 찾아야 하는 합, temp는 임시 합 변수

	//카드개수와 최대값을 입력받고 카드개수만큼 카드의 값을 입력받음
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &card[i]);

	//3장의 카드를 뽑을 수 있는 모든 경우의 수 따져보기
	for (i = 0; i < (n - 2); i++) {
		for (j = i + 1; j < (n - 1); j++) {
			for (k = j + 1; k < n; k++) {
				temp = card[i] + card[j] + card[k];	//임시변수에 해당 합 저장
				answer = choice(answer, temp, m);	//답을 찾는 함수를 통해 answer에 할당
			}
		}
	}
	printf("%d", answer);	//답 출력

	return 0;
}