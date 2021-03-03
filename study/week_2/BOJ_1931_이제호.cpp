#include <iostream>
#include <algorithm>

using namespace std;

typedef struct room {
	unsigned int in;
	unsigned int out;
}room;


bool decr(const room& r1, const room& r2) 
{ //내림차순 정렬
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
	int min = r[0].out; //제일 빨리 나오는 방을 최솟값으로 지정

	for (int i = 1; i < n; i++) {
		if (r[i].in < min) //나오는방보다 빨리 들어가면 안되므로 컨티뉴로 넘어감
			continue;
		cnt++;
		min = r[i].out;
	}
	cout << cnt;
	/*for (int i = 0; i < n; i++)
		cout << r[i].in <<" "<< r[i].out<<endl; */
}
