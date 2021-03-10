#include <iostream>
#include <algorithm>
#include <cstring>

int height[100][100]; // 필드값을 입력받기 위한 배열
bool check[100][100]; // 탐색을 했던 지점인가를 확인하기 위한 배열
int N;
int max_Height = -987654321; // 가장 높은 지점까지 모든 경우의 수를 돌려야하므로 필요
int max_Safeplace = -987654321; // 안전영역의 수
int cnt;

using namespace std;

//구조체로 구현해도 됨. 동서남북 탐색을 위한 도구
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void DFS(int r, int c, int rain) {
	for (int i = 0; i < 4; i++) {
		int next_r = r + dr[i];
		int next_c = c + dc[i];

		if (next_r < 0 || next_c < 0 || next_r >= N || next_c >= N) continue;
		if (height[next_r][next_c] <= rain || check[next_r][next_c]) continue;

		check[next_r][next_c] = true;
		DFS(next_r, next_c, rain);
	}
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> height[i][j];
			if (height[i][j] > max_Height)
				max_Height = height[i][j]; // 최고 높이를 구하여야 모든 경우를 돌려볼 수 있음.
		}
}

void solve()
{
	for (int rain = 0; rain <= max_Height; rain++)
	{
		cnt = 0;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if ((check[i][j] == false) && (height[i][j] > rain))
				{ // 그 지점을 아직 탐색하지 않았어야 하고, 안전한 영역이어야 함.
					cnt++;
					DFS(i, j, rain);
				}
				else
					check[i][j] = true;
			}
		max_Safeplace = max(max_Safeplace, cnt);
	}
}

void output()
{
	cout << max_Safeplace << endl;
}

int main()
{
	input();
	solve();
	output();
}