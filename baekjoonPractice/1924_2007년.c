/*
2021-08-04
백준 1924번 풀이
문제 : 2007년의 월과 일이 주어졌을 때 그 요일을 알아내는 프로그램
입력 : 첫째 줄에 빈 칸을 사이에 두고 x(1 ≤ x ≤ 12)와 y(1 ≤ y ≤ 31)이 주어진다
출력 : 첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.
작성자 : JihoKim0
*/
#include <stdio.h>

int main()
{
	int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	// 각 월에 대한 총 일 수
	char *weekday[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };	// 요일 정보를 담은 배열
	int month, date;
	scanf("%d %d", &month, &date);	// 월과 일 입력

	for (int i = 1; i < month; i++) {
		date += monthday[i];	// 입력받은 날짜를 일 수로 환산
	}

	printf("%s", weekday[date % 7]);	// 계산한 일 수를 7로 나눈 나머지를 인덱스로 하는 요일 출력
	return 0;
}