#include <iostream>
#include <algorithm>

using namespace std;

int sum[1001][3];

int shortway(int arr[1001][3], int nn,int color) //sum[][]���ϱ� N������ �ּ��� ���ϱ�
{
	if (nn == 2 && color == 0)
		sum[2][0] += arr[2][0] + min(arr[1][1], arr[1][2]);
	if (nn == 2 && color == 1)
		sum[2][1] += arr[2][1] + min(arr[1][0], arr[1][2]);
	if (nn == 2 && color == 2)
		sum[2][2] += arr[2][0] + min(arr[1][0], arr[1][1]);
		
	if (nn >= 2 && color == 0)
	{
		sum[nn][0] += arr[nn][0] + min(shortway(arr,nn-1,1), shortway(arr, nn - 1, 2)); // ���������� �������ΰ�� �������=��������+ ������ �Ķ���,�ʷ����� �ּڰ� 
	}
	if (nn >= 2 && color == 1)
	{
		sum[nn][1] += arr[nn][1] + min(shortway(arr, nn - 1, 0), shortway(arr, nn - 1, 2)); // ���������� �ʷϻ��ΰ�� �������=��������+ ������ ������,�Ķ����� �ּڰ� 
	}
	if (nn >= 2 && color == 2)
	{
		sum[nn][2] += arr[nn][2] + min(shortway(arr, nn - 1, 0), shortway(arr, nn - 1, 1)); // ���������� �Ķ����ΰ�� �������=��������+ ������ ������,�ʷ����� �ּڰ� 
	}
		
	return sum[nn][color]; //������� ��ȯ
}

int main(void)
{
	int N ,sum1,sum2,sum3,minsum;
	cin >> N;
	int way[1001][3];
	for (int i = 1; i <= N; i++)
	{
		cin >> way[i][0]>> way[i][1]>> way[i][2];
	}
	sum1 = shortway(way, N, 0);
	sum2 = shortway(way, N, 1);
	sum3 = shortway(way, N, 2);
	minsum = min(sum1,min(sum2,sum3));
	cout << minsum;
}