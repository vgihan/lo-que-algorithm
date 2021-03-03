#include <iostream>
#include <algorithm>

using namespace std;

typedef struct room {
	unsigned int in;
	unsigned int out;
}room;


bool decr(const room& r1, const room& r2) 
{ //�������� ����
	if (r1.out == r2.out) 
		return r1.in < r2.in;
	return r1.out < r2.out;
}
int main()
{
	int n;
	cin >> n;
	room r[100001];

	for (int i = 0; i < n; i++)
		cin >> r[i].in >> r[i].out;
	sort(r, r + n, decr);

	int cnt = 1;
	int min = r[0].out; //���� ���� ������ ���� �ּڰ����� ����

	for (int i = 1; i < n; i++) {
		if (r[i].in < min) //�����¹溸�� ���� ���� �ȵǹǷ� ��Ƽ���� �Ѿ
			continue;
		cnt++;
		min = r[i].out;
	}
	cout << cnt;
	/*for (int i = 0; i < n; i++)
		cout << r[i].in <<" "<< r[i].out<<endl; */
}
