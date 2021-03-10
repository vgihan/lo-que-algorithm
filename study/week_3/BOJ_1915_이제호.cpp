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
		string s;																//���ڿ��� �ް� �ƽ�Ű�ڵ� 0��ŭ ���� ������ ��ȯ
		cin >> s;
		for (int j = 0; j < m; j++) {
			int temp = s[j] - '0';
			dp[i][j] = temp;
		}
	}
}
void square_ans(int n, int m)
{
	for (int i = 1; i < n; i++)													//��ȭ�� ���·� ������ �� i+1���� �Ҽ������Ƿ�(ž�ٿ�)
	{
		for (int j = 1; j < m; j++)
		{
			if (dp[i][j] != 0)
			{
				dp[i][j] += min(dp[i-1][j-1], min(dp[i][j - 1], dp[i - 1][j]));		//���� Ư���� �� ���������� ��ó�� 0�� �ϳ��� ������ 
			}																		//���簢���� �ƴ�, �´�� �κ��� �ּҰ� 0�̸� 0�̴������Ƿ� �迭�� ���� ������ ����
		}																			//��� 1���� ũ�� �� ���� ������ ���� ���̸� ��Ÿ��
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