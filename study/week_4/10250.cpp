#include <iostream>

using namespace std;

int main()
{
	int T;
	int H, W, N; // ��,��ȣ,���°�մ�����
	int X, Y;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> H >> W >> N;
		if (N <= H * W)
		{
			if (N % H == 0)
			{
				Y = H * 100;
				X = N / H;
			}
			else
			{
				Y = (N % H) * 100;
				X = (N / H) + 1;
			}
			cout << Y + X << endl;
		}
		else
			cout << "���� �� á���";
	}
	return 0;
}