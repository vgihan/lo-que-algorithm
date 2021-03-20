#include <iostream>
#include <vector>

using namespace std;

//vector<int> v[1000]; ������� ������ ���� 
int arr[130][2];



int N;
char root, l, r;

void input(void)
{
	for (int i = 0; i < N; i++) {		//arr[A][0]=B //arr[A][1]=C ���·� ��Ʈ���� �迭�� ���� ��Ʈ�� �־ �����Ͽ���
		cin >> root >> l >> r;
		int a = root;
		int b = l;
		int c = r;
		arr[a][0] = l;
		arr[a][1] = r;
	}
}

void preorder(int X)					//�� �� ��
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

void inorder(int X)						// �� �� ��
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

void postorder(int X)				// �� �� ��
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