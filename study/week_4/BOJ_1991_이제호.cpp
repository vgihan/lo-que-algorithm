#include <iostream>
#include <vector>

using namespace std;

//vector<int> v[1000]; 저장공간 문제로 실패 
int arr[130][2];



int N;
char root, l, r;

void input(void)
{
	for (int i = 0; i < N; i++) {		//arr[A][0]=B //arr[A][1]=C 형태로 루트값을 배열의 값에 인트로 넣어서 저장하였음
		cin >> root >> l >> r;
		int a = root;
		int b = l;
		int c = r;
		arr[a][0] = l;
		arr[a][1] = r;
	}
}

void preorder(int X)					//루 왼 오
{
	if (X == '.')
		return;
	char c = X;
	int l = arr[X][0];
	int r = arr[X][1];
	cout << c;
	preorder(l);
	preorder(r);

}

void inorder(int X)						// 왼 루 오
{
	if (X == '.')
		return;
	char c = X;
	int l = arr[X][0];
	int r = arr[X][1];
	inorder(l);
	cout << c;
	inorder(r);

}

void postorder(int X)				// 왼 오 루
{
	if (X == '.')
		return;
	char c = X;
	int l = arr[X][0];
	int r = arr[X][1];
	postorder(l);
	postorder(r);
	cout << c;
}

int main(void)
{
	cin >> N;
	input();
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
}