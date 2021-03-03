#include <iostream>
#include <algorithm>

using namespace std;

int N;
int price[1001][3];
int dp[1001][3] = { 0, };
int mincost = 987654321;

enum Color				// 열거형 사용으로 숫자를 색으로 표현가능
{
	COLOR_RED,			//RED 0
	COLOR_GREEN,		//GREEN 1
	COLOR_BLUE,			//BLUE 2
};

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = COLOR_RED; j <= COLOR_BLUE; j++)
			cin >> price[i][j];
}

void solve()
{
	for (int i = 1; i <= N; i++)
	{
		dp[i][COLOR_RED] = min(dp[i - 1][COLOR_GREEN], dp[i - 1][COLOR_BLUE])+price[i][COLOR_RED];
		dp[i][COLOR_GREEN] = min(dp[i - 1][COLOR_RED], dp[i - 1][COLOR_BLUE])+price[i][COLOR_GREEN];
		dp[i][COLOR_BLUE] = min(dp[i - 1][COLOR_RED], dp[i - 1][COLOR_GREEN])+ price[i][COLOR_BLUE];
	}

	mincost = min(min(dp[N][COLOR_RED], dp[N][COLOR_GREEN]), dp[N][COLOR_BLUE]);
}

void output()
{
	cout << mincost << endl;
}

int main()
{
	input();
	solve();
	output();

	return 0;
}