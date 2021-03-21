#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, P;
int cnt = 0;

vector<int> g_line[7];

void solve()
{
	cin >> N >> P;
	int line, pret;
	for (int i = 0; i < N; i++)
	{
		cin >> line >> pret;
		if (g_line[line].empty())
		{
			g_line[line].push_back(pret);
			cnt++;
			continue;
		}
		if (pret>g_line[line].back())
		{
			g_line[line].push_back(pret);
			cnt++;
		}
		while(pret < g_line[line].back())
		{
			g_line[line].pop_back();
			cnt++;
			if (g_line[line].empty())
			{
				g_line[line].push_back(pret);
				cnt++;
				continue;
			}
			if (pret > g_line[line].back())
			{
				g_line[line].push_back(pret);
				cnt++;
				break;
			}
		}
	}
}


int main()
{
	solve();

	cout << cnt << endl;

	return 0;
}