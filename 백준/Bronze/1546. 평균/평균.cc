#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N, i, j, temp1, temp2, score[1000] = { 0, };
	double sum = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &score[i]);
	temp2 = score[0];
	for (i = 0; i < N-1; i++)
	{
		for (j = 0; j < N-1-i; j++)
			if (score[j] < score[j + 1])
			{
				temp1 = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp1;
			}
	}/*버블정렬까지 문제 없음!!!*/
	for (i = 0; i < N; i++)
	{
		sum += score[i];
	}
	sum = (sum / score[0] * 100) / N;
	printf("%f", sum);


	return 0;
}