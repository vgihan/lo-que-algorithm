#include <iostream>

using namespace std;

char B[8][8] = { 0 };
char W[8][8] = { 0 };
char T[50][50];
int main()
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
				if (j % 2 == 0)
					B[i][j] = 'B';
				else
					B[i][j] = 'W';
				if (i % 2 == 1)
				{
					if (j % 2 == 0)
						B[i][j] = 'W';
					else
						B[i][j] = 'B';
				}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j % 2 == 0)
				B[i][j] = 'W';
			else
				B[i][j] = 'B';
			if (i % 2 == 1)
			{
				if (j % 2 == 0)
					B[i][j] = 'B';
				else
					B[i][j] = 'W';
			}
		}
	}
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> T[i][j];
		}
	}
	for (int k = 0; k < m - 8; k++)
	{
		for (int l = 0; l < n - 8; n++)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (B[i][j] != T[i+k][j+l])
						count += 1;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
