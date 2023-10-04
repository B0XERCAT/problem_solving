#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int cnt, N, num1, num10, temp, N_1;
	scanf("%d", &N);
	temp = N;
	cnt = 0;
	while (1)
	{
		num1 = N % 10;
		num10 = N / 10;
		N_1 = num1 + num10;
		N = num1 * 10 + (N_1%10);
		cnt += 1;
		if (temp == N)
			break;
	}
	printf("%d", cnt);
	return 0;
}