#include <iostream>

using namespace std;

int main()
{
	int T;
	int H, W, N; // Ãþ,¹øÈ£,¸î¹øÂ°¼Õ´ÔÀÎÁö
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
			cout << "¹æÀÌ ´Ù Ã¡¾î¿ä";
	}
	return 0;
}