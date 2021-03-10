#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int map[1001][1001] = { 0, }; // ���⼭ 1001 ������ �迭�� ������ ������ 1���� ���簢�����
							  // 1���� ���簢���鿡 0���� �������־�߸� �ϴ� ������ �ֱ� �����̴�.
int maxlength = 0;			  // �ֳ��ϸ� n�� m�� 1�� ��츦 �������־�� �ϱ� �����̴�.

void input()
{
	string num; //���ڿ� �������� �Է¹ް� int������ ��ȯ���־���.
	cin >> n >> m;

	for (int r = 1; r <= n; r++)
	{
		cin >> num;
		for (int c = 1; c <= m; c++)
		{
			map[r][c] = num[c - 1] - '0';
		}
	}
}

void solve()
{
	for (int r = 1; r <= n; r++)
		for (int c = 1; c <= m; c++)
		{
			if (map[r][c] == 1)
			{
				map[r][c] = min(min(map[r][c - 1], map[r - 1][c]), map[r - 1][c - 1]) + 1;
				maxlength = max(maxlength, map[r][c]);
			}
		}
}

void output()
{
	cout << maxlength * maxlength << endl; //���簢���� ����ũ�⸦ ���ؾ� �ϹǷ� �������ش�.
}

int main()
{
	input();
	solve();
	output();

	return 0;
}