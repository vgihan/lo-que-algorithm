#include <iostream>
#include <algorithm>
#include <cstring>

int height[100][100]; // �ʵ尪�� �Է¹ޱ� ���� �迭
bool check[100][100]; // Ž���� �ߴ� �����ΰ��� Ȯ���ϱ� ���� �迭
int N;
int max_Height = -987654321; // ���� ���� �������� ��� ����� ���� �������ϹǷ� �ʿ�
int max_Safeplace = -987654321; // ���������� ��
int cnt;

using namespace std;

//����ü�� �����ص� ��. �������� Ž���� ���� ����
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
				max_Height = height[i][j]; // �ְ� ���̸� ���Ͽ��� ��� ��츦 ������ �� ����.
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
				{ // �� ������ ���� Ž������ �ʾҾ�� �ϰ�, ������ �����̾�� ��.
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