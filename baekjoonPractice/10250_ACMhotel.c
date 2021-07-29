/*
2021-07-29
백준 10250번 풀이
문제 : 호수의 뒤 2자리가 작을수록, 층수가 낮을수록 좋은 호실이다. 먼저 오는 손님부터 좋은 호실을 준다.
입력 : 프로그램은 표준 입력에서 입력 데이터를 받는다.
프로그램의 입력은 T 개의 테스트 데이터로 이루어져 있는데
T 는 입력의 맨 첫 줄에 주어진다.
각 테스트 데이터는 한 행으로서 H, W, N, 세 정수를 포함하고 있으며
각각 호텔의 층 수, 각 층의 방 수, 몇 번째 손님인지를 나타낸다(1≤ H, W≤ 99, 1≤N≤H×W)
출력 : N 번째 손님에게 배정되어야 하는 방 번호를 출력한다.
작성자 : JihoKim0
*/
#include <stdio.h>

int main()
{
	int t, i; //t는 테스트 데이터
	int h[99] = { NULL }, w[99] = { NULL }, n[9801] = { NULL }; //h는 층수, w는 각 층의 방 수, n은 몇번째 손님인지
	int height = 0, width = 1; //구할 층수와 방 호수

	scanf("%d", &t);	//테스트 데이터 개수 입력
	for (i = 0; i < t; i++)
		scanf("%d %d %d", &h[i], &w[i], &n[i]);	//층수, 방 수, 몇번째 손님인지 입력

	int count = 0;	//테스트 데이터만큼을 실행하기 위한 변수
	while (count < t) {	//t만큼 반복
		for (i = 1; i <= n[count]; i++) {
			if (height >= h[count]) {	//높이가 최대 높이보다 크거나 같다면
				height = 0;	//층수 초기화
				width++;	//호수 증가
			}
			height++;	//층수 증가
		}
		printf("%d\n", height * 100 + width);	//층수와 호수를 합산하여 최종 호수 출력
		height = 0, width = 1;	//층수와 호수 초기화
		count++;
	}

	return 0;
}