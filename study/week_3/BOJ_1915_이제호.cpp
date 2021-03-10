#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
string s;
int dp[1000][1000];

void input(int n, int m)
{
	for (int i = 0; i < n; i++) {
		string s;																//문자열로 받고 아스키코드 0만큼 빼서 정수로 변환
		cin >> s;
		for (int j = 0; j < m; j++) {
			int temp = s[j] - '0';
			dp[i][j] = temp;
		}
	}
}
void square_ans(int n, int m)
{
	for (int i = 1; i < n; i++)													//점화식 형태로 도출할 때 i+1꼴을 할수없으므로(탑다운)
	{
		for (int j = 1; j < m; j++)
		{
			if (dp[i][j] != 0)
			{
				dp[i][j] += min(dp[i-1][j-1], min(dp[i][j - 1], dp[i - 1][j]));		//문제 특성상 한 기준점에서 근처에 0이 하나라도 있으면 
			}																		//정사각형이 아님, 맞닿는 부분의 최소가 0이면 0이더해지므로 배열의 값이 변하지 않음
		}																			//모두 1보다 크면 그 값이 더해져 변의 길이를 나타냄
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dp[i][j] > ans) ans = dp[i][j];
		}
	}
	cout << ans * ans;
}

int main() {

	cin >> n >> m;	
	input(n, m);
	square_ans(n, m);	
}