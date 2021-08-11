/*
2021-08-11
hackerrank day 28 c언어 풀이
문제 : 이름과 이메일 정보가 담긴 데이터베이스를 입력받고 이름순으로 정렬 후 출력하기.
	단, gmail 이메일만 입력받는다.
입력 : 테이블의 총 행 수 N, 다음 줄에는 이름과 이메일 ID 문자열을 공백을 두고 입력
	(2 <= N <= 30) (이름의 길이는 20자 이하, 이메일 길이는 50자 이하)
출력 : gmail 계정이 있는 사용자들의 이름을 알파벳순으로 나열 후 이름 출력
작성자 : JihoKim0
*/


#include <stdio.h>
#include <string.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))	//정렬을 위한 매크로
typedef struct {	//데이터베이스 형식
	char name[20];
	char email[50];
}gmail;

void bubble_sort(gmail *list, int n)	//버블정렬 사용
{
	int i, j;
	gmail temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strcmp(list[j].name, list[j+1].name) > 0)	//구조체배열의 각 이름 순서를 비교하여 정렬
				SWAP(list[j], list[j + 1], temp);
		}
	}
}

int main()
{
	int n, i;
	gmail gmail[30];	//사용할 구조체 배열
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s", gmail[i].name, gmail[i].email);	//이름과 데이터베이스 입력받기
		if (strstr(gmail[i].email, "@gmail.com") == 0) {	//gmail 계정이 아니라면
			i--; n--;	//i와 n을 감소시켜 입력을 되돌린다
		}
	}

	bubble_sort(gmail, n);	//버블정렬
	for (i = 0; i < n; i++)
		printf("%s\n", gmail[i].name);

	return 0;
}