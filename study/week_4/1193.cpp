#include <iostream>

using namespace std;

int main()
{
	int X;
	int i = 1; // ���° �밢������
	int A = 0; // ������
	cin >> X;
	for(int sum = 0; sum+i < X ; i++)
	{
		sum += i;
		A = X - sum;
	}
	if (X == 1)
	{
		cout << "1/1" << endl;
	}
	else
	{

		if (i % 2 == 0)
		{
			cout << A << "/" << i + 1 - A << endl;
		}
		else
		{
			cout << i + 1 - A << "/" << A << endl;
		}
	}
	return 0;
}