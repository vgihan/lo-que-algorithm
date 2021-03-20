#include <iostream>
using namespace std;

int N;
char NODE[26][2];

void input()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		char alpha;
		cin >> alpha;
		cin >> NODE[alpha - 'A'][0] >> NODE[alpha - 'A'][1];
	}
}

void preOrder(char node) // 전위순회는 ROOT-L-R
{
	if (node == '.')
		return;
	else
	{
		cout << node;
		preOrder(NODE[node - 'A'][0]);
		preOrder(NODE[node - 'A'][1]);
	}
}

void inOrder(char node) // 중위순회는 L-ROOT-R
{
	if (node == '.')
		return;
	else
	{
		inOrder(NODE[node - 'A'][0]);
		cout << node;
		inOrder(NODE[node - 'A'][1]);
	}
}

void postOrder(char node) // 후위순회는 L-R-ROOT
{
	if (node == '.')
		return;
	else
	{
		postOrder(NODE[node - 'A'][0]);
		postOrder(NODE[node - 'A'][1]);
		cout << node;
	}
}

void solve()
{
	preOrder('A');	// 인자로 첫 시작 노드 'A'를 넣어줌
	cout << endl;
	inOrder('A');
	cout << endl;
	postOrder('A');
	cout << endl;
}

int main()
{
	input();
	solve();

	return 0;
}