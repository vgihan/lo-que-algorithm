#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int main()
{
	int T, H, W, N, i, c, d;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d %d %d", &H, &W, &N);

		c = N % H;
		d = N / H;
		if (c > 0) 
			d += 1;
		else 
			c = H;
		printf("%d\n", c * 100 + d);
	}
	return 0;
}