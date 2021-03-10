#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int map[1001][1001] = { 0, }; // 여기서 1001 까지의 배열을 선언한 이유는 1행의 정사각형들과
							  // 1열의 정사각형들에 0값을 대입해주어야만 하는 이유가 있기 때문이다.
int maxlength = 0;			  // 왜냐하면 n과 m이 1인 경우를 생각해주어야 하기 때문이다.

void input()
{
	string num; //문자열 형식으로 입력받고 int형으로 변환해주었음.
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
	cout << maxlength * maxlength << endl; //정사각형의 넓이크기를 구해야 하므로 제곱해준다.
}

int main()
{
	input();
	solve();
	output();

	return 0;
}